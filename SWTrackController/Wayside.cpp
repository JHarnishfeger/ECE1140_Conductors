#include "Wayside.h"

Wayside::Wayside(vector<Block> track, bool ln)
{
    suggestedSpeed = 0;
    manualMode = 0;
    id = 0;
    sector = track;
    PLCController p(sector);
    plc = p;
    line = ln;
    for(int i=0;i<sector.size();i++)
    {
        if(sector[i].getType()=="switch")
            swich.push_back(sector[i]);
        else if(sector[i].getType()=="crossing")
            crossing.push_back(sector[i]);
        else if(sector[i].getRailStatus())
            brokenRail.push_back(sector[i]);
    }
    WayStruct ws;
    wayStr = ws;
}

Wayside::Wayside()
{
    suggestedSpeed = 0;
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
    this->sector = w.sector;
    this->swich = w.swich;
    this->crossing = w.crossing;
    this->brokenRail = w.brokenRail;
    this->trackOccupancy = w.getTrackOccupancy();
    this->plc = w.plc;
    return *this;
}

void Wayside::update()
{
    suggestedSpeed = wayStr.suggestedSpeed;
    sector = wayStr.sector;
    authority = wayStr.auth;
    detectTrack();
    wayStr.sector = sector;
    wayStr.auth = authority;
    wayStr.id = id;
}

void Wayside::updateNoPLC()
{
    bool found=0;
    for(int i=0;i<sector.size();i++)
    {
        for(int j=0;j<swich.size();j++)
        {
            if(swich[j].getSwitchStatus()!=sector[i].getSwitchStatus()&&swich[j].getId()==sector[i].getId()) //IF SWITCH IS DIFFERENT THAN LOCAL POSITION
            {
                alerts.push_back("SWITCH " + std::to_string(swich[j].getId()) + " TOGGLED");
                swich[j].setSwitchStatus(sector[i].getSwitchStatus());
            }
        }
        for(int j=0;j<crossing.size();j++)
        {
            if(crossing[j].getCrossingStatus()!=sector[i].getCrossingStatus()&&crossing[j].getId()==sector[i].getId()) //IF CROSSING IS DIFFERENT THAN LOCAL POSITION
            {
                alerts.push_back("CROSSING " + std::to_string(crossing[j].getId()) + " TOGGLED");
                crossing[j].setCrossingStatus(sector[i].getCrossingStatus());
            }
        }
        for(int j=0;j<brokenRail.size();j++)
        {
            if(brokenRail[j].getRailStatus()!=sector[i].getRailStatus()&&brokenRail[j].getId()==sector[i].getId()) //IF BROKEN RAIL STATUS IS DIFFERENT THAN LOCAL VALUE
            {
                alerts.push_back("RAIL " + std::to_string(brokenRail[j].getId()) + " BROKEN");
                brokenRail[j].setRailStatus(sector[i].getRailStatus());
                found = 1;
            }
        }
        if(!found&&sector[i].getRailStatus()==true)
            brokenRail.push_back(sector[i]);
    }
}

bool Wayside::detectTrack()
{
    bool found=0;
    runPLC();
    for(int i=0;i<sector.size();i++)
    {
        for(int j=0;j<swich.size();j++)
        {
            if(swich[j].getSwitchStatus()!=sector[i].getSwitchStatus()&&swich[j].getId()==sector[i].getId())//IF SWITCH IS DIFFERENT THAN LOCAL POSITION
            {
                alerts.push_back("SWITCH " + std::to_string(swich[j].getId()) + " TOGGLED");
                swich[j].setSwitchStatus(sector[i].getSwitchStatus());
            }
        }
        for(int j=0;j<crossing.size();j++)
        {
            if(crossing[j].getCrossingStatus()!=sector[i].getCrossingStatus()&&crossing[j].getId()==sector[i].getId())//IF CROSSING IS DIFFERENT THAN LOCAL POSITION
            {
                alerts.push_back("CROSSING " + std::to_string(crossing[j].getId()) + " TOGGLED");
                crossing[j].setCrossingStatus(sector[i].getCrossingStatus());
            }
        }
        for(int j=0;j<brokenRail.size();j++)
        {
            if(brokenRail[j].getRailStatus()!=sector[i].getRailStatus()&&brokenRail[j].getId()==sector[i].getId())//IF BROKEN RAIL STATUS IS DIFFERENT THAN LOCAL VALUE
            {
                alerts.push_back("RAIL " + std::to_string(brokenRail[j].getId()) + " BROKEN");
                brokenRail[j].setRailStatus(sector[i].getRailStatus());
                found = 1;
            }
        }
        if(!found&&sector[i].getRailStatus()==true)
            brokenRail.push_back(sector[i]);
        if(plc.SS[i]==1)
            sector[i].setSuggestedSpeed(sector[i].getSpeedLimit());
        if(plc.ST[i]==1)
            sector[i].setSuggestedSpeed(0);
        else
            sector[i].setSuggestedSpeed(sector[i].getSpeedLimit());
    }
    return 1;
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

vector<Authority> Wayside::getAuthority()
{
    return authority;
}

void Wayside::setAuthority(vector<Authority> au)
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
    for(int i=0;i<brokenRail.size();i++)
        for(int j=0;j<brokenRail.size();j++)
        {
            if(i==j)
                continue;
            else if(brokenRail[i].getId()==brokenRail[j].getId())
            {
                brokenRail.erase(brokenRail.begin()+j);
                j--;
            }
        }
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
    for(int i=0;i<sector.size();i++)
    {
        if(sector[i].getId()==sw.getId())
        {
            sw.setSwitchStatus(!sw.getSwitchStatus());
            break;
        }
    }
    updateNoPLC();
    return sw.getSwitchStatus();
}

bool Wayside::toggleCrossing(Block &cr)
{
    for(int i=0;i<sector.size();i++)
    {
        if(sector[i].getId()==cr.getId())
        {
            cr.setCrossingStatus(!cr.getCrossingStatus());
            break;
        }
    }
    updateNoPLC();
    return cr.getCrossingStatus();
}

vector<Block> Wayside::getTrackOccupancy()
{
    vector<Block> occ;
    occ.clear();
    trackOccupancy.clear();
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
    plc.track = sector;
    plc.importPLC(filename);
}

void Wayside::runPLC()
{
    plc.auth = authority;
    plc.track = sector;
    plc.execute();
    plc.verifyPLC();
    updateFromPLC();
}

/*void Wayside::runPLCOnce(int p)
{
    plc.track = sector;
    plc.setPos(p);
    plc.runPLCOnce();
    updateFromPLC();
}*/

bool Wayside::updateFromPLC()
{
    bool change=0;
    for(int i=0;i<sector.size();i++)
    {
        if(sector[i].getSwitchStatus()!=plc.SW[i])
        {
            //ALERT
            change = 1;
            sector[i].setSwitchStatus(plc.SW[i]);
        }
        if(sector[i].getCrossingStatus()!=plc.CR[i])
        {
            //ALERT
            change = 1;
            sector[i].setCrossingStatus(plc.CR[i]);
        }
    }
    //std::cout << change << std::endl;
    return change;
}

void Wayside::wayStrInit()
{
    wayStr.suggestedSpeed = suggestedSpeed;
    wayStr.id = id;
    wayStr.sector = sector;
    wayStr.auth = authority;
}
