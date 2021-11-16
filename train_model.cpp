#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "train_model.h"


Train_Model::Train_Model() {
};

/*Function is the constructor with inputs of
  assigned crew and assigned number of cars
  that are connected to the train.
  */
Train_Model::Train_Model(double sS,int t,int a) {
  authority = a;
  suggestedSpeed = sS;
  numPassengers = t;
};

/*Function is to act as the de-constructor
  of the instance of train.
   */
Train_Model::~Train_Model(){
}

void Train_Model::setID(int id){
    ID = id;
}

std::string Train_Model::getNextStation(){
    return nextStation;
}

/*Function is to set the commanded speed
  of the train through an input of power.
  */
void Train_Model::setSpeed(double inputPower){
  power = inputPower;
  double force;
  force = power/actualSpeed;
  acceleration = force/mass;
  actualSpeed += acceleration;
}

/*Functions is to return the speed or accleration
 * of the train.*/
double Train_Model::getSpeed(){
    return actualSpeed;
}

double Train_Model::getAcceleration(){
    return acceleration;
}


/* functoin is to update passegnr count */
void Train_Model::updatePassengers(){
    numPassengers = rand()%20+20;
}

/*Function is to return the number of people
  on the train.
   */
int Train_Model::getPassengers(){
  return numPassengers; //This will be determined through a sensor input via. .txt file (or maybe crew member counting?).
}

/*Functions are for getting and setting crew size
 * and getting and setting the number of cars for each train
  */
int Train_Model::getCrew(){
  return crewCount;
}

int Train_Model::getCars(){
  return carCount;
}

void Train_Model::setCrew(int size){
    crewCount = size;
}
void Train_Model::setCars(int num){
    carCount = num;
}

/*Function is to return the value of the Ebrakes
  to the controller
  */
bool Train_Model::getBrakes(){
  return brakes;
}

/*Function is to set the boolean value
  of the brakes for display on UI.*/
void Train_Model::setBrakes(bool b){
  brakes = b;
  acceleration = -2;
}

/*Function is to set the emergency brakes
 * of the train model */
void Train_Model::setEbrakes(bool Eb){
  eBrakes = Eb;
  acceleration = -4;
}

/*Function is to return the value of the Ebrakes
  to the controller
  */
bool Train_Model::getEbrakes(){
  return eBrakes; //comes from passenger input
}

/*Function is for murphy inputs to set
  failures at any point in time.
  */
void Train_Model::setFailures(bool eF,bool sF, bool bF){
    brakeFail = bF;
    engineFail = eF;
    signalFail = sF;
}

/*Function is for murphy outputs of the
  three main failures.
  */
bool Train_Model::getEngineFail(){
    return engineFail;
}
bool Train_Model::getSignalFail(){
    return signalFail;
}
bool Train_Model::getBrakeFail(){
    return brakeFail;
}

/*Function is to set the authority using
  an input from the MBO, moving block authority.
  */
void Train_Model::setAuthority(int mba){
  authority = mba;
}

/*Function is to access the authority of
  the train.
  */
int Train_Model::getAuthority(){
  return authority;
}

/*Function is to set the interior lights
  and/or exterior lights of the train
  for display on the UI.
  */
void Train_Model::setDoors(bool leftdoor,bool rightdoor){
    leftDoor = leftdoor;
    rightDoor = rightdoor;
}

/*Function is to access the information
  about the interior/exterior lights.
  */
bool Train_Model::getLeftDoor(){
    return leftDoor;
}
bool Train_Model::getRightDoor(){
    return rightDoor;
}

/*Function is to set the doors
  of the train for display on UI.
  */
void Train_Model::setLights(bool iL,bool eL){
    interiorLights = iL;
    exteriorLights = eL;
}

/*Function is to acces the state
  of the doors on the train.
  */
bool Train_Model::getInteriorLights(){
    return interiorLights;
}
bool Train_Model::getExteriorLights(){
    return exteriorLights;
}


/*Function is to return the loctaion
  of the train using a vector of
  lattitude and longitude.
  */
double Train_Model::getGPS(){
    return 1;
}

void Train_Model::setTemperature(double temps){
    temperature = temps;
}

double Train_Model::getTemperature(){
    return temperature;
}
double Train_Model::getPower(){
    return power;
}

