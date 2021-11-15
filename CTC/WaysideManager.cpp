#include "WaysideManager.h"

WaysideManager::WaysideManager(){
	
}

WaysideManager::WaysideManager(std::list<WayStruct*> _waystructs) : waysides(_waystructs) {
	greenLineSwitches.push_back(12); //D->C and A->D
	greenLineSwitches.push_back(29); //F->G and Z->F
	greenLineSwitches.push_back(76); //M->N and N->R
	greenLineSwitches.push_back(85); //N->O and Q->N
}

std::list<int> WaysideManager::getGreenLineSwitches(){
	return greenLineSwitches;
}

Block& WaysideManager::getBlock(int id){
    Block b = Block(false, false, "", 0, false, 0, 0, 0, ' ', 0, 0, 0, false, false, false, false, false, false);

    return b;
}
