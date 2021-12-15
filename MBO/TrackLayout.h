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
  int delay;
  double blockTime;
  string infrastructure;
  int occupiedSection;
  Occupancy *occupied;
  Block *next;
  Block *peripheralBlock;
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
        Block* switch_block;
        vector<int> occupancySections;
        bool isRedLine;
        bool isPeripherals;
    public:
        TrackLayout();
        void setTrack(bool isRedLine, string file);
        Block* getHead(){return head;}
        void insert(string line);
        void linkOccupany(int duppedOccupancy);
        void setOccupany();
        void setPeripheralOccupancy();
        void display();
};
#endif
