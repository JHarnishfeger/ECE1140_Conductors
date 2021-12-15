#include "TrainControllerSignalHandler.h"
#include "SWTrainController.h"
#include "SWTrainController.cpp"


void TraincontrollerSignalHandler::newTrainController(){
    UISWTrainController *w = new UISWTrainController();
    SWTrainController *swtc = new SWTrainController();
    w->swtraincontroller = swtc;
    w->show();
    trainList.push_back(swtc);
}

double TraincontrollerSignalHandler::sendPowerTest(){
    return trainList[train_select]->getPowerCommand();
}

double TraincontrollerSignalHandler::sendGPSTest(){
    return trainList[train_select]->getGPS();
}
