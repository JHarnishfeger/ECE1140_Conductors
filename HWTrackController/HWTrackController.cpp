#include"HWTrackController.h"

HWTrackController::HWTrackController(){
  WayStruPtr = new WayStruct;
}
void HWTrackController::initializeHW(vector<Block> as){
  setBlocks(as);
  creatWayside();
}
void HWTrackController::setBlocks(vector<Block> assiTrack){
  assignedTrack = assiTrack;
}
HWTrackController::~HWTrackController(){
  delete WayStruPtr;
}

void HWTrackController::creatWayside(){
  WaysideHW.initWayside(assignedTrack);
  WaysideHWptr = &WaysideHW;
}

Wayside* HWTrackController::getWayside(){
  return WaysideHWptr;
}

void HWTrackController::setSuggestedSpeed(double ss){
  WaysideHWptr->setSuggestedSpeed(ss);
  /*
  vector<double> zeze = WaysideHWptr->getSuggestedSpeed();
  int size0 = zeze.size();
  cout << 'i' << size0 << endl;
  for(int i = 0; i < size0; i++){
    cout << 'i' << zeze[i] << endl;
  }
  vector<double> hehe = WaysideHW.getSuggestedSpeed();
  int size = hehe.size();
  cout << 'h' << size << endl;
  for(int i = 0; i < size; i++){
    cout << 'h' << hehe[i] << endl;
  }
  */
}

double HWTrackController::getCommandedSpeed(){
  /*
  vector<double> zeze = WaysideHWptr->getCommandedSpeed();
  int size0 = zeze.size();
  cout << 'i' << size0 << endl;
  for(int i = 0; i < size0; i++){
    cout << 'i' << zeze[i] << endl;
  }
  */
  return WaysideHWptr->getCommandedSpeed();
}

void HWTrackController::setAuthority(vector<Authority> aut){
  WaysideHWptr->setAuthority(aut);
}

vector<Authority> HWTrackController::getAuthority(){
  return WaysideHWptr->getAuthority();
}

int HWTrackController::getTrackSize(){
  //cout << WaysideHWptr->getTrackSize() << endl;
  return WaysideHWptr->getTrackSize();
}

void HWTrackController::setControlMode(bool m){
  manualControlMode = m;
  WaysideHWptr->setMode(m);
}

void HWTrackController::selectBlock_Manual(int id){
  //string comm = std::to_string(id);
//  cout << comm << endl;
  WaysideHW.sendToArduino(id);
}

void HWTrackController::updateTrack(){
  int size = getTrackSize();
  for(int i = 0; i< size; i++){
    double sug = WaysideHW.getSuggestedSpeed();
    assignedTrack[i].setSuggestedSpeed(sug);
    vector<bool> trackSide = WaysideHW.getBlockSwitchPosition();
    assignedTrack[i].setSwitch(trackSide[i]);
    vector<bool> crossingS = WaysideHW.getBlockCrossingState();
    assignedTrack[i].setCrossing(crossingS[i]);
    vector<bool> occu = WaysideHW.getBlockOccupancy();
    assignedTrack[i].setTrainPresent(occu[i]);
    vector<bool> brok = WaysideHW.getBrokenRail();
    assignedTrack[i].setBrokenCircuit(brok[i]);
  }
}

void HWTrackController::updateFromWayStruc(){
  double ss = WayStruPtr->suggestedSpeed;
  vector<Authority> aut = WayStruPtr->auth;
  setSuggestedSpeed(ss);
  setAuthority(aut);
}

void HWTrackController::updateToWayStruc(){
  WayStruPtr->sector = assignedTrack;
}

//importPLC();
