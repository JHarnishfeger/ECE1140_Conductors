#include "Block.h"
#include "Track.h"

//Constructors:
//Default constructor
Track::Track(){
	loadTrack("testTrack.txt");
	suggSpeed = 45.0;
}
//Full input constructor
Track::Track(vector<Block*> greenLineIN, vector<Block*> redLineIN, double suggSpeedIN){
	greenLine = greenLineIN;
	redLine = redLineIN;
	suggSpeed = suggSpeedIN;
}
//Functional constructor
Track::Track(string filename, double suggSpeedIN){
	loadTrack(filename);
	suggSpeed = suggSpeedIN;
}

//Initalize for QT
//Params: string, double
void Track::initalize(string filename, double suggSpeedIN){
	loadTrack(filename);
	suggSpeed = suggSpeedIN;
}

//Attributes:
//greenLine ------------------------------------------------------------
//Params: None
//Returns: vector<Block*>
//Desc: returns the value of the attribute greenLine as a vector<Block*>
vector<Block*> Track::getGreenLine(){
	return greenLine;
}

//redLine --------------------------------------------------------------
//Params: None
//Returns: vector<Block*>
//Desc: returns the value of the attribute redLine as a vector<Block*>
vector<Block*> Track::getRedLine(){
	return redLine;
}

//suggSpeed ------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute suggSpeed = to inputted double
void Track::setSuggSpeed(double suggSpeedIN){
	suggSpeed = suggSpeedIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute suggSpeed as a double
double Track::getSuggSpeed(){
	return suggSpeed;
}

//Class Functions:
//Params: string, int
//Returns: Block*
//Desc: searches for a block according to inputted line and id and returns it as a Block*
Block* Track::searchBlock(string line, int id){
	if(line == "green"){
		return greenLine.at(id);
	}else if(line == "red"){
		return redLine.at(id);
	}else{
		return NULL;
	}
}
//Params: string, int
//Returns: Block*
//Desc:searches for a block according to inputted line and assigned id and returns it as a Block*
Block* Track::searchBlockById(string line, int id){
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getId() == id){
				return greenLine.at(g);
			}
		}
	}else if(line == "red"){
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getId() == id){
				return redLine.at(r);
			}
		}
	}else{
		return NULL;
	}
	return NULL;
}
//Params: int,double
//Returns: Block*
//Desc: returns the Block* that is at the inputted distance away from the inputted Block id on the inputted line, otherwise returns NULL
Block* Track::go(string line, int id, double distance){
	double remainingDistance = distance;
	if(line == "green"){
		for(unsigned int g = id; g < greenLine.size(); g++){
			remainingDistance = remainingDistance - (greenLine.at(g)->getLength());
			if(remainingDistance == 0 || remainingDistance - (greenLine.at(g + 1)->getLength()) < 0){
				return greenLine.at(g);
			}
		}
	}else{
		for(unsigned int r = id; r < redLine.size(); r++){
			remainingDistance = remainingDistance - (redLine.at(r)->getLength());
			if(remainingDistance == 0 || remainingDistance - (redLine.at(r + 1)->getLength()) < 0){
				return redLine.at(r);
			}
		}
	}
	return NULL;
}


