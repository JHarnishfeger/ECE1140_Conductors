#ifndef TRAINMAKER_H
#define TRAINMAKER_H

#include <QObject>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "trainui.h"

class trainMaker : public QObject
{
    Q_OBJECT
    public:
        explicit trainMaker(QObject *parent = nullptr);
        trainMaker();
        ~trainMaker();
        void makeTrain(bool HorS,bool RorG);

    private:

        //train pointers
        trainUI *mainTrainUI = new trainUI(nullptr,HorS,ID);

        //strage for software trains and one hardware train
        std::vector<trainUI> SoftwareTrains;
        std::vector<trainUI> HardwareTrain;

        //variables to determine if hardware or software and ID
        int ID;
        bool HorS;

    signals:

        //Signals to send to Track Circuit and MBO
        void TrainInfo(uint8_t currentBlock,int ID);
        void transferCoords(int trainID,int currentBlock,double distance);

    public slots:

        //Track Model slots
        void TCData(uint64_t TrackCircuitData,int ID);
        void BeaconData(uint32_t BeaconData,int ID);

        //MBO slots
        void setAuth(double authDistance,double authSpeed,int ID);
};

#endif // TRAINMAKER_H
