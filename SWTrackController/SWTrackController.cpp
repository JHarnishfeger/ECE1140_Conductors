#include "SWTrackController.h"

SWTrackController::SWTrackController()
{
    suggestedSpeed = 0;
    authority = 0;
    manualMode = 0;
}

void SWTrackController::initialize(vector<Block> red, vector<Block> green, double s, double a, bool m)
{
    redLine = red;
    greenLine = green;
    setSuggestedSpeed(s);
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

SWTrackController::SWTrackController(vector<Block> red, vector<Block> green, int num, double s, double a, bool m)
{
    redLine = red;
    greenLine = green;
    createWaysides(num);
    setSuggestedSpeed(s);
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

void SWTrackController::sanityCheck()
{
    for(int i=0;i<waysides.size();i++)
    {
        std::cout << std::endl << "SANITY CHECK" << std::endl;
        std::cout << "WAYSIDE " << waysides[i].getID() << std::endl;
        std::cout << "SECTOR SIZE: " << waysides[i].sector.size() << std::endl;
        std::cout << "BLOCK RANGE: " << waysides[i].sector[0].getId() << " - " << waysides[i].sector.back().getId() << std::endl;
        std::cout << "SWITCHES: " << waysides[i].swich.size() << std::endl;
        for(int j=0;j<waysides[i].swich.size();j++)
            std::cout << waysides[i].swich[j].getId() << ", ";
        std::cout << std::endl << "CROSSINGS: " << waysides[i].crossing.size() << std::endl;
        for(int j=0;j<waysides[i].crossing.size();j++)
            std::cout << waysides[i].crossing[j].getId() << ", ";
        std::cout << std::endl << "BROKEN RAILS: " << waysides[i].getBrokenRails().size() << std::endl;
        std::cout << "SPEED: " << waysides[i].getSuggestedSpeed() << std::endl;
        std::cout << "AUTHORITY: " << waysides[i].getAuthority() << std::endl << std::endl;
    }
}

vector<Block> SWTrackController::getHWTrack()
{
    return hwTrack;
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

void SWTrackController::updateFromWaysides()
{
    bool check=0;
    int displace;
    for(int i=0;i<waysides.size();i++)
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
    wayPtr = &waysides;
}

void SWTrackController::updateWaysides()
{
    for(int i=0;i<waysides.size();i++)
    {
        waysides[i].setSuggestedSpeed(suggestedSpeed);
        waysides[i].setAuthority(authority);
        waysides[i].setMode(manualMode);
    }
    wayPtr = &waysides;
    getTrackOccupancy();
}

void SWTrackController::createWaysides(int waysideNum)
{
    std::cout << "Creating Waysides" << std::endl;
    int id=0;
    int trackSize = redLine.size() + greenLine.size(); //Finding most effective way to set waysides
    int redWaysideNum = std::ceil(static_cast<double>(waysideNum) * static_cast<double>(redLine.size()) / trackSize);
    int greenWaysideNum = std::ceil(static_cast<double>(waysideNum) * static_cast<double>(greenLine.size()) / trackSize);
    while(waysideNum>(redWaysideNum+greenWaysideNum))
    {
        if(redLine.size()>greenLine.size())
            redWaysideNum++;
        else
            greenWaysideNum++;
    }
    while(waysideNum<(redWaysideNum+greenWaysideNum))
    {
        if(redWaysideNum>=greenWaysideNum)
            redWaysideNum--;
        else
            greenWaysideNum--;
    }
    waysideNum = redWaysideNum + greenWaysideNum;
    std::cout << "Wayside Number Calculated" << std::endl;

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
            Wayside newOne(sector,0);
            waysides.push_back(newOne);
            waysides[i].setID(++id);
            sector.clear();
            nextSector += redWaysideSectorSize;
        }
    }
    std::cout << "Redline Waysides Done" << std::endl;
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
            Wayside newOne(sector,1);
            waysides.push_back(newOne);
            waysides[i].setID(++id);
            sector.clear();
            nextSector += greenWaysideSectorSize;
        }
    }
    std::cout << "Greenline Waysides Done" << std::endl;
    /*for(int i=0;i<waysides.size();i++)
    {
        std::cout << std::endl << "SANITY CHECK" << std::endl;
        std::cout << "WAYSIDE " << waysides[i].getID() << std::endl;
        std::cout << "SECTOR SIZE: " << waysides[i].sector.size() << std::endl;
        std::cout << "BLOCK RANGE: " << waysides[i].sector[0].getId() << " - " << waysides[i].sector.back().getId() << std::endl;
        std::cout << "SWITCHES: " << waysides[i].swich.size() << std::endl;
        for(int j=0;j<waysides[i].swich.size();j++)
            std::cout << waysides[i].swich[j].getId() << ", ";
        std::cout << std::endl << "CROSSINGS: " << waysides[i].crossing.size() << std::endl;
        for(int j=0;j<waysides[i].crossing.size();j++)
            std::cout << waysides[i].crossing[j].getId() << ", ";
        std::cout << std::endl << "BROKEN RAILS: " << waysides[i].getBrokenRails().size() << std::endl;
        std::cout << "SPEED: " << waysides[i].getSuggestedSpeed() << std::endl;
        std::cout << "AUTHORITY: " << waysides[i].getAuthority() << std::endl << std::endl;
    }*/
    //std::cout << "Waysides done" << std::endl;
}

