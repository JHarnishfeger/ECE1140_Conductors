#include "traincontroller.h"
#include "hwtrainui.h"

#include <iostream>
#include <iomanip>
#include <QDebug>
#include <windows.h>

TrainController::TrainController(QObject *parent) : QObject(parent)
{

}

void TrainController::decodeData(QString inputData)
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
        if(decodedData.substr(0,1) == "1")
        {
            setLeftDoors(true);
            leftDoors = true;
            train->setLeftDoor(leftDoors);
        }
        else
        {
            leftDoors = false;
            train->setLeftDoor(leftDoors);
        }

        if(decodedData.substr(1,1) == "1")
        {
            rightDoors = true;
            train->setRightDoor(rightDoors);
        }
        else
        {
            rightDoors = false;
            train->setRightDoor(rightDoors);
        }

        if(decodedData.substr(2,1) == "1")
        {
            interiorLights = true;
            train->setInteriorLights(interiorLights);
        }
        else
        {
            interiorLights = false;
            train->setInteriorLights(interiorLights);
        }

        if(decodedData.substr(3,1) == "1")
        {
            exteriorLights = true;
            train->setExteriorLights(exteriorLights);
        }
        else
        {
            exteriorLights = false;
            train->setExteriorLights(exteriorLights);
        }

        if(decodedData.substr(4,1) == "1")
        {
            serviceBreak = true;
            train->setBrakes(serviceBreak);
        }
        else
        {
            serviceBreak = false;
            train->setBrakes(serviceBreak);
        }

        if(decodedData.substr(5,1) == "1")
        {
            eBreak = true;
            train->setEbrakes(eBreak);
        }
        else
        {
            eBreak = false;
            train->setEbrakes(eBreak);
        }

        if(decodedData.substr(6,1) == "1")
        {
            passengerBreak = true;
            train->setBrakes(passengerBreak);
        }
        else
        {
            passengerBreak = false;
            train->setBrakes(passengerBreak);
        }

        if(decodedData.substr(7,1) == "1")
        {
            mode = "automatic";
        }
        else
        {
            mode = "manual";
        }

        atStation();

        commandedPower = QString::fromStdString(decodedData.substr(8));
        train->setPower(commandedPower.toDouble());
    }

}

QByteArray TrainController::encodeData()
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

    QByteArray output = "";

    double2string();

    output += "1";
    output += Kp.toLocal8Bit();
    output += Ki.toLocal8Bit();
    output += getCommandedSpeed().toLocal8Bit();
    output += currentSpeed_s.toLocal8Bit();
    output += suggestedSpeed_s.toLocal8Bit(); //AKA setPointSpeed
    output += speedLimit_s.toLocal8Bit();
    output += authority_s.toLocal8Bit();
    output += stationCode.toLocal8Bit();
    output += '\n';

    return output;

}

void TrainController::readSerial()
{
//    qDebug() << "hello";
    dataIN = serialport.arduino->readAll();
    temp = QString(dataIN);
    temp.remove('\r').remove('\n');
    string temp1 = "";
    QString temp2 = "";
    int len = temp.length();

    //qDebug() << "Initial Data: " << temp.length() << " " << temp;


    for(int i = 13; i < 19; i++)
    {
        if ((len%i) == 0)
        {
            temp1 = temp.toStdString();
            temp2 = QString::fromStdString(temp.toStdString().substr(0, i));
            break;
        }
    }
//    if (((len%13) == 0)||((len%14) == 0)||((len%15) == 0)||((len%16) == 0)||((len%17) == 0)||((len%18) == 0))
//    {
//        temp1 = temp.toStdString();
//        temp2 = QString::fromStdString(temp.toStdString().substr(0, 18));
//    }

//    temp2 = QString::fromStdString(temp.toStdString().substr(0, 18));
    //qDebug() << "Temp2: " << temp2;


    if(dataIN_concat.length() <= 18)
    {
        dataIN_concat += temp2;
        //qDebug() << "Data in concat: " << dataIN_concat.length() << " " << dataIN_concat;
        if(dataIN_concat.length() <=18 && dataIN_concat.front() == "1")
        {
            dataIN_concat.remove(0,1);
            qDebug() << "Receiving: " << dataIN_concat.length() << " " << dataIN_concat;
            decodeData(dataIN_concat);
            dataIN_concat = "";
        }

    }
    else
    {
        dataIN_concat = "";
    }
}

void TrainController::writeSerial()
{
    QByteArray temp = encodeData();

    const char* in = temp.data();

    serialport.arduino->write(in);
    qDebug() << "Sending: " << in;
}

void TrainController::atStation()
{
    QString temp_pow = commandedPower;

    //set power to zero if station is on the block
    if ((at_station == true) && !(currentSpeed == 0.0) && !(serviceBreak))
    {
        commandedPower = "00.00";
        setServiceBreaks(1);
    }
    else if (at_station == true)
    {
        commandedPower = "00.00";
    }


    //When the train stopped at a station, check timer if 60s passed (test when flipped with code belowe and see if timing error)
    if (at_station == true && just_stopped == true){
        //if (systemClock->currentTime() >= stationTimerEnd){ // train has been stopped for 60sec
            //Sleep(5000);//Sleep timer for first demo, will have to use the commented out code once we are able to use the same timer
            commandedPower = temp_pow; // keep power command as non-zero
            //close doors
            setLeftDoors(0);
            setRightDoors(0);
            setServiceBreaks(0);
            train->updatePassengers();
        //}
    }

    //When train just stopped, set a flag and start a timer
    if (at_station == true && currentSpeed == 0.0 && just_stopped == false){
        just_stopped = true;
        //stationTimerStart = systemClock->currentTime();
        //stationTimerEnd = stationTimerStart.addSecs(60);
        //open doors
        setLeftDoors(1);
        setRightDoors(1);
    }


    //When train has left the block with station, reset station flag.
    if (at_station == false && just_stopped == true){
        just_stopped = false;
    }

    train->setPower(commandedPower.toDouble());
}

