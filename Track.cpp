#include "Block.h"
#include "Track.h"
using namespace std;

//Constructors:
//Default constructor
Track::Track(){
    //cout << calling default constructor << endl;
    //loadTrack("greenLine.txt");
    //suggSpeed = 45.0;
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
    if(line == "Green"){
        return greenLine.at(id);
    }else if(line == "Red"){
        return redLine.at(id);
    }else{
        return NULL;
    }
}
//Params: string, int
//Returns: Block*
//Desc:searches for a block according to inputted line and assigned id and returns it as a Block*
Block* Track::searchBlockById(string line, int id){
    if(line == "Green"){
        for(unsigned int g = 0; g < greenLine.size(); g++){
            if(greenLine.at(g)->getBlockNumber() == id){
                return greenLine.at(g);
            }
        }
    }else if(line == "Red"){
        for(unsigned int r = 0; r < redLine.size(); r++){
            if(redLine.at(r)->getBlockNumber() == id){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    if(line == "Green"){
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
    string header, fsize, line, branch, blockNumber, length, grade, speedLimit, type,
    stationSide, elevation, trash;
    int fileSize;
    getline(inputFile,header);
    getline(inputFile,fsize);
    std::stringstream ss1(fsize);
    ss1 >> fileSize;
    for(int i = 0; i < fileSize; i++){
        getline(inputFile, line, ',');
        getline(inputFile, branch, ',');
        getline(inputFile, blockNumber, ',');
        getline(inputFile, length, ',');
        getline(inputFile, grade, ',');
        getline(inputFile, speedLimit, ',');
        getline(inputFile, type, ',');
        getline(inputFile, stationSide, ',');
        if(line == "Green"){
            getline(inputFile, elevation, ',');
            getline(inputFile, trash);
        }else{
            getline(inputFile, elevation);
        }
        int stationSDEG;
        if(stationSide.find("/") == 4){
            stationSDEG = 2;
        }else if(stationSide.substr(0,2) == "Ri"){
            stationSDEG = 1;
        }else if(stationSide.substr(0,2) == "Le"){
            stationSDEG = 0;
        }else{
            stationSDEG = -1;
        }
        if(line == "Green"){
            std::stringstream ss2(blockNumber);
            std::stringstream ss3(speedLimit);
            int blockNumG, speedLimG;
            ss2 >> blockNumG;
            ss3 >> speedLimG;
            greenLine.push_back(new Block(line, branch, blockNumG, stod(length), stod(grade), speedLimG, type, stationSDEG, stod(elevation), (double)speedLimG));
            if(type.substr(0,2) == "ST"){
                greenLine.at(i - 1)->setBeaconPresent(true);
            }
        }
        if(line == "Red"){
            std::stringstream ss5(blockNumber);
            std::stringstream ss6(speedLimit);
            std::stringstream ss7(stationSide);
            int stationSDER;
            if(stationSide.find("/") == 4){
                stationSDER = 2;
            }else if(stationSide.substr(0,2) == "Ri"){
                stationSDER = 1;
            }else if(stationSide.substr(0,2) == "Le"){
                stationSDER = 0;
            }else{
                stationSDER = -1;
            }
            int blockNumR, speedLimR;
            ss5 >> blockNumR;
            ss6 >> speedLimR;
            redLine.push_back(new Block(line, branch, blockNumR, stod(length), stod(grade), speedLimR, type, stationSDER, stod(elevation), (double)speedLimR));
            if(type.substr(0,2) == "ST"){
                redLine.at(i - 1)->setBeaconPresent(true);
            }
        }
    }
    for(unsigned int g = 0; g < greenLine.size(); g++){
            if(greenLine.at(g)->getType() == "SWITCH"){
                string Block1, Block2;
                if(greenLine.at(g)->getNextBlocks().at(0) == 0){
                    Block1 = "YARD";
                }else{
                    Block1 = searchBlockById("Green", greenLine.at(g)->getNextBlocks().at(0))->getBranch();
                }
                if(greenLine.at(g)->getNextBlocks().at(1) == 0){
                    Block2 = "YARD";
                }else{
                    Block2 = searchBlockById("Green", greenLine.at(g)->getNextBlocks().at(1))->getBranch();
                }
                greenLine.at(g)->setNextBranches(Block1 + Block2);
            }
        }
    for(unsigned int r = 0; r < redLine.size(); r++){
        if(redLine.at(r)->getType() == "SWITCH"){
            string Block1, Block2;
            if(redLine.at(r)->getNextBlocks().at(0) == 0){
                Block1 = "YARD";
            }else{
                Block1 = searchBlockById("Red", redLine.at(r)->getNextBlocks().at(0))->getBranch();
            }
            if(redLine.at(r)->getNextBlocks().at(1) == 0){
                Block2 = "YARD";
            }else{
                Block2 = searchBlockById("Red", redLine.at(r)->getNextBlocks().at(1))->getBranch();
            }
            redLine.at(r)->setNextBranches(Block1 + Block2);
        }
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
//integration ----------------------------------------------------------
//Params: vector<Block>
//Returns: None
//Desc: takes in a vector of blocks and updates the track with inputted vector<Block>
void Track::updateTrack(vector<Block> newTrack){
    //cout << "updating Track" << endl;
    for(unsigned int t = 0; t < newTrack.size(); t++){
        for(unsigned int g = 0; g < greenLine.size(); g++){
            if((newTrack.at(t).getLine() == "Green") && (newTrack.at(t).getBlockNumber() == greenLine.at(g)->getBlockNumber())){
                if(greenLine.at(g)->getSwitchStatus() != newTrack.at(t).getSwitchStatus()){
                    greenLine.at(g)->setSwitchStatus(newTrack.at(t).getSwitchStatus());
                }
                if(greenLine.at(g)->getCrossingStatus() != newTrack.at(t).getCrossingStatus()){
                    greenLine.at(g)->setCrossingStatus(newTrack.at(t).getCrossingStatus());
                }
                if(greenLine.at(g)->getSuggestedSpeed() != newTrack.at(t).getSuggestedSpeed()){
                    greenLine.at(g)->setSuggestedSpeed(newTrack.at(t).getSuggestedSpeed());
                }
            }
        }
        for(unsigned int r = 0; r < redLine.size(); r++){
            if((newTrack.at(t).getLine() == "Red") && (newTrack.at(t).getBlockNumber() == redLine.at(r)->getBlockNumber())){
                if(redLine.at(r)->getSwitchStatus() != newTrack.at(t).getSwitchStatus()){
                    redLine.at(r)->setSwitchStatus(newTrack.at(t).getSwitchStatus());
                }
                if(redLine.at(r)->getCrossingStatus() != newTrack.at(t).getCrossingStatus()){
                    redLine.at(r)->setCrossingStatus(newTrack.at(t).getCrossingStatus());
                }
                if(redLine.at(r)->getSuggestedSpeed() != newTrack.at(t).getSuggestedSpeed()){
                    redLine.at(r)->setSuggestedSpeed(newTrack.at(t).getSuggestedSpeed());
                }
            }
        }
    }
}
//Params: uint8_t, int, bool
//Returns: uint64_t
//Desc: handles the train info sent to Track Model by the Train Model
uint64_t Track::handleTCTrainInfo(uint8_t currBlock, int ID, bool line){

    int blockNum = (currBlock) & 0xFF;
    if(blockNum != 0){
        blockNum = blockNum - 1;
    }
    if(line == 1){
        greenLine.at(blockNum)->setTrainPresent(false);
    }else{
        redLine.at(blockNum)->setTrainPresent(false);
    }

    if(blockNum == 0 && line == 1){
        greenLine.at(63)->setTrainPresent(true);
        return greenLine.at(63)->getTrackCircuitData();
    }else if(blockNum == 0 && line == 0){
        redLine.at(10)->setTrainPresent(true);
        return redLine.at(10)->getTrackCircuitData();
    }else{
        if(line == 1){
            if(greenLine.at(blockNum)->getType() == "SWITCH"){
                if(greenLine.at(blockNum)->getSwitchStatus() == 1){
                    if(greenLine.at(blockNum)->getNextBlocks().at(0) == 0){
                        greenLine.at(blockNum)->setTrainPresent(false);
                        return 0;
                    }else{
                        greenLine.at(greenLine.at(blockNum)->getNextBlocks().at(0))->setTrainPresent(true);
                        return greenLine.at(greenLine.at(blockNum)->getNextBlocks().at(0))->getTrackCircuitData();
                    }
                }else{
                    if(greenLine.at(blockNum)->getNextBlocks().at(1) == 0){
                        greenLine.at(blockNum)->setTrainPresent(false);
                        return 0;
                    }else{
                        greenLine.at(greenLine.at(blockNum)->getNextBlocks().at(1))->setTrainPresent(true);
                        return greenLine.at(greenLine.at(blockNum)->getNextBlocks().at(1))->getTrackCircuitData();
                    }
                }
            }else{
                greenLine.at(blockNum + 1)->setTrainPresent(true);
                return greenLine.at(blockNum + 1)->getTrackCircuitData();
            }
        }else{
            if(redLine.at(blockNum)->getType() == "SWITCH"){
                if(redLine.at(blockNum)->getSwitchStatus() == 1){
                    if(redLine.at(blockNum)->getNextBlocks().at(0) == 0){
                        redLine.at(blockNum)->setTrainPresent(false);
                        return 0;
                    }else{
                        redLine.at(redLine.at(blockNum)->getNextBlocks().at(0))->setTrainPresent(true);
                        return redLine.at(redLine.at(blockNum)->getNextBlocks().at(0))->getTrackCircuitData();
                    }
                }else{
                    if(redLine.at(blockNum)->getNextBlocks().at(1) == 0){
                        redLine.at(blockNum)->setTrainPresent(false);
                        return 0;
                    }else{
                        redLine.at(redLine.at(blockNum)->getNextBlocks().at(1))->setTrainPresent(true);
                        return redLine.at(redLine.at(blockNum)->getNextBlocks().at(1))->getTrackCircuitData();
                    }
                }
            }else{
                redLine.at(blockNum + 1)->setTrainPresent(true);
                return redLine.at(blockNum + 1)->getTrackCircuitData();
            }
        }
    }
}
//Params: uint8_t, int, bool
//Returns: uint16_t
//Desc: handles the train info sent to Track Model by the Train Model
uint16_t Track::handleBeaconTrainInfo(uint8_t currBlock, int ID, bool line){

     int blockNum = (currBlock) & 0xFF;
     if(blockNum != 0){
         blockNum = blockNum - 1;
     }

    if(line == 1){
        if(greenLine.at(blockNum)->getBeaconPresent() == true){
            return greenLine.at(blockNum)->getBeaconData();
        }else{
            return 0;
        }
    }else{
        if(redLine.at(blockNum)->getBeaconPresent() == true){
            return redLine.at(blockNum)->getBeaconData();
        }else{
            return 0;
        }
    }
}
//toStrings ------------------------------------------------------------
//Params: None
//Returns: string
//Desc: returns the red and green line details as a formatted string
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
//Desc: returns ALL the red and green line details as a formatted string
string Track::toStringDetailed(){
    string retString = "";
    retString = retString + "GREEN LINE: \n";
    for(unsigned int g = 0; g < greenLine.size(); g++){
        retString = retString + greenLine.at(g)->Block::toStringDetailed();
    }
    retString = retString + "\n RED LINE: \n";
    for(unsigned int r = 0; r < redLine.size(); r++){
        retString = retString + redLine.at(r)->Block::toStringDetailed();
    }
    return retString;
}
