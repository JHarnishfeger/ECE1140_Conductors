#ifndef HWTRACKCONTROLLER_H
#define HWTRACKCONTROLLER_H

#include<iostream>
#include<vector>
#include"Wayside.cpp"

class HWTrackController{

private:
  Wayside *WaysideHWptr;
  Wayside WaysideHW;
  vector<Block> assignedTrack;
  void setBlocks(vector<Block>);
  void creatWayside();
  bool manualControlMode; //0:auto, 1: manual
public:
  HWTrackController();
  HWTrackController(vector<Block>);
  Wayside* getWayside();
  void setSuggestedSpeed(vector<double>);
  vector<double> getCommandedSpeed();
  void setAuthority(vector<double>);
  vector<double> getAuthority();
  int getTrackSize();
  void setControlMode(bool);
  void selectBlock_Manual(int);
  //importPLC();
};

#endif
