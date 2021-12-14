#include "TrainTracker.h"

TrainTracker::TrainTracker(TrackNodes* _track, WaysideManager* _waysideManager)
    : track(_track), waysideManager(_waysideManager){

}

bool TrainTracker::trainExists(std::string train){
    for(unsigned int i = 0; i < existentTrains.size(); i++){
        if(existentTrains[i] == train){
            return true;
        }
    }
    return false;
}

std::string TrainTracker::getTrainLocation(std::string trainName){
    if(!trainExists(trainName)){
        return "";
    }
    return  trainLocations[trainName];
}

void TrainTracker::update(std::list<std::pair<std::string, int>> trainsPerBranch){
    //std::unordered_map<std::string, std::vector<std::string>> trainOrder;
    //std::unordered_map<std::string, std::string> trainLocations;
    //std::vector<std::string> existentTrains;

    //std::unordered_map<std::string, int> lastTrainsPerbranch;

    for(auto branch = trainsPerBranch.begin(); branch != trainsPerBranch.end(); branch++){

        auto nextBranches = track->getNextBranch(branch->first);

        //Train has moved into next branch, there is one less train in this branch
        if(branch->second < lastTrainsPerbranch[branch->first]){

            //We need to look at authority to see where the train went
            std::string nextBranch = waysideManager->getAuthority(branch->first).nextBranch;

            if(nextBranch == "YARD"){
                //Going to the yard, remove front train
                trainLocations.erase(trainOrder[branch->first][0]);
                for(unsigned int i = 0; i < existentTrains.size(); i++){
                    if(existentTrains[i] == trainOrder[branch->first][0]){
                        existentTrains.erase(existentTrains.begin()+i);
                    }
                }
                trainOrder[branch->first].erase(trainOrder[branch->first].begin());

            }else{
                //Remove front train from this branch and put it into back of next branch
                trainLocations[trainOrder[branch->first][0]] = nextBranch;
                trainOrder[nextBranch].push_back(trainOrder[branch->first][0]);
                trainOrder[branch->first].erase(trainOrder[branch->first].begin());

                //Tell WaysideManager to update the authority for the next train in line
                waysideManager->setNextAuthorityFromQueue(branch->first);
            }

        //If there is a new train in town
        }else if(branch->second > lastTrainsPerbranch[branch->first]){
            //Tell WaysideManager to update the authority for the new train
            waysideManager->setNextAuthorityFromQueue(branch->first);
        }
    }
    //Update the LastTrainsPerBranch data
    for(auto& branch : trainsPerBranch){
        lastTrainsPerbranch[branch.first] = branch.second;
    }
}
