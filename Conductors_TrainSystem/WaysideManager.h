#ifndef WAYSIDEMANAGER_H
#define WAYSIDEMANAGER_H
#include "Authority.h"
#include "Branch.h"
#include "Block.h"
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <unordered_map>
#include "WayStruct.h"
#include "TrackNodes.h"

class WaysideManager{

	public:
	
		//Constructor
		WaysideManager();
        WaysideManager(std::list<WayStruct*> _waystructs, TrackNodes* _track);
	
		//Get a reference to a specific block in a wayside.
        Block* getBlock(int id);
		
		//Get a list of which branches have trains on them.
		std::list<std::string> getBranchesWithTrainsPresent();
		
		//get a list of all the switches on the green line
		std::list<int> getGreenLineSwitches();
		
		//Add the authorities for a new route to the queue
		void addNewRouteToQueues(std::list<Authority> route);

        bool getBlockClosedForMaintenence(int blockId);

        void setBlockClosedForMaintenence(int blockId, bool maintenence);

        void setAuthority(Authority authority);

        Authority getAuthority(std::string branch);
	
        void setNextAuthorityFromQueue(std::string branch);

        std::list<std::pair<std::string, int>> getTrainsPerBranch();

        std::list<WayStruct*> getWayStructs();

        //This should be given by Track Controller
        std::list<WayStruct*> waysides;

	private:
	
		//This is a hard-coded list of all the switches' block ids on the green line
        std::list<int> greenLineSwitches;
		
        //The key is the Branch name. Each branch has a queue associated with it.
        std::unordered_map<std::string, std::queue<Authority>> authorityQueues;

        TrackNodes* track;

        std::list<int> redMaintenence; //Blocks closed for maintenence on the red line
        std::list<int> greenMaintenence; //Blocks closed for maintenence on the green line

        //Suggested speeds for green line
        std::unordered_map<std::string, double> suggestedSpeeds;
};

#endif
