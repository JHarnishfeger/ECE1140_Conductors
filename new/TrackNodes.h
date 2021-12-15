#ifndef TRACKNODES_H
#define TRACKNODES_H
#include "Node.hpp"
#include "Branch.h"
#include <string>
#include <vector>
#include <list>

class TrackNodes{

public:

	//Constructor
    TrackNodes();

	//Find a specific node by its branch name. Bool param chooses which line to search on
	Node<Branch>* findNodeByName(std::string name, bool useGreen=true);
	
	//Get a route between two branches. Bool param chooses which line to search on
	std::list<std::string> getBranchRoute(std::string from, std::string to, bool useGreen=true);

    //Get the branch that a block is on
    std::string getBranchOfBlock(int blockId, bool useGreen=true);

    //The a list of branches that come after this branch
    std::list<std::string> getNextBranch(std::string branch);

    //Get the suggested speed along this branch
    double getSuggestedSpeed(std::string branch);

private:

	void addNodeToGreen(std::string name, int start, int end);

    std::vector<Node<Branch>> red; //Red line
    std::vector<Node<Branch>> green; //Green line

    std::unordered_map<std::string, double> suggestedSpeeds;
};

#endif // TRACKNODES_H
