#include "PLCController.h"

PLCController::PLCController()
{
    pos = 0;
}

PLCController::PLCController(vector<Block> tr)
{
    pos = 0;
    track = tr;
    bool flag = 0;
    /*for(int i=0;i<occupancy.size();i++)
    {
        for(int j=0;j<branchOccupancy.size();j++)
        {
            if(occupancy[i].getBranch()==branchOccupancy[j])
                flag = 1;
        }
        if(!flag)
            branchOccupancy.push_back(occupancy[i].getBranch());
        flag = 0;
    }*/
    bool auCheck;
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent()); //TRAIN
        SL.push_back(track[i].getType()=="switch"); //SWITCH LOCATION
        CL.push_back(track[i].getType()=="crossing"); //CROSSING LOCATION
        SW.push_back(track[i].getSwitchStatus()); //SWITCH POSITION
        CR.push_back(track[i].getCrossingStatus()); //CROSSING POSITION
        BR.push_back(track[i].getRailStatus()); //BROKEN RAIL
        SS.push_back(track[i].getSuggestedSpeed()>track[i].getSpeedLimit()); //SUGGESTED SPEED
        SR.push_back(0); //SPEED RESET
        ST.push_back(0);
        SA.push_back(track[i].getType()=="station"); //STATION LOCATION
        auCheck = 0;
        for(int j=0;j<auth.size();j++)
        {
            if(track[i].getBranch()==auth[j].branch&&track[i].getId()<=auth[j].endBlock)
                auCheck = 1;
        }
        AU.push_back(auCheck);
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

string PLCController::getFilename()
{
    return filename;
}

bool PLCController::switchTrack()
{
    track[pos].setSwitchStatus(!track[pos].getSwitchStatus());
    return track[pos].getSwitchStatus();
}

bool PLCController::toggleCrossing()
{
    track[pos].setCrossingStatus(!track[pos].getCrossingStatus());
    return track[pos].getCrossingStatus();
}

void PLCController::importPLC(string file)
{
    bool auCheck;
    filename = file;
    TR.clear();
    SL.clear();
    CL.clear();
    SW.clear();
    CR.clear();
    BR.clear();
    SS.clear();
    SR.clear();
    ST.clear();
    SA.clear();
    AU.clear();
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent()); //TRAIN
        SL.push_back(track[i].getType()=="switch"); //SWITCH LOCATION
        CL.push_back(track[i].getType()=="crossing"); //CROSSING LOCATION
        SW.push_back(track[i].getSwitchStatus()); //SWITCH POSITION
        CR.push_back(track[i].getCrossingStatus()); //CROSSING POSITION
        BR.push_back(track[i].getRailStatus()); //BROKEN RAIL
        SS.push_back(track[i].getSuggestedSpeed()>track[i].getSpeedLimit()); //SUGGESTED SPEED
        SR.push_back(0); //SPEED RESET
        ST.push_back(0); //STOP
        SA.push_back(track[i].getType()=="station"); //STATION LOCATION
        auCheck = 0;
        for(int j=0;j<auth.size();j++)
        {
            if(track[i].getBranch()==auth[j].branch&&track[i].getId()<=auth[j].endBlock)
                auCheck = 1;
        }
        AU.push_back(auCheck);
    }
}

