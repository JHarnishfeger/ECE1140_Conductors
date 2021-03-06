#ifndef HWTRACKCONTROLLER_H
#define HWTRACKCONTROLLER_H

#include<iostream>
#include<vector>
#include"Wayside_HW.h"

class HWTrackController{

private:
  WayStruct *WayStruPtr;
  WayStruct wayStrHW;
  Wayside_HW *WaysideHWptr;
  Wayside_HW WaysideHW;
  vector<Block> assignedTrack;
  void setBlocks(vector<Block>);
  void creatWayside();
  bool manualControlMode; //0:auto, 1: manual
public:
  HWTrackController();
  ~HWTrackController();
  void initializeHW(vector<Block>);
  Wayside_HW* getWayside();
  int getTrackSize();
  void setControlMode(bool);
  void selectBlock_Manual(int);
  WayStruct* getWayStructHW();
  void updateHWWayside();
};

#endif
