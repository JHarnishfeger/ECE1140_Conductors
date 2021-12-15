#ifndef SMBA_h
#define SMBA_h
#include "TrackLayout.h"
#include <QObject>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/*
 * SMBA class defines the actions the MBO can take to calculate
 * Safe Moving Block Authority
 */

class SMBA : public QObject
{
    Q_OBJECT

    private:
        vector<vector<double>> trainCoords;
        //vector<vector<double>> safeDistances; // member will change to vector<vector<double>> when module can use prediction
        TrackLayout line; // member function for the track object
        Block* head;
        double authDistance;
        double trainVelocity;
        bool isRedLine;
    public:
        SMBA();
        void updateTrainCoords(double trainID, double blockID, double blockDistance);
        void findTrain(double trainID);
        void calculateAuthority(Block* current, double trainID, int i, bool isPeriph);
        //double getSafeDistance(double trainID);
    public slots:
        void transferCoords(int trainID, int block, double distance, double velocity);
    signals:
        void setAuth(double authDistance, int ID);

};
#endif
