#ifndef SMBA_h
#define SMBA_h
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/*
 * SMBA class defines the actions the MBO can take to calculate
 * Safe Moving Block Authority
 */

class SMBA
{
    private:
        vector<vector<double>> trainCoords;
        vector<vector<double>> safeDistances; // member will change to vector<vector<double>> when module can use prediction
        vector<vector<string>> GPS_mapping;
        double authDistance;
        double authSpeed;
    public:
        SMBA();
        void receiveCoords(int trainID, double latitude, double longitude, double distanceTravelled);
        void updateTrainCoords(double trainID, double latitude, double longitude, double blockDistance);
        void calculateAuthority(double trainID, int GPS_mapping_pos);
        double getSafeDistance(double trainID);
        double getAuthDistance(){return authDistance;}
        double getAuthSpeed(){return authSpeed;}

};
#endif
