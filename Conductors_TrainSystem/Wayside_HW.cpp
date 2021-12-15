#include"Wayside_HW.h"
#include"SerialPortTrack.h"

char* unconstchar(const char* s) {
    if(!s)
      return NULL;
    int i;
    char* res = NULL;
    res = (char*) malloc(strlen(s)+1);
    if(!res){
        fprintf(stderr, "Memory Allocation Failed! Exiting...\n");
        exit(EXIT_FAILURE);
    } else{
        for (i = 0; s[i] != '\0'; i++) {
            res[i] = s[i];
        }
        res[i] = '\0';
        return res;
    }
}

const char *port0 = "\\\\.\\COM4";
char output[MAX_DATA_LENGTH];
char incoming[MAX_DATA_LENGTH];
char *port = unconstchar(port0);
SerialPortTrack ardu(port);

bool ifArduConnected(){
  return ardu.isConnected();
}

void writeToArdu(string com){
  string command = com;
  char *charArray = new char[command.size() + 1];
  copy(command.begin(), command.end(), charArray);
  charArray[command.size()] = '\n';

  ardu.writeSerialPort(charArray, MAX_DATA_LENGTH);

  delete [] charArray;
}

void receiveFromArdu(){
  ardu.readSerialPort(output, MAX_DATA_LENGTH);


}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
Wayside_HW::Wayside_HW(){

}
void Wayside_HW::initWayside(vector<Block> track){
  sector = track;
  PLCController p(track);
  hwPLC = p;
  wayStrInit();

  line = track[0].getLine();

  manualMode = 1; //set to manual mode
  maintenanceMode = 0;

  trackSize = track.size();
  suggestedSpeed=0;
  commandedSpeed=0;
  authority.resize(trackSize);

  for(int i = 0; i < trackSize; i++){
    int id = track[i].getBlockNumber();
    blockIDs.push_back(id);
    bool po = track[i].getSwitchStatus();
    blockSwitchPosition.push_back(po);
    bool cro = track[i].getCrossingStatus();
    blockCrossingState.push_back(cro);
    bool pre =track[i].getTrainPresent();
    blockOccupany.push_back(pre);
    bool bro = track[i].getRailStatus();
    brokenRail.push_back(bro);

    if(sector[i].getType()=="SWITCH"){
        ifBlockHasSwitch.push_back(1);
    }else{
        ifBlockHasSwitch.push_back(0);
    }

    if(sector[i].getType()=="CROSSING"){
        ifBlockHasCrossing.push_back(1);
    }else{
        ifBlockHasCrossing.push_back(0);
    }

    if(sector[i].getType()=="SWITCH")
        swich.push_back(sector[i]);
    else if(sector[i].getType()=="CROSSING")
        crossing.push_back(sector[i]);


  }
}

int Wayside_HW::getTrackSize(){
  //cout << trackSize << endl;
  return trackSize;
}

string Wayside_HW::getLine(){
  return line;
}

vector<int> Wayside_HW::getId(){
  return blockIDs;
}

void Wayside_HW::setMode(bool m){
  manualMode = m;
}

bool Wayside_HW::getMode(){
  return manualMode;
}

void Wayside_HW::sendToArduino(int s){
  string c = to_string(s);
  if(s>=0 && s<=9){
      c = "0" + c;
  }
  writeToArdu(c);
}
int Wayside_HW::receiveFromArduino(){
  receiveFromArdu();
  string id, id0;
  char tSwicth, crossing;
  string temp = output;
  string out = "";
  int outSize = temp.size();
  //cout <<"output = "<< output << endl;

  /*
  for(int i = 0; i < temp.size(); i++){
      cout << "temp=" << temp[i] << endl;
  }*/

  for (int i = 4;i < outSize; i++){
    if(output[i] != '\n')
    out = out + output[i];
  }
  if(out == ""){
      return 0;
  }
  //cout <<"out = "<< out << endl;
  id0 = out;
  id0.pop_back();
  id0.pop_back();
  id = id0;
  //cout << "id=" << id << endl;
  tSwicth = out[2];
  crossing = out[3];
  int idd;
  bool tSwicthh, crossingg;
  idd = stoi(id);
  if(tSwicth=='0'){
    tSwicthh = 0;
  }else if(tSwicth=='1'){
    tSwicthh = 1;
  }
  if(crossing == '0'){
    crossingg = 0;
  }else if(crossing == '1'){
    crossingg = 1;
  }
  for(int i = 0; i < trackSize; i++){
    if(blockIDs[i] == idd){
        if(!sector[i].getTrainPresent()){
              blockSwitchPosition[i] = tSwicthh;
              blockCrossingState[i] = crossingg;
              sector[i].setSwitchStatus(tSwicthh);
              sector[i].setCrossingStatus(crossingg);
        }else{
            return -1;
        }
    }
  }
  return 1;
}


vector<bool> Wayside_HW::getIfBlockHasSwitch(){
    return ifBlockHasSwitch;
}

