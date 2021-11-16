#include "WaysideManager.h"

WaysideManager::WaysideManager(){
	
}

WaysideManager::WaysideManager(std::list<WayStruct*> _waystructs, TrackNodes* _track) : waysides(_waystructs), track(_track) {
	greenLineSwitches.push_back(12); //D->C and A->D
	greenLineSwitches.push_back(29); //F->G and Z->F
	greenLineSwitches.push_back(76); //M->N and N->R
	greenLineSwitches.push_back(85); //N->O and Q->N
}

std::list<int> WaysideManager::getGreenLineSwitches(){
	return greenLineSwitches;
}

Block* WaysideManager::getBlock(int id){
    for(WayStruct* w : waysides){
        std::vector<Block>& sector = w->sector;
        for(int i = 0; i < sector.size(); i++){
            Block& b = sector[i];
            if(b.getId() == id){
                return &b;
            }
        }
    }
    return nullptr;
}

std::list<std::string> WaysideManager::getBranchesWithTrainsPresent(){
    std::list<std::string> list;
    for(WayStruct* w : waysides){
        std::vector<Block>& sector = w->sector;
        for(int i = 0; i < sector.size(); i++){
            Block& b = sector[i];
            if(b.getTrainPresent() == true){
                std::string branch = track->getBranchOfBlock(b.getId());
                bool alreadyInList = false;
                for(std::string br : list){
                    if(br == branch) alreadyInList = true;
                }
                if(!alreadyInList){
                    list.push_back(branch);
                }
            }
        }
    }
    return list;
}
