#include "mbo.h"
#include "ui_mbo.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

MBO::MBO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MBO)
{
    ui->setupUi(this);

    for(int i=0; i<24; i++){
        throughput.push_back(0);
    }
    startOfDay = "0";
    stations = 0;
}

MBO::~MBO()
{
    delete ui;
}

/*
 * This method creates the schedule that is sent to the CTC office. For now it is heavily based
 * on the drivers and their shifts instead of expected throughput.
 */
bool MBO::schedule(){
  created = false;

  TrackLayout greenline("C:/Users/User/Downloads/greenline_v2.csv");

  /* commenting out for iteration 3 - want to schedule one driver
  // verify there are enough drivers to cover entire day
  if(drivers.getNumDrivers() < ceil((24-stoi(startOfDay,nullptr,10))/8.0)){
    // NOTE: add error message here
    QMessageBox messageBox;
    messageBox.critical(0,"Error:1","There are not enough drivers to cover the entire day");
    messageBox.setFixedSize(500,200);
    return false;
  }
  */

  // verify there is driver scheduled for start of day
  if(drivers.getDriver(0).at(1) > startOfDay){
    // NOTE: add error message here
    QMessageBox messageBox;
    messageBox.critical(0,"Error:2","There is not a driver scheduled for the start of the day");
    messageBox.setFixedSize(500,200);
    return false;
  }

  /* commenting out for iteration 3 - want to schedule one driver
  // verify driver schedules cover day from declared start to end
  double contShift= stod(drivers.getDriver(0).at(1),nullptr)+8.5;;
  for(int i=1; i<drivers.getNumDrivers(); i++){
    if(contShift < stod(drivers.getDriver(i).at(1),nullptr)){
      // NOTE: add error message here
      QMessageBox messageBox;
      messageBox.critical(0,"Error:3","Driver shifts do not cover the entire day");
      messageBox.setFixedSize(500,200);
      return false;
    }
    contShift = stod(drivers.getDriver(i).at(1),nullptr)+8.5;
  }
  if(contShift < 24){
    // NOTE: add error message here
    QMessageBox messageBox;
    messageBox.critical(0,"Error:4","Driver shifts do not cover the entire day");
    messageBox.setFixedSize(500,200);
    return false;
  }
  */

  // vector will hold all drivers currently on shift, used for list of drivers to send on track
  vector<vector<string>> activeDrivers;
  // vector holds drivers currently driving a train on the track
  vector<vector<string>> driversOnTrack;

  // Id of each train. This number goes up to infinity and records every instance of a train on the track
  int trainID = 1;

  string infrastructure; // holds infrastructure string from block instance
  string driverName; // holds name of driver of specific train
  string trainIDstr; // trainID in string

  // total passengers who have ridden on the train that day
  int totPass=0;

  Block* head = greenline.getHead(); // get reference to head of track linked list
  Block* current = head;

  /*
   * This for loop is the beginning of the schedule generation process. It starts at beginning of the day
   * in seconds and iterates every 5 seconds until midnight is reached. Every iteration the generation will
   * attempt to send a driver on the track. The generation does not try to space out train departure for
   * passenger's convienence, this functionality would be very difficult to implement.
   */
  for(int secondsOfDay = stoi(startOfDay,nullptr,10)*60*60; secondsOfDay < 86400; secondsOfDay += 5){

    if((secondsOfDay%1800) == 0){ // determine if it is a half hour time (update activeDrivers every half hour)
      for(int i=0; i<drivers.getNumDrivers(); i++){ // update activeDrivers by checking shifts of all drivers
        int shift = stoi(drivers.getDriver(i).at(1),nullptr,10)*60*60; // get shift start in seconds
        if(secondsOfDay == shift){ // add driver to activeDrivers if their shift has started
          activeDrivers.push_back(drivers.getDriver(i));
        }
        else if(secondsOfDay == (shift + (4*60*60))){ // remove driver from activeDrivers if it is their break
          activeDrivers.erase(activeDrivers.begin()+i);
        }
        else if(secondsOfDay == (shift + (4.5*60*60))){ // add driver from activeDrivers if their break is over
          activeDrivers.push_back(drivers.getDriver(i));
        }
        else if(secondsOfDay == (shift + (8.5*60*60))){ // remove driver from activeDrivers if their shift is over
          activeDrivers.erase(activeDrivers.begin()+i);
        }
        else{ // do nothing --> purpose of if else is to skip calculation if earlier conditions are method
        }

      }
      if((secondsOfDay%3600)==0){}// NOTE: add functionality to calculate throughput at every hour
    }

    current = head; // reset current pointer

    /* update block list */
    while(current != NULL){ // check for end of block list
        if(current->occupied->trainID != 0){ // check if block is occupied
            current->timeOccupied += 5; // increment time since last location calculation
            if(current->timeOccupied >= current->blockTime){ // check if train has cleared block

                if((current->next != NULL) && (current->next->occupied->trainID == 0)){ // check that next block is unoccupied
                    current->next->occupied->trainID = current->occupied->trainID; // progress occupancy
                    current->occupied->trainID = 0; // clear occupancy of old block
                    current->timeOccupied = 0; // clear accumulated time in old block

                    infrastructure = current->next->infrastructure;
                    if(infrastructure.substr(0,7) == "STATION"){ // check if train has come to a station
                        trainIDstr = to_string(current->next->occupied->trainID);
                        for(int j =0;j<driversOnTrack.size();j++){ // find name of driver
                            if(driversOnTrack[j][1] == trainIDstr){
                                driverName = driversOnTrack[j][0];
                            }
                        }
                        // time to add to schedule
                        vector<string> vec{to_string(current->next->occupied->trainID),infrastructure,to_string(secondsOfDay),driverName};
                        generatedSchedule.push_back(vec);
                        totPass += 40; // assume an avg of 40 passengers get on at station. 18% max capacity -> reasonable estimate
                    }
                }
                else if(current->next == NULL){ // end of track reached
                    current->occupied->trainID = 0; // clear occupancy
                    current->timeOccupied = 0; // clear accumulated time in old block
                    trainIDstr = to_string(current->occupied->trainID);
                    for(int i=0; i<driversOnTrack.size();i++){
                        if(driversOnTrack[i][1] == trainIDstr){ // find entry in driversOnTrack that has same trainID
                            driversOnTrack.erase(driversOnTrack.begin()+i); // erase entry as it got to end of track
                        }
                    }
                }
            }
            else{} // do nothing, train hasn't cleared block
        }
        else{} // do nothing, train waits for next section to clear
        current = current->next; // move to next block
    }

    /* deploy new train if there is an available driver */
    if((driversOnTrack.size() != 0) && (driversOnTrack.size() < activeDrivers.size())){ // if there is an available driver
        if(head->occupied->trainID == 0){ // if head block is unoccupied
            // deploy first train
            trainID++; // create new train
            head->occupied->trainID = trainID; // assign occupancy to head block

            for(int k=0;k<activeDrivers.size();k++){ // find a driver from active drivers to send
                bool found = false;
                for(int l=0; l<driversOnTrack.size(); l++){
                    if(activeDrivers[k][0] == driversOnTrack[l][0]){
                        found = true;
                    }
                }
                if(!found){
                    driverName = activeDrivers[k][0];
                    break; // leave loop after finding available driver
                }
            }
            // add available driver to driver on track
            vector<string> vec{driverName,to_string(trainID)};
            driversOnTrack.push_back(vec);
        }
    }
    else if((driversOnTrack.size() == 0) && (activeDrivers.size() != 0)){ // send driver out
        if(head->occupied->trainID == 0){ // if head block is unoccupied
            // deploy first train
            trainID++; // create new train
            head->occupied->trainID = trainID; // assign occupancy to head block
            driverName = activeDrivers[0][0]; // if no drivers on track, but there is available driver, take first
            // add available driver to driver on track
            vector<string> vec{driverName,to_string(trainID)};
            driversOnTrack.push_back(vec);
        }
    }
    else{} // do nothing, all active drivers on track

  }
  int thr = totPass/(24-stoi(startOfDay));
  if(throughput[0] > thr){
      QMessageBox messageBox;
      messageBox.critical(0,"Alert:1","Throughput was not reached");
      messageBox.setFixedSize(500,200);
  }
  else{
      QMessageBox messageBox;
      messageBox.critical(0,"Alert:1","Throughput was reached");
      messageBox.setFixedSize(500,200);
  }
  created = true;
  return true;
}

