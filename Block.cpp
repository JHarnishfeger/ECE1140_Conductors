#include "Block.h"

//Init statics
int Block::instanceCounter = 0;
double Block::xCordTotal = 0.0;
double Block::yCordTotal = 0.0;
double Block::totalDistance = 0.0;

//Constructors:
//Default constructor
Block::Block(){
	passengers = 10;
	id = instanceCounter;
	instanceCounter++;
	line = "green";
	branch = "a";
	type = "rail";
	direction = "north";
	nextBlocks = "2,60";
	stationName = "";
	length = 10.0;
	TDBegin = totalDistance;
	totalDistance = totalDistance + length;
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
	beaconPresent = false;
	stationSide = true;
	encodeTrackCircuitData();
}

//Full input constructor
Block::Block(int passengersIN, string lineIN, string branchIN, string typeIN, string directionIN, string nextBlocksIN, string stationNameIN, double lengthIN,double xCordIN, double yCordIN, double gradeIN, double heightIN, double temperatureIN,
double speedLimitIN, double suggestedSpeedIN, bool authorityIN, bool railStatusIN, bool circuitStatusIN, bool powerStatusIN, bool heaterStatusIN, bool crossingStatusIN, bool switchStatusIN, bool trainPresentIN, bool beaconPresentIN, bool stationSideIN, uint32_t trackCircuitDataIN){
	passengers = passengersIN;
	id = instanceCounter;
	instanceCounter++;
	line = lineIN;
	branch = branchIN;
	type = typeIN;
	direction = directionIN;
	nextBlocks = nextBlocksIN;
	stationName = stationNameIN;
	length = lengthIN;
	TDBegin = totalDistance;
	totalDistance = totalDistance + length;
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
	beaconPresent = beaconPresentIN;
	stationSide = stationSideIN;
	trackCircuitData = trackCircuitDataIN;
}
//Functional constructor
Block::Block(string lineIN, string branchIN, int idIN, double lengthIN, double gradeIN, double speedLimitIN, 
string typeIN, double heightIN, double suggestedSpeedIN, string directionIN){
	instanceCounter++;
	if(typeIN.substr(0,2) == "st"){
		type = typeIN.substr(0,7);
		stationName = typeIN.substr(8,typeIN.size()-8);
	}else if(typeIN.substr(0,2) == "sw"){
		type = typeIN.substr(0,6);
		string branchParse = typeIN.substr(6,typeIN.size()-6); //(#:#)
		string branch1(typeIN.substr(7,typeIN.find(":")-7));
		string branch2(typeIN.substr(( typeIN.find(":") + 1 ),( typeIN.size() - 2 ) - typeIN.find(":")));
		nextBlocks = branch1 + "," + branch2; 
	}else{
		type = typeIN;
	}
	if(type == "station"){
		srand(time(NULL));
		passengers = rand() % 100 + 1;
	}else{
		passengers = 0;
	}
	line = lineIN;
	id = idIN;
	branch = branchIN;
	direction = directionIN;
	length = lengthIN;
	TDBegin = totalDistance;
	totalDistance = totalDistance + length;
	xCord = xCordTotal;
	yCord = yCordTotal;
	if(direction == "north"){
		yCordTotal = yCordTotal + length;
	}else if(direction == "east"){
		xCordTotal = xCordTotal + length;
	}else if(direction == "south"){
		yCordTotal = yCordTotal - length;
	}else if(direction == "west"){
		xCordTotal = xCordTotal - length;
	}else{
		//no change
	}
	grade = gradeIN;
	height = heightIN;
	temperature = 40.0;
	speedLimit = speedLimitIN;
	suggestedSpeed = suggestedSpeedIN;
	authority = false;
	railStatus = true;
	circuitStatus = true;
	powerStatus = true;
	heaterStatus = false;
	crossingStatus = false;
	switchStatus = true;
	trainPresent = false;
	beaconPresent = false;
	stationSide = true;
	encodeTrackCircuitData();
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
//Notes: type should be set to "rail", "yard", "station", "switch", or "crossing" function assumes no user error
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

//nextBlocks -----------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute nextBlocks = to inputted string
void Block::setNextBlocks(string nextBlocksIN){
	nextBlocks = nextBlocksIN;
}
//Params: None
//Returns: string
//Desc: returns the value of the attribute nextBlocks as a string
string Block::getNextBlocks(){
	return nextBlocks;
}

//stationName ----------------------------------------------------------
//Params: string
//Returns: None
//Desc: sets the value of the attribute stationName = to inputted string
void Block::setStationName(string stationNameIN){
	stationName = stationNameIN;
}

//Params: None
//Returns: string
//Desc: returns the value of the attribute stationNAme as a string
string Block::getStationName(){
	return stationName;
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
//Notes: bool true = train has authority false = true has no authority
//Params: bool
//Returns None
//Desc: sets the value of the attribute authority = to inputted bool
void Block::setAuthority(bool authorityIN){
	authority = authorityIN;
}
//Params: None
//Returns bool
//Desc: returns the value of the attribute authority as a bool
bool Block::getAuthority(){
	return authority;
}
//Params: None
//Returns: None
//Desc: toggles the bool value of the attribute authority
void Block::toggleAuthority(){
	authority = !(authority);
}

//railStatus -----------------------------------------------------------
//Notes: bool true = no rail failures bool false = rail failure
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
	railStatus = !(railStatus);
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
	circuitStatus = !(circuitStatus);
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
	powerStatus = !(powerStatus);
}

//heaterStatus ---------------------------------------------------------
//Notes: bool true = heater is active bool false = heater is inactive
//Params: bool 
//Returns: None
//Desc: sets the value of the attribute heaterStatus = to inputted bool
void Block::setHeaterStatus(bool heaterStatusIN){
	heaterStatus = heaterStatusIN;
	if(heaterStatus == true){
		temperature = 50.0;
	}else{
		temperature = 40.0;
	}
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
	heaterStatus = !(heaterStatus);
	if(heaterStatus == true){
		temperature = 50.0;
	}else{
		temperature = 40.0;
	}
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
	crossingStatus = !(crossingStatus);
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
	switchStatus = !(switchStatus);
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
	trainPresent = !(trainPresent);
}
//beaconPresent --------------------------------------------------------
//Notes: bool true = beacon is present on block false = no beacon present
//Params: bool
//Returns: None
//Desc: sets the value of the attribute beaconPresent = to inputted bool
void Block::setBeaconPresent(bool beaconPresentIN){
	beaconPresent = beaconPresentIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute beaconPresent as a bool
bool Block::getBeaconPresent(){
	return beaconPresent;
}
//stationSide ----------------------------------------------------------
//Notes: bool true = station on left false = station on right
//Params: bool
//Returns: None
//Desc: sets the value of the attribute stationSide = to inputted bool
void Block::setStationSide(bool stationSideIN){
	stationSide = stationSideIN;
}
//Params: None
//Returns: bool
//Desc: returns the value of the attribute stationSide as a bool
bool Block::getStationSide(){
	return stationSide;
}
//encodeData -----------------------------------------------------------
//Params: None
//Returns: None
//Desc: encodes data that needs tranferred between modules into a decodable unsigned 32 bit integer
void Block::encodeTrackCircuitData(){
	
	uint32_t speedLimitU, suggestedSpeedU, authorityU;
	
	speedLimitU = (uint32_t)(speedLimit + 0.5);
	suggestedSpeedU = (uint32_t)(suggestedSpeed + 0.5);
	authorityU = (uint32_t)(authority + 0.5);
	
	trackCircuitData = ((((uint32_t)speedLimitU)<<16)+(((uint32_t)suggestedSpeedU)<<8)+(((uint32_t)authorityU)));
}
//Params: None
//Returns: None
//Dessc: encodes that that needs transfferred between modules into a decodable unsigned 16 bit integer
void Block::encodeBeaconData(){
	if(beaconPresent == 1){
		
		int stationCode, incomingCode;
		bool headlights, stationHere;
		
		if(stationName == "shadyside"){
			stationCode = 1;
		}else if(stationName == "herron_ave"){
			stationCode = 2;
		}else if(stationName == "swissville"){
			stationCode = 3;
		}else if(stationName == "penn_station"){
			stationCode = 4;
		}else if(stationName == "steel_plaza"){
			stationCode = 5;
		}else if(stationName == "first_ave"){
			stationCode = 6;
		}else if(stationName == "station_square"){
			stationCode = 7;
		}else if(stationName == "south_hills_junction"){
			stationCode = 8;
		}else if(stationName == "pioneer"){
			stationCode = 9;
		}else if(stationName == "edgebrook"){
			stationCode = 10;
		}else if(stationName == "whited"){
			stationCode = 11;
		}else if(stationName == "south_bank"){
			stationCode = 12;
		}else if(stationName == "central"){
			stationCode = 13;
		}else if(stationName == "inglewood"){
			stationCode = 14;
		}else if(stationName == "overbrook"){
			stationCode = 15;
		}else if(stationName == "glenbury"){
			stationCode = 16;
		}else if(stationName == "dormont"){
			stationCode = 17;
		}else if(stationName == "mt_lebanon"){
			stationCode = 18;
		}else if(stationName == "poplar"){
			stationCode = 19;
		}else if(stationName == "castle_shannon"){
			stationCode = 20;
		}else if(type == "yard"){
			stationCode = 21;
		}else{
			stationCode = 31;
		}
		
		if(type == "underground"){
			headlights = 1;
		}else{
			headlights = 0;
		}
		
		if(type == "station"){
			stationHere = 1;
		}else{
			stationHere = 0;
		}
		
		if(headlights == 0 && stationHere == 0){
			incomingCode = 1;
		}else if(headlights == 1 && stationHere == 0){
			incomingCode = 2;
		}else if(headlights == 0 && stationHere == 1){
			incomingCode = 3;
		}else{
			incomingCode = 4;
		}
		
		beaconData = (((uint16_t)stationCode<<8)+(((uint16_t)incomingCode)));
	
	}else{
		beaconData = 0;
	}
}
//Params: None
//Returns: uint32_t
//Desc: returns a unsigned 32-bit integer representation of the track circuit data
uint32_t Block::getTrackCircuitData(){
	return trackCircuitData;
}
//Params: None
//Returns uint16_t
//Desc: returns a unsigned 16-bit integer representation of the beacon data
uint16_t Block::getBeaconData(){
	return beaconData;
}
//Params: None
//Returns: string
//Desc: Returns a formatted string representation of the block
string Block::toString(){
	string retString = "";
	retString = retString + "[" + std::to_string(id);
	retString = retString + "," + branch;
	retString = retString + "," + type;
	if(type == "station"){
		retString = retString + ":" + stationName;
	}
	retString = retString + ", L: " + std::to_string(length);
	retString = retString + ", X: " + std::to_string(xCord);
	retString = retString + ", Y: " + std::to_string(yCord);
	retString = retString + ", TDBegin: " + std::to_string(TDBegin);
	retString = retString + ", TP: " + std::to_string(trainPresent) + "]\n";
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
	if(type == "station"){
		retString = retString + ":" + stationName;
	}
	retString = retString + ", L: " + std::to_string(length);
	retString = retString + ", X: " + std::to_string(xCord);
	retString = retString + ", Y: " + std::to_string(yCord);
	retString = retString + ", TDBegin: " + std::to_string(TDBegin);
	retString = retString + ", TP: " + std::to_string(trainPresent) + "]\n";
	retString = retString + "BLOCK STATS: \n";
	retString = retString + "\t passengers: " + std::to_string(passengers);
	retString = retString + "\t direction: " + direction;
	retString = retString + "\t nextBlocks: " + nextBlocks;
	retString = retString + "\t length: " + std::to_string(length) + "\n";
	retString = retString + "\t grade: " + std::to_string(grade);
	retString = retString + "\t height: " + std::to_string(height);
	retString = retString + "\t stationName: " + stationName;
	retString = retString + "\t temperature: " + std::to_string(temperature) + "\n";
	retString = retString + "\t speedLimit: " + std::to_string(speedLimit);
	retString = retString + "\t suggestedSpeed: " + std::to_string(suggestedSpeed);
	retString = retString + "\t totalDistance: " + std::to_string(totalDistance);
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

