#include "Block.h"

//Default Constructor
Block::Block(){
    line = "Green";
    branch = "A";
    type = "STATION";
    stationName = "PIONEER";
    nextBranches = "DA";
    vector<int> nb{13,1};
    nextBlocks = nb;
    number = 2;
    speedLimit = 45;
    srand(time(0));
    passengers = rand() % 100 + 1;
    trafficLightStatus = -1;
    stationSide = 1;
    suggestedSpeed = 5;
    temperature = 32.0;
    length = 100.0;
    grade = 1.0;
    elevation = 1.0;
    authority = true;
    railStatus = true;
    circuitStatus = true;
    powerStatus = true;
    heaterStatus = true;
    crossingStatus = false;
    switchStatus = false;
    trainPresent = true;
    beaconPresent = false;
    encodeTrackCircuitData(); //trackCircuitData = (method sets trackCircuitData)
    encodeBeaconData(); //beaconData = (method sets beaconData)
}

//Full-input Constructor
Block::Block(string lineIN, string branchIN, string typeIN, string stationNameIN, string nextBranchesIN, vector<int> nextBlocksIN, int numberIN, int speedLimitIN, int passengersIN,
int trafficLightStatusIN, int stationSideIN, double suggestedSpeedIN, double temperatureIN, double lengthIN, double gradeIN, double elevationIN, bool authorityIN,
bool railStatusIN, bool circuitStatusIN, bool powerStatusIN, bool heaterStatusIN, bool crossingStatusIN, bool switchStatusIN, bool trainPresentIN,
bool beaconPresentIN, uint64_t trackCircuitDataIN, uint16_t beaconDataIN){
    line = lineIN;
    branch = branchIN;
    type = typeIN;
    stationName = stationNameIN;
    nextBranches = nextBranchesIN;
    nextBlocks = nextBlocksIN;
    number = numberIN;
    speedLimit = speedLimitIN;
    passengers = passengersIN;
    trafficLightStatus = trafficLightStatusIN;
    stationSide = stationSideIN;
    suggestedSpeed = suggestedSpeedIN;
    temperature = temperatureIN;
    length = floor(lengthIN);
    grade = gradeIN;
    elevation = elevationIN;
    authority = authorityIN;
    railStatus = railStatusIN;
    circuitStatus = circuitStatusIN;
    powerStatus = powerStatusIN;
    heaterStatus = heaterStatusIN;
    crossingStatus = crossingStatusIN;
    switchStatus = switchStatusIN;
    trainPresent = trainPresentIN;
    beaconPresent = beaconPresentIN;
    trackCircuitData = trackCircuitDataIN;
    beaconData = beaconDataIN;
}

//Functional Constructor
Block::Block(string lineIN, string branchIN, int numberIN, double lengthIN, double gradeIN, int speedLimitIN, string typeIN, int stationSideIN, double elevationIN, double suggestedSpeedIN){
    line = lineIN;
    branch = branchIN;
    nextBranches = "";
    number = numberIN;
    if(typeIN.substr(0,2) == "SW"){
        string Block1 = typeIN.substr(7,(typeIN.find_first_of(":") - 7));
        string Block2 =  typeIN.substr((typeIN.find_first_of(":") + 1), (typeIN.find_last_of(")") - (typeIN.find_first_of(":") + 1)));
        int Block1int, Block2int;
        std::stringstream ssB1(Block1);
        std::stringstream ssB2(Block2);
        ssB1 >> Block1int;
        ssB2 >> Block2int;
        vector<int> nb;
        nb.push_back(Block1int);
        nb.push_back(Block2int);
        nextBlocks = nb;
        type = typeIN.substr(0,6);
    }else if(typeIN.substr(0,2) == "ST"){
        if(typeIN.find(";") == (unsigned int) -1){
            string stationNameReg = typeIN.substr((typeIN.find_first_of(":") + 1), (typeIN.length() - (typeIN.find_first_of(":") + 1)));
            stationName = stationNameReg;
        }else{
            string stationNameUnder = typeIN.substr((typeIN.find_first_of(":") + 1), (typeIN.find_first_of(";") - typeIN.find_first_of(":") - 1));
            stationName = stationNameUnder;
        }
        vector<int> nb;
        nb.push_back(number + 1);
        nb.push_back(number + 1);
        nextBlocks = nb;
        type = typeIN.substr(0,7);
    }else{
        vector<int> nb;
        nb.push_back(number + 1);
        nb.push_back(number + 1);
        nextBlocks = nb;
        type = typeIN;
    }
    speedLimit = speedLimitIN;
    if(type == "STATION"){
        srand(time(0));
        passengers = rand() % 100 + 1;
    }else{
        passengers = 0;
    }
    trafficLightStatus = -1;
    stationSide = stationSideIN;
    suggestedSpeed = suggestedSpeedIN;
    temperature = 40.0;
    length = floor(lengthIN);
    grade = gradeIN;
    elevation = elevationIN;
    authority = true;
    railStatus = true;
    circuitStatus = true;
    powerStatus = true;
    heaterStatus = false;
    crossingStatus = false;
    switchStatus = true;
    trainPresent = false;
    beaconPresent = false;
    encodeTrackCircuitData();
    encodeBeaconData();
}

