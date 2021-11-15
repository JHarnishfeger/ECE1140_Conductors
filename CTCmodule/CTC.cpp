#include "CTC.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>

CTC::CTC(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct) {

	//Give the waystructs to WaysideManager
	std::list<WayStruct*> waystructs;
	for(int i = 0; i < sw_waystructs->size(); i++){
		waystructs.push_back(&(*sw_waystructs)[i]);
	}
	waystructs.push_back(hw_waystruct);
	waysideManager = WaysideManager(waystructs);

    mode = true;
    time = 0; //Assuming we start at time 0
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

    if(mode && schedule.size() > 0){
        CTCSchedule nextSchedule = schedule.front();
        schedule.erase(schedule.begin());
    }
    //TODO stuff here
}

/*
 * Set a single block to be open/closed due to maintenence.
 */
void CTC::setTrackMaintenence(int blockId, bool isBroken){
    //TODO
}

/*
 * Set a single block switch to a given direction (See Block.cpp)
 */
void CTC::setTrackSwitch(int blockId, char direction){
    //TODO
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
std::vector<Block> CTC::getSwitches(){
    std::vector<Block> switches;
    return switches;
    //TODO
}

/*
 * Dispatch a single schedule
 */
void CTC::dispatchTrain(CTCSchedule schedule){
    //TODO
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
    //TODO
    return false;
}

/*
 * Get whether a single block has a train on it currently
 * True = has train
 * False = doesn't have train
 */
bool CTC::getBlockHasTrainPresent(int blockId){
    return false;
    //TODO
}

/*
 * Get the direction property of a Block
 */
char CTC::getBlockDirection(int blockId){
    return ' ';
    //TODO
}

