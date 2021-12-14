#include "hwtraincontrollermoc.h"

#include <iostream>
#include <iomanip>

HWTrainControllerMoc::HWTrainControllerMoc()
{
    train = new trainModelMoc;
}

trainModelMoc* HWTrainControllerMoc::getTrainModelMoc()
{
    return train;
}

void HWTrainControllerMoc::decodeData(QString inputData)
{
    /*String decoding
        char 0    = parity bit      (1)
        char 1    = left doors      (0 = closed, 1 = open)
        char 2    = right doors     (0 = closed, 1 = open)
        char 3    = interior lights (0 = off, 1 = on)
        char 4    = exterior lights (0 = off, 1 = on)
        char 5    = serviceBreak    (0 = off, 1 = on)
        char 6    = eBreak          (0 = off, 1 = on)
        char 7    = passengerBreak  (0 = off, 1 = on)
        char 8    = mode            (0 = automatic, 1 = manual)
        char 9-end = commandedPower
    */

    string decodedData = inputData.toStdString();

    if(decodedData.length() >= 10 && decodedData.length() <= 18)
    {
        if(decodedData.substr(0,1) == "1")  setLeftDoors(1);
        else    setLeftDoors(0);
        if(decodedData.substr(1,1) == "1")  setRightDoors(1);
        else    setRightDoors(0);
        if(decodedData.substr(2,1) == "1")  setInteriorLights(1);
        else    setInteriorLights(0);
        if(decodedData.substr(3,1) == "1")  setExteriorLights(1);
        else    setExteriorLights(0);
        if(decodedData.substr(4,1) == "1")  setServiceBreaks(1);
        else    setServiceBreaks(0);
        if(decodedData.substr(5,1) == "1")  setEmergencyBreaks(1);
        else    setEmergencyBreaks(0);
        if(decodedData.substr(6,1) == "1")  setServiceBreaks(1);
        else    setServiceBreaks(0);
        if(decodedData.substr(7,1) == "1")  mode = "automatic";
        else    mode = "manual";

        commandedPower = QString::fromStdString(decodedData.substr(8));

        train->setPower(commandedPower.toDouble());

    }
}

QByteArray HWTrainControllerMoc::encodeData()
{
    /*String decoding
    char 0            = parity
    char 1-4          = kp
    char 5-8          = ki
    char 9-13        = commandedSpeed
    char 14-18        = currentSpeed
    char 19-23        = suggestedSpeed
    char 24-28        = speedLimit
    char 29-33        = authority
    char 34-38        = stationCode
    */

    if(nextStation == "Shadyside")                  stationCode = "00000";
    else if(nextStation == "Herron Ave")            stationCode = "00001";
    else if(nextStation == "Swissville")            stationCode = "00010";
    else if(nextStation == "Penn Station")          stationCode = "00011";
    else if(nextStation == "Steel Plaza")           stationCode = "00100";
    else if(nextStation == "First Ave")             stationCode = "00101";
    else if(nextStation == "Station Square")        stationCode = "00110";
    else if(nextStation == "South Hills Junction")  stationCode = "00111";
    else if(nextStation == "Pioneer")               stationCode = "01000";
    else if(nextStation == "Edgebrook")             stationCode = "01001";
    else if(nextStation == "Whited")                stationCode = "01010";
    else if(nextStation == "South Bank")            stationCode = "01011";
    else if(nextStation == "Central")               stationCode = "01100";
    else if(nextStation == "Inglewood")             stationCode = "01101";
    else if(nextStation == "Overbrook")             stationCode = "01110";
    else if(nextStation == "Glenbury")              stationCode = "01111";
    else if(nextStation == "Dormont")               stationCode = "10000";
    else if(nextStation == "Mt Lebanon")            stationCode = "10001";
    else if(nextStation == "Poplar")                stationCode = "10010";
    else if(nextStation == "Castle Shannon")        stationCode = "10011";
    else if(nextStation == "Yard")                  stationCode = "11111";
    else if(nextStation == "None")                  stationCode = "10100";

    QByteArray output = "";

    double2string();

    output += "1";
    output += Kp.toLocal8Bit();
    output += Ki.toLocal8Bit();
    output += getCommandedSpeed().toLocal8Bit();
    output += currentSpeed_s.toLocal8Bit();
    qDebug() << currentSpeed_s;
    output += suggestedSpeed_s.toLocal8Bit(); //AKA setPointSpeed
    output += speedLimit_s.toLocal8Bit();
    output += authority_s.toLocal8Bit();
    output += stationCode.toLocal8Bit();
    output += '\n';

    return output;

}

