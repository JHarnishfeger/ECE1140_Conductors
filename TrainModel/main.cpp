#include "trainui.h"
#include <iostream>
#include <QApplication>
//#include <Windows.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    trainUI w(50.0,5,5);
    w.show();

    //int codedStationCode = 31;
    //int codedStationHere = 1;
    //int16_t beacon = ((((uint16_t)codedStationCode)<<8)+(((uint16_t)codedStationHere)));
    //codedStationCode = 13;
    //codedStationHere = 3;
    //int16_t beacon2 = ((((uint16_t)codedStationCode)<<8)+(((uint16_t)codedStationHere)));
    //
    //int SpeedLimit, SuggestedSpeed, FBAuthority;
    //SpeedLimit = 28;
    //SuggestedSpeed = 15;
    //FBAuthority=1;
    //
    //int32_t tcData = ((((int32_t)SpeedLimit)<<16)+(((int32_t)SuggestedSpeed)<<8)+(((int32_t)FBAuthority)));
    //
    // w.mainTrain->setTCData(tcData);
    // w.mainTrain->setBeaconData(beacon);

     //w.mainTrain->setTCData(tcData);
     //w.mainTrain->setBeaconData(beacon2);

    return a.exec();
}
