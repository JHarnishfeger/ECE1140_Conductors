#ifndef PLCCONTROLLER_H
#define PLCCONTROLLER_H

#include <sstream>
using std::stringstream;

class PLCController
{
private:
    string filename;
    int pos;
public:
    PLCController(); //Empty constructor
    PLCController(vector<Block>,vector<Block>); //Initializes PLC Controller
    PLCController& operator=(PLCController&); //Allows copying of object
    vector<bool> TR; //Binary string representing track occupancy (1 = Occupied, 0 = Open)
    vector<bool> SL; //Binary string representing switch location (1 = Switch, 0 = Not Switch)
    vector<bool> SW; //Binary string representing switch position (1 = 1 Position, 0 = 0 Position)
    vector<bool> CL; //Binary string representing crossing location (1 = Crossing, 0 = Not Crossing)
    vector<bool> CR; //Binary string representing switch position (1 = Active, 0 = Inactive)
    vector<Block> track; //All blocks controlled by wayside, in order to create boolean vectors
    vector<Block> occupancy; //All blocks that are occupied by trains
    vector<string> branchOccupancy; //All branches in the sector that are occupied
    int getPos(); //Retrieves iterator
    void setPos(int); //Sets iterator
    bool branchOccupied(Block); //Checks if branch is occupied
    bool checkTrack(vector<Block>); //Uses PLC program to check for any actionable situations on the latest track. Returns 1 if the track has been changed.
    bool checkSwitches(bool,bool); //Uses PLC program to check for switches to be switched, returns 1 on appplicable block. Part of checkTrack().
    bool checkRails(); //Uses PLC program to check for broken rails, returns 1 on applicable block. Part of checkTrack().
    bool checkCrossings(bool); //Uses PLC program to check for railroad crossings that need to be activated, returns 1 on applicable block. Part of checkTrack().
    bool setTrack(bool); //Switches a junction at target. 0 = Left, 1 = Right. Returns 1 if the function was successful, 0 if an error occured.
    bool switchTrack(); //Switches a junction at target the other direction. Returns 1 if the function was successful, 0 if an error occured.
    bool toggleCrossing(); //Activates/Deactivates a railroad crossing at target, and the lights. Returns 1 if the function was successful, 0 if an error occured.
    void importPLC(string);
    void runPLC();
    void execute();
    void runPLCOnce();
};

#endif
