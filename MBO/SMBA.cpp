#include "SMBA.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

SMBA::SMBA(){
    string line;
    vector<string> v;
    ifstream file("C:/Users/User/Downloads/GPS_mapping.txt");
    if (file.is_open()){
        getline(file,line);
        while (getline (file,line)){
            stringstream ss(line);
            while (ss.good()) {
                  string substr;
                  getline(ss, substr, ',');
                  v.push_back(substr);
            }
            GPS_mapping.push_back(v);
        }
    }
}

/*
* This method takes the coordinates signal from the Train Model
*/
void SMBA::receiveCoords(int trainID, double latitude, double longitude, double distanceTravelled){

    double distance = 0.0;
    int i;
    for(i=0; i<GPS_mapping.size();i++){
        if((stod(GPS_mapping[i][4].substr(4)) == longitude) && (stod(GPS_mapping[i][5].substr(4)) == latitude)){
           break;
        }
        distance += stod(GPS_mapping[i][3].substr(4));
    }


    updateTrainCoords(static_cast<double>(trainID), latitude, longitude, distanceTravelled-distance);
    calculateAuthority(static_cast<double>(trainID), i);
}

/*
* This method takes the received train coordinates and updates the positions of all trains
* Need to add functionality to predict positions of other trains
*/
void SMBA::updateTrainCoords(double trainID, double latitude, double longitude, double blockDistance){
  bool found = false;
  int i;
  if(trainCoords.size() == 0){
    vector<double> vec {trainID, latitude, longitude, blockDistance};
    trainCoords.push_back(vec);
  }
  else{
    for(i=0; i < trainCoords.size(); i++){
      if(trainID == trainCoords[i][0]){
        trainCoords[i][1] = latitude;
        trainCoords[i][2] = longitude;
        trainCoords[i][3] = blockDistance;
        found = true;
      }
    }
  }
  if(!found){
    vector<double> vec {trainID, latitude, longitude, blockDistance};
    trainCoords.push_back(vec);
  }
  if(latitude == -3699.000000 && longitude == -7321.600000){ // hard coded ending coords
    trainCoords.erase(trainCoords.begin());
  }
}

void SMBA::calculateAuthority(double trainID, int GPS_mapping_pos){
  //double distance=0;
  //safeDistances.clear(); // wipe all previous safe distances to make room for new
    double diff = 0;

    for(int i=0; i<trainCoords.size();i++){
        if(trainCoords[i][0] == trainID){ // find train
            if(i == (trainCoords.size()-1)){
                authDistance = 99; // no train ahead, set auth to max
                authSpeed = stod(GPS_mapping[GPS_mapping_pos][7]); // this will fail
            }
            else{
                for(int j=0;j<GPS_mapping.size();j++){
                    if((stod(GPS_mapping[i][4].substr(4)) == trainCoords[i+1][2]) && (stod(GPS_mapping[i][5].substr(4)) == trainCoords[i+1][1])){
                        double nextTrainPos = stod(GPS_mapping[i][6].substr(10)) + trainCoords[i+1][3];
                        double TrainPos = stod(GPS_mapping[GPS_mapping_pos][6].substr(10)) + trainCoords[i][3];
                        diff = nextTrainPos - TrainPos;
                        break;
                    }
                }
                double maxSpeed = stod(GPS_mapping[GPS_mapping_pos][7]) * (10/36);
                double distanceToStop= (maxSpeed * maxSpeed)/4.0;
                if((diff-distanceToStop) >= 99.0){
                    authDistance = 99.0;
                }
                else if((diff-distanceToStop) < 99.0){
                    authDistance = diff-distanceToStop;
                }
                else{
                    authDistance = 0;
                }
                authSpeed = stod(GPS_mapping[GPS_mapping_pos][7]); // this will fail
                break;
            }
        }
    }
}

double SMBA::getSafeDistance(double trainID){
  for(int i=0; i<safeDistances.size(); i++){
    if(safeDistances[i][0] == trainID){
      return safeDistances[i][1];
    }
  }
  return 0.0;
}
