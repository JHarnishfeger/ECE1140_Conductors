#ifndef WAYSIDE_H
#define WAYSIDE_H

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <math.h>
using std::vector;
//#include "Block.cpp"
#include "PLCController.h"
#include "WayStruct.h"
//#include "PLCController.cpp"

class Wayside
{
private:
    vector<Block> brokenRail; //Holds the block number of any blocks with broken rails
    vector<Block> maintenance; //Holds the block number of any blocks undergoing maintenance
    vector<string> alerts; //Vector of alerts
    double suggestedSpeed; //Current suggested speed (imperial units)
    double commandedSpeed; //Current commanded speed (imperial units)
    vector<Authority> authority; //Current authority (imperial units)
    bool manualMode; //Shows if controller is in maintenance mode. 0 = Automatic, 1 = Manual
    bool line; //Indicates if wayside is on red line (0) or green line (1).
    int id; //The numerical ID of the wayside
public:
    Wayside(vector<Block>,bool); //Initialize wayside
    Wayside(); //Initialize Empty Wayside
    Wayside& operator=(Wayside&); //Copy wayside
    void initialize(); //Sets up module and initializes sub-modules and GUI
    void update(); //Sets current values upon being called, runs wayside in real time
    void updateNoPLC(); //Update method without running PLC (not in use)
    bool detectTrack(); //Detects any notable scenarios in the track using the PLC program
    int getID(); //Gets the wayside's ID
    void setID(int); //Sets the wayside's ID
    bool getLine(); //Gets the line that the wayside is on (Red = 0, Green = 1)
    void setLine(bool); //Sets the line that the wayside is on (Red = 0, Green = 1)
    double getSuggestedSpeed(); //Returns current suggested speed (imperial units)
    void setSuggestedSpeed(double); //Sets current suggested speed (imperial units)
    double getCommandedSpeed(); //Returns current commanded speed (imperial units)
    void setCommandedSpeed(double); //Sets current commanded speed (imperial units)
    vector<Authority> getAuthority(); //Returns current authority (imperial units)
    void setAuthority(vector<Authority>); //Sets current authority (imperial units)
    void addBrokenRail(Block); //Sets a rail of given ID as being broken
    void fixBrokenRail(Block); //Removes a rail from the broken rail list
    vector<Block> getBrokenRails(); //Produces a list of all broken rails
    void addMaintenance(Block); //Sets a block of given ID as undergoing maintenance
    void endMaintenance(Block); //Removes a block from the maintenance list
    vector<Block> getMaintenance(); //Produces a list of all blocks undergoing maintenance
    void addAlert(string); //Adds an alert to the list
    vector<string> getAlerts(); //Produces a list of all alerts
    void clearAlerts(); //Clears alert vector
    bool getMode(); //Checks if device is in maintenance mode
    void setMode(bool); //Sets device to the proper mode
    bool switchTrack(Block&); //Switches a track
    bool toggleCrossing(Block&); //Toggles a crossing
    vector<Block> getTrackOccupancy(); //Fetches track occupancy over sector
    void importPLC(string); //Imports given filename to PLC
    bool runPLC(); //Runs PLC over all blocks
    //void runPLCOnce(int);
    bool updateFromPLC(); //Retrieve updated data from PLCController
    void wayStrInit(); //Sets up WayStruct
    vector<Block> trackOccupancy; //Holds the blocks of where any trains are currently on the track
    vector<Block> swich; //Holds the block number of any blocks with broken rails
    vector<Block> crossing; //Holds the block number of any blocks with broken rails
    vector<Block> sector; //Holds all info about each block associated with the current wayside
    WayStruct wayStr; //WayStruct for this wayside
    PLCController plc; //Controller for the PLC program
};

#endif
