#include "SWTrackController.h"

SWTrackController::SWTrackController()
{
    speed = 0;
    authority = 0;
    manualMode = 0;
}

void SWTrackController::initialize(vector<Block> red, vector<Block> green, int num, double s, double a, bool m)
{
    redLine = red;
    greenLine = green;
    createWaysides(num);
    setSpeed(s);
    setAuthority(a);
    setMode(m);
    for(int i=0;i<redLine.size();i++)
    {
        if(redLine[i].getType()=="switch")
            swich.push_back(redLine[i]);
        else if(redLine[i].getType()=="crossing")
            crossing.push_back(redLine[i]);
        else if(redLine[i].getBrokenRail())
            brokenRail.push_back(redLine[i]);
    }
}

SWTrackController::SWTrackController(vector<Block> red, vector<Block> green, int num, double s, double a, bool m)
{
    redLine = red;
    greenLine = green;
    createWaysides(num);
    setSpeed(s);
    setAuthority(a);
    setMode(m);
    for(int i=0;i<redLine.size();i++)
    {
        if(redLine[i].getType()=="switch")
            swich.push_back(redLine[i]);
        else if(redLine[i].getType()=="crossing")
            crossing.push_back(redLine[i]);
        else if(redLine[i].getBrokenRail())
            brokenRail.push_back(redLine[i]);
    }
    for(int i=0;i<greenLine.size();i++)
    {
        if(greenLine[i].getType()=="switch")
            swich.push_back(greenLine[i]);
        else if(greenLine[i].getType()=="crossing")
            crossing.push_back(greenLine[i]);
        else if(greenLine[i].getBrokenRail())
            brokenRail.push_back(greenLine[i]);
    }
}

void SWTrackController::plcCheck()
{
    bool check=0;
    int displace;
    for(int i=0;i<waysides.size();i++)
    {
        if(waysides[i].detectTrack())
        {
            if(waysides[i].getLine())
            {
                for(int j=0;j<redLine.size();j++)
                {
                    if(redLine[j].getId()==waysides[i].sector[0].getId())
                    {
                        check = 1;
                        displace = j;
                    }
                    else if(redLine[j].getId()==waysides[i].sector[waysides[i].sector.size()-1].getId())
                        break;
                    if(check)
                    {
                        if(redLine[j].getSwitch()!=waysides[i].sector[j-displace].getSwitch())//IF SWITCH IS DIFFERENT THAN LOCAL POSITION
                        {
                            alerts.push_back("SWITCH " + std::to_string(redLine[j].getId()) + " TOGGLED");
                            redLine[j].setSwitch(waysides[i].sector[j-displace].getSwitch());
                            for(int k=0;k<swich.size();k++) //Update switch vector
                            {
                                if(swich[k].getId()==redLine[j].getId()&&swich[k].getLine()==redLine[j].getLine())
                                {
                                    swich[k].setSwitch(redLine[j].getSwitch());
                                    break;
                                }
                            }

                        }
                        else if(redLine[j].getCrossing()!=waysides[i].sector[j-displace].getCrossing())//IF CROSSING IS DIFFERENT THAN LOCAL VALUE
                        {
                            alerts.push_back("CROSSING " + std::to_string(redLine[j].getId()) + " TOGGLED");
                            redLine[j].setCrossing(waysides[i].sector[j-displace].getCrossing());
                            for(int k=0;k<crossing.size();k++) //Update crossing vector
                            {
                                if(crossing[k].getId()==redLine[j].getId()&&crossing[k].getLine()==redLine[j].getLine())
                                {
                                    crossing[k].setCrossing(redLine[j].getCrossing());
                                    break;
                                }
                            }
                        }
                        else if(redLine[j].getBrokenRail()!=waysides[i].sector[j-displace].getBrokenRail())//IF RAIL STATUS IS DIFFERENT THAN LOCAL VALUE
                        {
                            alerts.push_back("RAIL " + std::to_string(redLine[j].getId()) + " BROKEN");
                            redLine[j].setBrokenRail(waysides[i].sector[j-displace].getBrokenRail());
                            bool found=0;
                            for(int k=0;k<brokenRail.size();k++)
                            {
                                if(brokenRail[k].getId()==redLine[j].getId()&&brokenRail[k].getLine()==redLine[j].getLine())
                                {
                                    brokenRail[k].setBrokenRail(redLine[j].getBrokenRail());
                                    found = 1;
                                }
                            }
                            if(!found)
                                brokenRail.push_back(redLine[j]);
                        }
                    }
                }
            }
            else
            {
                for(int j=0;j<greenLine.size();j++)
                {
                    if(greenLine[j].getId()==waysides[i].sector[0].getId())
                    {
                        check = 1;
                        displace = j;
                    }
                    else if(greenLine[j].getId()==waysides[i].sector[waysides[i].sector.size()-1].getId())
                        break;
                    if(check)
                    {
                        if(greenLine[j].getSwitch()!=waysides[i].sector[j-displace].getSwitch())//IF SWITCH IS DIFFERENT THAN LOCAL POSITION
                        {
                            alerts.push_back("SWITCH " + std::to_string(greenLine[j].getId()) + " TOGGLED");
                            greenLine[j].setSwitch(waysides[i].sector[j-displace].getSwitch());
                            for(int k=0;k<swich.size();k++) //Update switch vector
                            {
                                if(swich[k].getId()==greenLine[j].getId()&&swich[k].getLine()==greenLine[j].getLine())
                                {
                                    swich[k].setSwitch(greenLine[j].getSwitch());
                                    break;
                                }
                            }
                        }
                        if(greenLine[j].getCrossing()!=waysides[i].sector[j-displace].getCrossing())//IF CROSSING IS DIFFERENT THAN LOCAL VALUE
                        {
                            alerts.push_back("CROSSING " + std::to_string(greenLine[j].getId()) + " TOGGLED");
                            greenLine[j].setCrossing(waysides[i].sector[j-displace].getCrossing());
                            for(int k=0;k<crossing.size();k++) //Update crossing vector
                            {
                                if(crossing[k].getId()==greenLine[j].getId()&&crossing[k].getLine()==greenLine[j].getLine())
                                {
                                    crossing[k].setCrossing(greenLine[j].getCrossing());
                                    break;
                                }
                            }
                        }
                        if(greenLine[j].getBrokenRail()!=waysides[i].sector[j-displace].getBrokenRail())
                        {
                            alerts.push_back("RAIL " + std::to_string(greenLine[j].getId()) + " BROKEN");
                            greenLine[j].setBrokenRail(waysides[i].sector[j-displace].getBrokenRail());
                            bool found=0;
                            for(int k=0;k<brokenRail.size();k++) //Update broken rail vector
                            {
                                if(brokenRail[k].getId()==greenLine[j].getId()&&brokenRail[k].getLine()==greenLine[j].getLine())
                                {
                                    brokenRail[k].setBrokenRail(greenLine[j].getBrokenRail());
                                    found = 1;
                                }
                            }
                            if(!found)
                                brokenRail.push_back(greenLine[j]);
                        }
                    }
                }
            }
        }
    }
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
    getTrackOccupancy();
}

