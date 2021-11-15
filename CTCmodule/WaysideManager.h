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

class WaysideManager{

	public:
	
		//Constructor
		WaysideManager(std::vector<Wayside>* _waysides);
	
		//Get a reference to a specific block in a wayside.
		Block& getBlock(int id);
		
		//Get a list of which branches have trains on them.
		std::list<std::string> getBranchesWithTrainsPresent();
	
	private:
	
		//This is a hard-coded list of all the switches' block ids on the green line
		std::list<int> greenLineSwitches;
		
		//This should be given by Track Controller
		std::vector<Wayside>* waysides;
		
		//The int is the block ID of a switch. Each switch has a queue associated with it.
		std::unordered_map<int, std::queue<Authority>> authorityQueues;
}

#endif