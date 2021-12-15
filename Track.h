#ifndef Track_H
#define Track_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Block.h"
#include <QDebug>
using std::vector;
using std::string;
using std::fstream;

//Track class
class Track{
    private:
        vector<Block*> greenLine;
        vector<Block*> redLine;
        double suggSpeed;
    public:
        //Constructors:
        Track();
        Track(vector<Block*>,vector<Block*>,double);
        Track(string,double);
        void initalize(string,double);
        //Attributes:
        //greenLine
        vector<Block*> getGreenLine();
        //redLine
        vector<Block*> getRedLine();
        //suggSpeed
        void setSuggSpeed(double);
        double getSuggSpeed();
        //class functions:
        Block* searchBlock(string,int);
        Block* searchBlockById(string,int);
        Block* go(string,int,double);
        vector<Block*> filterByType(string,string);
        vector<Block*> filterByBranch(string,string);
        vector<Block*> filterByRailStatus(string,bool);
        vector<Block*> filterByCircuitStatus(string,bool);
        vector<Block*> filterByPowerStatus(string,bool);
        vector<Block*> filterByHeaterStatus(string,bool);
        vector<Block*> filterByCrossingStatus(string,bool);
        vector<Block*> filterBySwitchStatus(string,bool);
        bool loadTrack(string);
        bool breakRail(string,int);
        bool breakCircuit(string,int);
        bool breakPower(string,int);
        bool fixRail(string,int);
        bool fixCircuit(string,int);
        bool fixPower(string,int);
        void updateTrack(vector<Block>);
        //intergration:
        void initalizeTrain(int);
        uint64_t handleTCTrainInfo(uint8_t,int,bool);
        uint16_t handleBeaconTrainInfo(uint8_t,int,bool);
        //toStrings
        string toString();
        string toStringDetailed();
};
//End Track class
#endif
