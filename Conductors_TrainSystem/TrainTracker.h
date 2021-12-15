#ifndef TRAINTRACKER_H
#define TRAINTRACKER_H
#include "Branch.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include "TrackNodes.h"
#include "WaysideManager.h"

class TrainTracker{

	public:

        TrainTracker(TrackNodes* _track, WaysideManager* _waysideManager);

        //Get train location. If train DNE, then new train is added at YARD branch.
        std::string getTrainLocation(std::string trainName);

        //Update how many trains are on which branches
        void update(std::list<std::pair<std::string, int>> trainsPerBranch);

        //Whether a given train name is currently on the track
        bool trainExists(std::string train);
	
	private:

        //Map linking each branch to an ordered list of trains
        std::unordered_map<std::string, std::vector<std::string>> trainOrder;

        //Map linking each train to a branch
        std::unordered_map<std::string, std::string> trainLocations;

        //Trains that currently exist
        std::vector<std::string> existentTrains;

        //The last updated data
        std::unordered_map<std::string, int> lastTrainsPerbranch;

        //We need access to TrackNodes
        TrackNodes* track;

        //We also need access to Waysides
        WaysideManager* waysideManager;
};

#endif
