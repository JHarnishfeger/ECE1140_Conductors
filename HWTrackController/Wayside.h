#ifndef WAYSIDE_H
#define WAYSIDE_H

#include<iostream>
#include<vector>
#include<string>
#include"Block.cpp"
#include<stdlib.h>
#include"serialCommunication.cpp"
using namespace std;


class Wayside{
  private:
    char line;
    bool manualMode; // 1: manualMode, 0: auto mode
    vector<int> blockIDs;
    int trackSize; //# blocks
    //vector<bool> ifBlockHasSwitch;
    vector<bool> blockSwitchPosition;
    vector<bool> blockCrossingState;
    //vector<bool> ifBlockHasCrossing;
    string dataToArdu;
    string dataFromArdu;
    vector<double> suggestedSpeed;
    vector<double> commandedSpeed;
    vector<double> authority;
    vector<bool> blockOccupany;
    vector<bool> brokenRail;
    bool maintenanceMode;

    //PLC plc;
  public:
    Wayide();
    void initWayside(vector<Block>); //Initialize Wayside
    int getTrackSize();
    vector<int> getId();
    char getLine();
    void setMode(bool); //Set manual/auto mode
    bool getMode();
    void sendToArduino();
    void receiveFromArduino();
    string encode();
    void decode(string);
    void updateWayside();
    void calculateCommandedSpeed();
    void setSuggestedSpeed(vector<double>);
    vector<double> getSuggestedSpeed();
    vector<double> getCommandedSpeed();
    void setAuthority(vector<double>);
    vector<double> getAuthority();
    vector<bool> getBlockSwitchPosition();
    vector<bool> getBlockCrossingState();
    vector<bool> getBrokenRail();
    void setBlockOccupancy(vector<bool>);
    vector<bool> getBlockOccupancy();
    void runPLC();
    void setMaintenanceMode(bool);
    bool getMaintenanceMode();


};

#endif
