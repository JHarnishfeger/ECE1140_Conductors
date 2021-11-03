#include "PLCController.h"

PLCController::PLCController()
{
    pos = 0;
}

PLCController::PLCController(vector<Block> tr, vector<Block> occ)
{
    pos = 0;
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
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent());
        SL.push_back(track[i].getType()=="switch");
        CL.push_back(track[i].getType()=="crossing");
        SW.push_back(track[i].getSwitch());
        CR.push_back(track[i].getCrossing());
    }
}

PLCController& PLCController::operator=(PLCController& p)
{
    this->pos = p.getPos();
    this->track = p.track;
    return *this;
}

int PLCController::getPos()
{
    return pos;
}

void PLCController::setPos(int i)
{
    pos = i;
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
            track[pos].setBrokenRail(true);
            flag = 1;
        }
        if(track[pos].getType()=="switch")
        {
            switchValid = !track[pos].getTrainPresent();
            branchValid = !branchOccupied(track[pos+1]);
            if(checkSwitches(switchValid,branchValid))
            {
                switchTrack();
                flag = 1;
            }
        }
        else if(track[pos].getType()=="crossing")
        {
            branchValid = !branchOccupied(track[pos]);
            if(checkCrossings(branchValid))
            {
                toggleCrossing();
                flag = 1;
            }
        }
        if(pos<track.size()-1)
            ++pos;
        else
        {
            pos = 0;
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
    return track[pos].getBrokenRail();
}
bool PLCController::checkCrossings(bool cr) //Uses PLC program to check for railroad crossings that need to be activated, returns 1 on applicable block. Part of checkTrack().
{
    return !cr;
}

bool PLCController::switchTrack()
{
    track[pos].setSwitch(!track[pos].getSwitch());
    return track[pos].getSwitch();
}

bool PLCController::toggleCrossing()
{
    track[pos].setCrossing(!track[pos].getCrossing());
    return track[pos].getCrossing();
}

void PLCController::importPLC(string file)
{
    filename = file;
    TR.clear();
    SL.clear();
    CL.clear();
    SW.clear();
    CR.clear();
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent());
        SL.push_back(track[i].getType()=="switch");
        CL.push_back(track[i].getType()=="crossing");
        SW.push_back(track[i].getSwitch());
        CR.push_back(track[i].getCrossing());
    }
}

