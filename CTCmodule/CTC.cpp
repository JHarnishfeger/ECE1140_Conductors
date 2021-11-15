#include "CTC.hpp"
#include <fstream>
#include <stdexcept>

CTCSchedule::CTCSchedule(int _train, int _destination, double _time){
    train = _train;
    destination = _destination;
    time = _time;
}

CTC::CTC(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct) {

	for(int i = 0; i < sw_waystructs->size(); i++){
		waystructs.push_back(&(*waystructs)[i]);
	}
	
	waystructs.push_back(hw_waystruct);

    mode = true;
    time = 0;
}

/*
 * Add a new schedule line to the back of the list.
 */
void CTC::addSchedule(CTCSchedule _schedule){
    schedule.push_back(_schedule);
}

/*
 * Load the MBO's schedule from a CSV file.
 */
void CTC::loadSchedule(std::string filepath){
    std::ifstream in(filepath);

    if(in.fail()){
        return;
    }

    //TODO: File loading code here (Read csv and add schedules to vector)

    in.close();
}

/*
 * Display the currently held CTC schedule
 */
std::string CTC::displaySchedule(){
    std::string rtn = "";
    for(auto s : schedule){
        rtn += "Train " + std::to_string(s.train) + " ";
        rtn += "to Block " + std::to_string(s.destination) + " ";
        rtn += "at Time " + std::to_string(s.time) + "\n";
    }
    return rtn;
}

/*
 * Add time to clock and update stored values.
 * Also updates internal model of track data.
 * If CTC is in automatic mode, switches will be set to allow
 * trains to get to their destinations.
 */
void CTC::update(std::vector<Block> trackData, int current_time){
    time = current_time;
    tochangeDirection.clear();
    track = trackData;

    if(mode && schedule.size() > 0){
        CTCSchedule nextSchedule = schedule.front();
        schedule.erase(schedule.begin());
    }
    //TODO
}

/*
 * Set a single block to be open/closed due to maintenence.
 */
void CTC::setTrackMaintenence(int blockId, bool isBroken){
    if(isBroken){
        for(int i = 0; i < closedForMaintenence.size(); i++){
            Block block = closedForMaintenence[i];
            if(block.getId() == blockId){
                return;
            }
        }
        closedForMaintenence.push_back(track[blockId]);
    }else{
        for(int i = 0; i < closedForMaintenence.size(); i++){
            Block block = closedForMaintenence[i];
            if(block.getId() == blockId){
                closedForMaintenence.erase(closedForMaintenence.begin() + i);
                return;
            }
        }
    }
}

/*
 * Set a single block switch to a given direction (See Block.cpp)
 */
void CTC::setTrackSwitch(int blockId, char direction){
    track[blockId].setDirection(direction);
    tochangeDirection.push_back(track[blockId]);
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
    for(Block block : track){
        if (block.getType() == "switch"){
            switches.push_back(block);
        }
    }
    return switches;
}

/*
 * Dispatch a single schedule
 */
void CTC::dispatchTrain(CTCSchedule schedule){
    //TODO
}

/*
 * Get a list of blocks currently closed for maintenence,
 * to be sent to the Track Controller.
 */
std::vector<Block> CTC::getBlocksClosedForMaintenence(){
    return closedForMaintenence;
}

/*
 * Get a list of changes to the track switching since the last time update() was run,
 * to be sent to the Track Controller.
 */
std::vector<Block> CTC::getNewTrackSwitchChanges(){
    return tochangeDirection;
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
    if(track.size() <= blockId || blockId < 0){
        throw std::out_of_range("Block does not exist");
    }
    for(int i = 0; i < closedForMaintenence.size(); i++){
        if(closedForMaintenence[i].getId() == blockId){
            return true;
        }
    }
    return false;
}

/*
 * Get whether a single block has a train on it currently
 * True = has train
 * False = doesn't have train
 */
bool CTC::getBlockHasTrainPresent(int blockId){
    if(track.size() <= blockId || blockId < 0){
        throw std::out_of_range("Block does not exist");
    }
    return track[blockId].getTrainPresent();
}

/*
 * Get the direction property of a Block
 */
char CTC::getBlockDirection(int blockId){
    if(track.size() <= blockId || blockId < 0){
        throw std::out_of_range("Block does not exist");
    }
    return track[blockId].getDirection();
}
