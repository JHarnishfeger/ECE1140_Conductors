#include "SWTrainController.h"

#include <iostream>
#include <iomanip>
#include <QDebug>
#include <windows.h>

SWTrainController::SWTrainController(){

}

SWTrainController::~SWTrainController(){

}

//Retunrs double but might just make void
double SWTrainController::calculatePower(){
    //Updates velocity and passenger ebrake status for calculation
    current_velocity=getCurrentVelocity();
    emergency_brake=train->getEbrakes();

    double power_redun = 0.0;
    double uk_redun = 0;
    double uk1_redun = uk1;
    double ek_redun = 0;
    double ek1_redun = ek1;

    //Redundancy check 1
    if (service_brake || emergency_brake || train->getBrakeFail() || authority<=0){ //If any brake is enables or no authority, power is cut
        power_command = 0;
    }else{
        //If in automatic mode, use commanded velocity, if in manual use setpoint velocity
        if (mode&&(current_velocity<=speed_limit))
            ek  = setpoint_velocity - current_velocity;
        else if(!mode&&(current_velocity<=speed_limit))
            ek  = commanded_velocity - current_velocity;
        else
            ek  = speed_limit - current_velocity;

        //Calculates uk and sets current error to previous error
        uk = uk1 + (T / 2) * (ek - ek1);
        ek1 = ek;

        //Calculates power
        power_command = kp * ek + ki * uk;

        //If power calculation exceeds max power, set power command to max power
        if(power_command > 120000){
            power_command = 120000;
        }
    }


    //Redundancy check 2
    if (service_brake || emergency_brake || train->getBrakeFail() || authority<=0){ //If any brake is enables or no authority, power is cut
        power_redun = 0;
    }else{
        //If in automatic mode, use commanded velocity, if in manual use setpoint velocity
        if (mode&&(current_velocity<=speed_limit))
            ek_redun  = setpoint_velocity - current_velocity;
        else if(!mode&&(current_velocity<=speed_limit))
            ek_redun  = commanded_velocity - current_velocity;
        else
            ek_redun  = speed_limit - current_velocity;

        //Calculates uk and sets current error to previous error
        uk_redun = uk1_redun + (T / 2) * (ek_redun - ek1_redun);
        ek1_redun = ek_redun;

        //Calculates power
        power_redun = kp * ek_redun + ki * uk_redun;

        //If power calculation exceeds max power, set power command to max power
        if(power_redun > 120000)
            power_redun = 120000;
    }

    //Redundancy check
    if(power_command!=power_redun){
        power_command=0.0;
    }

    //Check if need to stop at a station in automatic mode
    if (mode){
        atStation();
    }

//LOOK INTO FIXING WHEN CMND SPEED LOWERS TO 0, then hits - and keeps going -
    //if(power_command<0)
     //   train->setBrakes(1);

    train->setPower(power_command);
}