void TrainController::decodeTrackCircuit(){

    uint32_t tcdata = train->getTCData();

    speedLimit = (tcdata >> 16) & 0xFF;
    suggestedSpeed = (tcdata >> 8) & 0xFF;
    authority = (tcdata) & 0xFF;
}

void TrainController::decodeBeacon()
{

    uint16_t beacon = train->getBeaconData();

    int stationCode = (beacon >> 8) & 0xFF;
    int incomingCode = beacon & 0xFF;

    //Station NameDecoder
    if(stationCode == 1)                nextStation = "Shadyside";
    else if(stationCode == 2)           nextStation = "Herron Ave";
    else if(stationCode == 3)           nextStation = "Swissville";
    else if(stationCode == 4)           nextStation = "Penn Station";
    else if(stationCode == 5)           nextStation = "Steel Plaza";
    else if(stationCode == 6)           nextStation = "First Ave";
    else if(stationCode == 7)           nextStation = "Station Square";
    else if(stationCode == 8)           nextStation = "South Hills Junction";
    else if(stationCode == 9)           nextStation = "Pioneer";
    else if(stationCode == 10)          nextStation = "Edgebrook";
    else if(stationCode == 11)          nextStation = "Whited";
    else if(stationCode == 12)          nextStation = "South Bank";
    else if(stationCode == 13)          nextStation = "Central";
    else if(stationCode == 14)          nextStation = "Inglewood";
    else if(stationCode == 15)          nextStation = "Overbrook";
    else if(stationCode == 16)          nextStation = "Glenbury";
    else if(stationCode == 17)          nextStation = "Dormont";
    else if(stationCode == 18)          nextStation = "Mt Lebanon";
    else if(stationCode == 19)          nextStation = "Poplar";
    else if(stationCode == 20)          nextStation = "Castle Shannon";
    else if(stationCode == 21)          nextStation = "Yard";
    else if(stationCode == 31)          nextStation = "None";

    if(incomingCode == 1){//No station and no headlights
      at_station=false;
      setExternalLights(false);
    }else if(incomingCode == 2){//No station and headlights
        at_station=false;
        setExternalLights(true);
    }else if(incomingCode == 3){//Station and no headlights
        at_station=true;
        setExternalLights(false);
    }else if(incomingCode == 4){//Station and headlights
        at_station=true;
        setExternalLights(true);
    }
}

void TrainController::double2string()
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

QString TrainController::getKp()
{
    return Kp;
}

QString TrainController::getKi()
{
    return Ki;
}

QString TrainController::getCommandedSpeed()
{
    return commandedSpeed_s;
}

double TrainController::getCurrentSpeed()
{
    return train->getSpeed();
}

double TrainController::getSuggestedSpeed()
{
    return suggestedSpeed;
}

double TrainController::getSpeedLimit()
{
    return speedLimit;
}

double TrainController::getAuthority()
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

bool TrainController::getPassengerBreak()
{
    return passengerBreak;
}

QString TrainController::getCommandedPower()
{
    return commandedPower;
}

bool TrainController::getEngineFailure(){
    return train->getEngineFail();
}

bool TrainController::getTCFailure(){
    return train->getSignalFail();
}

bool TrainController::getBrakeFailure(){
    return train->getBrakeFail();
}

void TrainController::setKp(QString kp)
{
    Kp = kp;
}

void TrainController::setKi(QString ki)
{
    Ki = ki;
}

void TrainController::setCommandedSpeed(QString CommandedSpeed)
{
    commandedSpeed_s = CommandedSpeed;
}

void TrainController::setCurrentSpeed(QString CurrentSpeed)
{
    currentSpeed_s = CurrentSpeed;
}

void TrainController::setSuggestedSpeed(QString SuggestedSpeed)
{
    suggestedSpeed_s = SuggestedSpeed;
}

void TrainController::setSpeedLimit(QString SpeedLimit)
{
    speedLimit_s = SpeedLimit;
}

void TrainController::setAuthority(QString Authority)
{
    authority_s = Authority;
}

void TrainController::setNextStation(QString NextStation)
{
    nextStation = NextStation;
}

void TrainController::setLeftDoors(bool ld)
{
    train->setLeftDoor(ld);
}

void TrainController::setRightDoors(bool rd)
{
    train->setRightDoor(rd);
}

void TrainController::setInternalLights(bool il)
{
    train->setInteriorLights(il);
}

void TrainController::setExternalLights(bool el)
{
    train->setExteriorLights(el);
}

void TrainController::setServiceBreaks(bool sb)
{
    train->setBrakes(sb);
}

void TrainController::setEmergencyBreaks(bool eb)
{
    train->setEbrakes(eb);
}
