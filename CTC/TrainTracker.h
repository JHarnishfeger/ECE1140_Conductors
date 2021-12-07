#ifndef TRAINTRACKER_H
#define TRAINTRACKER_H
#include "Branch.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include "TrackNodes.h"

class TrainTracker{

	public:

        TrainTracker(TrackNodes* _track);

        std::string getTrainLocation(std::string trainName);


        void update(std::list<std::pair<std::string, int>> trainsPerBranch);
	
	private:

        //Map of list of trains per branch
        std::unordered_map<std::string, std::vector<std::string>> trainLocations;

        //We need access to TrackNodes
        TrackNodes* track;
};

#endif
