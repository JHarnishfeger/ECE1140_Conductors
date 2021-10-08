#ifndef trackModel_H
#define trackModel_H
#include <string>
#include <fstream>
#include <vector>
#include "Block.h"
using namespace std;

//Track Model Class
class trackModel{
	private:
		vector<Block> greenLine;
		vector<Block> redLine;
		double suggSpeed;
		double authority;
	public:
		int getLineSize(char);
		Block searchBlock(char, int);
		bool breakRail(char, int);
		bool breakCircuit(char, int);
		bool createpowerFailure(char, int);
		bool fixRail(char, int);
		bool fixCircuit(char, int);
		bool fixPower(char, int);
		double getSuggSpeed();
		double getAuthority();
		vector<Block> loadTrack(string);
		void greenToConsole();
		void redToConsole():
		//Send data method
};
//End trackModel class

#endif