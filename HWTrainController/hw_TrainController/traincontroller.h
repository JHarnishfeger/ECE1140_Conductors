#ifndef TRAINCONTROLLER_H
#define TRAINCONTROLLER_H

#include <QObject>
#include <string>
#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include "serialport.h"
#include "..\..\TrainModel\trainmodel.h"

using namespace std;

class TrainController : public QObject
{
    Q_OBJECT
public:

    SerialPort serialport;

    //connected train
    trainModel *train;

    //Transit Data Variables
    QString Kp, Ki;
    QString commandedSpeed_s;
    QString currentSpeed_s;
    QString suggestedSpeed_s;
    QString speedLimit_s;
    QString authority_s;
    QString mb_authority_s;
    double commandedSpeed = 00.00;
    double currentSpeed = 00.00;
    double suggestedSpeed = 10.00;
    double speedLimit = 00.00;
    double authority = 00.00;
    double mb_authority = 00.00;
    QString nextStation = "ShadySide";
    QString stationCode = "00000";

    //Utilities Variables
    bool leftDoors = false;
    bool rightDoors = false;
    bool interiorLights = false;
    bool exteriorLights = false;
    bool serviceBreak = false;
    bool eBreak = false;
    bool passengerBreak = false;

    //Extra internal Variables
    QString mode = "manual";
    QString commandedPower = "00000";
    QByteArray dataIN;
    QString temp;
    QString dataIN_concat = "";
    bool at_station = false;
    bool just_stopped = false;

    explicit TrainController(QObject *parent = nullptr);
    void readSerial();
    void writeSerial();
    void atStation();
    QString getKp();
    QString getKi();
    QString getCommandedSpeed();
    double getCurrentSpeed();
    double getSuggestedSpeed();
    double getSpeedLimit();
    double getAuthority();
    QString getMode();
    void double2string();
    bool getLeftDoors();
    bool getRightDoors();
    bool getInteriorLights();
    bool getExteriorLights();
    bool getServiceBreak();
    bool getEBreak();
    bool getPassengerBreak();
    QString getCommandedPower();
    void setKp(QString kp);
    void setKi(QString ki);
    void setCommandedSpeed(QString CommandedSpeed);
    void setCurrentSpeed(QString CurrentSpeed);
    void setSuggestedSpeed(QString SuggestedSpeed);
    void setSpeedLimit(QString SpeedLimit);
    void setAuthority(QString Authority);
    void setNextStation(QString NextStation);
    void decodeData(QString inputData);
    QByteArray encodeData();
    void decodeTrackCircuit();
    void decodeBeacon();
    bool getEngineFailure();
    bool getTCFailure();
    bool getBrakeFailure();
    void setLeftDoors(bool ld);
    void setRightDoors(bool rd);
    void setInteriorLights(bool il);
    void setExteriorLights(bool el);
    void setServiceBreaks(bool sb);
    void setEmergencyBreaks(bool eb);


};

//extern TrainController trainController;

#endif // TRAINCONTROLLER_H
