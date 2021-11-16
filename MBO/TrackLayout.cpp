#include "TrackLayout.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

TrackLayout::TrackLayout(string file){
  head = NULL;
  current = NULL;
  string line;
  ifstream layoutFile(file);
  if (layoutFile.is_open()){
    getline(layoutFile,line);
    while (getline (layoutFile,line)){
      insert(line);
    }
    layoutFile.close();
    setOccupany();
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
  //QMessageBox messageBox;
  //messageBox.critical(0,"Error:2",QString::fromStdString(line));
  //messageBox.setFixedSize(500,200);
  // make a new block
  Block* new_block = new Block;
  new_block->section = v[1];
  new_block->number = stoi(v[2]);
  new_block->length = stoi(v[3]);
  new_block->timeOccupied = 0;
  new_block->speedLimit = stoi(v[5]);
  new_block->infrastructure = v[6];
  new_block->blockTime = stod(v[7]);
  new_block->next = NULL;

  // If list is empty, make the new node the head
  if (head == NULL){
    head = new_block;
    current = head;
  }
  else{
    current->next = new_block;
    current = new_block;
    current->next = NULL;
  }

}

void TrackLayout::setOccupany(){
    current = head;
    int i=1;
    while(current != NULL){ // iterate through linked list
        Occupancy* occ = new Occupancy;
        occ->trainID = 1;
        current->occupied = occ; // create general occupany instance for each block
        // search list of sections and check if current section is present. If it is, set them to same occupancy struct
        for(int i=0; i<sections.size();i++){ // loop over all sections
            if((!sections.empty()) && (sections[i] == current->section)){ // if sections match, match occupancies
                Block* temp1;
                temp1 = head;
                while(temp1->next != NULL){
                    if(temp1->section == current->section){
                        Occupancy* dual_occ = new Occupancy;
                        dual_occ->trainID = 0;
                        current->occupied = dual_occ;
                        temp1->occupied = dual_occ;
                    }
                    temp1 = temp1->next;
                }
            }
        }
        // add current section to list of sections if next section is different from the current one
        // this is to prevent loop in concurrent blocks in a section
        if((current->next != NULL) && (current->next->section != current->section)){
            sections.push_back(current->section);
        }

        //Occupancy a = *current->occupied;
        current->occupied->trainID = 0; // set to unoccupied
        current = current->next; // go to next block in linked list

        i++;
    }
}

// add functionality to link occupancies of bidirectional sections
void TrackLayout::linkOccupany(){}

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
