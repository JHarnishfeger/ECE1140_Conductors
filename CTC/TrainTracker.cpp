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

            //Check if we are going to the yard
            bool yard = false;
            for(auto nextBranch : nextBranches){
                if(nextBranch == "YARD"){
                    yard = true;
                }
            }
            if(yard){
                //Going to the yard, remove front train
                trainLocations.erase(trainOrder[branch->first][0]);
                for(unsigned int i = 0; i < existentTrains.size(); i++){
                    if(existentTrains[i] == trainOrder[branch->first][0]){
                        existentTrains.erase(existentTrains.begin()+i);
                    }
                }
                trainOrder[branch->first].erase(trainOrder[branch->first].begin());

            //Move train position to next location in branch
            }else{
                //We need to look at authority to see where the train went
                std::string nextBranch = waysideManager->getAuthority(branch->first).nextBranch;

                //Remove front train from this branch and place it into back of next branch
                trainLocations[trainOrder[branch->first][0]] = nextBranch;
                trainOrder[nextBranch].push_back(trainOrder[branch->first][0]);
                trainOrder[branch->first].erase(trainOrder[branch->first].begin());
            }

        //If there is now an additional train in this branch, it came from the previous branch and was already dealt with.
        }
    }
    //Update the LastTrainsPerBranch data
    for(auto branch : trainsPerBranch){
        lastTrainsPerbranch[branch.first] = branch.second;
    }
}