//Params: string,string
//Returns: vector<Block*>
//Desc: searches for blocks on inputted line that match the inputted type and returns them as a vector<Block*>
vector<Block*> Track::filterByType(string line, string type){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getType() == type){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getType() == type){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,string
//Returns: vector<Block*>
//Desc: searches for blocks on inputted line that match the inputted brach and returns them as a vector<Block*>
vector<Block*> Track::filterByBranch(string line, string branch){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getBranch() == branch){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getBranch() == branch){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,bool
//Returns: vector<Block*>
//Desc: searches for blocks on inputted line whose railStatus = inputted boolean and returns them as a vector<Block*>
vector<Block*> Track::filterByRailStatus(string line, bool status){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getRailStatus() == status){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getRailStatus() == status){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,bool
//Returns vector<Block*>
//Desc: searches for blocks on inputted line whose circuitStatus = inputted boolean and returns them as a vector<Block*>
vector<Block*> Track::filterByCircuitStatus(string line, bool status){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getCircuitStatus() == status){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getCircuitStatus() == status){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,bool
//Returns vector<Block*>
//Desc: searches for blocks on inputted line whose powerStatus = inputted boolean and returns them as a vector<Block*>
vector<Block*> Track::filterByPowerStatus(string line, bool status){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getPowerStatus() == status){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getPowerStatus() == status){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,bool
//Returns vector<Block*>
//Desc: searches for blocks on inputted line whose heaterStatus = inputted boolean and returns them as a vector<Block*>
vector<Block*> Track::filterByHeaterStatus(string line, bool status){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getHeaterStatus() == status){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getHeaterStatus() == status){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,bool
//Returns vector<Block*>
//Desc: searches for blocks on inputted line whose crossingStatus = inputted boolean and returns them as a vector<Block*>
vector<Block*> Track::filterByCrossingStatus(string line, bool status){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getCrossingStatus() == status){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getCrossingStatus() == status){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string,bool
//Returns vector<Block*>
//Desc: searches for blocks on inputted line whose switchStatus = inputted boolean and returns them as a vector<Block*>
vector<Block*> Track::filterBySwitchStatus(string line, bool status){
	vector<Block*> retVect;
	if(line == "green"){
		for(unsigned int g = 0; g < greenLine.size(); g++){
			if(greenLine.at(g)->getSwitchStatus() == status){
				retVect.push_back(greenLine.at(g));
			}
		}
	}else{
		for(unsigned int r = 0; r < redLine.size(); r++){
			if(redLine.at(r)->getSwitchStatus() == status){
				retVect.push_back(redLine.at(r));
			}
		}
	}
	return retVect;
}
//Params: string
//Returns: bool
//Desc: loads data from a text file into the greenLine and redLine attributes as a vector<Block*>
//Notes: returns true if successful, false otherwise
bool Track::loadTrack(string filename){
	std::ifstream inputFile;
	inputFile.open(filename);
	
	string header, fsize, line, branch, id, length, grade, speedLimit, 
	type, height, direction;
	int fileSize;
	getline(inputFile,header);
	getline(inputFile,fsize);
	std::stringstream ss1(fsize);
	ss1 >> fileSize;
	for(int i = 0; i < fileSize; i++){
		getline(inputFile, line, ',');
		getline(inputFile, branch, ',');
		getline(inputFile, id, ',');
		getline(inputFile, length, ',');
		getline(inputFile, grade, ',');
		getline(inputFile, speedLimit, ',');
		getline(inputFile, type, ',');
		getline(inputFile, height, ',');
		getline(inputFile, direction);
		if(line == "green"){
			std::stringstream ss2(id);
			int idgreen = 0;
			ss2 >> idgreen;
			greenLine.push_back(new Block(line,branch,idgreen,stod(length),stod(grade),stod(speedLimit),type,stod(height),suggSpeed,direction));
			if(type == "station"){
				greenLine.at(i - 1)->setBeaconPresent(true);
			}
		}
		if(line == "red"){
			std::stringstream ss3(id);
			int idred = 0;
			ss3 >> idred;
			redLine.push_back(new Block(line,branch,idred,stod(length),stod(grade),stod(speedLimit),type,stod(height),suggSpeed,direction));
			if(type == "station"){
				redLine.at(i - 1)->setBeaconPresent(true);
			}
		}
		//Fix Branches?
	}
	inputFile.close();
	return false;
}
//Params: string,int
//Returns bool
//Desc: sets railStatus attribute == false for a block specified by inputted string and int
//Notes: returns true if succesful, false otherwise
bool Track::breakRail(string line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id)->setRailStatus(false);
		return true;
	}else{
		return false;
	}
}
//Params: string,int
//Returns bool
//Desc: sets circuitStatus attribute == false for a block specified by inputted string and int
//Notes: returns true if succesful, false otherwise
bool Track::breakCircuit(string line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id)->setCircuitStatus(false);
		return true;
	}else{
		return false;
	}
}
//Params: string,int
//Returns bool
//Desc: sets powerStatus attribute == false for a block specified by inputted string and int
//Notes: returns true if succesful, false otherwise
bool Track::breakPower(string line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id)->setPowerStatus(false);
		return true;
	}else{
		return false;
	}
}
//Params: string,int
//Returns bool
//Desc: sets railStatus attribute == true for a block specified by inputted string and int
//Notes: returns true if succesful, false otherwise
bool Track::fixRail(string line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id)->setRailStatus(true);
		return true;
	}else{
		return false;
	}
}
//Params: string,int
//Returns bool
//Desc: sets circuitStatus attribute == true for a block specified by inputted string and int
//Notes: returns true if succesful, false otherwise
bool Track::fixCircuit(string line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id)->setCircuitStatus(true);
		return true;
	}else{
		return false;
	}
}
//Params: string,int
//Returns bool
//Desc: sets powerStatus attribute == true for a block specified by inputted string and int
//Notes: returns true if succesful, false otherwise
bool Track::fixPower(string line, int id){
	if(searchBlock(line, id) != NULL){
		searchBlock(line, id)->setPowerStatus(true);
		return true;
	}else{
		return false;
	}
}
//Params: None
//Returns string
//Desc: returns a formatted string representation of the track
string Track::toString(){
	string retString = "";
	retString = retString + "GREEN LINE: \n";
	for(unsigned int g = 0; g < greenLine.size(); g++){
		retString = retString + greenLine.at(g)->toString();
	}
	retString = retString + "\n RED LINE: \n";
	for(unsigned int r = 0; r < redLine.size(); r++){
		retString = retString + redLine.at(r)->toString();
	}
	return retString;
}
//Params: None
//Returns: string
//Desc: returns a detailed formatted string representation of the track
string Track::toStringDetailed(){
	string retString = "";
	retString = retString + "GREEN LINE: \n";
	for(unsigned int g = 0; g < greenLine.size(); g++){
		retString = retString + greenLine.at(g)->toStringDetailed();
	}
	retString = retString + "\n RED LINE: \n";
	for(unsigned int r = 0; r < redLine.size(); r++){
		retString = retString + redLine.at(r)->toStringDetailed();
	}
	return retString;
}


