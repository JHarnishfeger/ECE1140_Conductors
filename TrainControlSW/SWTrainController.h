#ifndef SWTrainController_H
#define SWTrainController_H

#include <cstdint>
#include <string>
#include <stdlib.h>
#include "..\TrainModel\trainModel.h"

class SWTrainController{
    private:
        //Defining private variables
        //
        //Power variables
        double power_command = 0.0;
        double kp = 10000.0;
        double ki = 10000.0;
        double uk = 0.0;
        double uk1 = 0.0;
        double ek = 0.0;
        double ek1 = 0.0;
        double T = 1;

        //Transit data variables
        double authority = 0.0;
        double mb_authority = 0.0;
        double speed_limit = 0;
        std::string incommingStation = "None";
        double commanded_velocity = 0.0;
        double setpoint_velocity = 10.0;
        double current_velocity = 0.0;

        //Utilities variables
        bool service_brake = false;
        bool emergency_brake = false;
        bool left_doors = false;
        bool right_doors = false;
        bool interior_lights = false;
        bool exterior_lights = false;

        //Extra internal variables
        bool at_station = false;
        bool just_stopped = false;
        bool mode = true;
        //double gps = 0;

      public:
        trainModel* train;
        SWTrainController();//ADD TRAIN TO PARAMETER
        ~SWTrainController();

        //Internal operation, realtime, and module communitcation functions
        double calculatePower();
        void atStation();
        void decodeBeacon();
        void decodeTrackCircuit();

        //Accessors and mutators
        void setPowerCommand(double);
        double getPowerCommand(); //Will convert to unsigned int return when actually implimenting
        void setKp(double);
        double getKp();
        void setKi(double);
        double getKi();

        void setAuthority(double);
        double getAuthority();
        void setMBAuthority(double);
        double getMBAuthority();
        void setSpeedLimit(double);
        double getSpeedLimit();
        void setIncommingStation(std::string);
        std::string getIncommingStation();
        void setCommandedVelocity(double);
        double getCommandedVelocity();
        void setSetpointVelocity(double);
        double getSetpointVelocity();
        void setCurrentVelocity(double);
        double getCurrentVelocity();

        void setServiceBrake(bool);
        bool getServiceBrake();
        void setEmergencyBrake(bool);
        bool getEmergencyBrake();
        void setPassengerBrake(bool);
        bool getPassengerBrake();

        void setLeftDoors(bool);
        bool getLeftDoors();
        void setRightDoors(bool);
        bool getRightDoors();
        void setInteriorLights(bool);
        bool getInteriorLights();
        void setExteriorLights(bool);
        bool getExteriorLights();

        bool getAtStation();
        void setMode(bool);
        bool getMode();
        bool getEngineFailure();
        bool getTCFailure();
        bool getBrakeFailure();

};

#endif // SWTrainController.h
