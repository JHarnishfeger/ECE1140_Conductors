#include "TrackNodes.h"

TrackNodes::TrackNodes(){

	/* TODO: We must add extra nodes for F0, F1, E0, E1, etc, to represent that 
	 * trains can only continue one way through each track. There are only a 
	 * couple switches for a few of the track junctions, the rest are one-way. */

	//Introduce nodes for green line
    addNodeToGreen("A", 1, 3); 
    addNodeToGreen("B", 4, 6); 
    addNodeToGreen("C", 7, 12);
    addNodeToGreen("D", 13, 16);
    addNodeToGreen("E", 17, 20);
    addNodeToGreen("F", 21, 28);
    addNodeToGreen("G", 29, 32);
    addNodeToGreen("H", 33, 35);
    addNodeToGreen("I", 36, 57);
    addNodeToGreen("YARD", 58, 62); //We are ommiting J because no stations exist at J.
    addNodeToGreen("K", 63, 68);
    addNodeToGreen("L", 69, 73);
    addNodeToGreen("M", 74, 76);
    addNodeToGreen("N", 77, 85);
    addNodeToGreen("O", 86, 88);
    addNodeToGreen("P", 89, 97);
    addNodeToGreen("Q", 98, 100);
    addNodeToGreen("R", 101, 101);
    addNodeToGreen("S", 102, 104);
    addNodeToGreen("T", 105, 109);
    addNodeToGreen("U", 110, 116);
    addNodeToGreen("V", 117, 121);
    addNodeToGreen("W", 122, 143);
    addNodeToGreen("X", 144, 146);
    addNodeToGreen("Y", 147, 149);
    addNodeToGreen("Z", 150, 150);
    
    //Link nodes together
    findNodeByName("A")->addChild(findNodeByName("D"));
    findNodeByName("B")->addChild(findNodeByName("A"));
    findNodeByName("C")->addChild(findNodeByName("B"));
    findNodeByName("D")->addChild(findNodeByName("C"));
    findNodeByName("D")->addChild(findNodeByName("E"));
    findNodeByName("E")->addChild(findNodeByName("D"));
    findNodeByName("E")->addChild(findNodeByName("F"));
    findNodeByName("F")->addChild(findNodeByName("E"));
    findNodeByName("F")->addChild(findNodeByName("G"));
    findNodeByName("G")->addChild(findNodeByName("H"));
    findNodeByName("H")->addChild(findNodeByName("I"));
    findNodeByName("I")->addChild(findNodeByName("YARD"));
    findNodeByName("I")->addChild(findNodeByName("K"));
    findNodeByName("YARD")->addChild(findNodeByName("K"));
    findNodeByName("K")->addChild(findNodeByName("L"));
    findNodeByName("L")->addChild(findNodeByName("M"));
    findNodeByName("M")->addChild(findNodeByName("N"));
    findNodeByName("N")->addChild(findNodeByName("O"));
    findNodeByName("N")->addChild(findNodeByName("R"));
    findNodeByName("O")->addChild(findNodeByName("N"));
    findNodeByName("O")->addChild(findNodeByName("P"));
    findNodeByName("P")->addChild(findNodeByName("Q"));
    findNodeByName("Q")->addChild(findNodeByName("N"));
    findNodeByName("R")->addChild(findNodeByName("S"));
    findNodeByName("S")->addChild(findNodeByName("T"));
    findNodeByName("T")->addChild(findNodeByName("U"));
    findNodeByName("U")->addChild(findNodeByName("V"));
    findNodeByName("V")->addChild(findNodeByName("W"));
    findNodeByName("W")->addChild(findNodeByName("X"));
    findNodeByName("X")->addChild(findNodeByName("Y"));
    findNodeByName("Y")->addChild(findNodeByName("Z"));
    findNodeByName("Z")->addChild(findNodeByName("F"));
}

void TrackNodes::addNodeToGreen(std::string name, int start, int end){
	green.push_back(Node<Branch>(Branch(name, start, end)));
}

Node<Branch>* TrackNodes::findNodeByName(std::string name, bool useGreen){
	if(useGreen){
		for(int i = 0; i < green.size(); i++){
			Node<Branch>* node = &green[i];
			if(node->getValue().name == name){
					return node;
			}
		}
	}else{
		for(int i = 0; i < red.size(); i++){
			Node<Branch>* node = &red[i];
			if(node->getValue().name == name){
					return node;
			}
		}
	}
	return nullptr;
}

std::list<std::string> TrackNodes::getBranchRoute(std::string from, std::string to, bool useGreen){

	//Use BFS to solve for the route
	auto routeList = findNodeByName(from)->routeTo(findNodeByName(to));
	
	//Make new list containing only the branch names
	std::list<std::string> rtn;
	
	for(auto node : routeList){
		rtn.push_back(node->getValue().name);
	}
	return rtn;
}