//Attributes:
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
//nextBlocks -----------------------------------------------------------
//Params: int x2
//Returns: None
//Desc: sets the value of the attribute nextBlocks = to inputted ints
void Block::setNextBlocks(int block1,int block2){
    vector<int> retVect;
    retVect.push_back(block1);
    retVect.push_back(block2);
    nextBlocks = retVect;
}
//Params: None
//Returns: vector<int>
//Desc: returns the value of the attribute nextBlocks as a vector<int>
vector<int> Block::getNextBlocks(){
    return nextBlocks;
}
//number ---------------------------------------------------------------
//Params: int
//Returns: None
//Desc: sets the value of the attribute number = to inputted int
void Block::setBlockNumber(int numberIN){
    number = numberIN;
}

//Params: None
//Returns: int
//Desc: returns the value of the attribute number as an int
int Block::getBlockNumber(){
    return number;
}
//speedLimit -----------------------------------------------------------
//Params: int
//Returns: None
//Desc: sets the value of the attribute speedLimit = to inputted int
void Block::setSpeedLimit(int speedLimitIN){
    speedLimit = speedLimitIN;
}

//Params: None
//Returns: int
//Desc: returns the value of the attribute speedLimit as an int
int Block::getSpeedLimit(){
    return speedLimit;
}
//passengers -----------------------------------------------------------
//Params: int
//Returns: None
//Desc: sets the value of the attribute passengers = to inputted int
void Block::setPassengerCount(int passengersIN){
    passengers = passengersIN;
}
//Params: None
//Returns: int
//Desc: returns the value of the attribute passengers as an int
int Block::getPassengerCount(){
    return passengers;
}
//trafficLightStatus ---------------------------------------------------
//Notes: trafficLightStatus(TLS) = -1, no traffic light on block TLS = 0, red light TLS = 1 green light
//Params:int
//Returns: None
//Desc: sets the value of the attribute trafficLightStatus = to inputted int
void Block::setTrafficLightStatus(int trafficLightStatusIN){
    trafficLightStatus = trafficLightStatusIN;
}
//Params: None
//Returns: int
//Desc: returns the value of trafficLightStatus as an int
int Block::getTrafficLightStatus(){
    return trafficLightStatus;
}
//stationSide ----------------------------------------------------------
//Notes: stationSide = -1 no station, stationSide = 0 station on left, stationSide = 1 station on right, stationside = 2 station on both sides
//Params: int
//Returns: None
//Desc: sets the value of the attribute stationSide = to inputted int
void Block::setStationSide(int stationSideIN){
    stationSide = stationSideIN;
}
//Params: None
//Returns: int
//Desc: returns the value of the attribute stationSide as an int
int Block::getStationSide(){
    return stationSide;
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
//elevation ---------------------------------------------------------------
//Params: double
//Returns: None
//Desc: sets the value of the attribute elevation = to inputted double
void Block::setElevation(double elevationIN){
    elevation = elevationIN;
}
//Params: None
//Returns: double
//Desc: returns the value of the attribute elevation as a double
double Block::getElevation(){
    return elevation;
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
//trackCircuitData -----------------------------------------------------
//Params: None
//Returns: None
//Desc: encodes data that needs tranferred between modules into a decodable unsigned 32 bit integer
void Block::encodeTrackCircuitData(){

    trackCircuitData = ((((uint64_t)length)<<32)+(((uint64_t)number)<<24)+(((uint64_t)speedLimit)<<16)+(((uint64_t)suggestedSpeed)<<8)+(((uint64_t)authority)));

}
//Params: None
//Returns: uint32_t
//Desc: returns a unsigned 32-bit integer representation of the track circuit data
uint64_t Block::getTrackCircuitData(){
    return trackCircuitData;
}
//beaconData -----------------------------------------------------------
//Params: None
//Returns: None
//Dessc: encodes that that needs transfferred between modules into a decodable unsigned 16 bit integer
void Block::encodeBeaconData(){
    if(beaconPresent == 1){

        int stationCode, incomingCode;
        bool headlights, stationHere;

        if(stationName == "SHADYSIDE"){
            stationCode = 1;
        }else if(stationName == "HERRON_AVE"){
            stationCode = 2;
        }else if(stationName == "SWISSVILLE"){
            stationCode = 3;
        }else if(stationName == "PENN_STATION"){
            stationCode = 4;
        }else if(stationName == "STEEL_PLAZA"){
            stationCode = 5;
        }else if(stationName == "FIRST_AVE"){
            stationCode = 6;
        }else if(stationName == "STATION_SQUARE"){
            stationCode = 7;
        }else if(stationName == "SOUTH_HILLS_JUNCTION"){
            stationCode = 8;
        }else if(stationName == "PIONEER"){
            stationCode = 9;
        }else if(stationName == "EDGEBROOK"){
            stationCode = 10;
        }else if(stationName == "WHITED"){
            stationCode = 11;
        }else if(stationName == "SOUTH_BANK"){
            stationCode = 12;
        }else if(stationName == "CENTRAL"){
            stationCode = 13;
        }else if(stationName == "INGLEWOOD"){
            stationCode = 14;
        }else if(stationName == "OVERBROOK"){
            stationCode = 15;
        }else if(stationName == "GLENBURY"){
            stationCode = 16;
        }else if(stationName == "DORMONT"){
            stationCode = 17;
        }else if(stationName == "MT_LEBANON"){
            stationCode = 18;
        }else if(stationName == "POPLAR"){
            stationCode = 19;
        }else if(stationName == "CASTLE_SHANNON"){
            stationCode = 20;
        }else if(type == "YARD"){
            stationCode = 21;
        }else{
            stationCode = 31;
        }

        if(type == "UNDERGROUND"){
            headlights = 1;
        }else{
            headlights = 0;
        }

        if(type == "STATION"){
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
//Returns uint16_t
//Desc: returns a unsigned 16-bit integer representation of the beacon data
uint16_t Block::getBeaconData(){
    return beaconData;
}
//toStrings ------------------------------------------------------------
//Params: None
//Returns: string
//Desc: returns a representation of the block as a formatted string
string Block::toString(){
    string retString = "";
    retString = "[" + type + "," + branch + "," + std::to_string(number) + "," + std::to_string(length) + ",Train:" + std::to_string(trainPresent) + "]";
    return retString;
}
//Params: None
//Returns: string
//Desc: returns ALL the data about the block as a formatted string
string Block::toStringDetailed(){
    string retString = "";
    retString = "[" + type + "," + branch + "," + std::to_string(number) + "," + std::to_string(length) + ",Train:" + std::to_string(trainPresent) + "]:\n";
    retString = retString + "BLOCK STATS: \n";
    retString = retString + "\t Line: " + line;
    retString = retString + "\t Speed Limit: " + std::to_string(speedLimit);
    retString = retString + "\t Station Name: " + stationName;
    retString = retString + "\t Next Blocks: " + std::to_string(nextBlocks.at(0)) + "," + std::to_string(nextBlocks.at(1)) + "\n";
    retString = retString + "\t Authority: " + std::to_string(authority);
    retString = retString + "\t Grade: " + std::to_string(grade);
    retString = retString + "\t Elevation: " + std::to_string(elevation);
    retString = retString + "\t Next Branches: " + nextBranches + "\n";
    retString = retString + "\t Passengers: " + std::to_string(passengers);
    retString = retString + "\t Suggested Speed: " + std::to_string(suggestedSpeed);
    retString = retString + "\t Station Side: " + std::to_string(stationSide) + "\n";
    retString = retString + "\t Traffic Light: " + std::to_string(trafficLightStatus);
    retString = retString + "\t Crossing Status: " + std::to_string(crossingStatus);
    retString = retString + "\t Switch Status: " + std::to_string(switchStatus);
    retString = retString + "\t Beacon Present: " + std::to_string(beaconPresent) + "\n\n";
    return retString;
}
