#include "SWTrainController.h"

#include <iostream>
#include <iomanip>

void SWTrainController::calculatePower(){

    if (service_brake || emergency_brake || passenger_brake||authority<=0){ //If any brake is enables or no authority, power is cut
        power_command = 0;
    }else{
        //If in automatic mode, use commanded velocity, if in manual use setpoint velocity
        if (mode&&current_velocity<speed_limit)
            ek  = setpoint_velocity - current_velocity;
        else if(!mode&&current_velocity<speed_limit)
            ek  = commanded_velocity - current_velocity;
        else
            ek  = speed_limit - current_velocity;

        //Calculates uk and sets current error to previous error
        uk = uk1 + (T / 2) * (ek - ek1);
        ek1 = ek;

        //Calculates power
        power_command = kp * ek + ki * uk;

        //If power calculation exceeds max power, set power command to max power
        if(power_command > 120000)
            power_command = 120000;
    }

    //Check if need to stop at a station
    //atStation();
}

/*
void SWTrainController::atStation(){
    //No idea how to code this
}
*/


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

void SWTrainController::setIncommingStation(std::string ucs){
    incommingStation=ucs;
}

std::string SWTrainController::getIncommingStation(){
    return incommingStation;
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
    return current_velocity;
}


void SWTrainController::setServiceBrake(bool sb){
    service_brake = sb;
}

bool SWTrainController::getServiceBrake(){
    return service_brake;
}

void SWTrainController::setEmergencyBrake(bool eb){
    emergency_brake = eb;
}

bool SWTrainController::getEmergencyBrake(){
    return emergency_brake;
}

void SWTrainController::setPassengerBrake(bool pb){
    passenger_brake = pb;
}

bool SWTrainController::getPassengerBrake(){
    return passenger_brake;
}


void SWTrainController::setLeftDoors(bool ld){
    left_doors = ld;
}

bool SWTrainController::getLeftDoors(){
    return left_doors;
}

void SWTrainController::setRightDoors(bool rd){
    right_doors = rd;
}

bool SWTrainController::getRightDoors(){
    return right_doors;
}

void SWTrainController::setInteriorLights(bool il){
    interior_lights = il;
}

bool SWTrainController::getInteriorLights(){
    return interior_lights;
}

void SWTrainController::setExteriorLights(bool el){
    exterior_lights = el;
}

bool SWTrainController::getExteriorLights(){
    return exterior_lights;
}


bool SWTrainController::getAtStation(){
    return at_station;
}

bool SWTrainController::getTrainStopped(){
    return train_stopped;
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

double SWTrainController::getGPS(){
    return gps;
}
