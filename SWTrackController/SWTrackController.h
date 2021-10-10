#include <vector>
#include <fstream>
#include <cstdio>
#include "Block.h"
#include "PLCController.h"
#include "Wayside.h"

/*TODO:

-Send switch/crossing position data to CTC and Track Model
-Finish test interface
-Track occupancy from track model
-PLC logic

*/
class SWTrackController
{
private:
    double speed; //Current suggested speed (imperial units)
    double authority; //Current authority (imperial units)
    bool manualMode; //Shows if controller is in Manual mode. 0 = Automatic, 1 = Manual
public:
    SWTrackController(vector<Block>,vector<Block>,int,double,double,bool); //Takes red model, green model, number of waysides, speed, authority, and mode to create an instance of the SWTrackController
    void plcCheck(); //Runs PLC on each wayside
    void updateWaysides(); //Sends current values to all waysides
    void createWaysides(int); //Initializes a given number of waysides around the track
    vector<Wayside> waysides; //Holds all waysides as part of the track controller
    vector<Block> redLine; //Holds all info about each block of the red line.
    vector<Block> greenLine; //Holds all info about each block of the green line.
    double getSpeed(); //Returns current suggested speed (imperial units)
    void setSpeed(double); //Sets current suggested speed (imperial units)
    double getAuthority(); //Returns current authority (imperial units)
    void setAuthority(double); //Sets current authority (imperial units)
    bool getMode(); //Checks if device is in manual mode
    void setMode(bool); //Sets device to the proper mode
    void addMaintenance(Block); //Sets a block of given ID as undergoing maintenance
    void endMaintenance(Block); //Removes a block from the maintenance list
    vector<Block> getMaintenance(bool); //Produces a list of all blocks on selected line undergoing maintenance
    void addBrokenRail(Block); //Sets a rail as being broken
    void fixBrokenRail(Block); //Removes a rail from the broken rail list
    vector<Block> getBrokenRails(); //Produces a list of all broken rails
    bool switchTrack(Block); //Detect which wayside contains a given block, and switch the given track
    bool toggleCrossing(Block); //Detect which wayside contains a given crossing, and activate/deactivate it
    vector<Block> getLineOccupancy(bool); //Receives track occupancy from all waysides on the selected line (Red = 0, Green = 1)
    void testValues(); //Spits out all relavent values for testing purposes
};

SWTrackController::SWTrackController(vector<block> red, vector<Block> green, int num, double s, double a, bool m)
{
    redLine = red;
    greenLine = green;
    createWaysides(tr,num);
    setSpeed(s);
    setAuthority(a);
    setMode(m);
}

void SWTrackController::plcCheck()
{
    for(int i=0;i<waysides.size();i++)
        waysides[i].detectTrack();
    updateWaysides();
}

void SWTrackController::updateWaysides()
{
    for(int i=0;i<waysides.size();i++)
    {
        waysides[i].setSpeed(speed);
        waysides[i].setAuthority(authority);
        waysides[i].setMode(manualMode);
    }
}

void SWTrackController::createWaysides(int waysideNum)
{
    int trackSize = redLine.size() + greenLine.size(); //Finding most effective way to set waysides
    int redWaysideNum = waysideNum * static_cast<double>(redLine.size() / trackSize);
    int greenWaysideNum = waysideNum * static_cast<double>(greenLine.size() / trackSize);
    if(waysideNum!=(redWaysideNum+greenWaysideNum))
    {
        if(redLine.size()>greenLine.size())
            redWaysideNum++;
        else
            greenWaysideNum++;
    }

    int waysideSectorSize = redLine.size() / redWaysideNum; //Dividing up each line equally with waysides
    for(int j=0;j<2;j++)
    {
        int nextSector = waysideSectorSize;
        vector<Block> sector;
        for(int i=0;i<trackSize;i++)
        {
            if(i<nextSector||i!=trackSize-1)
                sector.push_back(track[i]);
            else
            {
                Wayside newWayside(sector);
                waysides.push_back(newWayside);
                nextSector += waysideSectorSize;
            }
        }
        waysideSectorSize = greenLine.size() / greenWaysideNum;
    }
}

double SWTrackController::getSpeed()
{
    return speed;
}

void SWTrackController::setSpeed(double sp)
{
    speed = sp;
    updateWaysides();
}

double SWTrackController::getAuthority()
{
    return authority;
}

void SWTrackController::setAuthority(double au)
{
    authority = au;
    updateWaysides();
}

bool SWTrackController::getMode()
{
    return manualMode;
}

