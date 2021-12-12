#include"HWTrackController.h"

HWTrackController::HWTrackController(){

}

void HWTrackController::initializeHW(vector<Block> as){
  setBlocks(as);
  creatWayside();
}

void HWTrackController::setBlocks(vector<Block> assiTrack){
  assignedTrack = assiTrack;
}

HWTrackController::~HWTrackController(){

}

void HWTrackController::creatWayside(){
  WaysideHW.initWayside(assignedTrack);
  WaysideHWptr = &WaysideHW;
  wayStrHW = WaysideHWptr->getWayStruct();
  WayStruPtr = &wayStrHW;
}

Wayside_HW* HWTrackController::getWayside(){
  return WaysideHWptr;
}

void HWTrackController::setSuggestedSpeed(double ss){
  WaysideHWptr->setSuggestedSpeed(ss);
}

double HWTrackController::getCommandedSpeed(){
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
  WaysideHW.sendToArduino(id);
}

WayStruct* HWTrackController::getWayStructHW(){
    return WayStruPtr;
}

void HWTrackController::updateHWWayside(){
    WaysideHW.updateHW();
    wayStrHW = WaysideHWptr->getWayStruct();
}


/*
void HWTrackController::updateTrack(){
  int size = getTrackSize();
  for(int i = 0; i< size; i++){
    double sug = WaysideHW.getSuggestedSpeed();
    assignedTrack[i].setSuggestedSpeed(sug);
    vector<bool> trackSide = WaysideHW.getBlockSwitchPosition();
    assignedTrack[i].setSwitchStatus(trackSide[i]);
    vector<bool> crossingS = WaysideHW.getBlockCrossingState();
    assignedTrack[i].setCrossingStatus(crossingS[i]);
    vector<bool> occu = WaysideHW.getBlockOccupancy();
    assignedTrack[i].setTrainPresent(occu[i]);
    vector<bool> brok = WaysideHW.getBrokenRail();
    assignedTrack[i].setRailStatus(brok[i]);
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
*/

//importPLC();
