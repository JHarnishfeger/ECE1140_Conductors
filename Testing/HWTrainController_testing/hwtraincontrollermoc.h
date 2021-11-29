#ifndef HWTRAINCONTROLLERMOC_H
#define HWTRAINCONTROLLERMOC_H

#include <QObject>
#include <string>
#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <QDebug>

#include "trainmodelmoc.h"
#include "serialportmoc.h"

using namespace std;

class HWTrainControllerMoc
{
public:
    HWTrainControllerMoc();

   // SerialPortMoc serialport;

    QString mode = "manual";
    QString commandedPower = "00000";

    QString Kp, Ki;
    QString commandedSpeed_s;
    QString currentSpeed_s;
    QString suggestedSpeed_s;
    QString speedLimit_s;
    QString authority_s;
    QString mb_authority_s;
    QString nextStation = "ShadySide";
    QString stationCode = "00000";

    double commandedSpeed = 00.00;
    double currentSpeed = 00.00;
    double suggestedSpeed = 10.00;
    double speedLimit = 00.00;
    double authority = 00.00;
    double mb_authority = 00.00;

    trainModelMoc* getTrainModelMoc();

    void decodeData(QString inputData);
    QByteArray encodeData();
    void double2string();

    //helper functions
    void setLeftDoors(bool ld);
    void setRightDoors(bool rd);
    void setInteriorLights(bool il);
    void setExteriorLights(bool el);
    void setServiceBreaks(bool sb);
    void setEmergencyBreaks(bool eb);

    QString getKp();
    QString getKi();
    QString getCommandedSpeed();
    double getCurrentSpeed();
    double getSuggestedSpeed();
    double getSpeedLimit();
    double getAuthority();

    void setKp(QString kp);
    void setKi(QString ki);
    void setCommandedSpeed(QString CommandedSpeed);
    void setCurrentSpeed_s(QString CurrentSpeed);
    void setSuggestedSpeed_s(QString SuggestedSpeed);
    void setSpeedLimit_s(QString SpeedLimit);
    void setAuthority_s(QString Authority);
    void setNextStation(QString NextStation);

    void setCurrentSpeed(double CurrentSpeed);
    void setSuggestedSpeed(double SuggestedSpeed);
    void setSpeedLimit(double SpeedLimit);
    void setAuthority(double Authority);

private:
    trainModelMoc *train;

};

#endif // HWTRAINCONTROLLERMOC_H
