#include"Wayside_HW.h"
#include"SerialPort.h"

char *port = "\\\\.\\COM4";
char output[MAX_DATA_LENGTH];
char incoming[MAX_DATA_LENGTH];

SerialPort ardu(port);


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

  //cout << "zhe" <<output << endl;

}

/*
int char_to_int(char c){
  int re = -1;
  if(c == '0'){
    re = 0;
  }else if(c == '1'){
    re = 1;
  }else if(c == '2'){
    re = 2;
  }else if(c == '3'){
    re = 3;
  }else if(c == '4'){
    re = 4;
  }else if(c == '5'){
    re = 5;
  }else if(c == '6'){
    re = 6;
  }else if(c == '7'){
    re = 7;
  }else if(c == '8'){
    re = 8;
  }else if(c == '9'){
    re = 9;
  }
  return re;
}

*/


void Wayside_HW::initWayside(vector<Block> track){
  sector = track;
  PLCController p(track);
  hwPLC = p;

  line = track[0].getLine();

  manualMode = 0; //set to auto mode
  maintenanceMode = 0;

  trackSize = track.size();
  suggestedSpeed=0;
  commandedSpeed=0;
  authority.resize(trackSize);

  for(int i = 0; i < trackSize; i++){
    int id = track[i].getId();
    blockIDs.push_back(id);
    bool po = track[i].getSwitchStatus();
    blockSwitchPosition.push_back(po);
    bool cro = track[i].getCrossingStatus();
    blockCrossingState.push_back(cro);
    bool pre =track[i].getTrainPresent();
    blockOccupany.push_back(pre);
    bool bro = track[i].getRailStatus();
    brokenRail.push_back(bro);

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
  writeToArdu(c);
}
void Wayside_HW::receiveFromArduino(){
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
      blockSwitchPosition[i] = tSwicthh;
      blockCrossingState[i] = crossingg;
      cout << "id: " << blockIDs[i] << endl;
      cout << "switch: " << blockSwitchPosition[i] << endl;
    cout << "Crossing: " << blockCrossingState[i] << endl;
    }
  }
}

//string encode();
//void decode(string);

//void updateWayside();

void Wayside_HW::calculateCommandedSpeed(){

    commandedSpeed = suggestedSpeed - 1.1;

}

void Wayside_HW::setSuggestedSpeed(double sugg){

    suggestedSpeed = sugg;

}

double Wayside_HW::getSuggestedSpeed(){
  return suggestedSpeed;
}

double Wayside_HW::getCommandedSpeed(){
  calculateCommandedSpeed();
  return commandedSpeed;
}

void Wayside_HW::setAuthority(vector<Authority> au){
  int size = au.size();
  for(int i = 0; i < size; i++){
    authority[i] = au[i];
  }
}

vector<Authority> Wayside_HW::getAuthority(){
  return authority;
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

//void runPLC();

void Wayside_HW::setMaintenanceMode(bool m){
  maintenanceMode = m;
}

bool Wayside_HW::getMaintenanceMode(){
  return maintenanceMode;
}
/*
bool Wayside::ifArduConnected(){
  return ardu.isConnected();
}
*/

bool Wayside_HW::ifHWConnected(){
    return ifArduConnected();
}
