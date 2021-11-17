#ifndef WAYSIDE_HW_H
#define WAYSIDE_HW_H

#include<iostream>
#include<vector>
#include<string>
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
    //vector<bool> ifBlockHasSwitch;
    vector<bool> blockSwitchPosition;
    vector<bool> blockCrossingState;
    //vector<bool> ifBlockHasCrossing;
    string dataToArdu;
    string dataFromArdu;
    double suggestedSpeed;
    double commandedSpeed;
    vector<Authority> authority;
    vector<bool> blockOccupany;
    vector<bool> brokenRail;
    bool maintenanceMode;

    //PLC plc;
  public:
    vector<Block> sector;
    PLCController hwPLC;
    void initWayside(vector<Block>); //Initialize Wayside
    int getTrackSize();
    vector<int> getId();
    string getLine();
    void setMode(bool); //Set manual/auto mode
    bool getMode();
    void sendToArduino(int);
    void receiveFromArduino();
    string encode();
    void decode(string);
    void updateWayside();
    void calculateCommandedSpeed();
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
    void runPLC();
    void setMaintenanceMode(bool);
    bool getMaintenanceMode();
    bool ifHWConnected();



};

#endif
