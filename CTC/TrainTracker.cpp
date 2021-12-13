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

        //Train has moved into next branch
        if(branch->second < lastTrainsPerbranch[branch->first]){

            bool yard = false;
            for(auto nextBranch : nextBranches){
                if(nextBranch == "YARD"){
                    yard = true; break;
                }
            }

            if(yard){
                //Remove front train
                for(unsigned int i = 0; i < existentTrains.size(); i++){
                    if(existentTrains[i] == trainOrder[branch->first][0]){

                    }
                }
                trainOrder[branch->first].remove(0);
            }else{
                //Move train position to next location in branch
                if(nextBranches.size() > 1){
                    //We need to look at authority to see where the train went

                }
            }
        }
    }
}
