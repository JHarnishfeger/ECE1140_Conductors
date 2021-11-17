#ifndef BLOCK_H
#define BLOCK_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
using std::string;

//Block class
class Block{
	private:
		static int instanceCounter;	
		static double xCordTotal;
		static double yCordTotal;
		static double totalDistance;
		int passengers;
		int id;
		string line;
		string branch;
		string type;
		string direction;
		string nextBranches;
		string stationName;
		double length;
		double xCord;
		double yCord;
		double grade;
		double height;
		double temperature;
		double speedLimit;
		double suggestedSpeed;
		double TDBegin;
		bool authority;
		bool railStatus;
		bool circuitStatus;
		bool powerStatus;
		bool heaterStatus;
		bool crossingStatus;
		bool switchStatus;
		bool trainPresent;
		uint32_t encodedData;
	public:
		//Constructors:
		Block();
		Block(int,string,string,string,string,string,string,double,double,double,double,double,double,double,double,bool,bool,bool,bool,bool,bool,bool,bool,uint32_t);
		Block(string,string,int,double,double,double,string,double,double,string);
		//Attributes:
		//passengers
		void setPassengers(int);
		int getPassengers();
		//id
		int getId();
		//line
		void setLine(string);
		string getLine();
		//branch
		void setBranch(string);
		string getBranch();
		//type
		void setType(string);
		string getType();
		//direction
		void setDirection(string);
		string getDirection();
		//nextBranches
		void setNextBranches(string);
		string getNextBranches();
		//stationName
		void setStationName(string);
		string getStationName();
		//length
		void setLength(double);
		double getLength();
		//xCord
		void setXCord(double);
		double getXCord();
		//yCord
		void setYCord(double);
		double getYCord();
		//grade
		void setGrade(double);
		double getGrade();
		//height
		void setHeight(double);
		double getHeight();
		//temperature
		void setTemperature(double);
		double getTemperature();
		//speedLimit
		void setSpeedLimit(double);
		double getSpeedLimit();
		//suggestedSpeed
		void setSuggestedSpeed(double);
		double getSuggestedSpeed();
		//authority
		void setAuthority(bool);
		bool getAuthority();
		void toggleAuthority();
		//railStatus
		void setRailStatus(bool);
		bool getRailStatus();
		void toggleRailStatus();
		//circuitStatus
		void setCircuitStatus(bool);
		bool getCircuitStatus();
		void toggleCircuitStatus();
		//powerStatus
		void setPowerStatus(bool);
		bool getPowerStatus();
		void togglePowerStatus();
		//heaterStatus
		void setHeaterStatus(bool);
		bool getHeaterStatus();
		void toggleHeaterStatus();
		//crossingStatus
		void setCrossingStatus(bool);
		bool getCrossingStatus();
		void toggleCrossingStatus();
		//switchStatus
		void setSwitchStatus(bool);
		bool getSwitchStatus();
		void toggleSwitchStatus();
		//trainPresent
		void setTrainPresent(bool);
		bool getTrainPresent();
		void toggleTrainPresent();
		//encoding
		void encodeData();
		uint32_t getEncodedData();
		//toStrings
		string toString();
		string toStringDetailed();
};
//End Block class
#endif