vector<Block> SWTrackController::setHardwareWayside(int id)
{
    //waysides.erase(waysides.begin()+id-1);  BREAKS CODE-----------
    return waysides[id-1].sector;
}

double SWTrackController::getSuggestedSpeed()
{
    return suggestedSpeed;
}

void SWTrackController::setSuggestedSpeed(double sp)
{
    //std::cout << "in" << std::endl;
    suggestedSpeed = sp;
    updateWaysides();
}

double SWTrackController::getCommandedSpeed()
{
    return commandedSpeed;
}

void SWTrackController::setCommandedSpeed(double sp)
{
    commandedSpeed = sp;
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
                    waysides[i].switchTrack(waysides[i].sector[j]);
                    for(int k=0;k<swich.size();k++)
                    {
                        if(swich[k].getId()==swt.getId()&&swich[k].getLine()==swt.getLine())
                            swich[k].setSwitch(waysides[i].sector[j].getSwitch());
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
            if(waysides[i].sector[j].getLine()==crs.getLine())
            {
                if(waysides[i].sector[j].getId()==crs.getId())
                {
                    waysides[i].toggleCrossing(waysides[i].sector[j]);
                    for(int k=0;k<crossing.size();k++)
                    {
                        if(crossing[k].getId()==crs.getId()&&crossing[k].getLine()==crs.getLine())
                            crossing[k].setCrossing(waysides[i].sector[j].getCrossing());
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

void SWTrackController::getTrackOccupancy()
{
    trackOccupancy.clear();
    //std::cout << waysides.size() << std::endl;
    //std::cout << waysides[0].getID();
    //std::cout << waysides[0].getTrackOccupancy()[0].getId();
    //std::cout << waysides[0].getTrackOccupancy().size();
    for(int i=0;i<waysides.size();i++)
        for(int j=0;j<waysides[i].getTrackOccupancy().size();j++)
            trackOccupancy.push_back(waysides[i].getTrackOccupancy()[j]);
}

void SWTrackController::testValues()
{
    std::cout << "Speed: " << suggestedSpeed << std::endl;
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
        if(trackOccupancy[i].getLine()=='r')
            std::cout << trackOccupancy[i].getId() << ", ";
    }

    std::cout << std::endl << "GREEN LINE TRAIN POSITIONS: ";
    for(int i=0;i<trackOccupancy.size();i++)
    {
        if(trackOccupancy[i].getLine()=='g')
            std::cout << trackOccupancy[i].getId() << ", ";
    }

    std::cout << std::endl << std::endl << "SWITCHES: ";
    for(int i=0;i<waysides.size();i++)
    {
        for(int j=0;j<waysides[i].swich.size();j++)
        {
            std::cout << waysides[i].swich[j].getId() << "(" << waysides[i].swich[j].getSwitch() << "), ";
        }
    }

    std::cout << std::endl << "CROSSINGS: ";
    for(int i=0;i<waysides.size();i++)
    {
        for(int j=0;j<waysides[i].crossing.size();j++)
        {
            std::cout << waysides[i].crossing[j].getId() << "(" << waysides[i].crossing[j].getCrossing() << "), ";
        }
    }

    std::cout << std::endl << "MAINTENANCE: ";
    for(int j=0;j<waysides.size();j++)
        for(int i=0;i<waysides[j].getMaintenance().size();i++)
        {
            std::cout << waysides[j].getMaintenance()[i].getId() << ", ";
        }

    std::cout << std::endl << "BROKEN RAILS: ";
    for(int j=0;j<waysides.size();j++)
        for(int i=0;i<waysides[j].getBrokenRails().size();i++)
        {
            std::cout << waysides[j].getBrokenRails()[i].getId() << ", ";
        }

    std::cout << std::endl << std::endl << "--WAYPTR--" << std::endl;
    std::cout << std::endl << std::endl << "SWITCHES: ";
    for(int i=0;i<wayPtr->size();i++)
    {
        for(int j=0;j<(*wayPtr)[i].swich.size();j++)
        {
            std::cout << (*wayPtr)[i].swich[j].getId() << "(" << (*wayPtr)[i].swich[j].getSwitch() << "), ";
        }
    }

    std::cout << std::endl << "CROSSINGS: ";
    for(int i=0;i<wayPtr->size();i++)
    {
        for(int j=0;j<(*wayPtr)[i].crossing.size();j++)
        {
            std::cout << (*wayPtr)[i].crossing[j].getId() << "(" << (*wayPtr)[i].crossing[j].getCrossing() << "), ";
        }
    }

    std::cout << std::endl << std::endl;
}
