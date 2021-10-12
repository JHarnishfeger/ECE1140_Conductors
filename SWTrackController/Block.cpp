#include "Block.h"

//Initalizing count as 0 (should increase everytime a Block constructor is called)
int Block::count = 0;

//Method: Block()
//Params: None
//Returns: None
//Desc: creates a Block with default values
Block::Block(){
	line = 'g';
	branch = 'a';
	type = "rail";
	length = 2.0;
	trainPresent = false;
	id = count;
	count++;
	grade = 5.0;
	suggestedSpeed = 25.0;
	speedLimit = 30.0;
	direction = 'e';
	temperature = 32.0;
	beacons = 0;
	height = 1.0;
	brokenRail = false;
	brokenCircuit = false;
	powerFailure = false;
	crossingActivated = false;
	switchPosition = false;
}

//Method Block(char line, char branch, string type, double length, bool trainPresent, double grade, double suggestedSpeed, double speedLimit, char direction, double temperature, int beacons, double height, bool brokenRail, bool brokenCircuit, bool powerFailure)
//Params: charx2, string, doublex6, boolx4, int
//Returns: None
//Desc: creates a Block with inputted values;
Block::Block(char lineIN, char branchIN, string typeIN, double lengthIN, bool trainPresentIN, double gradeIN, double suggestedSpeedIN, double speedLimitIN, char directionIN,
double temperatureIN, int beaconsIN, double heightIN, bool brokenRailIN, bool brokenCircuitIN, bool powerFailureIN, bool crossingActivatedIN, bool switchPositionIN){
	line = lineIN;
	branch = branchIN;
	type = typeIN;
	length = lengthIN;
	trainPresent = trainPresentIN;
	id = count;
	count++;
	grade = gradeIN;
	suggestedSpeed = suggestedSpeedIN;
	speedLimit = speedLimitIN;
	direction = directionIN;
	temperature = temperatureIN;
	beacons = beaconsIN;
	height = heightIN;
	brokenRail = brokenRailIN;
	brokenCircuit = brokenCircuitIN;
	powerFailure = powerFailureIN;
	crossingActivated = crossingActivatedIN;
	switchPosition = switchPositionIN;
}

//Method: getCount()
//Params: None
//Returns: int
//Desc: returns the value of the member variable count as an int
int Block::getCount() const{
	return count;
}

//Method: setLine(char line)
//Params: char
//Returns: None
//Desc: sets member variable line = to inputted char only accepts ('g' or 'r')(case sensitive) otherwise defaults to NULL
void Block::setLine(char lineIN){
	if(lineIN == 'g' || lineIN == 'r'){
		line = lineIN;
	}else{
		line = ' ';
	}
}

//Method: getLine()
//Params: None
//Returns: char
//Desc: returns the value of the line member variable as a char
char Block::getLine(){
	return line;
}

//Method: setBranch(char branch)
//Params: char
//Returns: None
//Desc: sets member variable branc = to inputted char
void Block::setBranch(char branchIN){
	branch = branchIN;
}

//Method: getBranch()
//Params: None
//Returns: char
//Desc: returns the value of the branch member variable as a char
char Block::getBranch(){
	return branch;
}

//Method: setType(string type)
//Params: string
//Returns: None
//Desc: sets member variable type = inputted string only accepts ("rail", "station", "yard", "crossing", "switch")(case sensitive) otherwise defaults to NULL
void Block::setType(string typeIN){
	if(typeIN == "rail" || typeIN == "station" || typeIN == "yard" || typeIN == "crossing" || typeIN == "switch"){
		type = typeIN;
	}else{
		type = ' ';
	}
}

//Method: getType()
//Params: None
//Returns: string
//Desc: returns the value of the type member variable as a string
string Block::getType(){
	return type;
}

//Method: setLength(double length)
//Params: double
//Returns: None
//Desc: sets member variable length = inputted double
void Block::setLength(double lengthIN){
	length = lengthIN;
}

//Method: getLength()
//Params: None
//Returns: double
//Desc: returns the value of the member variable length as a double
double Block::getLength(){
	return length;
}

//Method: setTrainPresent(bool trainPresent)
//Params: bool
//Returns: None
//Desc: sets member variable trainPresent = to inputted bool
void Block::setTrainPresent(bool trainPresentIN){
	trainPresent = trainPresentIN;
}

//Method: getTrainPresent()
//Params: None
//Returns: bool
//Desc: returns the value of the member variable trainPresent as a bool
bool Block::getTrainPresent(){
	return trainPresent;
}

//Method: setId(int)
//Params: int
//Returns: None
//Desc: set the member variable id = to inputted int
void Block::setId(int idIN){
	id = idIN;
}

//Method: getId()
//Params: None
//Returns: int
//Desc: returns the value of the member variable Id as an int
int Block::getId(){
	return id;
}

//Method: setGrade(double grade)
//Params: double
//Returns: None
//Desc: set the member variable grade = to the inputted double
void Block::setGrade(double gradeIN){
	grade = gradeIN;
}

//Method: getGrade()
//Params: None
//Returns: double
//Desc: returns the value of the member varaible grade as a double
double Block::getGrade(){
	return grade;
}

