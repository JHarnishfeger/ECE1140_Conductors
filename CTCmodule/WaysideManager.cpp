#include "WaysideManager.h"

WaysideManager(std::vector<Wayside>* _waysides) : waysides(_waysides) {
	greenLineSwitches.push_back(12); //D->C and A->D
	greenLineSwitches.push_back(29); //F->G and Z->F
	greenLineSwitches.push_back(76); //M->N and N->R
	greenLineSwitches.push_back(85); //N->O and Q->N
}


