#include "TrainControllerSignalHandler.h"
#include "SWTrainController.h"
#include "SWTrainController.cpp"
#include<QDebug>

//Creates a new train and assigns an Id value
//New trains are put in a vector of train controllers as well as a vector of UIs
//Need to pass in a train via train model in param
void TraincontrollerSignalHandler::newTrainController(int id){
    UISWTrainController *w = new UISWTrainController(id);
    SWTrainController *swtc = new SWTrainController(id);
    w->swtraincontroller = swtc;
    w->show();
    trainList.push_back(swtc);
    uiList.push_back(w);
    numofTrains++;
}

//Searches for train via Id and deletes the traincontroller and its Id
void TraincontrollerSignalHandler::deleteTrain(int id){
    for(int i=0; i<=numofTrains; i++){
        if(trainList[i]->getId()==id){
            uiList[i]->~UISWTrainController();
            trainList[i]->~SWTrainController();
            trainList.erase(trainList.begin()+i);
            uiList.erase(uiList.begin()+i);
            numofTrains--;
        }
    }
}


//Searches for train via Id and sends beacon info
void TraincontrollerSignalHandler::sendBeacon(uint64_t beacon, int id){
    for(int i=0; i<=numofTrains; i++){
        if(trainList[i]->getId()==id){
            trainList[i]->decodeBeacon(beacon);
        }
    }
}

//Searches for train via Id and sends track circuit info
void TraincontrollerSignalHandler::sendTrackCircuit(uint64_t tcdata, int id){
    for(int i=0; i<=numofTrains; i++){
        if(trainList[i]->getId()==id){
            trainList[i]->decodeTrackCircuit(tcdata);
        }
    }
}
