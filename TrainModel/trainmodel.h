#ifndef TRAINMODEL_H
#define TRAINMODEL_H
#include <iostream>
#include <QObject>
//#include "SMBA.h"

class trainModel{

    private:

        //Hardware 0 or Software 1
        bool HardwareOrSoftware;

        //Red (1) or Green line (0)
        bool RedOrGreen;

        //ID of train and next station
        int ID;
        std::string nextStation;

        //speed variables
        double actualSpeed0,actualSpeed1;
        double suggestedSpeed;
        double acceleration0,acceleration1;
        double power;
        int speedLimit;
        double decelerationRateBrake;
        double decelerationRateEmergencyBrake;

        //passenger variable
        int numPassengers;	//number of passengers

        //metrics of the train
        double mass; //in Kg
        double modelMass = 4000; //kg
        double width,length,height;
        int carCount;
        int crewCount;

        //boolean operation values
        bool brakes,eBrakes;
        bool brakeFail,engineFail,signalFail;
        bool interiorLights,exteriorLights;
        bool leftDoor,rightDoor;

        //authority
        double authDistance;
        double authSpeed;

        //temperature
        double temperature;

        //Distance traveled
        double distanceTraveled;

        //Track Circuit Data
        uint64_t TCData;

        //Beacon Data
        uint16_t BeaconData;

    public:
        trainModel(bool HorS,bool RorG);
        ~trainModel();

        //IDs
        void setID(int id);
        int getID();
        std::string getNextStation();

        //speed functions
        void setSpeed(double power);
        double getSpeed();
        double getAcceleration();
        void setPower(double pow);
        double getPower();

        //passenger functions
        void setPassengers(int num);
        int getPassengers();
        void updatePassengers();

        //constant values
        void setCrew(int size);
        void setCars(int num);
        int getCrew();
        int getCars();

        //brakes
        void setBrakes(bool b);
        bool getBrakes();
        void setEbrakes(bool Eb);
        bool getEbrakes();

        //failures
        void setFailures(bool eF,bool sF, bool bF);
        bool getEngineFail();
        bool getSignalFail();
        bool getBrakeFail();

        //authority
        void setAuthority(double Distance,double Speed);
        double getAuthority();

        //lights
        void setInteriorLights(bool interiorLights);
        void setExteriorLights(bool exteriorLights);
        bool getInteriorLights();
        bool getExteriorLights();

        //doors
        void setLeftDoor(bool leftdoor);
        void setRightDoor(bool rightdoor);
        bool getLeftDoor();
        bool getRightDoor();

        //gps
        double getGPS();

        //temp
        void setTemperature(double temperature);
        double getTemperature();

        //speed limit
        void setSpeedLimit(int SL);
        int getSpeedLimit();

        //send Track Circuit Data
        void setTCData(uint64_t Data);
        uint64_t getTCData();

        //send Beacon Data
        void setBeaconData(uint16_t Data);
        uint16_t getBeaconData();

};

#endif // TRAINMODEL_H
