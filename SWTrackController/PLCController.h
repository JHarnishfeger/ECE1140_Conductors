class PLCController
{
private:
    ifstream plc;
    int iterator;
public:
    PLCController(vector<Block>);
    PLCController operator=(PLCController); //Allows copying of object
    vector<Block> track;
    Block target;
    int getIterator(); //Retrieves iterator
    void setIterator(int); //Sets iterator
    void checkTrack(); //Uses PLC program to check for any actionable situations.
    bool checkSwitches(); //Uses PLC program to check for switches to be switched, returns 1 on appplicable block. Part of checkTrack().
    bool checkRails(); //Uses PLC program to check for broken rails, returns 1 on applicable block. Part of checkTrack().
    bool checkCrossings(); //Uses PLC program to check for railroad crossings that need to be activated, returns 1 on applicable block. Part of checkTrack().
    bool setTrack(bool); //Switches a junction at target. 0 = Left, 1 = Right. Returns 1 if the function was successful, 0 if an error occured.
    bool switchTrack(); //Switches a junction at target the other direction. Returns 1 if the function was successful, 0 if an error occured.
    bool toggleCrossing(); //Activates/Deactivates a railroad crossing at target, and the lights. Returns 1 if the function was successful, 0 if an error occured.
};

PLCController::PLCController(vector<Block> tr)
{
    iterator = 0;
    track = tr;
    target = track[iterator];
}

PLCController PLCController::operator=(PLCController p)
{
    this->iterator = p.getIterator();
    this->track = p.track;
    this->target = p.target;
    return *this;
}

int PLCController::getIterator()
{
    return iterator;
}

void PLCController::setIterator(int i)
{
    iterator = i;
}

void PLCController::checkTrack()
{
    while(1==1)
    {
        if(checkRails())
        {} //MARK BROKEN
        if(0) //IF TARGET IS A SWITCH
        {
            if(checkSwitches())
                switchTrack();
        }
        else if(0) //IF TARGET IS A CROSSING
        {
            if(checkCrossings())
                toggleCrossing();
        }
        target = track[++iterator];
    }
}