void MBO::exportSchedule(){
    QString filename = "C:/Users/User/Downloads/schedule.csv";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        for(int i=0;i<generatedSchedule.size();i++){
            for(int j=0; j<4; j++){
                stream << QString::fromStdString(generatedSchedule[i][j]);
                stream << ",";
            }
            stream << "\n";
        }
    }
}

void MBO::on_GenerateScheduleButton_clicked() // generate schedule
{
    if(schedule()){

    QString s;

    if(generatedSchedule.empty()){
        QMessageBox messageBox;
        messageBox.critical(0,"Alert:1","Schedule was not generated");
        messageBox.setFixedSize(500,200);
    }

    for(int i=0;i<generatedSchedule.size();i++){
        for(int j=0; j<4; j++){
            s.append(QString::fromStdString(generatedSchedule[i][j]));
            s.append(",");
        }
        s.append("\n");
    }
    ui->ScheduleDisplay->setText(s);
    }
}

void MBO::on_HourlyThroughputButton_clicked() // enter hourly throughput
{
    QString s1 = ui->ThroughputHourComboBox->currentText();
    QString s2 = ui->EnterThroughputTextBox->toPlainText();
    setThroughput(s2.toInt(),s1.toInt());
}

void MBO::on_DayThroughputButton_clicked() // enter day long throughput
{
    QString s2 = ui->EnterThroughputTextBox->toPlainText();
    setThroughput(s2.toInt());
}

void MBO::on_HireDriverButton_clicked() // hire driver
{
    QString s1 = ui->EnterNameTextBox->toPlainText();
    QString s2 = ui->EnterShiftComboBox->currentText();
    drivers.hireDriver(s1.toStdString(), s2.toStdString());

    QString s3;
    s3.append("Name | Shift\n");;
    for(int i=0; i<drivers.getNumDrivers(); i++){
        s3.append(QString::fromStdString(drivers.getDriver(i)[0]));
        s3.append(" | ");
        s3.append(QString::fromStdString(drivers.getDriver(i)[1]));
        s3.append(":00\n");
    }
    ui->DriversDisplay->setText(s3);
}

void MBO::on_FireDriverButton_clicked() // fire driver
{
    QString s1 = ui->EnterNameTextBox->toPlainText();
    drivers.fireDriver(s1.toStdString());

    QString s3;
    s3.append("Name | Shift\n");;
    for(int i=0; i<drivers.getNumDrivers(); i++){
        s3.append(QString::fromStdString(drivers.getDriver(i)[0]));
        s3.append(" | ");
        s3.append(QString::fromStdString(drivers.getDriver(i)[1]));
        s3.append(":00\n");
    }
    ui->DriversDisplay->setText(s3);
}

void MBO::on_StartOfDayButton_clicked() // start of day button
{
    setStartOfDay(ui->StartOfDayComboBox->currentText().toStdString());
}

void MBO::on_ExportScheduleButton_clicked()
{
    if(created){
        exportSchedule();
    }
}

