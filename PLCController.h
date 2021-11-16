#ifndef PLCCONTROLLER_H
#define PLCCONTROLLER_H

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <sstream>
#include "Block.h"
#include "Authority.h"
using std::vector;
using std::string;
using std::stringstream;


class PLCController
{
private:
    string filename;
    int pos;
public:
    PLCController(); //Empty constructor
    PLCController(vector<Block>); //Initializes PLC Controller
    PLCController& operator=(PLCController&); //Allows copying of object
    vector<bool> TR; //Binary string representing track occupancy (1 = Occupied, 0 = Open)
    vector<bool> SL; //Binary string representing switch location (1 = Switch, 0 = Not Switch)
    vector<bool> SW; //Binary string representing switch position (1 = 1 Position, 0 = 0 Position)
    vector<bool> CL; //Binary string representing crossing location (1 = Crossing, 0 = Not Crossing)
    vector<bool> CR; //Binary string representing switch position (1 = Active, 0 = Inactive)
    vector<bool> BR; //Binary string representing broken rail status (1 = Broken, 0 = Unbroken)
    vector<bool> SS; //Binary string representing a block where speed limit is violated (1 = Violated, 0 = Safe)
    vector<bool> SR; //Binary string representing blocks that need to be reduced to speed limit (1 = Reset, 0 = Keep)
    vector<bool> ST; //Binary string representing blocks that the commanded speed should be 0 (1 = Set 0, 0 = Keep)
    vector<bool> SA; //Binary string representing station location (1 = Station, 0 = Not Station)
    vector<bool> AU; //Binary string representing authority (1 = Auth on Block, 2 = No Auth on Block)
    vector<vector<bool>> checkVecs;
    vector<vector<bool>> oldVecs;
    vector<Block> track; //All blocks controlled by wayside, in order to create boolean vectors
    vector<Authority> auth;
    vector<string> branchOccupancy; //All branches in the sector that are occupied
    int getPos(); //Retrieves iterator
    void setPos(int); //Sets iterator
    string getFilename();
    bool branchOccupied(Block); //Checks if branch is occupied
    bool checkTrack(vector<Block>); //Uses PLC program to check for any actionable situations on the latest track. Returns 1 if the track has been changed.
    bool checkSwitches(bool,bool); //Uses PLC program to check for switches to be switched, returns 1 on appplicable block. Part of checkTrack().
    bool checkRails(); //Uses PLC program to check for broken rails, returns 1 on applicable block. Part of checkTrack().
    bool checkCrossings(bool); //Uses PLC program to check for railroad crossings that need to be activated, returns 1 on applicable block. Part of checkTrack().
    bool setTrack(bool); //Switches a junction at target. 0 = Left, 1 = Right. Returns 1 if the function was successful, 0 if an error occured.
    bool switchTrack(); //Switches a junction at target the other direction. Returns 1 if the function was successful, 0 if an error occured.
    bool toggleCrossing(); //Activates/Deactivates a railroad crossing at target, and the lights. Returns 1 if the function was successful, 0 if an error occured.
    void importPLC(string);
    bool runPLC();
    void execute();
    //void runPLCOnce();
    bool verifyPLC();
};

#endif
