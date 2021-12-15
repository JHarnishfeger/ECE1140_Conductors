#ifndef TRAINMAKER_H
#define TRAINMAKER_H

#include <QObject>
#include <vector>
#include "trainui.h"

class trainMaker : public QObject
{
    Q_OBJECT
public:
    explicit trainMaker(QObject *parent = nullptr);
    void newTrain(bool HardwareOrSoftware,bool GreenOrRed);

private:
    int ID = 1;
    std::vector<trainUI*> HardwareTrains;
    std::vector<trainUI*> SoftwareTrains;

signals:

    //Signals to send to Track Circuit and MBO
    void TrainInfo(uint8_t currentBlock,int ID,bool RorG);
    void transferCoords(int trainID,int currentBlock,double distance);

    void update2();

public slots:

    //Track Model slots
    void TCData(uint64_t TrackCircuitData,int ID);
    void BeaconData(uint16_t BeaconData,int ID);

    //MBO slots
    void setAuth(double authDistance,double authSpeed,int ID);

    //Connecting to lower level
    void callAgainTCData(uint8_t currentBlock, int trainID, bool RorG);

    void update();
};

#endif // TRAINMAKER_H
