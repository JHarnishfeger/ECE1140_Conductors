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
	
	srand(time(0));
	Track t1("greenLine.txt", 45.0);
	t1.loadTrack("redLine.txt");
	cout << "\n START toString()------------------------------------------ \n" << endl;
	cout << t1.toString() << endl;
	cout << "\n END toString()------------------------------------------ \n" << endl;
	cout << "\n START toStringDetailed()---------------------------------- \n " << endl;
	cout << t1.toStringDetailed();
	cout << "\n END toStringDetailed()---------------------------------- \n " << endl;
	
}