void PLCController::runPLC()
{
    std::ifstream plc(filename);
    string line;
    string command;
    string arg;
    string dataTarget;
    string posTarget;
    int posOffset;
    vector<string> args;
    bool value=0;
    bool inOpp=0;
    bool inTask=0;
    bool error=0;
    bool allArgs=0;
    bool negate=0;
    int stretch = 0;
    vector<bool> argVals;
    string opp;
    vector<string> opps;
    while(std::getline(plc,line))
    {
        command = "";
        //std::cout << line << std::endl;
        stringstream lineParse(line);
        //std::cout << lineParse.str() << std::endl;
        lineParse >> command;
        //std::cout << command << std::endl;
        if(command=="TASK")
        {
            inTask = 1;
        }
        else if(command=="ENDTASK")
        {
            inTask = 0;
        }
        else if(command=="OPP"&&inTask)
        {
            arg = "";
            opp = "";
            value = 0;
            allArgs = 0;
            argVals.clear();
            args.clear();
            opps.clear();

            for(int i=0;i<3;i++)
            {
                arg = "";
                error = 0;
                lineParse >> arg; //READING ARGUMENT <-- ISSUE: The program continues reading in the last word rather than "" when empty
                if(arg=="")
                    break;
                //std::cout << arg[0] << ", " << arg.back() << std::endl;
                if(arg[0]!='('||arg.back()!=')')
                {
                    error = 1;
                    break;
                }
                else
                {
                    arg.erase(0,1);
                    arg.pop_back();
                    args.push_back(arg);
                }
                lineParse >> opp;
                if(opp=="")
                    break;
                opps.push_back(opp);
            }
            if(error)
            {
                std::cout << "An error occurred." << std::endl;
                break;
            }

            //std::cout << "Num of args: " << args.size() << std::endl;
            for(int i=0;i<args.size();i++) //Computing values for arguments
            {
                negate = 0;
                stretch = 0;
                if(args[i][0]=='!')
                {
                    negate = 1;
                    args[i].erase(0,1);
                }

                if(args[i]!="1"&&args[i]!="0")
                {
                    dataTarget = args[i].substr(0,2);
                    args[i].erase(0,2);

                    if(args[i].back()=='+')
                    {
                        stretch = 1;
                        args[i].pop_back();
                    }
                    else if(args[i].back()=='-')
                    {
                        stretch = -1;
                        args[i].pop_back();
                    }

                    posTarget = args[i];
                    if(posTarget!="")
                        posOffset = std::stoi(posTarget);
                    else
                        posOffset = 0;
                }
                else
                    stretch = 2;

                //std::cout << "Here, right?" << std::endl;

                if(dataTarget=="TR")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<TR.size();j++)
                                argVals[i] = argVals[i] || TR[j];
                    }
                    else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<TR.size())
                        argVals.push_back(TR[pos+posOffset]);
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<TR.size();j++)
                        {
                            if(pos+posOffset<TR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || TR[j];
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(pos+posOffset<TR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || TR[j];
                        }
                    }
                }
                else if(dataTarget=="SL")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<SL.size();j++)
                                argVals[i] = argVals[i] || SL[j];
                    }
                    else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SL.size())
                        argVals.push_back(SL[pos+posOffset]);
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<SL.size();j++)
                        {
                            if(pos+posOffset<SL.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SL[j];
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(pos+posOffset<SL.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SL[j];
                        }
                    }
                }
                else if(dataTarget=="SW")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<SW.size();j++)
                                argVals[i] = argVals[i] || SW[j];
                    }
                    else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SW.size())
                        argVals.push_back(SW[pos+posOffset]);
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<SW.size();j++)
                        {
                            if(pos+posOffset<SW.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SW[j];
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(pos+posOffset<SW.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SW[j];
                        }
                    }
                }
                else if(dataTarget=="CL")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<CL.size();j++)
                                argVals[i] = argVals[i] || CL[j];
                    }
                    else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<CL.size())
                        argVals.push_back(CL[pos+posOffset]);
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<CL.size();j++)
                        {
                            if(pos+posOffset<CL.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CL[j];
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(pos+posOffset<CL.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CL[j];
                        }
                    }
                }
                else if(dataTarget=="CR")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<CR.size();j++)
                                argVals[i] = argVals[i] || CR[j];
                    }
                    else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<CR.size())
                        argVals.push_back(CR[pos+posOffset]);
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<CR.size();j++)
                        {
                            if(pos+posOffset<CR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CR[j];
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(pos+posOffset<CR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CR[j];
                        }
                    }
                }

                if(negate)
                    argVals[i] = !argVals[i];
            }

            value = argVals[0];
            //std::cout << "Vals: " << argVals[0];
            for(int i=1;i<argVals.size();i++)
            {
                //std::cout << " " << argVals[i];
                if(opps[i-1]=="&")
                    value = value && argVals[i];
                else if(opps[i-1]=="|")
                    value = value || argVals[i];
            }
            //std::cout << std::endl;

            inOpp = value;
        }
        else if(command=="OUT"&&inTask&&inOpp)
        {
            lineParse >> arg;
            lineParse >> value;

            dataTarget = arg.substr(0,2);
            arg.erase(0,2);

            if(arg[arg.size()-1]=='+')
            {
                stretch = 1;
                arg.pop_back();
            }
            else if(arg[arg.size()-1]=='-')
            {
                stretch = -1;
                arg.pop_back();
            }

            posTarget = arg;
            if(posTarget!="")
                posOffset = std::stoi(posTarget);
            else
                stretch = 2;

            if(dataTarget=="TR")
            {
                if(stretch==2)
                {
                    for(int j=0;j<TR.size();j++)
                        TR[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<TR.size())
                    TR[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<TR.size();j++)
                    {
                        if(pos+posOffset>=0)
                            TR[j] = value;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(pos+posOffset<TR.size())
                            TR[j] = value;
                    }
                }
            }
            else if(dataTarget=="SL")
            {
                if(stretch==2)
                {
                    for(int j=0;j<SL.size();j++)
                        SL[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SL.size())
                    SL[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<SL.size();j++)
                    {
                        if(pos+posOffset>=0)
                            SL[j] = value;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(pos+posOffset<SL.size())
                            SL[j] = value;
                    }
                }
            }
            else if(dataTarget=="SW")
            {
                if(stretch==2)
                {
                    for(int j=0;j<SW.size();j++)
                        SW[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SW.size())
                    SW[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<SW.size();j++)
                    {
                        if(pos+posOffset>=0)
                            SW[j] = value;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(pos+posOffset<SW.size())
                            SW[j] = value;
                    }
                }
            }
            else if(dataTarget=="CL")
            {
                if(stretch==2)
                {
                    for(int j=0;j<CL.size();j++)
                        CL[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<CL.size())
                    CL[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<CL.size();j++)
                    {
                        if(pos+posOffset>=0)
                            CL[j] = value;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(pos+posOffset<CL.size())
                            CL[j] = value;
                    }
                }
            }
            else if(dataTarget=="CR")
            {
                if(stretch==2)
                {
                    for(int j=0;j<CR.size();j++)
                        CR[j] = value;
                }
                if(stretch==0&&pos+posOffset>=0&&pos+posOffset<CR.size())
                    CR[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<CR.size();j++)
                    {
                        if(pos+posOffset>=0)
                            CR[j] = value;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(pos+posOffset<CR.size())
                            CR[j] = value;
                    }
                }
            }
        }
        else if(command[0]=='#')
            continue;
    }
}

