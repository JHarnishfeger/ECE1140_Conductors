#ifndef BLOCK_H
#define BLOCK_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
using std::string;

//Block class
class Block{
	private:
		static int instanceCounter;
		static string branchesList;
		static int branchIndex;
		int id;
		string line;
		string branch;
		string type;
		string direction;
		string nextBranches;
		double length;
		double grade;
		double height;
		double temperature;
		double speedLimit;
		double suggestedSpeed;
		//double authority?
		bool railStatus;
		bool circuitStatus;
		bool powerStatus;
		bool heaterStatus;
		bool crossingStatus;
		bool switchStatus;
	public:
		//Constructors:
		Block();
		Block(string,string,string,string,string,double,double,double,double,double,double,bool,bool,bool,bool,bool,bool);
		Block(string,string,string,double,double,double,double,double,double);
		//Attributes:
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
		//length
		void setLength(double);
		double getLength();
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
		//Authority?
};
//End Block class
#endif