vector<bool> Wayside_HW::getIfBlockHasCrossing(){
    return ifBlockHasCrossing;
}

vector<bool> Wayside_HW::getBlockSwitchPosition(){
  return blockSwitchPosition;
}

vector<bool> Wayside_HW::getBlockCrossingState(){
  return blockCrossingState;
}

vector<bool> Wayside_HW::getBrokenRail(){
  return brokenRail;
}

void Wayside_HW::setBlockOccupancy(vector<bool> occ){
  int size = occ.size();
  for(int i = 0; i < size; i++){
    blockOccupany[i] = occ[i];
  }
}
vector<bool> Wayside_HW::getBlockOccupancy(){
  return blockOccupany;
}


void Wayside_HW::setMaintenanceMode(bool m){
  maintenanceMode = m;
}

bool Wayside_HW::getMaintenanceMode(){
  return maintenanceMode;
}


bool Wayside_HW::ifHWConnected(){
    return ifArduConnected();
}


void Wayside_HW::importPLC(string filename){
    hwPLC.track = sector;
    hwPLC.importPLC(filename);
}

bool Wayside_HW::runPLC(){
    bool correct;
    hwPLC.auth = authority;
    hwPLC.track = sector;
    hwPLC.execute();
    correct = hwPLC.verifyPLC();
    updatetFromPLC();
    return correct;
}

bool Wayside_HW::updatetFromPLC(){
    bool change = 0;
    if(manualMode == 0){
        for(int i = 0; i < sector.size(); i++){
            if(sector[i].getSwitchStatus() != hwPLC.SW[i]){
                change = 1;
                sector[i].setSwitchStatus(hwPLC.SW[i]);
                blockSwitchPosition[i] = hwPLC.SW[i];
            }
            if(sector[i].getCrossingStatus() != hwPLC.CR[i]){
                change = 1;
                sector[i].setCrossingStatus(hwPLC.CR[i]);
                blockCrossingState[i] = hwPLC.CR[i];
            }
        }
    }
    return change;
}



void Wayside_HW::wayStrInit(){
    wayStr.suggestedSpeed = suggestedSpeed;
    wayStr.id = 0;
    wayStr.sector = sector;
    wayStr.auth = authority;
}

void Wayside_HW::updateFromWayStr(){
    suggestedSpeed = wayStr.suggestedSpeed;
    //sector = wayStr.sector;
    authority = wayStr.auth;
}

void Wayside_HW::updateToWayStr(){
    wayStr.sector = sector;
    wayStr.auth = authority;
    wayStr.id = 0;
}

void Wayside_HW::updateTrack(vector<Block> t){
    sector = t;
    int trackSize = t.size();
    blockOccupany.clear();
    for(int i = 0; i < trackSize; i++){
        blockOccupany.push_back(t[i].getTrainPresent());
    }
    detectTrack();
}

bool Wayside_HW::detectTrack(){
    bool found = 0;
    if(!runPLC())
        cout << "From detectTrack: PLC output was incorrect. Track wasnot changed." << endl;
    for(int i = 0; i < sector.size(); i++){
        for(int j = 0; j < swich.size(); j++){
            if(swich[j].getSwitchStatus() != sector[i].getSwitchStatus() && swich[j].getBlockNumber() == sector[i].getBlockNumber()){
                cout << "Switch " << to_string(swich[j].getBlockNumber()) << " Toggled." << endl;
                swich[j].setSwitchStatus(sector[i].getSwitchStatus());
                blockSwitchPosition[i] = swich[j].getSwitchStatus();
            }
        }
        for(int j = 0; j < crossing.size(); j++){
            if(crossing[j].getCrossingStatus() != sector[i].getCrossingStatus() && crossing[j].getBlockNumber() == sector[i].getBlockNumber()){
                cout << "Crossing " << to_string(crossing[j].getBlockNumber()) << " Toggled." << endl;
                crossing[j].setCrossingStatus(sector[i].getCrossingStatus());
                blockCrossingState[i] = crossing[j].getCrossingStatus();
            }
        }
        for(int j = 0; j < brokenRail.size(); j++){
            if(brokenRail[j] != sector[i].getRailStatus() && j == i){
                cout << "Rail " << i << " Broken." << endl;
                brokenRail[j] = sector[i].getRailStatus();
                found = 1;
            }
        }
        //if(!found && sector[i].getRailStatus() == true)
            //brokenRail.push_back(sector[i]);
        if(hwPLC.SS[i] == 1)
            sector[i].setSuggestedSpeed(sector[i].getSpeedLimit());
        if(hwPLC.ST[i] == 1)
            sector[i].setSuggestedSpeed(0);
        else
            sector[i].setSuggestedSpeed(sector[i].getSpeedLimit());
    }
    return found;
}

WayStruct Wayside_HW::getWayStruct(){
    return wayStr;
}

void Wayside_HW::updateHW(){

    //if(manualMode == 0){
        updateFromWayStr();
        detectTrack();
        updateToWayStr();
    //}else{
        //updateFromWayStr();
    //}

}