void HWTrainControllerMoc::double2string()
{

    QString temp_currentSpeed_s = QString::number(train->getSpeed(), 'f', 2);
    QString temp_suggestedSpeed_s = QString::number(getSuggestedSpeed(), 'f', 2);
    QString temp_speedLimit_s = QString::number(getSpeedLimit(), 'f', 2);
    QString temp_authority_s = QString::number(getAuthority(), 'f', 2);

    if(temp_currentSpeed_s[1] == '.')
    {
        temp_currentSpeed_s.insert(0, QString('0'));
    }
    if(temp_suggestedSpeed_s[1] == '.')
    {
        temp_suggestedSpeed_s.insert(0, QString('0'));
    }
    if(temp_speedLimit_s[1] == '.')
    {
        temp_speedLimit_s.insert(0, QString('0'));
    }
    if(temp_authority_s[1] == '.')
    {
        temp_authority_s.insert(0, QString('0'));
    }

//    qDebug() << "Current Speed: " << temp_currentSpeed_s;
//    qDebug() << "Suggested Speed: " << temp_suggestedSpeed_s;
//    qDebug() << "SpeedLimit: " << temp_speedLimit_s;
//    qDebug() << "Authority: " << temp_authority_s;

    setCurrentSpeed(temp_currentSpeed_s);
    setSuggestedSpeed(temp_suggestedSpeed_s);
    setSpeedLimit(temp_speedLimit_s);
    setAuthority(temp_authority_s);

}


void HWTrainControllerMoc::setLeftDoors(bool ld)
{
    train->setLeftDoor(ld);
}

void HWTrainControllerMoc::setRightDoors(bool rd)
{
    train->setRightDoor(rd);
}

void HWTrainControllerMoc::setInteriorLights(bool il)
{
    train->setInteriorLights(il);
}

void HWTrainControllerMoc::setExteriorLights(bool el)
{
    train->setExteriorLights(el);
}

void HWTrainControllerMoc::setServiceBreaks(bool sb)
{
    train->setBrakes(sb);
}

void HWTrainControllerMoc::setEmergencyBreaks(bool eb)
{
    train->setEbrakes(eb);
}

QString HWTrainControllerMoc::getKp()
{
    return Kp;
}

QString HWTrainControllerMoc::getKi()
{
    return Ki;
}

QString HWTrainControllerMoc::getCommandedSpeed()
{
    return commandedSpeed_s;
}

double HWTrainControllerMoc::getCurrentSpeed()
{
    return train->getSpeed();
}

double HWTrainControllerMoc::getSuggestedSpeed()
{
    return suggestedSpeed;
}

double HWTrainControllerMoc::getSpeedLimit()
{
    return speedLimit;
}

double HWTrainControllerMoc::getAuthority()
{
    return authority;
}

void HWTrainControllerMoc::setCommandedSpeed(QString CommandedSpeed)
{
    commandedSpeed_s = CommandedSpeed;
}

void HWTrainControllerMoc::setCurrentSpeed(QString CurrentSpeed)
{
    currentSpeed_s = CurrentSpeed;
}

void HWTrainControllerMoc::setSuggestedSpeed(QString SuggestedSpeed)
{
    suggestedSpeed_s = SuggestedSpeed;
}

void HWTrainControllerMoc::setSpeedLimit(QString SpeedLimit)
{
    speedLimit_s = SpeedLimit;
}

void HWTrainControllerMoc::setAuthority(QString Authority)
{
    authority_s = Authority;
}

void HWTrainControllerMoc::setNextStation(QString NextStation)
{
    nextStation = NextStation;
}

void HWTrainControllerMoc::setKp(QString kp)
{
    Kp = kp;
}

void HWTrainControllerMoc::setKi(QString ki)
{
    Ki = ki;
}

