#include "Wayside.h"

Wayside::Wayside(vector<Block> track, bool ln)
{
    suggestedSpeed = 0;
    authority = 0;
    manualMode = 0;
    id = 0;
    sector = track;
    PLCController p(sector,trackOccupancy);
    plc = p;
    line = ln;
    for(int i=0;i<sector.size();i++)
    {
        if(sector[i].getType()=="switch")
            swich.push_back(sector[i]);
        else if(sector[i].getType()=="crossing")
            crossing.push_back(sector[i]);
        else if(sector[i].getBrokenRail())
            brokenRail.push_back(sector[i]);
    }
}

Wayside::Wayside()
{
    suggestedSpeed = 0;
    authority = 0;
    manualMode = 0;
    id = 0;
    line = 0;
}

Wayside& Wayside::operator=(Wayside& w)
{
    this->suggestedSpeed = w.getSuggestedSpeed();
    this->authority = w.getAuthority();
    this->manualMode = w.getMode();
    this->line = w.getLine();
    this->id = w.getID();
    this->plc = w.plc;
    return *this;
}

void Wayside::update()
{
    calculateSpeed();
    detectTrack();
}

bool Wayside::detectTrack()
{
    bool detect=0;
    bool found=0;
    bool check = plc.checkTrack(sector);
    while(check)
    {
        detect = 1;
        sector = plc.track;
        check = plc.checkTrack(sector);
    }
    if(detect)
        for(int i=0;i<sector.size();i++)
        {
            for(int j=0;j<swich.size();j++)
            {
                if(swich[j].getSwitch()!=sector[i].getSwitch()&&swich[j].getId()==sector[i].getId())//IF SWITCH IS DIFFERENT THAN LOCAL POSITION
                {
                    alerts.push_back("SWITCH " + std::to_string(swich[j].getId()) + " TOGGLED");
                    swich[j].setSwitch(sector[i].getSwitch());
                }
            }
            for(int j=0;j<crossing.size();j++)
            {
                if(crossing[j].getCrossing()!=sector[i].getCrossing()&&crossing[j].getId()==sector[i].getId())//IF CROSSING IS DIFFERENT THAN LOCAL POSITION
                {
                    alerts.push_back("CROSSING " + std::to_string(crossing[j].getId()) + " TOGGLED");
                    crossing[j].setCrossing(sector[i].getCrossing());
                }
            }
            for(int j=0;j<brokenRail.size();j++)
            {
                if(brokenRail[j].getBrokenRail()!=sector[i].getBrokenRail()&&brokenRail[j].getId()==sector[i].getId())//IF BROKEN RAIL STATUS IS DIFFERENT THAN LOCAL VALUE
                {
                    alerts.push_back("RAIL " + std::to_string(brokenRail[j].getId()) + " BROKEN");
                    brokenRail[j].setBrokenRail(sector[i].getBrokenRail());
                    found = 1;
                }
            }
            if(!found&&sector[i].getBrokenRail()==true)
                brokenRail.push_back(sector[i]);
        }
    return detect;
}

void Wayside::calculateSpeed()
{
    commandedSpeed = suggestedSpeed;
}

int Wayside::getID()
{
    return id;
}

void Wayside::setID(int i)
{
    id = i;
}

bool Wayside::getLine()
{
    return line;
}

void Wayside::setLine(bool l)
{
    line = l;
}

double Wayside::getSuggestedSpeed()
{
    return suggestedSpeed;
}

void Wayside::setSuggestedSpeed(double sp)
{
    suggestedSpeed = sp;
}

double Wayside::getCommandedSpeed()
{
    return commandedSpeed;
}

void Wayside::setCommandedSpeed(double sp)
{
    commandedSpeed = sp;
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
        if(brokenRail[i].getId()==r.getId())
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
    for(int i=0;i<maintenance.size();i++)
    {
        if(maintenance[i].getId()==m.getId())
        {
            maintenance.erase(maintenance.begin()+i);
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

void Wayside::addAlert(string s)
{
    alerts.push_back(s);
}

vector<string> Wayside::getAlerts()
{
    return alerts;
}

void Wayside::clearAlerts()
{
    alerts.clear();
}

bool Wayside::getMode()
{
    return manualMode;
}

void Wayside::setMode(bool m)
{
    manualMode = m;
}

bool Wayside::switchTrack(Block &sw)
{
    sw.setSwitch(!sw.getSwitch());
    return sw.getSwitch();
}

bool Wayside::toggleCrossing(Block &crossing)
{
    crossing.setCrossing(!crossing.getCrossing());
    return crossing.getCrossing();
}

vector<Block> Wayside::getTrackOccupancy()
{
    vector<Block> occ;
    for(int i=0;i<sector.size();i++)
    {
        if(sector[i].getTrainPresent()==true)
        {
            occ.push_back(sector[i]);
        }
    }
    trackOccupancy = occ;
    return occ;
}

void Wayside::importPLC(string filename)
{
    plc.importPLC(filename);
}

void Wayside::runPLC()
{
    plc.execute();
}

void Wayside::runPLCOnce(int p)
{
    plc.setPos(p);
    plc.runPLCOnce();
}
