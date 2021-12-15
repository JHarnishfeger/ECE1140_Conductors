#include "mbo.h"
#include "ui_mbo.h"
#include <QMessageBox>
#include <QDebug>
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
    isRedLine = false;
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
  string filepath = "";

  // send the filepath depending on whether its the red or green line
  if(isRedLine){
      filepath = "redline_v2.csv";
  }
  else{
      filepath = "greenline_v2.csv";
  }

  TrackLayout line;// parse the track layout into a linked list
  line.setTrack(isRedLine,filepath);

  // verify there are enough drivers to cover entire day
  if(drivers.getNumDrivers() < ceil((24-stoi(startOfDay,nullptr,10))/8.0)){
    // NOTE: add error message here
    QMessageBox messageBox;
    messageBox.critical(0,"Error:1","There are not enough drivers to cover the entire day");
    messageBox.setFixedSize(500,200);
    return false;
  }

  // verify there is driver scheduled for start of day
  if(drivers.getDriver(0).at(1) > startOfDay){
    // NOTE: add error message here
    QMessageBox messageBox;
    messageBox.critical(0,"Error:2","There is not a driver scheduled for the start of the day");
    messageBox.setFixedSize(500,200);
    return false;
  }

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

  // vector will hold all drivers currently on shift, used for list of drivers to send on track
  vector<vector<string>> activeDrivers;
  // vector holds drivers currently driving a train on the track
  vector<vector<string>> driversOnTrack;
  // vector to hold the hours when throughput was not reached
  vector<int> failedThroughputs;

  // Id of each train. This number goes up to infinity and records every instance of a train on the track
  int trainID = 0;

  bool isPeriph = false; // tracks whether the circuit is iterating through a peripheral path

  string infrastructure; // holds infrastructure string from block instance
  string driverName; // holds name of driver of specific train
  string trainIDstr; // trainID in string

  // total passengers who have ridden on the train that day
  int totPass=0;

  MBO_Block* head = line.getHead(); // get reference to head of track linked list
  MBO_Block* current = head;
  MBO_Block* save_curr = new MBO_Block;

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
            for(int k=0;k<activeDrivers.size(); k++){
                if(drivers.getDriver(i).at(0) == activeDrivers[k][0]){
                    activeDrivers.erase(activeDrivers.begin()+i);
                }
            }
        }
        else if(secondsOfDay == (shift + (4.5*60*60))){ // add driver from activeDrivers if their break is over
          activeDrivers.push_back(drivers.getDriver(i));
        }
        else if(secondsOfDay == (shift + (8.5*60*60))){ // remove driver from activeDrivers if their shift is over
            for(int k=0;k<activeDrivers.size(); k++){
                if(drivers.getDriver(i).at(0) == activeDrivers[k][0]){
                    activeDrivers.erase(activeDrivers.begin()+i);
                }
            }
        }
        else{ // do nothing --> purpose of if else is to skip calculation if earlier conditions are method
        }

      }
      if((secondsOfDay%3600)==0){
          int hour = (86400 - 3600)/24;
          if(throughput[hour-1] <= totPass){ // throughput passes
              totPass = 0; // reset passenger count
          }
          else{ // throughput not met
              failedThroughputs.push_back(hour);
          }
      }// NOTE: add functionality to calculate throughput at every hour
    }

    current = head; // reset current pointer

    /* update block list */
    while(current != NULL){ // check for end of block list
        if(current->occupied->trainID != 0){ // check if block is occupied
            // passed occupied check, we have found a train
            if(current->delay <= 0){ // make sure there is no delay on train
                current->timeOccupied += 5; // increment time since last location calculation
                if(current->timeOccupied >= current->blockTime){ // check if train has cleared block
                    // case that train is on a normal block and next block is unoccupied
                    if((current->next != NULL) && (current->next->occupied->trainID == 0)){ // check that next block is unoccupied
                        current->next->occupied->trainID = current->occupied->trainID; // progress occupancy
                        current->occupied->trainID = 0; // clear occupancy of old block
                        current->timeOccupied = 0; // clear accumulated time in old block

                        infrastructure = current->next->infrastructure;
                        if(infrastructure.substr(0,7) == "STATION"){ // check if train has come to a station
                            trainIDstr = to_string(current->next->occupied->trainID);
                            current->next->delay = 60; // add minute delay for stations
                            for(int j =0;j<driversOnTrack.size();j++){ // find name of driver
                                if(driversOnTrack[j][1] == trainIDstr){
                                    driverName = driversOnTrack[j][0];
                                }
                            }
                            // time to add to schedule
                            vector<string> vec{to_string(current->next->occupied->trainID),infrastructure,to_string(secondsOfDay),driverName};
                            generatedSchedule.push_back(vec);
                            totPass += 50; // assume an avg of 50 passengers get on at station. 18% max capacity -> reasonable estimate
                        }
                    }
                    // case that train is in a peripheral loop, and next block is unoccupied
                    else if(isRedLine && (current->next == NULL) && (current->peripheralBlock != NULL) && (current->peripheralBlock->occupied->trainID == 0)){
                        current->peripheralBlock->occupied->trainID = current->occupied->trainID; // progress occupancy
                        current->occupied->trainID = 0; // clear occupancy of old block
                        current->timeOccupied = 0; // clear accumulated time in old block
                        // No stations in peripherals
                    }
                    else if((current->next == NULL) && (current->peripheralBlock == NULL)){ // end of track reached
                        trainIDstr = to_string(current->occupied->trainID);
                        current->occupied->trainID = 0; // clear occupancy
                        current->timeOccupied = 0; // clear accumulated time in old block
                        for(int i=0; i<driversOnTrack.size();i++){
                            if(driversOnTrack[i][1] == trainIDstr){ // find entry in driversOnTrack that has same trainID
                                driversOnTrack.erase(driversOnTrack.begin()+i); // erase entry as it got to end of track
                            }
                        }
                    }
                    // case that train is on a switch block, next block is occupied, and peripheral is unoccupied
                    else if(isRedLine && (current->next->occupied->trainID != 0) && (current->peripheralBlock != NULL) && (current->peripheralBlock->occupied->trainID == 0)){
                        current->peripheralBlock->occupied->trainID = current->occupied->trainID; // progress occupancy
                        current->occupied->trainID = 0; // clear occupancy of old block
                        current->timeOccupied = 0; // clear accumulated time in old block
                        // No stations in peripherals
                    }
                    else{} // do nothing, next block is occupied
                }
                else{} // do nothing, train hasn't cleared block
            }
            else{
                current->delay -= 5; // reduce the delay by five seconds
            }
        }
        else{} // do nothing, block is empty
        // progress
        if(isRedLine && current->peripheralBlock != NULL){ // at a switch, need to probe into peripheral loop
            if(!isPeriph){ // save the switch block if we are just entering peripheral loop
                save_curr = current->next; // save block after switch since switch is already taken
            }
            isPeriph = true; // state that we are in a peripheral loop
            current = current->peripheralBlock; // move to next block
            if(current->next != NULL){ // if the next block has a valid "next" attribute, revert to beginning of peripheral
                current = save_curr; // we are at end of peripheral loop, revert to beginning
                isPeriph = false;
            }
        }
        else{ // normal progression
            current = current->next; // move to next block
        }
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
    else if((driversOnTrack.size() == 0) && (activeDrivers.size() != 0)){ // send driver out, there are no trains on track
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
  if(failedThroughputs.size() != 0){
      string s;
      for(int i=0; i<failedThroughputs.size(); i++){
          s.append(to_string(failedThroughputs[i]) + ":00,");
      }
      QMessageBox messageBox;
      messageBox.critical(0,"Alert:1","Throughput was not reached in these hours: " + QString::fromStdString(s));
      messageBox.setFixedSize(500,200);
  }
  else{
      QMessageBox messageBox;
      messageBox.critical(0,"Alert:2","Throughput was reached");
      messageBox.setFixedSize(500,200);
  }
  created = true;
  return true;
}

void MBO::exportSchedule(){
    QString filename = "schedule.csv";
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

void MBO::on_GenerateScheduleButton_clicked(){ // generate schedule
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
        s.clear(); // clear the text after display
    }
}

void MBO::on_HourlyThroughputButton_clicked(){ // enter hourly throughput
    QString s1 = ui->ThroughputHourComboBox->currentText();
    QString s2 = ui->EnterThroughputTextBox->toPlainText();
    setThroughput(s2.toInt(),s1.toInt());
}

void MBO::on_DayThroughputButton_clicked(){ // enter day long throughput
    QString s2 = ui->EnterThroughputTextBox->toPlainText();
    setThroughput(s2.toInt());
}

void MBO::on_HireDriverButton_clicked(){ // hire driver
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

void MBO::on_FireDriverButton_clicked(){ // fire driver
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

void MBO::on_StartOfDayButton_clicked(){ // start of day button
    setStartOfDay(ui->StartOfDayComboBox->currentText().toStdString());
}

void MBO::on_ExportScheduleButton_clicked(){ // export schedule button
    if(created){
        exportSchedule();
    }
    else{
        // NOTE: add error message here
        QMessageBox messageBox;
        messageBox.critical(0,"Error:5","No schedule was created.");
        messageBox.setFixedSize(500,200);
    }
}

void MBO::on_horizontalSlider_valueChanged(int value){ // slider that determines line
    qDebug()<< value;
    if(value == 0){
        isRedLine = false;
    }
    if(value == 1){
        isRedLine = true;
    }
}