void SWTrainController::atStation(){
    double temp_pow = power_command;

    //Set power to zero if station on the block
    if (at_station == true&&!(current_velocity==0.0)&&!service_brake){ //If not stopped and service brake isn't on
        setServiceBrake(1);
    }

    //When the train stopped at a station, check timer if 60s passed (test when flipped with code belowe and see if timing error)
    if (at_station == true && just_stopped == true){
        //if (systemClock->currentTime() >= stationTimerEnd){ // train has been stopped for 60sec
            Sleep(5000);//Sleep timer for first demo, will have to use the commented out code once we are able to use the same timer
            //close doors
            setLeftDoors(0);
            setRightDoors(0);
            setServiceBrake(0);
            train->updatePassengers();
            setServiceBrake(0);
        //}
    }

    //When train just stopped, set a flag and start a timer
    if (at_station == true && current_velocity == 0.0 && just_stopped == false){
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
}


void SWTrainController::decodeBeacon(){

    uint16_t beacon = train->getBeaconData();

    int stationCode = (beacon >> 8) & 0xFF;
    int incomingCode = beacon & 0xFF;

    //Station NameDecoder
    if(stationCode == 1)                incommingStation = "Shadyside";
    else if(stationCode == 2)           incommingStation = "Herron Ave";
    else if(stationCode == 3)           incommingStation = "Swissville";
    else if(stationCode == 4)           incommingStation = "Penn Station";
    else if(stationCode == 5)           incommingStation = "Steel Plaza";
    else if(stationCode == 6)           incommingStation = "First Ave";
    else if(stationCode == 7)           incommingStation = "Station Square";
    else if(stationCode == 8)           incommingStation = "South Hills Junction";
    else if(stationCode == 9)           incommingStation = "Pioneer";
    else if(stationCode == 10)          incommingStation = "Edgebrook";
    else if(stationCode == 11)          incommingStation = "Whited";
    else if(stationCode == 12)          incommingStation = "South Bank";
    else if(stationCode == 13)          incommingStation = "Central";
    else if(stationCode == 14)          incommingStation = "Inglewood";
    else if(stationCode == 15)          incommingStation = "Overbrook";
    else if(stationCode == 16)          incommingStation = "Glenbury";
    else if(stationCode == 17)          incommingStation = "Dormont";
    else if(stationCode == 18)          incommingStation = "Mt Lebanon";
    else if(stationCode == 19)          incommingStation = "Poplar";
    else if(stationCode == 20)          incommingStation = "Castle Shannon";
    else if(stationCode == 21)          incommingStation = "Yard";
    else if(stationCode == 31)          incommingStation = "None";

    if(incomingCode == 1){//No station and no headlights
      at_station=0;
      exterior_lights=0;
    }else if(incomingCode == 2){//No station and headlights
        at_station=0;
        exterior_lights=1;
    }else if(incomingCode == 3){//Station and no headlights
        at_station=1;
        exterior_lights=0;
    }else if(incomingCode == 4){//Station and headlights
        at_station=1;
        exterior_lights=1;
    }
}

void SWTrainController::decodeTrackCircuit(){

    int64_t tcdata = train->getTCData();

    blocklength = (tcdata >> 32) & 0x1FF;
    blocknum = (tcdata >> 24) & 0xFF;
    speed_limit = (tcdata >> 16) & 0xFF;
    setpoint_velocity = (tcdata >> 8) & 0xFF;
    authority = (tcdata) & 0xFF;
}


//Accessors and mutators

void SWTrainController::setPowerCommand(double power){
    power_command = power;
}

double SWTrainController::getPowerCommand(){
    return power_command;
}

void SWTrainController::setKp(double kpin){
    kp = kpin;
}

double SWTrainController::getKp(){
    return kp;
}

void SWTrainController::setKi(double kiin){
    ki = kiin;
}

double SWTrainController::getKi(){
    return ki;
}

void SWTrainController::setAuthority(double auth){
    authority = auth;
}

double SWTrainController::getAuthority(){
    return authority;
}

void SWTrainController::setMBAuthority(double mbauth){
    mb_authority = mbauth;
}

double SWTrainController::getMBAuthority(){
    return mb_authority;
}

void SWTrainController::setCommandedVelocity(double vcmd){
    commanded_velocity = vcmd;
}

double SWTrainController::getCommandedVelocity(){
    return commanded_velocity;
}

void SWTrainController::setSetpointVelocity(double vsp){
    setpoint_velocity = vsp;
}

double SWTrainController::getSetpointVelocity(){
    return setpoint_velocity;
}

void SWTrainController::setCurrentVelocity(double vcurr){
    current_velocity = vcurr;
}

double SWTrainController::getCurrentVelocity(){
    return train->getSpeed();
}


void SWTrainController::setServiceBrake(bool sb){
    service_brake=sb;
    train->setBrakes(sb);
}

bool SWTrainController::getServiceBrake(){
    return train->getBrakes();
}

void SWTrainController::setEmergencyBrake(bool eb){
    emergency_brake=eb;
    train->setEbrakes(eb);
}

bool SWTrainController::getEmergencyBrake(){
    return train->getEbrakes();
}
/*
void SWTrainController::setPassengerBrake(bool pb){
    passenger_brake = pb;
}

bool SWTrainController::getPassengerBrake(){
    return passenger_brake;
}
*/

void SWTrainController::setLeftDoors(bool ld){
    left_doors = ld;
    train->setLeftDoor(left_doors);
}

bool SWTrainController::getLeftDoors(){
    return train->getLeftDoor();
}

void SWTrainController::setRightDoors(bool ld){
    right_doors = ld;
    train->setRightDoor(right_doors);
}

bool SWTrainController::getRightDoors(){
    return train->getRightDoor();
}

void SWTrainController::setInteriorLights(bool il){
    interior_lights = il;
    train->setInteriorLights(interior_lights);
}

bool SWTrainController::getInteriorLights(){
    return train->getInteriorLights();
}

void SWTrainController::setExteriorLights(bool el){
    exterior_lights = el;
    train->setExteriorLights(exterior_lights);
}

bool SWTrainController::getExteriorLights(){
    return train->getExteriorLights();
}


bool SWTrainController::getAtStation(){
    return at_station;
}

void SWTrainController::setMode(bool opp){
    mode=opp;
}

bool SWTrainController::getMode(){
    return mode;
}

void SWTrainController::setSpeedLimit(double sl){
    speed_limit=sl;
}

double SWTrainController::getSpeedLimit(){
    return speed_limit;
}

void SWTrainController::setIncommingStation(std::string is){
    incommingStation=is;
}

std::string SWTrainController::getIncommingStation(){
    return incommingStation;
}

bool SWTrainController::getEngineFailure(){
    return train->getEngineFail();
}


bool SWTrainController::getTCFailure(){
    return train->getSignalFail();
}


bool SWTrainController::getBrakeFailure(){
    return train->getBrakeFail();
}

void SWTrainController::failureCheck(){
    if(train->getEngineFail()){//If track circuit failure
        if(!train->getEbrakes()&&!train->getBrakeFail())//Enable Ebrake if not
            train->setEbrakes(1);
    }else if(train->getSignalFail()){//If track engine failure
        if(!train->getEbrakes()&&!(train->getBrakeFail()))//Enable Ebrake if not
            train->setEbrakes(1);
    }else if(train->getBrakeFail()){//If brake failure
        train->setEbrakes(0);
        train->setBrakes(0);
    }
}

int SWTrainController::getTrainID(){
    return train->getID();
}

int SWTrainController::getblocknum(){
    return blocknum;
}

int SWTrainController::getblocklength(){
    return blocklength;
}

double SWTrainController::getdistTraveledOnBlock(){
    return distTraveledOnBlock;
}

bool SWTrainController::newBlock(){
    //qDebug()<<distTraveledOnBlock;
    if(blocklength<=distTraveledOnBlock){
        distTraveledOnBlock=0;
        return 1;
    }else{
        distTraveledOnBlock+=((current_velocity/3.6)*T); //Converts km/hr to m/s then divides by clock speed
        return 0;
    }
}

uint8_t SWTrainController::getEncodedBlock(){
    return(((uint8_t)blocknum));
}
