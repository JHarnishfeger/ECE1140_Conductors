#include "CTC.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "WaysideManager.h"

CTC::CTC(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct) :
trainTracker(&track){

    if(sw_waystructs == nullptr || hw_waystruct == nullptr){
        std::cout << "CTC: WayStructs are being recieved as null!\n";
    }

	//Give the waystructs to WaysideManager
	std::list<WayStruct*> waystructs;
    if(sw_waystructs != nullptr && hw_waystruct != nullptr){
        for(unsigned int i = 0; i < sw_waystructs->size(); i++){
            waystructs.push_back(&(*sw_waystructs)[i]);
        }
        waystructs.push_back(hw_waystruct);
    }
    waysideManager = WaysideManager(waystructs, &track);
    mode = true;
    time = 0; //Assuming we start at time 0
}

CTC::~CTC(){

}

/*
 * Add a new schedule line to the back of the list.
 */
void CTC::addSchedule(CTCSchedule _schedule){
    scheduleManager.addSchedule(_schedule);
}

/*
 * Load the MBO's schedule from a CSV file.
 */
void CTC::loadSchedule(std::string filepath){
  scheduleManager.loadSchedule(filepath);
}

/*
 * Display the currently held CTC schedule
 */
std::string CTC::displaySchedule(){
	return scheduleManager.displaySchedule();
}

/*
 * Add time to clock and update stored values.
 * Also updates internal model of track data.
 * If CTC is in automatic mode, switches will be set to allow
 * trains to get to their destinations.
 */
void CTC::update(int current_time){
    time = current_time;

    //TODO stuff here
    auto nextSchedule = scheduleManager.loadNextSchedule();
    if(mode == true && time >= nextSchedule.time && nextSchedule.train != ""){
        dispatchTrain(nextSchedule);
        scheduleManager.popNextSchedule();
    }
}

/*
 * Set a single block to be open/closed due to maintenence.
 */
void CTC::setTrackMaintenence(int blockId, bool isBroken){
    Block* block = waysideManager.getBlock(blockId);
    if(block != nullptr){
        return waysideManager.setBlockClosedForMaintenence(blockId, isBroken);
    }
}

/*
 * Set a single block switch to a given direction (See Block.cpp)
 */
void CTC::setTrackSwitch(int blockId, bool direction){
    //THIS IMPLEMENTATION IS WRONG. CTC NEEDS TO USE AUTHORITY TO FLIP SWITCHES.
    Block* block = waysideManager.getBlock(blockId);
    if(block != nullptr){
        if(getTrackMaintenence(blockId) == true){
            block->setSwitchStatus(direction);
        }
    }
}

/*
 * Set the current mode for the CTC:
 * True = automatic, False = manual
 */
void CTC::setCTCMode(bool _mode){
    mode = _mode;
}

/*
 * Returns a vector list of only the blocks that have switches
 */
std::list<int> CTC::getSwitches(){
    return waysideManager.getGreenLineSwitches();
}

/*
 * Dispatch a single schedule
 */
void CTC::dispatchTrain(CTCSchedule schedule){
    std::cout << "Dispatched train " << schedule.train << " to block " <<
                 schedule.destination << " at time " << time << std::endl;

    //TODO
    //Get the route
    
    //Right now, all trains come from yard
    int destinationBlock = schedule.destination;
    std::list<std::string> route = track.getBranchRoute("YARD", track.getBranchOfBlock(schedule.destination));
    
    //Send Authorities to each wayside
    std::list<Authority> authorities;
    for(auto itr = route.begin(); itr != route.end(); itr++){
        if(*itr == route.back()){
            authorities.push_back(Authority{*itr, "", destinationBlock});
        }else{
            auto itr2 = itr;
            authorities.push_back(Authority{*itr, *(++itr2) ,-1});
        }
    }

    waysideManager.addNewRouteToQueues(authorities);
}

/*
 * Get the current suggested speed
 */
double CTC::getSuggestedSpeed(){
    return 0.f; //TODO
}

/*
 * Get whether a single block is closed for maintenence.
 * True = closed
 * False = open
 */
bool CTC::getTrackMaintenence(int blockId){
    Block* block = waysideManager.getBlock(blockId);
    if(block != nullptr){
        return waysideManager.getBlockClosedForMaintenence(blockId);
    }else{
        return false;
    }
}

/*
 * Get whether a single block has a train on it currently
 * True = has train
 * False = doesn't have train
 */
bool CTC::getBlockHasTrainPresent(int blockId){
    Block* block = waysideManager.getBlock(blockId);
    if(block != nullptr){
        return block->getTrainPresent();
    }else{
        return false;
    }
}

/*
 * Get the direction property of a Block
 */
bool CTC::getBlockDirection(int blockId){
    //THIS IS OK, unlike the setSwitch() implementation
    Block* block = waysideManager.getBlock(blockId);
    if(block != nullptr){
        return block->getSwitchStatus();
    }else{
        return false;
    }
}

bool CTC::blockExists(int blockId){
    return (waysideManager.getBlock(blockId) != nullptr);
}

std::list<std::string> CTC::getBranchesWithTrainsPresent(){
    return waysideManager.getBranchesWithTrainsPresent();
}