void SWTrackController::createWaysides(int waysideNum)
{
    int id=0;
    int trackSize = redLine.size() + greenLine.size(); //Finding most effective way to set waysides
    int redWaysideNum = std::ceil(static_cast<double>(waysideNum) * static_cast<double>(redLine.size()) / trackSize);
    int greenWaysideNum = std::ceil(static_cast<double>(waysideNum) * static_cast<double>(greenLine.size()) / trackSize);
    if(waysideNum!=(redWaysideNum+greenWaysideNum))
    {
        if(redLine.size()>greenLine.size())
            redWaysideNum++;
        else
            greenWaysideNum++;
    }

    int redWaysideSectorSize = redLine.size() / redWaysideNum; //Dividing up each line equally with waysides
    int greenWaysideSectorSize = greenLine.size() / greenWaysideNum;

    int nextSector = redWaysideSectorSize;
    vector<Block> sector;
    for(int i=0;i<redLine.size();i++)
    {
        if(i<nextSector&&i!=redLine.size()-1)
        {
            sector.push_back(redLine[i]);
        }
        else
        {
            sector.push_back(redLine[i]);
            Wayside newWayside(sector,0);
            newWayside.setID(++id);
            waysides.push_back(newWayside);
            sector.clear();
            nextSector += redWaysideSectorSize;
        }
    }

    nextSector = greenWaysideSectorSize;
    for(int i=0;i<greenLine.size();i++)
    {
        if(i<nextSector&&i!=greenLine.size()-1)
        {
            sector.push_back(greenLine[i]);
        }
        else
        {
            sector.push_back(greenLine[i]);
            Wayside newWayside(sector,1);
            newWayside.setID(++id);
            waysides.push_back(newWayside);
            sector.clear();
            nextSector += greenWaysideSectorSize;
        }
    }
}

