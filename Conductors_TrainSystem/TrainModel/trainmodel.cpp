#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "trainmodel.h"
#include<QDebug>

/*Function is the constructor with inputs of
  assigned crew and assigned number of cars
  that are connected to the train.
  */
trainModel::trainModel(bool HardwareOrSoftware) {
  authDistance = 0;
  authSpeed = 0;
  numPassengers = 0;
  crewCount = 1;
  carCount = 2;
  mass = (carCount * modelMass) + (numPassengers * 70);
  actualSpeed0 = 0;
  actualSpeed1 = 1;
  acceleration0 = 0;
  acceleration1 = 0;
  leftDoor = false;
  rightDoor = false;
  interiorLights = true;
  exteriorLights = false;
  brakes = false;
  eBrakes = false;
  engineFail = false;
  signalFail = false;
  brakeFail = false;
  temperature = 60;
  decelerationRateBrake = -1.2;
  decelerationRateEmergencyBrake = -2.73;
  HorS = HardwareOrSoftware;
};

/*Function is to act as the de-constructor
  of the instance of train.
   */
trainModel::~trainModel(){
}

void trainModel::setID(int id){
    ID = id;
}

std::string trainModel::getNextStation(){
    return nextStation;
}

/*Function is to set the commanded speed
  of the train through an input of power.
  */
void trainModel::setSpeed(double inputPower){
  double force;

  //setting power for display
  power = inputPower;


  if(brakes == true){
      if(acceleration1 > 0)
        acceleration1 = 0;
    acceleration1 = acceleration1 + decelerationRateBrake;
    if((actualSpeed1+acceleration1) <= 0){
        actualSpeed1 = 0;
        actualSpeed0 = 0;
        acceleration0 = 0;
        acceleration1 = 0;
    }
  }
  else if(eBrakes == true){
        if(acceleration1 > 0)
            acceleration1 = 0;
        acceleration1 = acceleration1 + decelerationRateEmergencyBrake;
        if((actualSpeed1+acceleration1) <= 0){
            engineFail = false;
            signalFail = false;
            actualSpeed1 = 0;
            actualSpeed0 = 0;
            acceleration0 = 0;
            acceleration1 = 0;
        }
      }
    //Doesnt work well need to fix
    else if(brakeFail == true){
        if(acceleration1 > 0)
            acceleration1 = 0;
        acceleration1 = acceleration1 - 0.01;
        if((actualSpeed1+acceleration1) <= 0){
            actualSpeed1 = 0;
            actualSpeed0 = 0;
            acceleration0 = 0;
            acceleration1 = 0;
            brakeFail = false;
        }
     }
  else if(engineFail == true){
      if(acceleration1 > 0)
        acceleration1 = 0;
      acceleration1 = acceleration1 + decelerationRateEmergencyBrake;
      if((actualSpeed1+acceleration1) <= 0){
          actualSpeed1 = 0;
          actualSpeed0 = 0;
          acceleration0 = 0;
          acceleration1 = 0;
          brakeFail = false;
      }
   }
    else {
      if(actualSpeed1==0)
        actualSpeed1=1;
      force = power/actualSpeed1;
      acceleration1 = force/mass;
      if (acceleration1 > 2){
          acceleration1 = 2;
      }
    }

  actualSpeed1 = actualSpeed0 + ((.5) * (acceleration0 + acceleration1));
  distanceTraveled += actualSpeed1;

  //reinitializing the previous iterated acceleration and speed
  acceleration0 = acceleration1;
  actualSpeed0 = actualSpeed1;
}

/*Functions is to return the speed or accleration
 * of the train.*/
double trainModel::getSpeed(){
    return actualSpeed1;
}

double trainModel::getAcceleration(){
    return acceleration1;
}

//speed limit functions
void trainModel::setSpeedLimit(int SL){
    speedLimit = SL;
}
int trainModel::getSpeedLimit(){
    return speedLimit;
}

/* functoin is to update passegnr count */
void trainModel::updatePassengers(){
    numPassengers = rand()%20+80;
}

/*Function is to return the number of people
  on the train.
   */
int trainModel::getPassengers(){
  return numPassengers; //This will be determined through a sensor input via. .txt file (or maybe crew member counting?).
}

/*Functions are for getting and setting crew size
 * and getting and setting the number of cars for each train
  */
int trainModel::getCrew(){
  return crewCount;
}

int trainModel::getCars(){
  return carCount;
}

void trainModel::setCrew(int size){
    crewCount = size;
}
void trainModel::setCars(int num){
    carCount = num;
}

/*Function is to return the value of the Ebrakes
  to the controller
  */
bool trainModel::getBrakes(){
  return brakes;
}

/*Function is to set the boolean value
  of the brakes for display on UI.*/
void trainModel::setBrakes(bool b){
  brakes = b;
}

/*Function is to set the emergency brakes
 * of the train model */
void trainModel::setEbrakes(bool Eb){
  eBrakes = Eb;
}

/*Function is to return the value of the Ebrakes
  to the controller
  */
bool trainModel::getEbrakes(){
  return eBrakes; //comes from passenger input
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
void trainModel::setFailures(bool eF,bool sF, bool bF){
    brakeFail = bF;
    engineFail = eF;
    signalFail = sF;
}

/*Function is for murphy outputs of the
  three main failures.
  */
bool trainModel::getEngineFail(){
    return engineFail;
}
bool trainModel::getSignalFail(){
    return signalFail;
}
bool trainModel::getBrakeFail(){
    return brakeFail;
}

/*Function is to set the authority using
  an input from the MBO, moving block authority.
  */
void trainModel::setAuthority(double Distance,double Speed){
  authDistance = Distance;
  authSpeed = Speed;
}

/*Function is to access the authority of
  the train.
  */
int trainModel::getAuthority(){
  return authDistance;
}

/*Function is to set the interior lights
  and/or exterior lights of the train
  for display on the UI.
  */
void trainModel::setLeftDoor(bool leftdoor){
    leftDoor = leftdoor;
}

void trainModel::setRightDoor(bool rightdoor){
    rightDoor = rightdoor;
}

/*Function is to access the information
  about the interior/exterior lights.
  */
bool trainModel::getLeftDoor(){
    return leftDoor;
}
bool trainModel::getRightDoor(){
    return rightDoor;
}

/*Function is to set the doors
  of the train for display on UI.
  */
void trainModel::setInteriorLights(bool iL){
    interiorLights = iL;
}

void trainModel::setExteriorLights(bool eL){
    exteriorLights = eL;
}

/*Function is to acces the state
  of the doors on the train.
  */
bool trainModel::getInteriorLights(){
    return interiorLights;
}
bool trainModel::getExteriorLights(){
    return exteriorLights;
}


/*Function is to return the loctaion
  of the train using a vector of
  lattitude and longitude.
  */
double trainModel::getGPS(){
    return 1;
}

void trainModel::setTemperature(double temps){
    temperature = temps;
}

double trainModel::getTemperature(){
    return temperature;
}

void trainModel::setPower(double pow){
    power=pow;
}

double trainModel::getPower(){
    return power;
}

int trainModel::getID(){
    return ID;
}

//Track circuit get and set
void trainModel::setTCData(uint64_t Data){
    TCData = Data;
}

uint64_t trainModel::getTCData(){
    if(signalFail == true){
        return 0;
    }
    else{
        return TCData;
    }
}

//Beacon get and set
void trainModel::setBeaconData(uint16_t Data){
    BeaconData = Data;
}

uint16_t trainModel::getBeaconData(){
    return BeaconData;
}
