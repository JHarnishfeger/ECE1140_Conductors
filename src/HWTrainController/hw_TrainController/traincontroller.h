#ifndef TRAINCONTROLLER_H
#define TRAINCONTROLLER_H



#include <QObject>
#include <string>
#include <iostream>

using namespace std;

class TrainController : public QObject
{
    Q_OBJECT
public:
    QByteArray encodeData();
    QString Kp, Ki, commandedSpeed, currentSpeed, suggestedSpeed, speedLimit, authority;
    bool leftDoors = false;
    bool rightDoors = false;
    bool interiorLights = false;
    bool exteriorLights = false;
    bool serviceBreak = false;
    bool eBreak = false;
    bool passengerBreak = false;
    QString mode = "manual";
    QString commandedPower = "00000";
    QString nextStation = "ShadySide";
    QString stationCode = "00000";

    explicit TrainController(QObject *parent = nullptr);
    void decodeData(QString inputData);

    QString getKp();
    QString getKi();
    QString getCommandedSpeed();
    QString getCurrentSpeed();
    QString getSuggestedSpeed();
    QString getSpeedLimit();
    QString getAuthority();
    QString getMode();
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






signals:

};

extern TrainController trainController;

#endif // TRAINCONTROLLER_H
