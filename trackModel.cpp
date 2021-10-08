#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "Block.h"
#include "trackModel.h"
using namespace std;

//Method: getLineSize(char line)
//Params: char
//Returns: int
//Desc: returns the size of the inputted char corresponding to a line ('g' = green 'r' = red) and returns it as an int otherwise returns -1
int trackModel::getLineSize(char line) const{
	if(line == 'g'){
		return greenLine.size();
	}else if(line == 'r'){
		return redLine.size();
	}else{
		return -1;
	}
}

//Method: searchBlock(char line, int id)
//Params: char, int
//Returns: Block
//Desc: finds a Block in a line based on inputted char and id and returns it as a Block otherwise returns NULL
Block trackModel::searchBlock(char line, int id){
	if(line == 'g'){
		return greenLine.at(id);
	}else if(line == 'r'){
		return redLine.at(id);
	}else{
		return NULL;
	}
}

//Method: breakRail(char line, int id)
//Params: char, int
//Returns: bool
//Desc: finds a block in a line based on inputted char and id and setBrokenRail(true) if successful returns true otherwise false
bool trackModel::breakRail(char line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id).setBrokenRail(true);
		return true;
	}else{
		return false;
	}
}

//Method: breakCircuit(char line, int id)
//Params: char, id
//Returns: bool
//Desc: finds a block in a line based on inputted char and id and setBrokenCircuit(true) if successful returns true otherwise false
bool trackModel::breakCircuit(char line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id).setBrokenCircuit(true);
		return true;
	}else{
		return false;
	}
}

//Method: createPowerFailure(char line, int id)
//Params: char, id
//Returns: bool
//Desc: finds a block in a line based on inputted char and id and setPowerFailure(true) is successful returns true otherwise false
bool trackModel::createPowerFailure(char line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id).setPowerFailure(true);
		return true;
	}else{
		return false;
	}
}

//Method: fixRail(char line, int id)
//Params: char, int
//Returns: bool
//Desc: finds a block in a line based on inputted char and id and setBrokenRail(false) if successful returns true otherwise false
bool trackModel::fixRail(char line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id).setBrokenRail(false);
		return true;
	}else{
		return false;
	}
}

//Method: fixCircuit(char line, int id)
//Params: char, id
//Returns: bool
//Desc: finds a block in a line based on inputted char and id and setBrokenCircuit(true) if successful returns true otherwise false
bool trackModel::fixCircuit(char line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id).setBrokenCircuit(false);
		return true;
	}else{
		return false;
	}
}

//Method: fixPower(char line, int id)
//Params: char, id
//Returns: bool
//Desc: finds a block in a line based on inputted char and id and setPowerFailure(true) is successful returns true otherwise false
bool trackModel::fixPower(char line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id).setPowerFailure(false);
		return true;
	}else{
		return false;
	}
}

//Method: getSuggSpeed()
//Params: None	
//Returns: double
//Desc: returns the value of the member variable suggSpeed as a double
double trackModel::getSuggSpeed(){
	return suggSpeed;
}

//Method: getAuthority() 
//Params: None
//Returns: double
//Desc: returns the value of the member variable authority as a double
double trackModel::getAuthority(){
	return authority;
}

//Method: greenToConsole()
//Params: None
//Returns: None
//Desc: prints the vector of Bloks on the green line in a formatted string to console
void greenToConsole(){
	cout << "needs finished green" << endl;
}

//Method: redToConsole()
//Params: None
//Returns: None
//Desc: prints the vector of the Blocks on the red line in a formatted string to console
void redToConsole(){
	cout << "needs finished red" << endl;
}