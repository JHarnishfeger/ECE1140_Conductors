#ifndef TRAINCONTROLLERSIGNALHANDLER_H
#define TRAINCONTROLLERSIGNALHANDLER_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "uiswtraincontroller.h"
#include <QMainWindow>
#include <QObject>

class TraincontrollerSignalHandler : public QObject
{
public:
    std::vector<SWTrainController*> trainList;

    int train_select = 0;
    void newTrainController();
    void decodeBeacon(uint64_t);
    uint64_t sendGPS();
    uint8_t sendPower();

    double sendPowerTest();
    double sendGPSTest();

};

#endif // TRAINCONTROLLERSIGNALHANDLER_H
