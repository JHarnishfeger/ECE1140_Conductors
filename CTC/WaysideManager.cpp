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
        for(unsigned int i = 0; i < sector.size(); i++){
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
        for(unsigned int i = 0; i < sector.size(); i++){
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

bool WaysideManager::getBlockClosedForMaintenence(int blockId){
    for(int i : greenMaintenence){
        if(blockId == i){
            return true;
        }
    }
    return false;
}

void WaysideManager::setBlockClosedForMaintenence(int blockId, bool maintenence){
    if(maintenence){
        if(!getBlockClosedForMaintenence(blockId)){
            //Add to list
            greenMaintenence.push_back(blockId);
        }
    }else{
        if(getBlockClosedForMaintenence(blockId)){
            //Remove from list
            for(auto itr = greenMaintenence.begin(); itr != greenMaintenence.end(); ++itr){
                if(*itr == blockId){
                    greenMaintenence.erase(itr);
                    return;
                }
            }
        }
    }
}

void WaysideManager::setAuthority(Authority authority){
    for(WayStruct* w : waysides){
        bool includedInbranch = false;
        std::vector<Block>& sector = w->sector;
        for(unsigned int i = 0; i < sector.size(); i++){
            if(track->getBranchOfBlock(sector[i].getId()) == authority.branch){
                includedInbranch = true;
            }
        }
        if(includedInbranch){
            w->auth.push_back(authority);
        }
    }
}

void WaysideManager::addNewRouteToQueues(std::list<Authority> route){
    for(Authority& authority : route){
        authorityQueues[authority.branch].push(authority);
    }
}

Authority WaysideManager::getAuthority(std::string branch){
    for(WayStruct* w : waysides){
        std::vector<Block>& sector = w->sector;
        for(unsigned int i = 0; i < sector.size(); i++){
            if(track->getBranchOfBlock(sector[i].getId()) == branch){
                auto authorities = w->auth;
                for(unsigned int i = 0; i < authorities.size(); i++){
                    if(authorities[i].branch == branch){
                        return authorities[i];
                    }
                }
            }
        }
    }
    return Authority{};
}

void WaysideManager::setNextAuthorityFromQueue(std::string branch){
    std::cout << "Made it to here!\n";
    if(authorityQueues[branch].empty()){
        return;
    }
    setAuthority(authorityQueues[branch].front());
    authorityQueues[branch].pop();
}

std::list<std::pair<std::string, int>> WaysideManager::getTrainsPerBranch(){
    std::list<std::pair<std::string, int>> list;
    std::unordered_map<std::string, int> trainsPerBranch;

    for(WayStruct* w : waysides){
        std::vector<Block>& sector = w->sector;
        for(unsigned int i = 0; i < sector.size(); i++){
            Block& b = sector[i];
            if(b.getTrainPresent() == true){
                trainsPerBranch[track->getBranchOfBlock(b.getId())]++;
            }
        }
    }

    for(auto branch : trainsPerBranch){
        list.push_back(std::pair<std::string, int>(branch.first, branch.second));
    }

    return list;
}
