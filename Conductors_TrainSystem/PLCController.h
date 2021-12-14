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
    vector<bool> NB; //Binary string representing next branch to be taken (0 = Switch Pos 0, 1 = Switch Pos 1)
    vector<bool> TL; //Binary string representing traffic light location (0 = Not Light, 1 = Light)
    vector<bool> TC; //Binary string representing traffic light color (0 = Red, 1 = Green)
    vector<vector<bool>> checkVecs; //Vectors to be filled with the results of checking each value a second time
    vector<vector<bool>> oldVecs; //Vectors holding the previous values of the PLC execution
    vector<Block> track; //All blocks controlled by wayside, in order to create boolean vectors
    vector<Authority> auth; //Authority data for all applicable branches
    int getPos(); //Retrieves iterator
    void setPos(int); //Sets iterator
    string getFilename();
    bool switchTrack(); //Switches a junction at target the other direction. Returns 1 if the function was successful, 0 if an error occured.
    bool toggleCrossing(); //Activates/Deactivates a railroad crossing at target, and the lights. Returns 1 if the function was successful, 0 if an error occured.
    void importPLC(string);
    bool runPLC();
    void execute();
    //void runPLCOnce();
    bool verifyPLC();
};

#endif
