#include "trainmodelmoc.h"

trainModelMoc::trainModelMoc()
{

}

/*Function is to set the interior lights
  and/or exterior lights of the train
  for display on the UI.
  */
void trainModelMoc::setLeftDoor(bool leftdoor){
    leftDoor = leftdoor;
}

void trainModelMoc::setRightDoor(bool rightdoor){
    rightDoor = rightdoor;
}

/*Function is to access the information
  about the interior/exterior lights.
  */
bool trainModelMoc::getLeftDoor(){
    return leftDoor;
}
bool trainModelMoc::getRightDoor(){
    return rightDoor;
}

/*Function is to set the doors
  of the train for display on UI.
  */
void trainModelMoc::setInteriorLights(bool iL){
    interiorLights = iL;
}

void trainModelMoc::setExteriorLights(bool eL){
    exteriorLights = eL;
}

/*Function is to acces the state
  of the doors on the train.
  */
bool trainModelMoc::getInteriorLights(){
    return interiorLights;
}
bool trainModelMoc::getExteriorLights(){
    return exteriorLights;
}

/*Function is to return the value of the Ebrakes
  to the controller
  */
bool trainModelMoc::getBrakes(){
  return brakes;
}

/*Function is to set the boolean value
  of the brakes for display on UI.*/
void trainModelMoc::setBrakes(bool b){
  brakes = b;
}

/*Function is to set the emergency brakes
 * of the train model */
void trainModelMoc::setEbrakes(bool Eb){
  eBrakes = Eb;
}

/*Function is to return the value of the Ebrakes
  to the controller
  */
bool trainModelMoc::getEbrakes(){
  return eBrakes; //comes from passenger input
}

void trainModelMoc::setPower(double pow){
    power=pow;
}

double trainModelMoc::getPower(){
    return power;
}

double trainModelMoc::getSpeed(){
    return actualSpeed;
}

void trainModelMoc::setSpeed(double speed)
{
    actualSpeed = speed;
}
