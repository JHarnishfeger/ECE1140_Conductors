#include "TrackLayout.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

TrackLayout::TrackLayout(){
  isPeripherals = false; // variable for tracking whether the red line has hit the peripheral loops blocks
  isRedLine = false;
  head = NULL;
  current = NULL;
  switch_block = NULL; // block for saving spot when branching to peripheral blocks
}

void TrackLayout::setTrack(bool isRedLine, string file){
    this->isRedLine = isRedLine; // set isRedLine

    string line;
    ifstream layoutFile(file);
    if (layoutFile.is_open()){
      getline(layoutFile,line);
      while (getline (layoutFile,line)){
        insert(line);
      }
      layoutFile.close();
      setOccupany();
      if(isRedLine){
          setPeripheralOccupancy();
      }
    }
    else cout << "Unable to open file";
}

void TrackLayout::insert(string line)
{
  // parse comma delimited string into vector
  vector<string> v;
  stringstream ss(line);
  while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
  }

  // make new blocks
  Block* new_block = new Block; // block for normal progression

  if(isRedLine && v[0] == "Peripheral"){ // determine if next blocks handle peripherals (only for red line)
      isPeripherals = !isPeripherals; // toggle isPeripherals

      if(isPeripherals){ // going into peripherals
         switch_block = current; // save spot for when leaving peripherals
      }
      else{ // leaving peripherals
         Block* temp = current; // save end of peripheral loop
         current = switch_block; // revert to saved spot for normal progression
         switch_block = temp; // save end of peripheral loop
      }
  }
  else{
      new_block->section = v[1];
      new_block->number = stoi(v[2]);
      new_block->length = stoi(v[3]);
      new_block->timeOccupied = 0;
      new_block->delay = 0;
      new_block->speedLimit = stoi(v[5]);
      new_block->infrastructure = v[6];
      new_block->blockTime = stod(v[7]);
      new_block->occupiedSection = stoi(v[8]);
      new_block->next = NULL;
      new_block->peripheralBlock = NULL;

      if(isRedLine){ // test for exit of periphal loops
          // Basically there is no easy way to determine where the peripheral loops exit with the way
          // I constructed my .csv file. The work around is to hard-check for the change from the normal
          // line progression to the switch that connects the peripheral loops and then connect my exit
          // to that
          if(new_block != NULL && current != NULL){
              if((new_block->occupiedSection == 8) && (current->occupiedSection == 7)){
                  switch_block->peripheralBlock = new_block;
              }
              if((new_block->occupiedSection == 10) && (current->occupiedSection == 9)){
                  switch_block->peripheralBlock = new_block;
              }
              if((new_block->occupiedSection == 8) && (current->occupiedSection == 9)){
                  switch_block->peripheralBlock = new_block;
              }
              if((new_block->occupiedSection == 6) && (current->occupiedSection == 7)){
                  switch_block->peripheralBlock = new_block;
              }
          }
      }

      // If list is empty, make the new node the head
      if (head == NULL){
        head = new_block;
        current = head;
      }
      else if(isPeripherals){ // peripheral loops only use the peripheral block object
        current->peripheralBlock = new_block; // set the current block's periph block to the one created (op includes switch block)
        current = new_block; // progress current pointer
        current->peripheralBlock = NULL; // initialize next instance's periph block
      }
      else{ // else add the new node to the end of the list
        current->next = new_block;
        current = new_block;
        current->next = NULL;
      }
  }
}

void TrackLayout::setOccupany(){
    current = head;
    int i=1; // testing purposes
    while(current != NULL){ // iterate through linked list
        Occupancy* occ = new Occupancy;
        occ->trainID = 0; // set to unoccupied
        current->occupied = occ; // create general occupany instance for each block
        // search list of sections and check if current section is present. If it is, set them to same occupancy struct
        for(int i=0; i<occupancySections.size();i++){ // loop over all (occupancy) sections
            if((!occupancySections.empty()) && (occupancySections[i] == current->occupiedSection)){ // if sections match, match occupancies
                linkOccupany(occupancySections[i]); // call method that links occupancy of all blocks in bidirectional sections
            }
        }
        // add current occupied section to list of occupancy sections if next section is different from the current one
        // this is to prevent loop in concurrent blocks in a section
        if((current->next != NULL) && (current->next->occupiedSection != current->occupiedSection)){
            occupancySections.push_back(current->occupiedSection);
        }

        current = current->next; // go to next block in linked list

        i++;
    }
}

// add functionality to link occupancies of bidirectional sections
void TrackLayout::linkOccupany(int duppedSection){
    // iterate until the dupped occupancy section is over
    while(true){
        Block* temp; // create temp Block to find the duplicated sections
        temp = head; // set the temp Block instance to the beginning of the list
        while(temp != NULL){
            if(temp->occupiedSection == current->occupiedSection){
                Occupancy* dual_occ = new Occupancy;
                dual_occ->trainID = 0;
                current->occupied = dual_occ;
                temp->occupied = dual_occ;
            }
            temp = temp->next;
        }
        // only go to next block within occupancy
        if((current->next->occupiedSection == duppedSection) && (current->next != NULL)){
            current = current->next;
        }
        else{
            break; // kill while loop if the next block is in a different occupancy section
        }
    }
}
/*
 * This method is used to set shared occupancy for both the peripheral loops.
 * Too tired to think of dynamacy, so I hard coded using the occupancy sections
 * set in the .csv file.
 */
void TrackLayout::setPeripheralOccupancy(){
    current = head;
    vector<int> peripheralOccupancySections;

    // create occupancy objects for both peripheral loops
    Occupancy* LoopRST = new Occupancy;
    LoopRST->trainID = 0;
    Occupancy* LoopOPQ = new Occupancy;
    LoopOPQ->trainID = 0;

    // iterate through list to find peripheral loops
    while(current != NULL){ // iterate through linked list
        if(current->peripheralBlock != NULL){
            Block* temp = current; // set temp variable to current block where switch is found

            while(temp->peripheralBlock != NULL){
                // test for occupancy sections in periph loops. Should skip switch block
                if(temp->occupiedSection == 14){
                    temp->occupied = LoopRST;
                }
                if(temp->occupiedSection == 13){
                    temp->occupied = LoopOPQ;
                }
                temp = temp->peripheralBlock; // progress through peripheral loop
            }
        }
        current = current->next; // progress through list
    }
}

void TrackLayout::display()
{
  Block* temp = head;
  while(temp != NULL)
  {
    cout << temp->section << ",";
    cout << temp->number << ",";
    cout << temp->length << ",";
    cout << temp->speedLimit << ",";
    cout << temp->infrastructure << "\n";
    temp = temp->next;
  }
  cout << endl;
}
