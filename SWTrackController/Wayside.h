class Wayside
{
private:
    vector<Block> brokenRail; //Holds the block number of any blocks with broken rails
    vector<Block> maintenance; //Holds the block number of any blocks undergoing maintenance
    double speed; //Current suggested speed (imperial units)
    double authority; //Current authority (imperial units)
    bool manualMode; //Shows if controller is in maintenance mode. 0 = Automatic, 1 = Manual
    bool line; //Indicates if wayside is on red line (0) or green line (1).
public:
    Wayside(vector<Block>,bool); //Initialize wayside
    void initialize(); //Sets up module and initializes sub-modules and GUI
    void detectTrack(); //Detects any notable scenarios in the track using the PLC program
    double getSpeed(); //Returns current suggested speed (imperial units)
    void setSpeed(double); //Sets current suggested speed (imperial units)
    double getAuthority(); //Returns current authority (imperial units)
    void setAuthority(double); //Sets current authority (imperial units)
    void addBrokenRail(Block); //Sets a rail of given ID as being broken
    void fixBrokenRail(Block); //Removes a rail from the broken rail list
    vector<Block> getBrokenRails(); //Produces a list of all broken rails
    void addMaintenance(Block); //Sets a block of given ID as undergoing maintenance
    void endMaintenance(Block); //Removes a block from the maintenance list
    vector<int> getMaintenance(); //Produces a list of all blocks undergoing maintenance
    bool getMode(); //Checks if device is in maintenance mode
    void setMode(bool); //Sets device to the proper mode
    bool switchTrack(Block); //Switches a track
    bool toggleCrossing(Block); //Toggles a crossing
    //getTrackOcccupancy
    vector<Block> trackOccupancy; //Holds the blocks of where any trains are currently on the track
    vector<Block> sector; //Holds all info about each block associated with the current wayside
    PLCController plc; //Controller for the PLC program
};

Wayside::Wayside(vector<Block> track, bool ln)
{
    sector = track;
    PLCController p(sector);
    plc = p;
    line = ln;
}

void Wayside::detectTrack()
{
    plc.checkTrack();
}

double Wayside::getSpeed()
{
    return speed;
}

void Wayside::setSpeed(double sp)
{
    speed = sp;
}

double Wayside::getAuthority()
{
    return authority;
}

void Wayside::setAuthority(double au)
{
    authority = au;
}

void Wayside::addBrokenRail(Block i)
{
    brokenRail.push_back(i);
}

void Wayside::fixBrokenRail(Block r)
{
    bool flag=0;
    for(int i=0;i<brokenRail.size();i++)
    {
        if(brokenRail[i].getID()==r.getID())
        {
            brokenRail.erase(brokenRail.begin()+i);
            flag = 1;
        }
        if(flag)
            break;
    }
}

vector<Block> Wayside::getBrokenRails()
{
    return brokenRail;
}

void Wayside::addMaintenance(Block i)
{
    maintenance.push_back(i);
}

void Wayside::endMaintenance(Block m)
{
    bool flag=0;
    for(int i=0;i<brokenRail.size();i++)
    {
        if(brokenRail[i].getID()==m.getID())
        {
            brokenRail.erase(brokenRail.begin()+i);
            flag = 1;
        }
        if(flag)
            break;
    }
}

vector<Block> Wayside::getMaintenance()
{
    return maintenance;
}

bool Wayside::getMode()
{
    return manualMode;
}

void Wayside::setMode(bool m)
{
    manualMode = m;
}

bool Wayside::switchTrack(Block switch)
{
    plc.switchTrack(switch);
}

bool Wayside::toggleCrossing(Block crossing)
{
    plc.toggleCrossing(crossing);
}
