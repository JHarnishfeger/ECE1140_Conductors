#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <time.h>
#include "Block.h"
#include "Block.cpp"
#include "Track.h"
#include "Track.cpp"
using std::string;
using namespace std;

int main(){
	
	/*string station = "station:shadyside";
	string slice = station.substr(0,7);
	string name = station.substr(8,station.size()-8);
	cout << slice << endl;
	cout << name << endl;*/
	
	/*string switchh = "SWITCH(86:100)";
	string type = switchh.substr(0,6);
	string branches = switchh.substr(6,switchh.size()-6);
	cout << type << endl;
	cout << branches << endl;
	string branch1 = switchh.substr(7,switchh.find(":")-7);
	string branch2 = switchh.substr((switchh.find(":") + 1),(switchh.size()-2)-switchh.find(":"));
	string Branches = branch1 + branch2;
	cout << branch1 << endl;
	cout << branch2 << endl;
	cout << Branches << endl;*/
	
	srand(time(NULL));
	Track t1("greenLine2.txt", 45.0);
	cout << t1.toString() << endl;
	cout << "\n END toString()------------------------------------------ \n" << endl;
	cout << t1.toStringDetailed();
	cout << "\n END toStringDetailed()---------------------------------- \n " << endl;
	
	
}
