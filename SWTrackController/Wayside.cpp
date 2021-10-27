#include "Wayside.h"

Wayside::Wayside(vector<Block> track, bool ln)
{
    sector = track;
    PLCController p(sector,trackOccupancy);
    plc = p;
    line = ln;
}

Wayside Wayside::operator=(Wayside w)
{
    this->speed = w.getSpeed();
    this->authority = w.getAuthority();
    this->manualMode = w.getMode();
    this->line = w.getLine();
    this->id = w.getID();
}

bool Wayside::detectTrack()
{
    bool detect=0;
    bool check = plc.checkTrack(sector);
    while(check)
    {
        detect = 1;
        sector = plc.track;
        check = plc.checkTrack(sector);
    }
    return detect;
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
    for(int i=0;i<brokenRail.size();i++)
    {
        if(brokenRail[i].getId()==m.getId())
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
