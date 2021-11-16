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
	
	srand(time(NULL));
	Track t1("testTrack.txt", 45.0);
	cout << t1.toString() << endl;
	cout << "\n END toString()------------------------------------------ \n" << endl;
	cout << t1.toStringDetailed();
	cout << "\n END toStringDetailed()---------------------------------- \n " << endl;
	
}
