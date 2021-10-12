#ifndef WAYSIDE_H
#define WAYSIDE_H

class Wayside
{
private:
    vector<Block> brokenRail; //Holds the block number of any blocks with broken rails
    vector<Block> maintenance; //Holds the block number of any blocks undergoing maintenance
    double speed; //Current suggested speed (imperial units)
    double authority; //Current authority (imperial units)
    bool manualMode; //Shows if controller is in maintenance mode. 0 = Automatic, 1 = Manual
    bool line; //Indicates if wayside is on red line (0) or green line (1).
    int id;
public:
    Wayside(vector<Block>,bool); //Initialize wayside
    Wayside operator=(Wayside); //Copy wayside
    void initialize(); //Sets up module and initializes sub-modules and GUI
    bool detectTrack(); //Detects any notable scenarios in the track using the PLC program
    int getID(); //Gets the wayside's ID
    void setID(int); //Sets the wayside's ID
    bool getLine(); //Gets the line that the wayside is on (Red = 0, Green = 1)
    double getSpeed(); //Returns current suggested speed (imperial units)
    void setSpeed(double); //Sets current suggested speed (imperial units)
    double getAuthority(); //Returns current authority (imperial units)
    void setAuthority(double); //Sets current authority (imperial units)
    void addBrokenRail(Block); //Sets a rail of given ID as being broken
    void fixBrokenRail(Block); //Removes a rail from the broken rail list
    vector<Block> getBrokenRails(); //Produces a list of all broken rails
    void addMaintenance(Block); //Sets a block of given ID as undergoing maintenance
    void endMaintenance(Block); //Removes a block from the maintenance list
    vector<Block> getMaintenance(); //Produces a list of all blocks undergoing maintenance
    bool getMode(); //Checks if device is in maintenance mode
    void setMode(bool); //Sets device to the proper mode
    bool switchTrack(Block); //Switches a track
    bool toggleCrossing(Block); //Toggles a crossing
    vector<Block> getTrackOccupancy(); //Fetches track occupancy over sector
    vector<Block> trackOccupancy; //Holds the blocks of where any trains are currently on the track
    vector<Block> sector; //Holds all info about each block associated with the current wayside
    PLCController plc; //Controller for the PLC program
};

#endif
