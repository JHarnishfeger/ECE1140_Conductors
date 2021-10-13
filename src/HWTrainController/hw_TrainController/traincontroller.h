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
    QString Kp, Ki, commandedVelocity, currentVelocity, suggestedVelocity, speedLimit, authority;
    bool leftDoors = false;
    bool rightDoors = false;
    bool interiorLights = false;
    bool exteriorLights = false;
    bool serviceBreak = false;
    bool eBreak = false;
    QString mode = "manual";
    QString power = "00000";
    QString nextStation = "YARD";
    QString stationCode = "00000";

    explicit TrainController(QObject *parent = nullptr);
    void decodeData(QString inputData);

    QString getKp();
    QString getKi();
    QString getCommandedVelocity();
    QString getCurrentVelocity();
    QString getSuggestedVelocity();
    QString getSpeedLimit();
    QString getAuthority();
    bool getLeftDoors();
    bool getRightDoors();
    bool getInteriorLights();
    bool getExteriorLights();
    bool getServiceBreak();
    bool getEBreak();
    QString getPower();

    void setKp(QString kp);
    void setKi(QString ki);
    void setCommandedVelocity(QString CommandedVelocity);
    void setCurrentVelocity(QString CurrentVelocity);
    void setSuggestedVelocity(QString SuggestedVelocity);
    void setSpeedLimit(QString SpeedLimit);
    void setAuthority(QString Authority);






signals:

};

extern TrainController trainController;

#endif // TRAINCONTROLLER_H
