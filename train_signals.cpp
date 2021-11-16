#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "train_signals.h"


void Train_Signals::newTrain(uint32_t trackModelData){
    double crew;
    double cars;
    double authority,suggestedSpeed,tickets;

    //set amount of crew and cars per train model
    crew = 4;
    cars = 4;

    //converting trackModelData into doubles

    //`using a mask for all 3 doubles while using and operation with
    //the track model data
    //int startBit;
    //
    //unsigned mask;
    //startBit = ; //Patrick will decide
    //mask = ((1 << ) - 1) << startBit;
    //authority = trackModelData & mask;
    //
    //unsigned mask;
    //startBit = ; //Patrick will decide
    //mask = ((1 << ) - 1) << startBit;
    //authority = trackModelData & mask;
    //
    //unsigned mask;
    //startBit = ; //Patrick will decide
    //mask = ((1 << ) - 1) << startBit;
    //authority = trackModelData & mask;
    //
    //new Train_Model tempTrain(authority,suggestedSpeed,tickets);
    //new TrainUI w;
    //w->tempTrain;
    //w->show();
    //
    //Trains.push_back(tempTrain);
}

void Train_Signals::powerDecoder(uint8_t power){

}

uint64_t Train_Signals::trainGPS(){
    //create a uint64_t as GPS

    return GPS;
}

uint64_t Train_Signals::trainData(){
    return data;
}

int Train_Signals::trainID(){
    count = 1;
    if (count != 1){
        count ++;
    }
    return count;
}
