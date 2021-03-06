#include "CTC.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "WaysideManager.h"

CTC::CTC(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct) :
trainTracker(&track, &waysideManager){

    /*if(sw_waystructs == nullptr || hw_waystruct == nullptr){
        std::cout << "CTC: WayStructs are being recieved as null!\n";
    }else{
        std::cout << "CTC: WayStructs are OK\n";
    }*/

	//Give the waystructs to WaysideManager
    //std::cout << "Original Addr: Vector: " << &sw_waystructs << std::endl;
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
    time += current_time;

    auto nextSchedule = scheduleManager.loadNextSchedule();
    if(mode == true && time >= nextSchedule.time && nextSchedule.train != ""){
        dispatchTrain(nextSchedule);
        scheduleManager.popNextSchedule();
    }

    try{
        auto trainsPerBranch = waysideManager.getTrainsPerBranch();
        trainTracker.update(trainsPerBranch); //This line is crashing
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
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
void CTC::dispatchTrain(CTCSchedule schedule, bool hw){
    std::string startingBranch;
    if(!trainTracker.trainExists(schedule.train)){
        startingBranch = "YARD";
        std::cout << "CTC: Creating a new train: \"" << schedule.train << "\"\n";
        //TODO Create new train here
        //newTrain(int 1,int) //first int is hardware(0) or software(1)
                            //second int is if its on the green(0) or red(1)
    }
    startingBranch = trainTracker.getTrainLocation(schedule.train);
    int destinationBlock = scheduleManager.getDestinationBlock(schedule.destination);
    std::list<std::string> route;
    try{
        route = track.getBranchRoute(
            startingBranch,
            track.getBranchOfBlock(destinationBlock)
        );
    }catch(std::exception& e){
        std::cout << "CTC Error: " <<  e.what() << std::endl;
        return;
    }

    std::cout << "Dispatched train " << schedule.train << " from branch " <<
                 startingBranch << " to block " << scheduleManager.getDestinationBlock(schedule.destination) <<
                 ", Branch " << track.getBranchOfBlock(scheduleManager.getDestinationBlock(schedule.destination)) <<
                 " at time " << schedule.time << ".\n";

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
    Block* block = waysideManager.getBlock(blockId);
    if(block != nullptr){
        //std::cout << "CTC: Switch " << blockId << " Is now " << block->getSwitchStatus() << std::endl;
        return block->getSwitchStatus();
    }else{
        //std::cout << "CTC Error: Can't find switch\n";
        return false;
    }
}

bool CTC::blockExists(int blockId){
    return (waysideManager.getBlock(blockId) != nullptr);
}

std::list<std::string> CTC::getBranchesWithTrainsPresent(){
    return waysideManager.getBranchesWithTrainsPresent();
}
