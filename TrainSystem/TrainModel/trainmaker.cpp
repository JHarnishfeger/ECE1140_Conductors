#include "trainmaker.h"

trainMaker::trainMaker(QObject *parent) : QObject(parent){
}

void trainMaker::newTrain(bool HardwareOrSoftware,bool GreenOrRed){

    //create a pointer trainui
    trainUI *TheTrain = new trainUI(nullptr,HardwareOrSoftware,ID,GreenOrRed);

    TheTrain -> show();
    //connecting lower level with maker class
    connect(TheTrain,SIGNAL(callAgainTCData(uint8_t,int,bool)),this,SLOT(callAgainTCData(uint8_t,int,bool)));
    connect(this,SIGNAL(update2()),TheTrain,SLOT(updateUI()));

    //pushing into the vectors
    if(HardwareOrSoftware == 0 && (HardwareTrains.size() < 1)){
        HardwareTrains.push_back(TheTrain);
    }
    else {
        SoftwareTrains.push_back(TheTrain);
    }
    ID++;
}

void trainMaker::TCData(uint64_t TrackCircuitData,int ID){
    if(SoftwareTrains.size()>0){
        for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
            if(SoftwareTrains[i]->mainTrain->getID() == ID){
                SoftwareTrains[i]->mainTrain->setTCData(TrackCircuitData);
            }
        }
    }
    if(HardwareTrains.size()>0){
        if(HardwareTrains[0]->mainTrain->getID() == ID){
                HardwareTrains[0]->mainTrain->setTCData(TrackCircuitData);
        }
    }
}

void trainMaker::BeaconData(uint16_t BeaconData,int ID){
    if(SoftwareTrains.size()>0){
        for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
            if(SoftwareTrains[i]->mainTrain->getID() == ID){
                SoftwareTrains[i]->mainTrain->setBeaconData(BeaconData);
            }
        }
    }

    if(HardwareTrains.size()>0){
        if(HardwareTrains[0]->mainTrain->getID() == ID){
            HardwareTrains[0]->mainTrain->setBeaconData(BeaconData);
        }
    }
}

void trainMaker::setAuth(double authDistance,int ID){
    if(SoftwareTrains.size()>0){
        for(unsigned long long int i=0;i<SoftwareTrains.size();i++){
            if(SoftwareTrains[i]->mainTrain->getID() == ID){
                SoftwareTrains[i]->mainTrain->setAuthority(authDistance);
            }
        }
    }
    if(HardwareTrains.size()>0){
        if(HardwareTrains[0]->mainTrain->getID() == ID){
            HardwareTrains[0]->mainTrain->setAuthority(authDistance);
        }
    }
}

void trainMaker::callAgainTCData(uint8_t currentBlock, int trainID,bool RorG){
    emit TrainInfo(currentBlock, trainID,RorG);
}

void trainMaker::update(){
        emit update2();
}

void trainMaker::xferCoords(int trainID,int currentBlock,double distance,double velocity){
    qDebug() << "xferCoords";
    emit transferCoords(trainID,currentBlock,distance,velocity);
    qDebug() << "trasnferred";
}
