#ifndef TRAIN_SIGNALS_H
#define TRAIN_SIGNALS_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include "train.h"

class Train_Signals
{
private:
    uint64_t data;
    uint64_t GPS;
    struct beacon;
    std::vector<Train_Model> Trains;
    int count;

  public:
    Train_Signals();
    void newTrain(uint32_t trackModelData);
    void powerDecoder(uint8_t power);
    uint64_t trainGPS();
    uint64_t trainData();
    int trainID();

};

#endif // TRAIN_SIGNALS_H
