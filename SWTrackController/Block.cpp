#include "Block.h"

//Init statics
int Block::instanceCounter = 0;
string Block::branchesList = "abcdefghijklmnopqrstuvwxyz";
int Block::branchIndex = 0;
double Block::xCordTotal = 0.0;
double Block::yCordTotal = 0.0;

//Constructors:
//Default constructor
Block::Block(){
	passengers = 10;
	id = instanceCounter;
	instanceCounter++;
	line = "green";
	branch = "a";
	type = "RAIL";
	direction = "north";
	nextBranches = "bc";
	length = 10.0;
	xCord = 0.0;
	yCord = 0.0;
	grade = 1.0;
	height = 5.0;
	temperature = 50.0;
	speedLimit = 45.0;
	suggestedSpeed = 45.0;
	authority = false;
	railStatus = true;
	circuitStatus = true;
	powerStatus = true;
	heaterStatus = true;
	crossingStatus = false;
	switchStatus = true;
	trainPresent = false;
}

//Full input constructor
Block::Block(int passengersIN, string lineIN, string branchIN, string typeIN, string directionIN, string nextBranchesIN, double lengthIN,double xCordIN, double yCordIN, double gradeIN, double heightIN, double temperatureIN,
double speedLimitIN, double suggestedSpeedIN, bool authorityIN, bool railStatusIN, bool circuitStatusIN, bool powerStatusIN, bool heaterStatusIN, bool crossingStatusIN, bool switchStatusIN, bool trainPresentIN){
	passengers = passengersIN;
	id = instanceCounter;
	instanceCounter++;
	line = lineIN;
	branch = branchIN;
	type = typeIN;
	direction = directionIN;
	nextBranches = nextBranchesIN;
	length = lengthIN;
	xCord = xCordIN;
	yCord = yCordIN;
	grade = gradeIN;
	height = heightIN;
	temperature = temperatureIN;
	speedLimit = speedLimitIN;
	suggestedSpeed = suggestedSpeedIN;
	authority = authorityIN;
	railStatus = railStatusIN;
	circuitStatus = circuitStatusIN;
	powerStatus = powerStatusIN;
	heaterStatus = heaterStatusIN;
	crossingStatus = crossingStatusIN;
	switchStatus = switchStatusIN;
	trainPresent = trainPresentIN;
}
//Functional constructor
Block::Block(string lineIN, string typeIN, string directionIN, double lengthIN, double gradeIN, double temperatureIN, double heightIN,
double speedLimitIN, double suggestedSpeedIN){
	if(type == "STATION"){
		passengers = rand() % 100 + 1;
	}else{
		passengers = 0;
	}
	id = instanceCounter;
	instanceCounter++;
	line = lineIN;
	branch = branchesList[branchIndex];
	type = typeIN;
	direction = directionIN;
	if(type == "SWITCH"){
		nextBranches = branchesList.substr(branchIndex,2);
		branchIndex++;
	}else{
		nextBranches = "";
	}
	length = lengthIN;
	xCord = xCordTotal;
	yCord = yCordTotal;
	if(direction == "north"){
		yCordTotal = yCordTotal + length;
	}else if(direction == "east"){
		xCordTotal = xCordTotal + length;
	}else if(direction == "south"){
		yCordTotal = yCordTotal - length;
	}else{
		xCordTotal = xCordTotal - length;
	}
	grade = gradeIN;
	height = heightIN;
	temperature = temperatureIN;
	speedLimit = speedLimitIN;
	suggestedSpeed = suggestedSpeedIN;
	authority = false;
	railStatus = true;
	circuitStatus = true;
	powerStatus = true;
	heaterStatus = true;
	crossingStatus = false;
	switchStatus = true;
	trainPresent = false;
}

//Attributes:
//passengers -----------------------------------------------------------
//Params:
//Returns:
//Desc:
void Block::setPassengers(int passengersIN){
	passengers = passengersIN;
}
//Params:
//Returns:
//Desc:
int Block::getPassengers(){
	return passengers;
}

//id -------------------------------------------------------------------
//Params: None
//Returns: int
//Desc: returns the value of the attribute id as an integer
int Block::getId(){
	return id;
}

