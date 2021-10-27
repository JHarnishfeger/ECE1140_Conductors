#include "SWTrackController.cpp"
#include <sstream>
#include <Windows.h>
#include <time.h>

Block a('g','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block b('g','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block c('g','a',"switch",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block d('g','a',"rail",2.0,true,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block e('r','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block f('r','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block g('r','a',"crossing",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block h('r','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block i('r','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
Block j('r','a',"rail",2.0,false,5.0,25.0,30.0,'e',32.0,0,1.0,false,false,false,false,false);
vector<Block> green{a,b,c,d};
vector<Block> red{e,f,g,h,i,j};

int main()
{
    SWTrackController tc(red,green,2,0,0,0);
    while(1==1)
    {
        std::system("cls");
        string command;
        double value;
        tc.testValues();
        tc.plcCheck();
        std::cout << std::endl;
        std::cin >> command;
        std::cin >> value;
        //std::cout << command << ", " << value << std::endl << std::endl;
        if(command=="speed")
            tc.setSpeed(value);
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
            std::cout << "The red line covers blocks " << tc.redLine[0].getId() << " to " << tc.redLine[tc.redLine.size()-1].getId() << "." << std::endl;
            Sleep(2000);
        }
        else if(command=="greenLine")
        {
            std::cout << "The green line covers blocks " << tc.greenLine[0].getId() << " to " << tc.greenLine[tc.greenLine.size()-1].getId() << "." << std::endl;
            Sleep(2000);
        }
        else if(command=="break"){
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.addBrokenRail(tc.waysides[i].sector[j]);
        }
        else if(command=="maintenance")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.addMaintenance(tc.waysides[i].sector[j]);
        }
        else if(command=="done")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.endMaintenance(tc.waysides[i].sector[j]);
        }
        else if(command=="switch")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.switchTrack(tc.waysides[i].sector[j]);
        }
        else if(command=="crossing")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.toggleCrossing(tc.waysides[i].sector[j]);
        }
        else if(command=="setTrain")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.waysides[i].sector[j].setTrainPresent(true);
            tc.getTrackOccupancy();
        }
        else if(command=="removeTrain")
        {
            for(int i=0;i<tc.waysides.size();i++)
                for(int j=0;j<tc.waysides[i].sector.size();j++)
                    if(tc.waysides[i].sector[j].getId()==value)
                        tc.waysides[i].sector[j].setTrainPresent(false);
            tc.getTrackOccupancy();
        }
    }
}
