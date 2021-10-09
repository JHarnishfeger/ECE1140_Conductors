#ifndef Block_H
#define Block_H
#include <string>

//Block Class:
class Block{
  private:
	static int count;
    char line;
	char branch:
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
	bool brokenRail
	bool brokenCircuit;
	bool powerFailure;
  public:
	int getCount() const;
    void setLine(char);
    char getLine();
	void setBranch(char);
	char getBranch();
    void setType(string);
    string getType();
    void setLength(double);
    double getLength();
    void setTrainPresent(bool);
    bool getTrainPresent();
    void setId(int);
    int getId() const;
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
	int getBeachons();
	void setHeight(double);
	double getHeight():
	void setBrokenRail(bool);
	bool getBrokenRail();
	void setBrokenCircuit(bool);
	bool getBrokenCircuit();
	void setPowerFailure(bool);
	bool getPowerFailure();
	void toConsole();
};
// End Block class

#endif