vector<Block> SWTrackController::setHardwareWayside(int id)
{
    waysides.erase(waysides.begin()+id-1);
    return waysides[id-1].sector;
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

bool SWTrackController::addMaintenance(Block mn)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==mn.getLine())
            {
                if(waysides[i].sector[j].getId()==mn.getId())
                {
                    waysides[i].addMaintenance(mn);
                    maintenance.push_back(mn);
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

bool SWTrackController::endMaintenance(Block mn)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==mn.getLine())
            {
                if(waysides[i].sector[j].getId()==mn.getId())
                {
                    waysides[i].endMaintenance(mn);
                    for(int k=0;k<maintenance.size();k++)
                    {
                        if(maintenance[k].getId()==mn.getId()&&maintenance[k].getLine()==mn.getLine())
                        {
                            maintenance.erase(maintenance.begin()+k);
                            break;
                        }
                    }
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

vector<Block> SWTrackController::getMaintenance()
{
    return maintenance;
}

bool SWTrackController::addBrokenRail(Block rl)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==rl.getLine())
            {
                if(waysides[i].sector[j].getId()==rl.getId())
                {
                    waysides[i].addBrokenRail(rl);
                    brokenRail.push_back(rl);
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

bool SWTrackController::fixBrokenRail(Block rl)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==rl.getLine())
            {
                if(waysides[i].sector[j].getId()==rl.getId())
                {
                    waysides[i].fixBrokenRail(rl);
                    for(int k=0;k<brokenRail.size();k++)
                    {
                        if(brokenRail[k].getId()==rl.getId()&&brokenRail[k].getLine()==rl.getLine())
                        {
                            brokenRail.erase(brokenRail.begin()+k);
                            break;
                        }
                    }
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

vector<Block> SWTrackController::getBrokenRails()
{
    return brokenRail;
}

bool SWTrackController::switchTrack(Block swt)
{
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getLine()==swt.getLine())
            {
                if(waysides[i].sector[j].getId()==swt.getId())
                {
                    waysides[i].switchTrack(swt);
                    for(int k=0;k<swich.size();k++)
                    {
                        if(swich[k].getId()==swt.getId()&&swich[k].getLine()==swt.getLine())
                            swich[k].setSwitch(swt.getSwitch());
                    }
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
    bool found=0;
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].sector.size();j++)
        {
            if(waysides[i].sector[j].getId()==crs.getId())
            {
                waysides[i].toggleCrossing(crs);
                for(int k=0;k<crossing.size();k++)
                {
                    if(crossing[k].getId()==crs.getId()&&crossing[k].getLine()==crs.getLine())
                        crossing[k].setSwitch(crs.getCrossing());
                }
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

void SWTrackController::getTrackOccupancy()
{
    trackOccupancy.clear();
    for(int i=0;i<waysides.size();i++)
        trackOccupancy.insert(std::end(trackOccupancy), std::begin(waysides[i].getTrackOccupancy()), std::end(waysides[i].getTrackOccupancy()));
}

void SWTrackController::testValues()
{
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Authority: " << authority << std::endl;
    std::cout << "Mode: " << manualMode << std::endl;
    std::cout << "# of Waysides: " << waysides.size() << std::endl;
    for(int i=0;i<waysides.size();i++)
    {
        if(waysides[i].getLine())
            std::cout << "GREEN ";
        else
            std::cout << "RED ";
        std::cout << " LINE - Wayside " << i << ": Blocks " << waysides[i].sector[0].getId() << " - " << waysides[i].sector[waysides[i].sector.size()-1].getId() << std::endl;
    }

    std::cout << std::endl << std::endl << "RED LINE TRAIN POSITIONS: ";
    for(int i=0;i<trackOccupancy.size();i++)
    {
        if(!trackOccupancy[i].getLine())
            std::cout << trackOccupancy[i].getId() << ", ";
    }

    std::cout << std::endl << "GREEN LINE TRAIN POSITIONS: ";
    for(int i=0;i<trackOccupancy.size();i++)
    {
        if(trackOccupancy[i].getLine())
            std::cout << trackOccupancy[i].getId() << ", ";
    }

    std::cout << std::endl << std::endl << "SWITCHES: ";
    for(int i=0;i<swich.size();i++)
    {
        std::cout << swich[i].getId() << ", ";
    }

    std::cout << std::endl << "CROSSINGS: ";
    for(int i=0;i<crossing.size();i++)
    {
        std::cout << crossing[i].getId() << ", ";
    }

    std::cout << std::endl << "MAINTENANCE: ";
    for(int i=0;i<maintenance.size();i++)
    {
        std::cout << maintenance[i].getId() << ", ";
    }

    std::cout << std::endl << "BROKEN RAILS: ";
    for(int i=0;i<brokenRail.size();i++)
    {
        std::cout << brokenRail[i].getId() << ", ";
    }

    std::cout << std::endl << std::endl;
}
