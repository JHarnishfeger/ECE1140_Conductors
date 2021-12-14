#ifndef BLOCK_H
#define BLOCK_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using std::string;
using std::cout;
using std::endl;

//Block Class:
class Block{
  private:
    static int count;
    char line;
	string branch;
    string type;
    double length;
    bool trainPresent;
    int id;
    double grade;
    double suggestedSpeed;
    double speedLimit;
    char direction;
    double temperature;
    int beacons;
    double height;
	bool brokenRail;
	bool brokenCircuit;
	bool powerFailure;
    bool crossingActivated;
    bool switchPosition;
  public:
    Block();
    Block(char, char, string, double, bool, double, double, double, char, double, int, double, bool, bool, bool, bool, bool);
	int getCount() const;
    void setLine(char);
    char getLine();
	void setBranch(string);
	string getBranch();
    void setType(string);
    string getType();
    void setLength(double);
    double getLength();
    void setTrainPresent(bool);
    bool getTrainPresent();
    void setId(int);
    int getId();
	void setGrade(double);
	double getGrade();
	void setSuggestedSpeed(double);
	double getSuggestedSpeed();
	void setSpeedLimit(double);
	double getSpeedLimit();
	void setDirection(char);
	char getDirection();
	void setTemperature(double);
	double getTemperature();
	void setBeacons(int);
	int getBeacons();
	void setHeight(double);
	double getHeight();
	void setBrokenRail(bool);
	bool getBrokenRail();
	void setBrokenCircuit(bool);
	bool getBrokenCircuit();
	void setPowerFailure(bool);
	bool getPowerFailure();
    void setCrossing(bool);
    bool getCrossing();
    void setSwitch(bool);
    bool getSwitch();
	void toConsole();
};
// End Block class

#endif