//line -----------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute line = to inputted string
//Notes: line should be set to "green" or "red" function assumes no user error
void Block::setLine(string lineIN){
	line = lineIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute line as a string
string Block::getLine(){
	return line;
}

//branch ---------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute branch = to inputted string
void Block::setBranch(string branchIN){
	branch = branchIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute branch as a string
string Block::getBranch(){
	return branch;
}

//type -----------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute type = to inputted string
//Notes: type should be set to "RAIL", "yard", "STATION", "SWITCH", or "CROSSING" function assumes no user error
void Block::setType(string typeIN){
	type = typeIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute type as a string
string Block::getType(){
	return type;
}

//direction ------------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute direction = to inputted string
//Notes: direction should be set to "north", "east", "south", or "west" fucntion assumes no user error
void Block::setDirection(string directionIN){
	direction = directionIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute direction as a string
string Block::getDirection(){
	return direction;
}

//nextBranches ---------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute nextBranches = to inputted string
void Block::setNextBranches(string nextBranchesIN){
	nextBranches = nextBranchesIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute nextBranches as a string
string Block::getNextBranches(){
	return nextBranches;
}

//length ---------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute length = to inputted double
void Block::setLength(double lengthIN){
	length = lengthIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute length as a double
double Block::getLength(){
	return length;
}

//xCord ----------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute xCord = to inputted double
void Block::setXCord(double xCordIN){
	xCord = xCordIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute xCord as a double
double Block::getXCord(){
	return xCord;
}

//yCord ----------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute yCord = to inputted double
void Block::setYCord(double yCordIN){
	yCord = yCordIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute yCord as a double
double Block::getYCord(){
	return yCord;
}

//grade ----------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute grade = to inputted double
void Block::setGrade(double gradeIN){
	grade = gradeIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute grade as a double
double Block::getGrade(){
	return grade;
}

//height ---------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute height = to inputted double
void Block::setHeight(double heightIN){
	height = heightIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute height as a double
double Block::getHeight(){
	return height;
}

//temperature ----------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute temperature = to inputted double
void Block::setTemperature(double temperatureIN){
	temperature = temperatureIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute temperature as a double
double Block::getTemperature(){
	return temperature;
}

//speedLimit -----------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute speedLimit = to inputted double
void Block::setSpeedLimit(double speedLimitIN){
	speedLimit = speedLimitIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute speedLimit as a double
double Block::getSpeedLimit(){
	return speedLimit;
}

//suggestedSpeed -------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute suggestedSpeed = to inputted double
void Block::setSuggestedSpeed(double suggestedSpeedIN){
	suggestedSpeed = suggestedSpeedIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute suggestedSpeed as a double
double Block::getSuggestedSpeed(){
	return suggestedSpeed;
}

//authority ------------------------------------------------------------
void Block::setAuthority(bool authorityIN){
	authority = authorityIN;
}

bool Block::getAuthority(){
	return authority;
}

//railStatus -----------------------------------------------------------
//Notes: bool true == no rail failures bool false = rail failure
//Params: bool
//Returns: None
//Desc: sets the value of the attribute railStatus = to inputted bool
void Block::setRailStatus(bool railStatusIN){
	railStatus = railStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute railStatus as a bool
bool Block::getRailStatus(){
	return railStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute railStatus
void Block::toggleRailStatus(){
	railStatus = ~railStatus;
}

//circuitStatus --------------------------------------------------------
//Notes: bool true = no circuit failures bool false = circuit failure
//Params: bool
//Returns: None
//Desc: sets the value of the attribute circuitStatus = to inputted bool
void Block::setCircuitStatus(bool circuitStatusIN){
	circuitStatus = circuitStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute circuitStatus as a bool
bool Block::getCircuitStatus(){
	return circuitStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute circuitStatus
void Block::toggleCircuitStatus(){
	circuitStatus = ~circuitStatus;
}

//powerStatus ----------------------------------------------------------
//Notes: bool true = no power failures bool false = power failure
//Params: bool
//Returns: None
//Desc: sets the value of the attribute powerStatus = to inputted bool
void Block::setPowerStatus(bool powerStatusIN){
	powerStatus = powerStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute powerStatus as a bool
bool Block::getPowerStatus(){
	return powerStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute powerStatus
void Block::togglePowerStatus(){
	powerStatus = ~powerStatus;
}

//heaterStatus ---------------------------------------------------------
//Notes: bool true = heater is active bool false = heater is inactive
//Params: bool
//Returns: None
//Desc: sets the value of the attribute heaterStatus = to inputted bool
void Block::setHeaterStatus(bool heaterStatusIN){
	heaterStatus = heaterStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute heaterStatus as a bool
bool Block::getHeaterStatus(){
	return heaterStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute heaterStatus
void Block::toggleHeaterStatus(){
	heaterStatus = ~heaterStatus;
}

//crossingStatus -------------------------------------------------------
//Notes: bool true = crossing is active bool false = crossing is inactive
//Params: bool
//Returns: None
//Desc: sets the value of the attribute crossingStatus = to inputted bool
void Block::setCrossingStatus(bool crossingStatusIN){
	crossingStatus = crossingStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute crossingStaus as a bool
bool Block::getCrossingStatus(){
	return crossingStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute crossingStatus
void Block::toggleCrossingStatus(){
	crossingStatus = ~crossingStatus;
}

//switchStatus ---------------------------------------------------------
//Notes: bool true = crossing is pointed upwards towards nextBranch[0] bool false = crossing is pointed downwards towards nextBranch[1]
//Params: bool
//Returns: None
//Desc: sets the value of the attribute switchStatus = to inputted bool
void Block::setSwitchStatus(bool switchStatusIN){
	switchStatus = switchStatusIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute switchStatus as a bool
bool Block::getSwitchStatus(){
	return switchStatus;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute switchStatus
void Block::toggleSwitchStatus(){
	switchStatus = ~switchStatus;
}
//trainPresent ---------------------------------------------------------
//Notes: bool true = train is present on block false = no train is present
//Params: bool
//Returns: None
//Desc: sets the value of the attribute trainPresent = to inputted bool
void Block::setTrainPresent(bool trainPresentIN){
	trainPresent = trainPresentIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute trainPresent as a bool
bool Block::getTrainPresent(){
	return trainPresent;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute trainPresent
void Block::toggleTrainPresent(){
	trainPresent = ~trainPresent;
}
//Params: None
//Returns: string
//Desc: Returns a formatted string representation of the block
string Block::toString(){
	string retString = "";
	retString = retString + "[" + std::to_string(id);
	retString = retString + "," + branch;
	retString = retString + "," + type;
	retString = retString + ", X: " + std::to_string(xCord);
	retString = retString + ", Y: " + std::to_string(yCord) + "]\n";
	return retString;
}
//Params: None
//Returns: string
//Desc: Returns a detailed formatted string representation of the block
string Block::toStringDetailed(){
	string retString = "";
	retString = retString + "[" + std::to_string(id);
	retString = retString + "," + branch;
	retString = retString + "," + type;
	retString = retString + ", X: " + std::to_string(xCord);
	retString = retString + ", Y: " + std::to_string(yCord) + "]\n";
	retString = retString + "BLOCK STATS: \n";
	retString = retString + "\t passengers: " + std::to_string(passengers);
	retString = retString + "\t direction: " + direction;
	retString = retString + "\t length: " + std::to_string(length) + "\n";
	retString = retString + "\t grade: " + std::to_string(grade);
	retString = retString + "\t height: " + std::to_string(height);
	retString = retString + "\t temperature: " + std::to_string(temperature) + "\n";
	retString = retString + "\t speedLimit: " + std::to_string(speedLimit);
	retString = retString + "\t suggestedSpeed: " + std::to_string(suggestedSpeed);
	retString = retString + "\n BlOCK STATUS: \n";
	retString = retString + "\t railStatus: " + std::to_string(railStatus);
	retString = retString + "\t circuitStatus: " + std::to_string(circuitStatus);
	retString = retString + "\t powerStatus: " + std::to_string(powerStatus) + "\n";
	retString = retString + "\t heaterStatus: " + std::to_string(heaterStatus);
	retString = retString + "\t crossingStatus: " + std::to_string(crossingStatus);
	retString = retString + "\t switchStatus: " + std::to_string(switchStatus) + "\n";
	retString = retString + "\t trainPresent: " + std::to_string(trainPresent);
	retString = retString + "\n\n";
	return retString;
}