//Method: setSuggestedSpeed(double suggestedSpeed)
//Params:	double
//Returns:	None
//Desc: set the member variable suggestedSpeed = the the inputted double
void Block::setSuggestedSpeed(double suggestedSpeedIN){
	suggestedSpeed = suggestedSpeedIN;
}

//Method: getSuggestedSpeed()
//Params: None
//Returns: double
//Desc: returns the value of the member variable suggestedSpeed as a double
double Block::getSuggestedSpeed(){
	return suggestedSpeed;
}

//Method: setSpeedLimit(double speedLimit)
//Params: double
//Returns: None
//Desc: sets the member variable speedLimit = to the inputted double
void Block::setSpeedLimit(double speedLimitIN){
	speedLimit = speedLimitIN;
}

//Method: getSpeedLimit()
//Params: None
//Returns: double
//Desc: returns the value of the member variable speedLimit as a double
double Block::getSpeedLimit(){
	return speedLimit;
}

//Method: setDirection(char direction)
//Params: char
//Returns: None
//Desc: set the member variable direction = to inputted char ('n', 'e', 's', 'w') ('n' = north, 'e' = east, 's' = south, 'w' = west) otherwise defaults to None
void Block::setDirection(char directionIN){
	if(directionIN == 'n' || directionIN == 'e' || directionIN == 's' || directionIN == 'w'){
		direction = directionIN;
	}else{
		direction = ' ';
	}
}

//Method: getDirection()
//Params: None
//Returns: char
//Desc: returns the value of the member variable direction as a char
char Block::getDirection(){
	return direction;
}

//Method: setTemperature(double temperature)
//Params: double
//Returns: None
//Desc: set the member variable temperature = to the inputted double
void Block::setTemperature(double temperatureIN){
	temperature = temperatureIN;
}

//Method: getTemperature()
//Params: None
//Returns: double
//Desc: returns the value of the member variable temperature as a double
double Block::getTemperature(){
	return temperature;
}

//Method: setBeacons(int beacons)
//Params: int
//Returns: None
//Desc: set the member variable beacons = to the inputted int
void Block::setBeacons(int beaconsIN){
	beacons = beaconsIN;
}

//Method: getBeacons()
//Params: None
//Returns: int
//Desc: returns the value of the member variable beacons as an int
int Block::getBeacons(){
	return beacons;
}

//Method: setHeight(double height)
//Params: double
//Returns: None
//Desc: set the member variable height = to the inputted double
void Block::setHeight(double heightIN){
	height = heightIN;
}

//Method: getHeight()
//Params: None
//Returns: double
//Desc: returns the value of the member variable height as a double
double Block::getHeight(){
	return height;
}

//Method: setBrokenRail(bool brokenRailIN)
//Params: bool
//Returns: None
//Desc: set the member variable brokenRail = to the inputted bool
void Block::setBrokenRail(bool brokenRailIN){
	brokenRail = brokenRailIN;
}

//Method: getBrokenRail()
//Params: None
//Returns: bool
//Desc: returns the value of the member variable brokenRail as a bool
bool Block::getBrokenRail(){
	return brokenRail;
}

//Method: setBrokenCircuit(bool brokenCircuitIN)
//Params: bool
//Returns: None
//Desc: set the member variable brokenCircuit = to the inputted bool
void Block::setBrokenCircuit(bool brokenCircuitIN){
	brokenCircuit = brokenCircuitIN;
}

//Method: getBrokenCircuit()
//Params: None
//Returns: bool
//Desc: returns the value of the member variable brokenCircuit as a bool
bool Block::getBrokenCircuit(){
	return brokenCircuit;
}

//Method: setPowerFailure(bool powerFailureIN)
//Params: bool
//Returns: None
//Desc: set the member variable powerFailure = to the inputted bool
void Block::setPowerFailure(bool powerFailureIN){
	powerFailure = powerFailureIN;
}

//Method: getPowerFailure()
//Params: None
//Returns: bool
//Desc: returns the value of the member variable powerFailure as a bool
bool Block::getPowerFailure(){
	return powerFailure;
}

void Block::setCrossing(bool c){
	crossingActivated = c;
}

bool Block::getCrossing(){
	return crossingActivated;
}

void Block::setSwitch(bool s){
	switchPosition = s;
}

bool Block::getSwitch(){
	return switchPosition;
}

//Method: toConsole()
//Params: None
//Returns: None
//Desc: prints the Blocks member variable values in a fromatted string to console
void Block::toConsole(){
	cout << "line: " << line << " direction: " << direction << endl;
	cout << "type: " << type << " temperature: " << temperature << endl;
	cout << "length: " << length << " beacons: " << beacons << endl;
	cout << "trainPresent: " << trainPresent << " height: " << height << endl;
	cout << "count: " << count << " brokenRail: " << brokenRail << endl;
	cout << "id: " << id << " brokenCircuit: " << brokenCircuit << endl;
	cout << "grade: " << grade << " powerFailure: " << powerFailure << endl;
	cout << "suggestedSpeed: " << suggestedSpeed << " speedLimit: " << speedLimit << endl;
}
