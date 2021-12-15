#include "trainmaker.h"

trainMaker::trainMaker(QObject *parent) : QObject(parent){
}

void trainMaker::newTrain(bool HardwareOrSoftware,bool GreenOrRed){

    //create a pointer trainui
    trainUI *TheTrain = new trainUI(nullptr,HardwareOrSoftware,ID,GreenOrRed);

    TheTrain -> show();
    //connecting lower level with maker class
    connect(TheTrain,SIGNAL(callAgainTCData(uint8_t,int)),this,SLOT(callAgainTCData(uint8_t,int)));
    connect(this,SIGNAL(update2()),TheTrain,SLOT(updateUI()));

    //pushing into the vectors
    if(HardwareOrSoftware == 0 && (HardwareTrains.size() < 1)){
        std::cout << "push" << std::endl;
        HardwareTrains.push_back(TheTrain);
    }
    else {
        std::cout << "push" << std::endl;
        SoftwareTrains.push_back(TheTrain);
    }
    ID++;
}

void trainMaker::TCData(uint64_t TrackCircuitData,int ID){
    for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
        if(SoftwareTrains[i]->mainTrain->getID() == ID){
            SoftwareTrains[ID]->mainTrain->setTCData(TrackCircuitData);
        }
    }
}

void trainMaker::BeaconData(uint16_t BeaconData,int ID){
    for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
        if(SoftwareTrains[i]->mainTrain->getID() == ID){
            SoftwareTrains[ID]->mainTrain->setBeaconData(BeaconData);
        }
    }
}

void trainMaker::setAuth(double authDistance,double authSpeed,int ID){
    for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
        if(SoftwareTrains[i]->mainTrain->getID() == ID){
            SoftwareTrains[ID]->mainTrain->setAuthority(authDistance,authSpeed);
        }
    }
}

void trainMaker::callAgainTCData(uint8_t currentBlock, int trainID){
    emit TrainInfo(currentBlock, trainID);
}

void trainMaker::update(){
    for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
        emit update2();
    }
}
