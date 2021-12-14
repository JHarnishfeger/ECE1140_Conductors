#ifndef TRACKLAYOUT_H
#define TRACKLAYOUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Making occupancy struct
struct Occupancy {
  int trainID;
};

// Making a block struct
struct Block {
  string section;
  int number;
  int length;
  int speedLimit;
  int timeOccupied;
  double blockTime;
  string infrastructure;
  Occupancy *occupied;
  Block *next;
};

/*
 * TrackLayout class reads the track layout and parses it
 * into a data structure that can be used
 */

class TrackLayout
{
    private:
        Block* head;
        Block* current;
        vector<string> sections;
    public:
        TrackLayout();
        TrackLayout(string file);
        Block* getHead(){return head;}
        void insert(string line);
        void linkOccupany();
        void setOccupany();
        void display();
};
#endif
