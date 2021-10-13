#include "traincontroller.h"
#include "traincontrollermainwindow.h"

TrainController::TrainController(QObject *parent) : QObject(parent)
{

}

void TrainController::decodeData(QString inputData)
{

    /*String decoding
      char 0        = parity bit      (1)
      char 1        = left doors      (0 = closed, 1 = open)
      char 2        = right doors     (0 = closed, 1 = open)
      char 3        = interior lights (0 = off, 1 = on)
      char 4        = exterior lights (0 = off, 1 = on)
      char 5-9      = power
      char 10       = break           (0 = off, 1 = on)
      char 11       = emergency break (0 = off, 1 = on)
      char 12       = mode            (0 = automatic, 1 = manual)
    */
    string decodedData = inputData.toStdString();

    if(decodedData.length() == 12)
    {
        if(decodedData.substr(0,1) == "1")
        {
            leftDoors = true;
        }
        else
        {
            leftDoors = false;
        }
        if(decodedData.substr(1,1) == "1")
        {
            rightDoors = true;
        }
        else
        {
            rightDoors = false;
        }
        if(decodedData.substr(2,1) == "1")
        {
            interiorLights = true;
        }
        else
        {
            interiorLights = false;
        }
        if(decodedData.substr(3,1) == "1")
        {
            exteriorLights = true;
        }
        else
        {
            exteriorLights = false;
        }

        power = QString::fromStdString(decodedData.substr(4,5));

        if(decodedData.substr(9,1) == "1")
        {
            serviceBreak = true;
        }
        else
        {
            serviceBreak = false;
        }
        if(decodedData.substr(10,1) == "1")
        {
            eBreak = true;
        }
        else
        {
            eBreak = false;
        }
        if(decodedData.substr(11,1) == "1")
        {
            mode = "automatic";
        }
        else
        {
            mode = "manual";
        }
    }

}

QByteArray TrainController::encodeData()
{
    /*String encoding
    char 0            = parity
    char 1-5          = kp
    char 6-10         = ki
    char 11-15        = authority
    char 16-20        = commandedSpeed
    char 21-25        = setpointSpeed
    char 26-30        = currentSpeed
    char 31-35        = stationCode
    char 36           = announcing
    */

    if(nextStation == "ShadySide")                  stationCode = "00000";
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

    QByteArray output = "";

    output += "1";
    output += Kp.toLocal8Bit();
    //qDebug() << output;
    output += Ki.toLocal8Bit();
    //qDebug() << output;
    output += authority.toLocal8Bit();
    //qDebug() << output;
    output += commandedVelocity.toLocal8Bit();
   // qDebug() << output;
    output += suggestedVelocity.toLocal8Bit();
    //qDebug() << output;
    output += currentVelocity.toLocal8Bit();
    //qDebug() << output;
    output += stationCode.toLocal8Bit();
    output += '\n';

    return output;

}

QString TrainController::getKp()
{
    return Kp;
}

QString TrainController::getKi()
{
    return Ki;
}

QString TrainController::getCommandedVelocity()
{
    return commandedVelocity;
}

QString TrainController::getCurrentVelocity()
{
    return currentVelocity;
}

QString TrainController::getSuggestedVelocity()
{
    return suggestedVelocity;
}

QString TrainController::getSpeedLimit()
{
    return speedLimit;
}

QString TrainController::getAuthority()
{
    return authority;
}

QString TrainController::getMode()
{
    return mode;
}

bool TrainController::getLeftDoors()
{
    return leftDoors;
}

bool TrainController::getRightDoors()
{
    return rightDoors;
}

bool TrainController::getInteriorLights()
{
    return interiorLights;
}

bool TrainController::getExteriorLights()
{
    return exteriorLights;
}

bool TrainController::getServiceBreak()
{
    return serviceBreak;
}

bool TrainController::getEBreak()
{
    return eBreak;
}

QString TrainController::getPower()
{
    return power;
}

void TrainController::setKp(QString kp)
{
    Kp = kp;
}

void TrainController::setKi(QString ki)
{
    Ki = ki;
}

void TrainController::setCommandedVelocity(QString CommandedVelocity)
{
    commandedVelocity = CommandedVelocity;
}

void TrainController::setCurrentVelocity(QString CurrentVelocity)
{
    currentVelocity = CurrentVelocity;
}

void TrainController::setSuggestedVelocity(QString SuggestedVelocity)
{
    suggestedVelocity = SuggestedVelocity;
}

void TrainController::setSpeedLimit(QString SpeedLimit)
{
    speedLimit = SpeedLimit;
}

void TrainController::setAuthority(QString Authority)
{
    authority = Authority;
}

void TrainController::setNextStation(QString nxtStation)
{
    nextStation = nxtStation;
}

TrainController trainController;
