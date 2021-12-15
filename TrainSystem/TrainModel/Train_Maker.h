#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "trainui.h>

class Train_Maker {
	
	public:
		Train_Maker();
		~Train_Maker();
		void makeTrain();
		
	private:
		trainUI *newTrain;
		vector<trainUI> PussySwamp;
}
