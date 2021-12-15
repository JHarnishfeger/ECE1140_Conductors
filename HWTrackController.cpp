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

int HWTrackController::getTrackSize(){
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
