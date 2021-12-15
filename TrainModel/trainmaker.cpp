#include "trainmaker.h"

trainMaker::trainMaker(QObject *parent) : QObject(parent){
}

void trainMaker::newTrain(bool HardwareOrSoftware,bool RedOrGreen){

    //create a pointer trainui
    trainUI *TheTrain = new trainUI(nullptr,HardwareOrSoftware,ID,RedOrGreen);

    //connecting lower level with maker class
    QObject::connect(TheTrain,SIGNAL(callAgainTCData(uint8_t,int)),this,SLOT(callAgainTCData(uint8_t,int)));

    //pushing into the vectors
    if(HardwareOrSoftware == 0 && (HardwareTrains.size() < 1)){
        HardwareTrains.push_back(TheTrain);
        TheTrain->show();
    }
    else {
        SoftwareTrains.push_back(TheTrain);
        TheTrain->show();
    }
    ID++;
}

void trainMaker::TCData(uint64_t TrackCircuitData,int ID){
    for(int i=0;i<SoftwareTrains.size();i++){
        if(SoftwareTrains[i]->mainTrain->getID() == ID){
            SoftwareTrains[ID]->mainTrain->setTCData(TrackCircuitData);
        }
    }
}

void trainMaker::BeaconData(uint16_t BeaconData,int ID){
    for(int i=0;i<SoftwareTrains.size();i++){
        if(SoftwareTrains[i]->mainTrain->getID() == ID){
            SoftwareTrains[ID]->mainTrain->setBeaconData(BeaconData);
        }
    }
}

void trainMaker::setAuth(double authDistance,double authSpeed,int ID){
    for(int i=0;i<SoftwareTrains.size();i++){
        if(SoftwareTrains[i]->mainTrain->getID() == ID){
            SoftwareTrains[ID]->mainTrain->setAuthority(authDistance,authSpeed);
        }
    }
}

void trainMaker::callAgainTCData(uint8_t currentBlock, int trainID){
    TrainInfo(currentBlock, trainID);
}
