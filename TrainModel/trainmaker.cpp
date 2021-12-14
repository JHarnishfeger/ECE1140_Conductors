#include "trainmaker.h"

trainMaker::trainMaker(QObject *parent) : QObject(parent){

}

trainMaker::~trainMaker(){
    HardwareTrain.clear();
    SoftwareTrains.clear();
}

void trainMaker::makeTrain(bool HorS, bool RorG){

    //determining if the train is hardware or software
    if(HorS == 0 && (HardwareTrain.size() < 1)){
        HardwareTrain.push_back(mainTrainUI);
    }
    else {
        SoftwareTrains.push_back(mainTrainUI);
    }

}

void trainMaker::TCData(uint64_t TrackCircuitData,int ID){
    SoftwareTrains[ID].mainTrain->setTCData(TrackCircuitData);
}

void trainMaker::BeaconData(uint32_t BeaconData,int ID){
    SoftwareTrains[ID].mainTrain->setBeaconData(BeaconData);
}

void trainMaker::setAuth(double authDistance,double authSpeed,int ID){
    SoftwareTrains[ID].mainTrain->setAuthority(authDistance,authSpeed);
}
