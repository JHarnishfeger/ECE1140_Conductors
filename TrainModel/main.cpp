#include "trainmaker.h"
#include <iostream>
#include <QApplication>
//#include <Windows.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    trainMaker w(nullptr);
//    w.newTrain(1,0);
//    w.newTrain(1,1);
    w.newTrain(0,0);

    //trainUI w(nullptr,1);
    //w.mainTrain->setID(22);
    //w.show();
    //
    //int codedStationCode = 31;
    //int codedStationHere = 1;
    //int16_t beacon = ((((uint16_t)codedStationCode)<<8)+(((uint16_t)codedStationHere)));
    //codedStationCode = 13;
    //codedStationHere = 3;
    //int16_t beacon2 = ((((uint16_t)codedStationCode)<<8)+(((uint16_t)codedStationHere)));
    //
    //int SpeedLimit, SuggestedSpeed, FBAuthority, blocknum, blocklength;
    //SpeedLimit = 70;
    //SuggestedSpeed = 15;
    //FBAuthority=1;
    //blocknum=18;
    //blocklength=400;
    //
    //int64_t tcData = ((((int64_t)blocklength)<<32)+(((int64_t)blocknum)<<24)+(((int64_t)SpeedLimit)<<16)+(((int64_t)SuggestedSpeed)<<8)+(((int64_t)FBAuthority)));
    //
    // w.mainTrain->setTCData(tcData);
    // w.mainTrain->setBeaconData(beacon);

    return a.exec();
}
