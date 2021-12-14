#include "SWTrackController.cpp"
#include "Wayside.cpp"
#include "PLCController.cpp"
#include "Block.cpp"
#include <Windows.h>
#include <time.h>

Block a('g','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block b('g','a',"CROSSING",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block c('g','a',"SWITCH",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block d('g','a',"RAIL",2.0,true,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false); //Occ
Block e('g','a',"SWITCH",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block f('g','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block g('g','a',"CROSSING",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block h('g','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block i('g','a',"SWITCH",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block j('g','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block k('g','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block l('g','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block m('g','a',"SWITCH",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block n('r','a',"RAIL",2.0,true,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block o('r','a',"SWITCH",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block p('r','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block q('r','a',"CROSSING",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block r('r','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block s('r','a',"SWITCH",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block t('r','a',"RAIL",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
vector<Block> green{a,b,c,d,e,f,g,h,i,j,k,l,m};
vector<Block> red{n,o,p,q,r,s,t};

int main()
{
    //std::cout << "check" << std::endl;
    SWTrackController tc(red,green,2,0,0,0);
    //std::cout << "made" << std::endl;
    string command;
    //std::cin >> command;
    //tc.sanityCheck();
    while(1==1)
    {
        std::system("cls");
        double value;
        string file;
        tc.testValues();
        //tc.plcCheck();
        std::cout << std::endl;
        std::cin >> command;
        std::cin >> value;
        //std::cout << command << ", " << value << std::endl << std::endl;
        if(command=="speed")
            tc.setSuggestedSpeed(value);
        else if(command=="authority")
            tc.setAuthority(value);
        else if(command=="mode")
            tc.setMode(value);
        else if(command=="wayside")
        {
            std::cout << "There are " << tc.waysides.size() << " software waysides around the track." << std::endl;
            Sleep(2000);
        }
        else if(command=="redLine")
        {
            std::cout << "The red line covers blocks " << tc.redLine[0].getBlockNumber() << " to " << tc.redLine[tc.redLine.size()-1].getBlockNumber() << "." << std::endl;
            Sleep(2000);
        }
        else if(command=="greenLine")
        {
            std::cout << "The green line covers blocks " << tc.greenLine[0].getBlockNumber() << " to " << tc.greenLine[tc.greenLine.size()-1].getBlockNumber() << "." << std::endl;
            Sleep(2000);
        }
        else if(command=="break"){
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.addBrokenRail(tc.waysides[i].sector[j]);
        }
        else if(command=="maintenance")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.addMaintenance(tc.waysides[i].sector[j]);
        }
        else if(command=="done")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.endMaintenance(tc.waysides[i].sector[j]);
        }
        else if(command=="SWITCH")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.waysides[i].switchTrack(tc.waysides[i].sector[j]);
        }
        else if(command=="CROSSING")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.waysides[i].toggleCrossing(tc.waysides[i].sector[j]);
        }
        else if(command=="setTrain")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.waysides[i].sector[j].setTrainPresent(true);
            tc.getTrackOccupancy();
        }
        else if(command=="removeTrain")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getBlockNumber()==value)
                        tc.waysides[i].sector[j].setTrainPresent(false);
            tc.getTrackOccupancy();
        }
        else if(command=="runPLC")
        {
            std::cin >> file;
            for(int i=0;i<tc.waysides.size();i++)
            {
                tc.waysides[i].importPLC(file);
                tc.waysides[i].detectTrack();
                Sleep(2000);
            }
            tc.updateFromWaysides();
            std::cin >> file;
        }
        else if(command=="runPLCOnce")
        {
            std::cin >> file;
            for(int i=0;i<tc.waysides.size();i++)
            {
                tc.waysides[i].importPLC(file);
                tc.waysides[i].runPLCOnce(value);
                Sleep(2000);
            }
            tc.updateFromWaysides();
            std::cin >> file;
        }
    }
}
