#ifndef SWTRACKCONTROLLER_H
#define SWTRACKCONTROLLER_H
#include "Wayside.h"
//#include "Wayside.cpp"

class SWTrackController
{
private:
    bool manualMode; //Shows if controller is in Manual mode. 0 = Automatic, 1 = Manual
public:
    SWTrackController(); //Creates empty instance of track controller
    void initialize(vector<Block*>,vector<Block*>,bool); //Initializes an empty controller
    SWTrackController(vector<Block*>,vector<Block*>,int,bool); //Takes red model, green model, number of waysides, speed, authority, and mode to create an instance of the SWTrackController
    vector<Block> getHWTrack(); //Returns the track reserved for the HW wayside
    void sanityCheck(); //Prints out vital track data to ensure it has been parsed correctly
    void update(); //Clock-powered function that makes all waysides work in real time
    void plcCheck(); //Runs PLC on each wayside
    void updateWaysides(); //Sends current values to all waysides
    void updateFromWaysides(); //Pull vital info from all SW waysides
    void createWaysides(int); //Initializes a given number of waysides around the track
    vector<Block> setHardwareWayside(int); //Sets a wayside of the given ID to be the hardware-controlled wayside
    vector<Wayside> waysides; //Holds all waysides as part of the track controller
    vector<WayStruct>* wayPtr; //Holds data from all waysides for the CTC to read/update
    vector<Block> redLine; //Holds all info about each block of the red line.
    vector<Block> greenLine; //Holds all info about each block of the green line.
    vector<Block> swich; //Holds the block number of any blocks with broken rails
    vector<Block> crossing; //Holds the block number of any blocks with broken rails
    vector<Block> brokenRail; //Holds the block number of any blocks with broken rails
    vector<Block> maintenance; //Holds the block number of any blocks undergoing maintenance
    vector<Block> trackOccupancy; //Vector of all blocks that have a train on them
    vector<Block> hwTrack; //Blocks reserved for HW Wayside
    int hwWay; //Wayside ID reserved for HW Wayside
    vector<string> alerts; //Vector of alerts
    bool getMode(); //Checks if device is in manual mode
    void setMode(bool); //Sets device to the proper mode
    bool addMaintenance(Block); //Sets a block of given ID as undergoing maintenance
    bool endMaintenance(Block); //Removes a block from the maintenance list
    vector<Block> getMaintenance(); //Produces a list of all blocks undergoing maintenance
    bool addBrokenRail(Block); //Sets a rail as being broken
    bool fixBrokenRail(Block); //Removes a rail from the broken rail list
    vector<Block> getBrokenRails(); //Produces a list of all broken rails
    bool switchTrack(Block); //Detect which wayside contains a given block, and switch the given track
    bool toggleCrossing(Block); //Detect which wayside contains a given crossing, and activate/deactivate it
    void getTrackOccupancy(); //Fetches track occupancy from all waysides
    void testValues(); //Spits out all relavent values for testing purposes
};

#endif
