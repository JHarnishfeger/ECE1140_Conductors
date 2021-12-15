#ifndef TRAINCONTROLLERSIGNALHANDLER_H
#define TRAINCONTROLLERSIGNALHANDLER_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "uiswtraincontroller.h"
#include <QMainWindow>
#include <QObject>
#include <QTimer>
#include<QDebug>


class TraincontrollerSignalHandler : public QObject
{
public:
    std::vector<SWTrainController*> trainList;
    std::vector<UISWTrainController*> uiList;

    int numofTrains = 0;
    void newTrainController(int);
    void deleteTrain(int);
    //ALTERNATE OPTION, SKIP SIGNAL HANDLER ALL TOGETHER AND PUT A Beacon and TC function in the train model
    void sendBeacon(uint64_t, int);
    void sendTrackCircuit(uint64_t, int);

};

#endif // TRAINCONTROLLERSIGNALHANDLER_H
