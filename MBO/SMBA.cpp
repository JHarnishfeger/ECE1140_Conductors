#include "SMBA.h"
#include <QDebug>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

SMBA::SMBA(){
    isRedLine = false; // make global variable later
    authDistance = 0;
    trainVelocity = 0;
    string filepath = "";

    // send the filepath depending on whether its the red or green line
    if(isRedLine){
        filepath = "C:/Users/User/Downloads/redline_v2.csv";
    }
    else{
        filepath = "C:/Users/User/Downloads/greenline_v2.csv";
    }
    line.setTrack(isRedLine,filepath);
    head = line.getHead(); // get reference to head of track linked list
}

/*
* This method takes the coordinate signals from the Train Model
*/
void SMBA::transferCoords(int trainID, int block, double distance, double velocity){

    trainVelocity = velocity; // sets the velocity of the train in question

    updateTrainCoords(static_cast<double>(trainID), static_cast<double>(block), distance);
    findTrain(static_cast<double>(trainID));

    // save the calculated authority values
    double temp_authDistance;
    temp_authDistance = authDistance;

    // recalculate authority values (safety measure)
    findTrain(static_cast<double>(trainID));
    // if there is an inconsistency in the calculations, set distance to zero so Train knows to brake immediately
    if(authDistance != temp_authDistance){
        authDistance = 0;
    }
    qDebug()<<authDistance;
    // send Authority back to Train Model
    emit setAuth(authDistance,trainID);
    //emit setAuth(authDistance,trainID); // set the authority twice for safety
}

/*
* This method takes the received train coordinates and updates the positions of all trains
*/
void SMBA::updateTrainCoords(double trainID, double blockID, double blockDistance){
  bool found = false;
  double prevBlockID = 0; // when new train on track, give null previous block
  int i;
  if(trainCoords.size() == 0){ // track empty, add first train
    vector<double> vec {trainID, blockID, blockDistance, prevBlockID};
    trainCoords.push_back(vec);
    found = true; // skip adding new train to track
  }
  else{
    for(i=0; i < trainCoords.size(); i++){ // iterate over the active trains
      if(trainID == trainCoords[i][0]){ // check if the train is already on the track
        trainCoords[i][2] = blockDistance; // update distance in block
        if(trainCoords[i][1] != blockID){ // check if block has changed
            trainCoords[i][3] = trainCoords[i][1]; // store the old block into the prev slot
            trainCoords[i][1] = blockID; // update the current block
        }
        found = true; // skip adding new train to track
      }
    }
  }
  if(!found){ // new train on track
    vector<double> vec {trainID, blockID, blockDistance, prevBlockID};
    trainCoords.push_back(vec);
  }

  if(isRedLine){ // hard coded ending coords
      if(blockID == 9 && blockDistance>63){ // if they are far enough in last block, destroy train
        for(i=0; i < trainCoords.size(); i++){
          if(trainID == trainCoords[i][0]){
            trainCoords.erase(trainCoords.begin()+i);
          }
        }
      }
  }
  else{ // greenline
    if(blockID == 62 && blockDistance>41){ // if they are far enough in last block, destroy train
      for(i=0; i < trainCoords.size(); i++){
        if(trainID == trainCoords[i][0]){
          trainCoords.erase(trainCoords.begin()+i);
        }
      }
    }
  }
}

void SMBA::findTrain(double trainID){
    //Block* head = line.getHead(); // get reference to head of track linked list
    Block* current = head;

    for(int i=0; i<trainCoords.size(); i++){ // iterate through train list
        if(trainCoords[i][0] == trainID){ // check if found train in question
            while(current->next != NULL){ // iterate through block list
                if((trainCoords[i][3] != 0) && (current->number == trainCoords[i][3])){ // find block that the train was just in
                    // confirm that train is moving in the direction that you are at in the block list
                    if(current->next->number == trainCoords[i][1]){ // two points make a line

                        calculateAuthority(current, trainID, i, false);
                        return;
                    }
                    // case that the last block was a switch block and train went into peripheral
                    //if(current->peripheralBlock != NULL && current->peripheralBlock->number == trainCoords[i][1]){

                    //}
                }
                if(isRedLine && current->peripheralBlock != NULL){ // case when train is on switch block, checks peripheral path
                    Block* curr_periph = current; // branch from switch block in case there is no train in peripheral path
                    while(curr_periph->peripheralBlock != NULL){ // iterate through peripheral path
                        if(curr_periph->number == trainCoords[i][3]){ // find block that the train was just in
                            // confirm that train is moving in the direction that you are at in the block list
                            if(curr_periph->peripheralBlock->number == trainCoords[i][1]){ // two points make a line
                                calculateAuthority(curr_periph, trainID, i, true);
                                return;
                            }
                            curr_periph = curr_periph->peripheralBlock; // progress through peripheral path
                        }
                    }
                }
                if(trainCoords[i][3] == 0){ // train is in first block
                    // no need for checks, we know where the train is
                    calculateAuthority(current, trainID, i, false);
                    return;
                }
                current = current->next;
            }
        }
    }
}

void SMBA::calculateAuthority(Block* current, double trainID, int i, bool isPeriph){

    if(isPeriph){
        current = current->peripheralBlock; // progress one block, we are now in current block
    }
    else if (current == head){ // do not move a block forward if at the head
    }
    else{
        current = current->next; // progress one block, we are now in current block
    }

    // now that we have found the block the train is in as well as its direction,
    // we can butcher the position of the current block since we end after calculation
    double distanceToNextTrain = 0;
    for(int j=0; j<3; j++){ // check the next three blocks
        for(int k=0; k<trainCoords.size(); k++){ // iterate through list of trains
            // check if any trains are in the block that is not the train in question
            if((trainCoords[k][0] != trainID) && (current->number == trainCoords[k][1])){
                // we have found a train that is in front of our train in question
                // find difference in distance between the trains

                if(current->number == trainCoords[i][1]){ // if we are in same block
                    distanceToNextTrain = trainCoords[k][2] - trainCoords[i][2];
                }
                // add distance traveled in block of train in front of train in question
                distanceToNextTrain += trainCoords[k][2];

                // Now we have the distance to the next train. Calculate auth and quit
                distanceToNextTrain -= 40; // true distance, account for train length
                // find distance between the tail of the next train and the distance the
                // train will travel if the e brake is slammed
                authDistance = distanceToNextTrain - (((trainVelocity/3.6)*(trainVelocity/3.6))/(2*2.73));

                if(authDistance > 99.0){
                    authDistance = 99.0;
                }
                if(authDistance < 0){
                    authDistance = 0;
                }
                return; // auth is calculated, quit method
            }
        }

        if(current->number == trainCoords[i][1]){ // if we are in same block
            distanceToNextTrain += current->length - trainCoords[i][2];
        }
        else{ // if train is in later blocks
            distanceToNextTrain += current->length;
        }

        if(isRedLine && isPeriph && current->peripheralBlock != NULL){
            current = current->peripheralBlock; // progress one block, we are now in current block
        }
        else{
            current = current->next;
        }
    }
    // no train found, calculate authority anyway
    authDistance = distanceToNextTrain - (((trainVelocity/3.6)*(trainVelocity/3.6))/(2*2.73));

    if(authDistance > 99.0){
        authDistance = 99.0;
    }
    if(authDistance < 0){
        authDistance = 0;
    }
}
