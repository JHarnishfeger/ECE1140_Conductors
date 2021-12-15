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
struct MBO_Block {
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
  MBO_Block *next;
  MBO_Block *peripheralBlock;
};

/*
 * TrackLayout class reads the track layout and parses it
 * into a data structure that can be used
 */

class TrackLayout
{
    private:
        MBO_Block* head;
        MBO_Block* current;
        MBO_Block* switch_block;
        vector<int> occupancySections;
        bool isRedLine;
        bool isPeripherals;
    public:
        TrackLayout();
        void setTrack(bool isRedLine, string file);
        MBO_Block* getHead(){return head;}
        void insert(string line);
        void linkOccupany(int duppedOccupancy);
        void setOccupany();
        void setPeripheralOccupancy();
        void display();
};
#endif
