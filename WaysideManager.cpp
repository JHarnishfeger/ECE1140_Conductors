#include "WaysideManager.h"

WaysideManager::WaysideManager(){
    suggestedSpeeds["A"] = 45;
    suggestedSpeeds["B"] = 45;
    suggestedSpeeds["C"] = 45;
    suggestedSpeeds["D"] = 70;
    suggestedSpeeds["E"] = 60;
    suggestedSpeeds["F"] = 70;
    suggestedSpeeds["G"] = 30;
    suggestedSpeeds["H"] = 30;
    suggestedSpeeds["I"] = 30;
    suggestedSpeeds["YARD"] = 30;
    suggestedSpeeds["K"] = 70;
    suggestedSpeeds["L"] = 40;
    suggestedSpeeds["M"] = 40;
    suggestedSpeeds["N"] = 70;
    suggestedSpeeds["O"] = 25;
    suggestedSpeeds["P"] = 25;
    suggestedSpeeds["Q"] = 25;
    suggestedSpeeds["R"] = 26;
    suggestedSpeeds["S"] = 28;
    suggestedSpeeds["T"] = 28;
    suggestedSpeeds["U"] = 30;
    suggestedSpeeds["V"] = 15;
    suggestedSpeeds["W"] = 20;
    suggestedSpeeds["X"] = 20;
    suggestedSpeeds["Y"] = 20;
    suggestedSpeeds["Z"] = 20;
}

WaysideManager::WaysideManager(std::list<WayStruct*> _waystructs, TrackNodes* _track) : waysides(_waystructs), track(_track) {
	greenLineSwitches.push_back(12); //D->C and A->D
	greenLineSwitches.push_back(29); //F->G and Z->F
	greenLineSwitches.push_back(76); //M->N and N->R
	greenLineSwitches.push_back(85); //N->O and Q->N
}

std::list<WayStruct*> WaysideManager::getWayStructs()
{
    return waysides;
}

std::list<int> WaysideManager::getGreenLineSwitches(){
	return greenLineSwitches;
}

Block* WaysideManager::getBlock(int id){
    for(WayStruct* w : waysides){
        std::vector<Block>& sector = w->sector;
        for(unsigned int i = 0; i < sector.size(); i++){
            Block& b = sector[i];
            if(b.getBlockNumber() == id){
                /*std::cout << "CTC WayStr ID: " << w->id << std::endl;
                std::cout << "CTC Local: " << w->sector[11].getSwitchStatus() << ", WayStruct: " << w->sector[11].getSwitchStatus() << std::endl;
                std::cout << "CTC Address: " << &w << std::endl;*/
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
                std::string branch = track->getBranchOfBlock(b.getBlockNumber());
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
            if(track->getBranchOfBlock(sector[i].getBlockNumber()) == authority.branch){
                includedInbranch = true;
            }
        }
        if(includedInbranch){
            w->auth.push_back(authority);
            w->suggestedSpeed = suggestedSpeeds[authority.branch];
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
            if(track->getBranchOfBlock(sector[i].getBlockNumber()) == branch){
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
                trainsPerBranch[track->getBranchOfBlock(b.getBlockNumber())]++;
            }
        }
    }

    for(auto branch : trainsPerBranch){
        list.push_back(std::pair<std::string, int>(branch.first, branch.second));
    }

    return list;
}
