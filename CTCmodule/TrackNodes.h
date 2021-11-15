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

    std::string getBranchOfBlock(int blockId, bool useGreen=true);

private:

	void addNodeToGreen(std::string name, int start, int end);

    std::vector<Node<Branch>> red; //Red line
    std::vector<Node<Branch>> green; //Green line
};

#endif // TRACKNODES_H