void SWTrackController::setMode(bool m)
{
    manualMode = m;
    updateWaysides();
}

void SWTrackController::addMaintenance(Block mn)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==mn.getLine())
            {
                if(waysides[i].sector[j].getID()==mn.getID())
                {
                    waysides[i].addMaintenance(mn);
                    i = waysides.size();
                    found = 1;
                    break;
                }
            }
            else
                break;
        }
    if(!found)
        return 0;
    else
        return 1;
}

void SWTrackController::endMaintenance(Block mn)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==mn.getLine())
            {
                if(waysides[i].sector[j].getID()==mn.getID())
                {
                    waysides[i].endMaintenance(mn);
                    i = waysides.size();
                    found = 1;
                    break;
                }
            }
            else
                break;
        }
    if(!found)
        return 0;
    else
        return 1;
}

vector<Block> SWTrackController::getMaintenance(bool l)
{
    vector<Block> maintenance;
    for(int i=0;i<waysides.size();i++)
        if(waysides[i].line==l)
            for(int j=0;j<waysides[i].maintenance.size();j++)
                maintenance.push_back(waysides[i].maintenance[j]);
    return maintenance;
}

void SWTrackController::addBrokenRail(Block rl)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==rl.getLine())
            {
                if(waysides[i].sector[j].getID()==rl.getID())
                {
                    waysides[i].addBrokenRail(rl);
                    i = waysides.size();
                    found = 1;
                    break;
                }
            }
            else
                break;
        }
    if(!found)
        return 0;
    else
        return 1;
}

void SWTrackController::fixBrokenRail(Block rl)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==rl.getLine())
            {
                if(waysides[i].sector[j].getID()==rl.getID())
                {
                    waysides[i].fixBrokenRail(rl);
                    i = waysides.size();
                    found = 1;
                    break;
                }
            }
            else
                break;
        }
    if(!found)
        return 0;
    else
        return 1;
}

vector<Block> SWTrackController::getBrokenRails(bool l)
{
    vector<Block> maintenance;
    for(int i=0;i<waysides.size();i++)
        if(waysides[i].line==l)
            for(int j=0;j<waysides[i].brokenRail.size();j++)
                maintenance.push_back(waysides[i].brokenRail[j]);
    return maintenance;
}

bool SWTrackController::switchTrack(Block swt)
{
    //CHECK IF GIVEN BLOCK IS A SWITCH
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==swt.getLine())
            {
                if(waysides[i].sector[j].getID()==swt.getID())
                {
                    waysides[i].switchTrack(swt);
                    i = waysides.size();
                    found = 1;
                    break;
                }
            }
            else
                break;
        }
    if(!found)
        return 0;
    else
        return 1;
}

bool SWTrackController::toggleCrossing(Block crs)
{
    //CHECK IF GIVEN BLOCK IS A CROSSING
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getID()==crs.getID())
            {
                waysides[i].toggleCrossing(crs);
                i = waysides.size();
                found = 1;
                break;
            }
        }
    if(!found)
        return 0;
    else
        return 1;
}

vector<Block> SWTrackController::getLineOccupancy(bool l)
{
    vector<Block> occupancy;
    for(int i=0;i<waysides.size();i++)
        if(waysides[i].line==l)
            for(int j=0;j<waysides[i].trackOccupancy.size();j++)
                occupancy.push_back(waysides[i].trackOccupancy[j]);
    return occupancy;
}

void SWTrackController::testValues()
{
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Authority: " << authority << std::endl;
    std::cout << "Mode: " << manualMode << std::endl;
    std::cout << "# of Waysides: " << waysides.size() << std::endl;
    for(int i=0;i<waysides.size();i++)
    {
        if(waysides[i].line)
            std::cout << "GREEN ";
        else
            std::cout << "RED ";
        std::cout << " LINE - Wayside " << i << ": Blocks " << waysides[i].sector[0].getID() << " - " << waysides[i].sector[waysides[i].sector.size()-1].getID() << std::endl;
    }

    std::cout << std::endl << "RED LINE TRAIN POSITIONS: ";
    vector<Block> rpos = getLineOccupancy(0);
    for(int i=0;i<rpos.size();i++)
    {
        std::cout << rpos[i].getID() << ", ";
    }

    std::cout << std::endl << "GREEN LINE TRAIN POSITIONS: ";
    vector<Block> gpos = getLineOccupancy(1);
    for(int i=0;i<gpos.size();i++)
    {
        std::cout << gpos[i].getID() << ", ";
    }
    std::cout << std::endl << std::endl;
}
