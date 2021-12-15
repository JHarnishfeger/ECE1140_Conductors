#include "drivers.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Drivers::Drivers(){}

/*
* This method adds a driver to the list of available Drivers
* Vector is sorted by shiftStart parameter
*/
void Drivers::hireDriver(string name, string shiftStart){
  bool inserted = false;
  if(!drivers.empty()){
    for(int i=0; i<drivers.size(); i++){
      if(stoi(shiftStart) < stoi(drivers[i][1])){
        auto it = drivers.begin()+i;
        drivers.insert(it, vector<string>());
        drivers[i].push_back(name);
        drivers[i].push_back(shiftStart);
        inserted = true;
        break;
      }
    }
  }
  if(drivers.empty() || !inserted){
    vector<string> vec{name,shiftStart};
    drivers.push_back(vec);
  }
}

/*
* This method removes a driver from the list of available Drivers
* This is done by deleting the individual driver's vector entry from
* the drivers vector
*/
void Drivers::fireDriver(string name){
  for(int i=0; i < drivers.size(); i++){
    if(name == drivers[i][0]){
      drivers.erase(drivers.begin()+i);
      break; // only fire one driver at a time
    }
  }
}

/*
* This method returns a driver's shift from the list of available Drivers using name
*/
string Drivers::getDriverShift(string name){
  for(int i=0; i < drivers.size(); i++){
    if(name == drivers[i][0]){
      return drivers[i][1];
    }
  }
  QMessageBox messageBox; // NOTE: add error message
  messageBox.critical(0,"Error:5","Tried to get shift of driver that does not exist");
  messageBox.setFixedSize(500,200);
  return "";
}

/*
* This method returns a driver vector from the list of drivers using index
*/
vector<string> Drivers::getDriver(int index){
  return drivers[index];
}

/*
* This method prints out all of the Driver's names and schedules
* May need to change how the shifts are displayed depending on Qt
*/
void Drivers::displayShifts(){
  for(int i=0; i < drivers.size(); i++){
      cout << drivers[i][0] << " " << drivers[i][1] << endl;
  }
}
