#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

Train_Maker::Train_Maker(){
	
}

Train_Maker::~Train_Maker(){
	delete PussySwamp;
}

Train_Maker::makeTrain(){
	PussySwamp.push_back(newTrain);
}
