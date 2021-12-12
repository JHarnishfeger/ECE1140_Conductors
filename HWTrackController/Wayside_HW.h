#ifndef WAYSIDE_HW_H
#define WAYSIDE_HW_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
//#include"Block.h"
#include<stdlib.h>
//#include"serialCommunication.h"
#include"WayStruct.h"
#include"PLCController.h"
using namespace std;



class Wayside_HW{
  private:
    string line;
    bool manualMode; // 1: manualMode, 0: auto mode
    vector<int> blockIDs;
    int trackSize; //# blocks
    vector<bool> ifBlockHasSwitch;
    vector<bool> blockSwitchPosition;
    vector<bool> blockCrossingState;
    vector<bool> ifBlockHasCrossing;
    string dataToArdu;
    string dataFromArdu;
    double suggestedSpeed;
    double commandedSpeed;
    vector<Authority> authority;
    vector<bool> blockOccupany;
    vector<bool> brokenRail;
    bool maintenanceMode;
    //PLCController plc;
    //PLC plc;
  public:
    void initWayside(vector<Block>); //Initialize Wayside
    int getTrackSize();
    vector<int> getId();
    string getLine();
    void setMode(bool); //Set manual/auto mode
    bool getMode();
    void sendToArduino(int);
    int receiveFromArduino();
    string encode();
    void decode(string);
    void updateWayside();
    void calculateCommandedSpeed();
    vector<bool> getIfBlockHasSwitch();
    vector<bool> getIfBlockHasCrossing();
    void setSuggestedSpeed(double);
    double getSuggestedSpeed();
    double getCommandedSpeed();
    void setAuthority(vector<Authority>);
    vector<Authority> getAuthority();
    vector<bool> getBlockSwitchPosition();
    vector<bool> getBlockCrossingState();
    vector<bool> getBrokenRail();
    void setBlockOccupancy(vector<bool>);
    vector<bool> getBlockOccupancy();
    void importPLC(string);
    bool runPLC();
    bool updatetFromPLC();
    void wayStrInit();
    void updateHW();
    void updateFromWayStr();
    void updateToWayStr();
    bool detectTrack();
    WayStruct getWayStruct();
    void setMaintenanceMode(bool);
    bool getMaintenanceMode();
    bool ifHWConnected();
    vector<Block> trackOccupancy;
    vector<Block> swich;
    vector<Block> crossing;
    WayStruct wayStr;
    vector<Block> sector;
    PLCController hwPLC;


};

#endif