void PLCController::execute()
{
    TR.clear();
    SL.clear();
    CL.clear();
    SW.clear();
    CR.clear();
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent());
        SL.push_back(track[i].getType()=="switch");
        CL.push_back(track[i].getType()=="crossing");
        SW.push_back(track[i].getSwitch());
        CR.push_back(track[i].getCrossing());
    }

    std::cout << "TR Values      : ";
    for(int i=0;i<TR.size();i++)
        std::cout << TR[i] << " ";
    std::cout << std::endl << "SL Values      : ";
    for(int i=0;i<SL.size();i++)
        std::cout << SL[i] << " ";
    std::cout << std::endl << "SW Values      : ";
    for(int i=0;i<SW.size();i++)
        std::cout << SW[i] << " ";
    std::cout << std::endl << "CL Values      : ";
    for(int i=0;i<CL.size();i++)
        std::cout << CL[i] << " ";
    std::cout << std::endl << "CR Values      : ";
    for(int i=0;i<CR.size();i++)
        std::cout << CR[i] << " ";
    std::cout << std::endl << std::endl;

    for(pos=0;pos<TR.size();pos++)
        runPLC();

    std::cout << "Final TR Values: ";
    for(int i=0;i<TR.size();i++)
        std::cout << TR[i] << " ";
    std::cout << std::endl << "Final SL Values: ";
    for(int i=0;i<SL.size();i++)
        std::cout << SL[i] << " ";
    std::cout << std::endl << "Final SW Values: ";
    for(int i=0;i<SW.size();i++)
        std::cout << SW[i] << " ";
    std::cout << std::endl << "Final CL Values: ";
    for(int i=0;i<CL.size();i++)
        std::cout << CL[i] << " ";
    std::cout << std::endl << "Final CR Values: ";
    for(int i=0;i<CR.size();i++)
        std::cout << CR[i] << " ";
    std::cout << std::endl << std::endl;
}

void PLCController::runPLCOnce()
{
    TR.clear();
    SL.clear();
    CL.clear();
    SW.clear();
    CR.clear();
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent());
        SL.push_back(track[i].getType()=="switch");
        CL.push_back(track[i].getType()=="crossing");
        SW.push_back(track[i].getSwitch());
        CR.push_back(track[i].getCrossing());
    }

    std::cout << "TR Values      : ";
    for(int i=0;i<TR.size();i++)
        std::cout << TR[i] << " ";
    std::cout << std::endl << "SL Values      : ";
    for(int i=0;i<SL.size();i++)
        std::cout << SL[i] << " ";
    std::cout << std::endl << "SW Values      : ";
    for(int i=0;i<SW.size();i++)
        std::cout << SW[i] << " ";
    std::cout << std::endl << "CL Values      : ";
    for(int i=0;i<CL.size();i++)
        std::cout << CL[i] << " ";
    std::cout << std::endl << "CR Values      : ";
    for(int i=0;i<CR.size();i++)
        std::cout << CR[i] << " ";
    std::cout << std::endl << std::endl;

    runPLC();

    std::cout << "Final TR Values: ";
    for(int i=0;i<TR.size();i++)
        std::cout << TR[i] << " ";
    std::cout << std::endl << "Final SL Values: ";
    for(int i=0;i<SL.size();i++)
        std::cout << SL[i] << " ";
    std::cout << std::endl << "Final SW Values: ";
    for(int i=0;i<SW.size();i++)
        std::cout << SW[i] << " ";
    std::cout << std::endl << "Final CL Values: ";
    for(int i=0;i<CL.size();i++)
        std::cout << CL[i] << " ";
    std::cout << std::endl << "Final CR Values: ";
    for(int i=0;i<CR.size();i++)
        std::cout << CR[i] << " ";
    std::cout << std::endl << std::endl;
}
