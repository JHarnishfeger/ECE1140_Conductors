#include"HWTrackController.h"

HWTrackController::HWTrackController(vector<Block> as){
  setBlocks(as);
  creatWayside();
}
void HWTrackController::setBlocks(vector<Block> assiTrack){
  assignedTrack = assiTrack;
}

void HWTrackController::creatWayside(){
  WaysideHW.initWayside(assignedTrack);
  WaysideHWptr = &WaysideHW;
}

Wayside* HWTrackController::getWayside(){
  return WaysideHWptr;
}

void HWTrackController::setSuggestedSpeed(vector<double> ss){
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

vector<double> HWTrackController::getCommandedSpeed(){
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

void HWTrackController::setAuthority(vector<double> aut){
  WaysideHWptr->setAuthority(aut);
}

vector<double> HWTrackController::getAuthority(){
  return WaysideHWptr->getAuthority();
}

int HWTrackController::getTrackSize(){
  //cout << WaysideHWptr->getTrackSize() << endl;
  return WaysideHWptr->getTrackSize();
}

void HWTrackController::setControlMode(bool m){
  manualControlMode = m;
}

void HWTrackController::selectBlock_Manual(int id){
  string comm = std::to_string(id);
//  cout << comm << endl;
  writeToArdu(comm);
}
//importPLC();
