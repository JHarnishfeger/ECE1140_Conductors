#ifndef DRIVERS_H
#define DRIVERS_H

#include <QMainWindow>

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Drivers
{
public:
    Drivers();

    int getNumDrivers(){return drivers.size();}
    void hireDriver(string name, string shiftStart);
    void fireDriver(string name);
    string getDriverShift(string name);
    vector<string> getDriver(int index);
    void displayShifts();

private:
    vector<vector<string>> drivers;
};

#endif // DRIVERS_H
