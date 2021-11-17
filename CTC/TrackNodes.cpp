#include "TrackNodes.h"

TrackNodes::TrackNodes(){

	//Introduce nodes for green line
    addNodeToGreen("A", 1, 3); 
    addNodeToGreen("B", 4, 6); 
    addNodeToGreen("C", 7, 12);
    addNodeToGreen("D0", 13, 16);
    addNodeToGreen("D1", 13, 16);
    addNodeToGreen("E0", 17, 20);
    addNodeToGreen("E1", 17, 20);
    addNodeToGreen("F0", 21, 28);
    addNodeToGreen("F1", 21, 28);
    addNodeToGreen("G", 29, 32);
    addNodeToGreen("H", 33, 35);
    addNodeToGreen("I", 36, 57);
    addNodeToGreen("YARD", 58, 62); //We are ommiting J because no stations exist at J.
    addNodeToGreen("K", 63, 68);
    addNodeToGreen("L", 69, 73);
    addNodeToGreen("M", 74, 76);
    addNodeToGreen("N0", 77, 85);
    addNodeToGreen("N1", 77, 85);
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
    findNodeByName("A")->addChild(findNodeByName("D0"));
    findNodeByName("B")->addChild(findNodeByName("A"));
    findNodeByName("C")->addChild(findNodeByName("B"));
    findNodeByName("D1")->addChild(findNodeByName("C"));
    findNodeByName("D0")->addChild(findNodeByName("E0"));
    findNodeByName("E1")->addChild(findNodeByName("D1"));
    findNodeByName("E0")->addChild(findNodeByName("F0"));
    findNodeByName("F1")->addChild(findNodeByName("E1"));
    findNodeByName("F0")->addChild(findNodeByName("G"));
    findNodeByName("G")->addChild(findNodeByName("H"));
    findNodeByName("H")->addChild(findNodeByName("I"));
    findNodeByName("I")->addChild(findNodeByName("YARD"));
    findNodeByName("I")->addChild(findNodeByName("K"));
    findNodeByName("YARD")->addChild(findNodeByName("K"));
    findNodeByName("K")->addChild(findNodeByName("L"));
    findNodeByName("L")->addChild(findNodeByName("M"));
    findNodeByName("M")->addChild(findNodeByName("N0"));
    findNodeByName("N0")->addChild(findNodeByName("O"));
    findNodeByName("N1")->addChild(findNodeByName("R"));
    findNodeByName("O")->addChild(findNodeByName("P"));
    findNodeByName("P")->addChild(findNodeByName("Q"));
    findNodeByName("Q")->addChild(findNodeByName("N1"));
    findNodeByName("R")->addChild(findNodeByName("S"));
    findNodeByName("S")->addChild(findNodeByName("T"));
    findNodeByName("T")->addChild(findNodeByName("U"));
    findNodeByName("U")->addChild(findNodeByName("V"));
    findNodeByName("V")->addChild(findNodeByName("W"));
    findNodeByName("W")->addChild(findNodeByName("X"));
    findNodeByName("X")->addChild(findNodeByName("Y"));
    findNodeByName("Y")->addChild(findNodeByName("Z"));
    findNodeByName("Z")->addChild(findNodeByName("F1"));
}

void TrackNodes::addNodeToGreen(std::string name, int start, int end){
	green.push_back(Node<Branch>(Branch(name, start, end)));
}

Node<Branch>* TrackNodes::findNodeByName(std::string name, bool useGreen){
	if(useGreen){
		if(name == "D"){name = "D0";}
		else if(name == "E"){name = "E0";}
		else if(name == "F"){name = "F0";}
		else if(name == "N"){name = "N0";}
		
		for(int i = 0; i < green.size(); i++){
			Node<Branch>* node = &green[i];
			if(node->getValue().name == name){
					return node;
			}
		}
	}
	return nullptr;
}

std::list<std::string> TrackNodes::getBranchRoute(std::string from, std::string to, bool useGreen){
	if(useGreen){
		//Use BFS to solve for the route
		auto routeList = findNodeByName(from)->routeTo(findNodeByName(to));
	
		//Make new list containing only the branch names
		std::list<std::string> rtn;
		for(auto node : routeList){
			std::string name = node->getValue().name;
			if(name[0] == 'D') name = "D";
			if(name[0] == 'E') name = "E";
			if(name[0] == 'F') name = "F";
			if(name[0] == 'N') name = "N";
			rtn.push_back(name);
		}
		return rtn;
	}else{
		return std::list<std::string>();
	}
}

std::string TrackNodes::getBranchOfBlock(int blockId, bool useGreen){
    if(useGreen){
        for(auto node : green){
            Branch branch = node.getValue();
            if(blockId >= branch.start && blockId <= branch.end){
                return branch.name;
            }
        }
    }
    return "";
}
