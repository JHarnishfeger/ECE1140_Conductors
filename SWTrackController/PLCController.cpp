#include "PLCController.h"

PLCController::PLCController()
{
    iterator = 0;
}

PLCController::PLCController(vector<Block> tr, vector<Block> occ)
{
    iterator = 0;
    track = tr;
    occupancy = occ;
    bool flag = 0;
    for(int i=0;i<occupancy.size();i++)
    {
        for(int j=0;j<branchOccupancy.size();j++)
        {
            if(occupancy[i].getBranch()==branchOccupancy[j])
                flag = 1;
        }
        if(!flag)
            branchOccupancy.push_back(occupancy[i].getBranch());
        flag = 0;
    }
}

PLCController& PLCController::operator=(PLCController& p)
{
    this->iterator = p.getIterator();
    this->track = p.track;
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

bool PLCController::branchOccupied(Block b)
{
    for(int i=0;i<branchOccupancy.size();i++)
        if(b.getBranch()==branchOccupancy[i])
            return 1;
    return 0;
}

bool PLCController::checkTrack(vector<Block> tr)
{
    track = tr;
    bool flag=0;
    bool switchValid;
    bool branchValid;
    while(1==1)
    {
        if(checkRails())
        {
            track[iterator].setBrokenRail(true);
            flag = 1;
        }
        if(track[iterator].getType()=="switch")
        {
            switchValid = !track[iterator].getTrainPresent();
            branchValid = !branchOccupied(track[iterator+1]);
            if(checkSwitches(switchValid,branchValid))
            {
                switchTrack();
                flag = 1;
            }
        }
        else if(track[iterator].getType()=="crossing")
        {
            branchValid = !branchOccupied(track[iterator]);
            if(checkCrossings(branchValid))
            {
                toggleCrossing();
                flag = 1;
            }
        }
        if(iterator<track.size()-1)
            ++iterator;
        else
        {
            iterator = 0;
            break;
        }
    }
    return flag;
}

bool PLCController::checkSwitches(bool sw, bool br) //Uses PLC program to check for switches to be switched, returns 1 on appplicable block. Part of checkTrack().
{
    if(br)
        return 0;
    else if(sw)
        return 1;
}
bool PLCController::checkRails() //Checks for broken rails, returns 1 on applicable block. Part of checkTrack().
{
    return track[iterator].getBrokenRail();
}
bool PLCController::checkCrossings(bool cr) //Uses PLC program to check for railroad crossings that need to be activated, returns 1 on applicable block. Part of checkTrack().
{
    return !cr;
}

bool PLCController::switchTrack()
{
    track[iterator].setSwitch(!track[iterator].getSwitch());
    return track[iterator].getSwitch();
}

bool PLCController::toggleCrossing()
{
    track[iterator].setCrossing(!track[iterator].getCrossing());
    return track[iterator].getCrossing();
}