bool PLCController::runPLC()
{
    std::ifstream plc(filename);
    /*if(!plc.good())
        return 0;*/
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
        stretch = 0;
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
            //std::cout << line << std::endl;
            arg = "";
            opp = "";
            value = 0;
            allArgs = 0;
            argVals.clear();
            args.clear();
            opps.clear();

            for(int i=0;i<10;i++)
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
                return 0;
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
                    {
                        stretch = 2;
                        posOffset = 0;
                    }
                }
                else
                    stretch = 2;

                //std::cout << "Here, right?" << std::endl;
                //std::cout << "Stretch " << stretch << std::endl;
                if(dataTarget=="TR")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<TR.size();j++)
                                argVals[i] = argVals[i] || TR[j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<TR.size())
                            argVals.push_back(TR[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<TR.size();j++)
                        {
                            if(pos+posOffset<TR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || TR[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
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
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<SL.size())
                            argVals.push_back(SL[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
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
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<SW.size())
                            argVals.push_back(SW[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<SW.size();j++)
                        {
                            if(pos+posOffset<SW.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SW[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
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
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<CL.size())
                            argVals.push_back(CL[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<CL.size();j++)
                        {
                            if(pos+posOffset<CL.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CL[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
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
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<CR.size())
                            argVals.push_back(CR[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<CR.size();j++)
                        {
                            if(pos+posOffset<CR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CR[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
                            if(pos+posOffset<CR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || CR[j];
                        }
                    }
                }
                else if(dataTarget=="BR")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<BR.size();j++)
                                argVals[i] = argVals[i] || BR[j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<BR.size())
                            argVals.push_back(BR[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<BR.size();j++)
                        {
                            if(pos+posOffset<BR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || BR[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
                            if(pos+posOffset<SL.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SL[j];
                        }
                    }
                }
                else if(dataTarget=="SS")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<SS.size();j++)
                                argVals[i] = argVals[i] || SS[j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<SS.size())
                            argVals.push_back(SS[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<SS.size();j++)
                        {
                            if(pos+posOffset<SS.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SS[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
                            if(pos+posOffset<SS.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SS[j];
                        }
                    }
                }
                else if(dataTarget=="SR")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<SR.size();j++)
                                argVals[i] = argVals[i] || SR[j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<SR.size())
                            argVals.push_back(SR[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<SR.size();j++)
                        {
                            if(pos+posOffset<SR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SR[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
                            if(pos+posOffset<SR.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SR[j];
                        }
                    }
                }
                else if(dataTarget=="ST")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<SR.size();j++)
                                argVals[i] = argVals[i] || ST[j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<ST.size())
                            argVals.push_back(ST[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<ST.size();j++)
                        {
                            if(pos+posOffset<ST.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || ST[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
                            if(pos+posOffset<ST.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || ST[j];
                        }
                    }
                }
                else if(dataTarget=="SA")
                {
                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<SA.size();j++)
                                argVals[i] = argVals[i] || SA[j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<SA.size())
                            argVals.push_back(SA[pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<SA.size();j++)
                        {
                            if(pos+posOffset<SA.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SA[j];
                            if(SL[j]==1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(SL[j]==1)
                                break;
                            if(pos+posOffset<SA.size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || SA[j];
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
            //std::cout << "VALUE: " << value << std::endl;
            //if(inOpp) //TESTING
            //    std::cout << "Hit!" << std::endl;
        }
        else if(command=="OUT"&&inTask&&inOpp)
        {
            lineParse >> arg;
            lineParse >> value;

            //std::cout << "Arg: " << arg << ", Val: " << value << std::endl;
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

            //std::cout << "Stretch: " << stretch << std::endl;
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
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
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
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
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
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
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
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<CR.size())
                            CR[j] = value;
                    }
                }
            }
            else if(dataTarget=="BR")
            {
                if(stretch==2)
                {
                    for(int j=0;j<BR.size();j++)
                        BR[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<BR.size())
                    BR[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<BR.size();j++)
                    {
                        if(pos+posOffset>=0)
                            BR[j] = value;
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<BR.size())
                            BR[j] = value;
                    }
                }
            }
            else if(dataTarget=="SS")
            {
                if(stretch==2)
                {
                    for(int j=0;j<SS.size();j++)
                        SS[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SS.size())
                    SS[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<SS.size();j++)
                    {
                        if(pos+posOffset>=0)
                            SS[j] = value;
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<SS.size())
                            SS[j] = value;
                    }
                }
            }
            else if(dataTarget=="SR")
            {
                if(stretch==2)
                {
                    for(int j=0;j<SR.size();j++)
                        SR[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SR.size())
                    SR[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<SR.size();j++)
                    {
                        if(pos+posOffset>=0)
                            SR[j] = value;
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<SR.size())
                            SR[j] = value;
                    }
                }
            }
            else if(dataTarget=="ST")
            {
                if(stretch==2)
                {
                    for(int j=0;j<ST.size();j++)
                        ST[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<ST.size())
                    ST[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<ST.size();j++)
                    {
                        if(pos+posOffset>=0)
                            ST[j] = value;
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<ST.size())
                            ST[j] = value;
                    }
                }
            }
            else if(dataTarget=="SA")
            {
                if(stretch==2)
                {
                    for(int j=0;j<SA.size();j++)
                        SA[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<SA.size())
                    SA[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<SA.size();j++)
                    {
                        if(pos+posOffset>=0)
                            SA[j] = value;
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<SA.size())
                            SA[j] = value;
                    }
                }
            }
            else if(dataTarget=="AU")
            {
                if(stretch==2)
                {
                    for(int j=0;j<AU.size();j++)
                        AU[j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<AU.size())
                    AU[pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<AU.size();j++)
                    {
                        if(pos+posOffset>=0)
                            AU[j] = value;
                        if(SL[j]==1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(SL[j]==1)
                            break;
                        if(pos+posOffset<AU.size())
                            AU[j] = value;
                    }
                }
            }
        }
        else if(command[0]=='#')
            continue;
    }
    plc.close();
    return 1;
}

void PLCController::execute()
{
    bool auCheck;
    TR.clear();
    SL.clear();
    CL.clear();
    SW.clear();
    CR.clear();
    BR.clear();
    SS.clear();
    SR.clear();
    ST.clear();
    SA.clear();
    AU.clear();
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent()); //TRAIN
        SL.push_back(track[i].getType()=="switch"); //SWITCH LOCATION
        CL.push_back(track[i].getType()=="crossing"); //CROSSING LOCATION
        SW.push_back(track[i].getSwitchStatus()); //SWITCH POSITION
        CR.push_back(track[i].getCrossingStatus()); //CROSSING POSITION
        BR.push_back(track[i].getRailStatus()); //BROKEN RAIL
        SS.push_back(track[i].getSuggestedSpeed()>track[i].getSpeedLimit()); //SUGGESTED SPEED
        SR.push_back(0); //SPEED RESET
        ST.push_back(0); //STOP
        SA.push_back(track[i].getType()=="station"); //STATION LOCATION
        auCheck = 0;
        for(int j=0;j<auth.size();j++)
        {
            if(track[i].getBranch()==auth[j].branch&&track[i].getId()<=auth[j].endBlock)
                auCheck = 1;
        }
        AU.push_back(auCheck);
    }
    checkVecs.clear();
    checkVecs.push_back(TR);
    checkVecs.push_back(SL);
    checkVecs.push_back(CL);
    checkVecs.push_back(SW);
    checkVecs.push_back(CR);
    checkVecs.push_back(BR);
    checkVecs.push_back(SS);
    checkVecs.push_back(SR);
    checkVecs.push_back(ST);
    checkVecs.push_back(SA);
    checkVecs.push_back(AU);
    oldVecs.clear();
    oldVecs.push_back(TR);
    oldVecs.push_back(SL);
    oldVecs.push_back(CL);
    oldVecs.push_back(SW);
    oldVecs.push_back(CR);
    oldVecs.push_back(BR);
    oldVecs.push_back(SS);
    oldVecs.push_back(SR);
    oldVecs.push_back(ST);
    oldVecs.push_back(SA);
    oldVecs.push_back(AU);

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
    std::cout << std::endl << "BR Values      : ";
    for(int i=0;i<BR.size();i++)
        std::cout << BR[i] << " ";
    std::cout << std::endl << "SS Values      : ";
    for(int i=0;i<SS.size();i++)
        std::cout << SS[i] << " ";
    std::cout << std::endl << "SR Values      : ";
    for(int i=0;i<SR.size();i++)
        std::cout << SR[i] << " ";
    std::cout << std::endl << "ST Values      : ";
    for(int i=0;i<ST.size();i++)
        std::cout << ST[i] << " ";
    std::cout << std::endl << "SA Values      : ";
    for(int i=0;i<SA.size();i++)
        std::cout << SA[i] << " ";
    std::cout << std::endl << "AU Values      : ";
    for(int i=0;i<AU.size();i++)
        std::cout << AU[i] << " ";
    std::cout << std::endl << std::endl;

    for(pos=0;pos<TR.size();pos++)
    {
        //std::cout << "Executing " << filename << " at position " << pos << std::endl;
        runPLC();
    }

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
    std::cout << std::endl << "Final BR Values: ";
    for(int i=0;i<BR.size();i++)
        std::cout << BR[i] << " ";
    std::cout << std::endl << "Final SS Values: ";
    for(int i=0;i<SS.size();i++)
        std::cout << SS[i] << " ";
    std::cout << std::endl << "Final SR Values: ";
    for(int i=0;i<SR.size();i++)
        std::cout << SR[i] << " ";
    std::cout << std::endl << "Final ST Values: ";
    for(int i=0;i<ST.size();i++)
        std::cout << ST[i] << " ";
    std::cout << std::endl << "Final SA Values: ";
    for(int i=0;i<SA.size();i++)
        std::cout << SA[i] << " ";
    std::cout << std::endl << "Final AU Values: ";
    for(int i=0;i<AU.size();i++)
        std::cout << AU[i] << " ";
    std::cout << std::endl << std::endl;
}

/*void PLCController::runPLCOnce()
{
    TR.clear();
    SL.clear();
    CL.clear();
    SW.clear();
    CR.clear();
    BR.clear();
    SS.clear();
    SR.clear();
    ST.clear();
    SA.clear();
    for(int i=0;i<track.size();i++)
    {
        TR.push_back(track[i].getTrainPresent()); //TRAIN
        SL.push_back(track[i].getType()=="switch"); //SWITCH LOCATION
        CL.push_back(track[i].getType()=="crossing"); //CROSSING LOCATION
        SW.push_back(track[i].getSwitchStatus()); //SWITCH POSITION
        CR.push_back(track[i].getCrossingStatus()); //CROSSING POSITION
        BR.push_back(track[i].getRailStatus()); //BROKEN RAIL
        SS.push_back(track[i].getSuggestedSpeed()>track[i].getSpeedLimit()); //SUGGESTED SPEED
        SR.push_back(0); //SPEED RESET
        ST.push_back(0); //STOP
        SA.push_back(track[i].getType()=="station"); //STATION LOCATION
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
    std::cout << std::endl << "BR Values      : ";
    for(int i=0;i<BR.size();i++)
        std::cout << BR[i] << " ";
    std::cout << std::endl << "SS Values      : ";
    for(int i=0;i<SS.size();i++)
        std::cout << SS[i] << " ";
    std::cout << std::endl << "SR Values      : ";
    for(int i=0;i<SR.size();i++)
        std::cout << SR[i] << " ";
    std::cout << std::endl << "ST Values      : ";
    for(int i=0;i<ST.size();i++)
        std::cout << ST[i] << " ";
    std::cout << std::endl << "SA Values      : ";
    for(int i=0;i<SA.size();i++)
        std::cout << SA[i] << " ";
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
    std::cout << std::endl << "Final BR Values: ";
    for(int i=0;i<BR.size();i++)
        std::cout << BR[i] << " ";
    std::cout << std::endl << "Final SS Values: ";
    for(int i=0;i<SS.size();i++)
        std::cout << SS[i] << " ";
    std::cout << std::endl << "Final SR Values: ";
    for(int i=0;i<SR.size();i++)
        std::cout << SR[i] << " ";
    std::cout << std::endl << "Final ST Values: ";
    for(int i=0;i<ST.size();i++)
        std::cout << ST[i] << " ";
    std::cout << std::endl << "Final SA Values: ";
    for(int i=0;i<SA.size();i++)
        std::cout << SA[i] << " ";
    std::cout << std::endl << std::endl;
}*/

bool PLCController::verifyPLC()
{
    bool correct=1;
    for(pos=0;pos<TR.size();pos++)
    {
        std::ifstream plc(filename);
        string line;
        string command;
        string arg;
        string dataTarget;
        string posTarget;
        int posOffset;
        vector<string> args;
        int index;
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
            //std::cout << line << std::endl;
            command = "";
            stretch = 0;
            stringstream lineParse(line);
            lineParse >> command;
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
                //std::cout << line << std::endl;
                arg = "";
                opp = "";
                value = 0;
                allArgs = 0;
                argVals.clear();
                args.clear();
                opps.clear();

                for(int i=0;i<10;i++)
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
                    return 0;
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
                        {
                            stretch = 2;
                            posOffset = 0;
                        }
                    }
                    else
                        stretch = 2;
                    //std::cout << "Here, right?" << std::endl;
                    //std::cout << "Stretch " << stretch << std::endl;

                    if(dataTarget=="TR")
                        index = 0;
                    else if(dataTarget=="SL")
                        index = 1;
                    else if(dataTarget=="CL")
                        index = 2;
                    else if(dataTarget=="SW")
                        index = 3;
                    else if(dataTarget=="CR")
                        index = 4;
                    else if(dataTarget=="BR")
                        index = 5;
                    else if(dataTarget=="SS")
                        index = 6;
                    else if(dataTarget=="SR")
                        index = 7;
                    else if(dataTarget=="ST")
                        index = 8;
                    else if(dataTarget=="SA")
                        index = 9;
                    else if(dataTarget=="AU")
                        index = 10;

                    if(stretch==2)
                    {
                        argVals.push_back(0);
                        for(int j=0;j<checkVecs[index].size();j++)
                                argVals[i] = argVals[i] || checkVecs[index][j];
                    }
                    else if(stretch==0)
                    {
                        if(pos+posOffset>=0&&pos+posOffset<checkVecs[index].size())
                            argVals.push_back(checkVecs[index][pos+posOffset]);
                        else
                            argVals.push_back(0);
                    }
                    else if(stretch==1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j<checkVecs[index].size();j++)
                        {
                            if(pos+posOffset<checkVecs[index].size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || checkVecs[index][j];
                            if(checkVecs[1][j]==1&&index!=1)
                                break;
                        }
                    }
                    else if(stretch==-1)
                    {
                        argVals.push_back(0);
                        for(int j=pos+posOffset;j>=0;j--)
                        {
                            if(checkVecs[1][j]==1&&index!=1)
                                break;
                            if(pos+posOffset<checkVecs[index].size()&&pos+posOffset>=0)
                                argVals[i] = argVals[i] || checkVecs[index][j];
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
                //std::cout << "CHECK VALUE: " << value << std::endl;
                //if(inOpp) //TESTING
                //    std::cout << "Hit!" << std::endl;
            }
            if(command=="OUT"&&inTask&&inOpp)
            {
                //std::cout << "we in" << std::endl;
                lineParse >> arg;
                lineParse >> value;

                //std::cout << "Arg: " << arg << ", Val: " << value << std::endl;
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
                    index = 0;
                else if(dataTarget=="SL")
                    index = 1;
                else if(dataTarget=="CL")
                    index = 2;
                else if(dataTarget=="SW")
                    index = 3;
                else if(dataTarget=="CR")
                    index = 4;
                else if(dataTarget=="BR")
                    index = 5;
                else if(dataTarget=="SS")
                    index = 6;
                else if(dataTarget=="SR")
                    index = 7;
                else if(dataTarget=="ST")
                    index = 8;
                else if(dataTarget=="SA")
                    index = 9;
                else if(dataTarget=="AU")
                    index = 10;

                if(stretch==2)
                {
                    for(int j=0;j<checkVecs[index].size();j++)
                        checkVecs[index][j] = value;
                }
                else if(stretch==0&&pos+posOffset>=0&&pos+posOffset<checkVecs[index].size())
                    checkVecs[index][pos+posOffset] = value;
                else if(stretch==1)
                {
                    for(int j=pos+posOffset;j<checkVecs[index].size();j++)
                    {
                        if(pos+posOffset>=0)
                            checkVecs[index][j] = value;
                        if(checkVecs[1][j]==1&&index!=1)
                            break;
                    }
                }
                else if(stretch==-1)
                {
                    for(int j=pos+posOffset;j>=0;j--)
                    {
                        if(checkVecs[1][j]==1&&index!=1)
                            break;
                        if(pos+posOffset<checkVecs[index].size())
                            checkVecs[index][j] = value;
                    }
                }
            }
            else if(command[0]=='#')
                continue;
        }
        plc.close();
    }
    std::cout << "Check TR Values: ";
    for(int i=0;i<checkVecs[0].size();i++)
        std::cout << checkVecs[0][i] << " ";
    std::cout << std::endl << "Check SL Values: ";
    for(int i=0;i<checkVecs[1].size();i++)
        std::cout << checkVecs[1][i] << " ";
    std::cout << std::endl << "Check SW Values: ";
    for(int i=0;i<checkVecs[3].size();i++)
        std::cout << checkVecs[3][i] << " ";
    std::cout << std::endl << "Check CL Values: ";
    for(int i=0;i<checkVecs[2].size();i++)
        std::cout << checkVecs[2][i] << " ";
    std::cout << std::endl << "Check CR Values: ";
    for(int i=0;i<checkVecs[4].size();i++)
        std::cout << checkVecs[4][i] << " ";
    std::cout << std::endl << "Check BR Values: ";
    for(int i=0;i<checkVecs[5].size();i++)
        std::cout << checkVecs[5][i] << " ";
    std::cout << std::endl << "Check SS Values: ";
    for(int i=0;i<checkVecs[6].size();i++)
        std::cout << checkVecs[6][i] << " ";
    std::cout << std::endl << "Check SR Values: ";
    for(int i=0;i<checkVecs[7].size();i++)
        std::cout << checkVecs[7][i] << " ";
    std::cout << std::endl << "Check ST Values: ";
    for(int i=0;i<checkVecs[8].size();i++)
        std::cout << checkVecs[8][i] << " ";
    std::cout << std::endl << "Check SA Values: ";
    for(int i=0;i<checkVecs[9].size();i++)
        std::cout << checkVecs[9][i] << " ";
    std::cout << std::endl << "Check AU Values: ";
    for(int i=0;i<checkVecs[10].size();i++)
        std::cout << checkVecs[10][i] << " ";
    std::cout << std::endl << std::endl;

    correct = correct && (checkVecs[0]==TR);
    correct = correct && (checkVecs[1]==SL);
    correct = correct && (checkVecs[2]==CL);
    correct = correct && (checkVecs[3]==SW);
    correct = correct && (checkVecs[4]==CR);
    correct = correct && (checkVecs[5]==BR);
    correct = correct && (checkVecs[6]==SS);
    correct = correct && (checkVecs[7]==SR);
    correct = correct && (checkVecs[8]==ST);
    correct = correct && (checkVecs[9]==SA);
    correct = correct && (checkVecs[10]==AU);
    std::cout << "VALID: " << correct << std::endl;
    if(!correct)
    {
        TR = oldVecs[0];
        SL = oldVecs[1];
        CL = oldVecs[2];
        SW = oldVecs[3];
        CR = oldVecs[4];
        BR = oldVecs[5];
        SS = oldVecs[6];
        SR = oldVecs[7];
        ST = oldVecs[8];
        SA = oldVecs[9];
        AU = oldVecs[10];
    }
    return correct;
}
