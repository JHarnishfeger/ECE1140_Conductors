#ifndef Track_H
#define Track_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include "Block.h"
using std::vector;
using std::string;

//Track class
class Track{
	private:
		vector<Block*> greenLine;
		vector<Block*> redLine;
		double suggSpeed;
		//double authority?
	public:
		//Constructors:
		Track();
		Track(vector<Block*>,vector<Block*>,double);
		Track(string,double);
		//Attributes:
		//greenLine
		vector<Block*> getGreenLine();
		//redLine
		vector<Block*> getRedLine();
		//suggSpeed
		void setSuggSpeed(double);
		double getSuggSpeed();
		//authority?
		//Class Functions:
		Block* searchBlock(string,int);
		Block* go(string,int,double);
		vector<Block*> filterByType(string,string);
		vector<Block*> filterByBranch(string,string);
		vector<Block*> filterByRailStatus(string,bool);
		vector<Block*> filterByCircuitStatus(string,bool);
		vector<Block*> filterByPowerStatus(string,bool);
		vector<Block*> filterByHeaterStatus(string,bool);
		vector<Block*> filterByCrossingStatus(string,bool);
		vector<Block*> filterBySwitchStatus(string,bool);
		bool loadTrack(string);
		bool breakRail(string,int);
		bool breakCircuit(string,int);
		bool breakPower(string,int);
		bool fixRail(string,int);
		bool fixCircuit(string,int);
		bool fixPower(string,int);
		string toString();
		unsigned int encodeData();
		void decodeData(unsigned int);
};
//End Track class
#endif
