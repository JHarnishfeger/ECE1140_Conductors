#ifndef BLOCK_H
#define BLOCK_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
using std::string;
using std::vector;
using namespace std;

//Block class
class Block{
	private:
		string line;
		string branch;
		string type;
		string stationName;
		string nextBranches;
		vector<int> nextBlocks;
		int number;
		int speedLimit;
		int passengers;
		int trafficLightStatus;
		int stationSide;
		double suggestedSpeed;
		double temperature;
		double length;
		double grade;
		double elevation;
		bool authority;
		bool railStatus;
		bool circuitStatus;
		bool powerStatus;
		bool heaterStatus;
		bool crossingStatus;
		bool switchStatus;
		bool trainPresent;
		bool beaconPresent;
		uint32_t trackCircuitData;
		uint16_t beaconData;
	public:
		//Constructors: ------------------------------------------------
		Block();
		Block(string,string,string,string,string,vector<int>,int,int,int,int,int,double,double,double,double,double,bool,bool,bool,bool,bool,bool,bool,bool,bool,uint32_t,uint16_t);
		Block(string,string,int,double,double,int,string,int,double,double);
		//Attributes: --------------------------------------------------
		//line:
		void setLine(string);
		string getLine();
		//branch:
		void setBranch(string);
		string getBranch();
		//type:
		void setType(string);
		string getType();
		//stationName:
		void setStationName(string);
		string getStationName();
		//nextBranches
		void setNextBranches(string);
		string getNextBranches();
		//nextBlocks:
		void setNextBlocks(int,int);
		vector<int> getNextBlocks();
		//number:
		void setBlockNumber(int);
		int getBlockNumber();
		//speedLimit:
		void setSpeedLimit(int);
		int getSpeedLimit();
		//passengers:
		void setPassengerCount(int);
		int getPassengerCount();
		//trafficLightStatus:
		void setTrafficLightStatus(int);
		int getTrafficLightStatus();
		//stationSide:
		void setStationSide(int);
		int getStationSide();
		//suggestedSpeed:
		void setSuggestedSpeed(double);
		double getSuggestedSpeed();
		//temperature:
		void setTemperature(double);
		double getTemperature();
		//length:
		void setLength(double);
		double getLength();
		//grade:
		void setGrade(double);
		double getGrade();
		//elevation:
		void setElevation(double);
		double getElevation();
		//authority:
		void setAuthority(bool);
		bool getAuthority();
		void toggleAuthority();
		//railStatus:
		void setRailStatus(bool);
		bool getRailStatus();
		void toggleRailStatus();
		//circuitStatus:
		void setCircuitStatus(bool);
		bool getCircuitStatus();
		void toggleCircuitStatus();
		//powerStatus:
		void setPowerStatus(bool);
		bool getPowerStatus();
		void togglePowerStatus();
		//heaterStatus:
		void setHeaterStatus(bool);
		bool getHeaterStatus();
		void toggleHeaterStatus();
		//crossingStatus:
		void setCrossingStatus(bool);
		bool getCrossingStatus();
		void toggleCrossingStatus();
		//switchStatus:
		void setSwitchStatus(bool);
		bool getSwitchStatus();
		void toggleSwitchStatus();
		//trainPresent:
		void setTrainPresent(bool);
		bool getTrainPresent();
		void toggleTrainPresent();
		//beaconPresent:
		void setBeaconPresent(bool);
		bool getBeaconPresent();
		//trackCircuitData:
		void encodeTrackCircuitData();
		uint32_t getTrackCircuitData();
		//beaconData:
		void encodeBeaconData();
		uint16_t getBeaconData();
		//toStrings
		string toString();
		string toStringDetailed();
};
//End Block class
#endif


