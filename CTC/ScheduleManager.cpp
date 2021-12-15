#include "ScheduleManager.h"
#include <fstream>
#include <iostream>
#include "string_utils.hpp"

CTCSchedule::CTCSchedule(std::string _train, std::string _destination, int _time){
    train = _train;
    destination = _destination;
    time = _time;
}

ScheduleManager::ScheduleManager(){
    //These are the station names coming from the MBO.
    stations["STATION; PIONEER"] = 2;
    stations["STATION; EDGEBROOK"] = 9;
    stations["STATION"] = 16;
    stations["STATION; WHITED"] = 22;
    stations["STATION; SOUTHBANK"] = 31;
    stations["STATION; CENTRAL"] = 38; //USED TWICE
    stations["STATION; INGLEWOOD"] = 47; //USED TWICE
    stations["STATION; OVERBROOK"] = 56; //USED TWICE
    stations["STATION; GLENBURY"] = 65; //USED TWICE
    stations["STATION; DORMONT"] = 73; //USED TWICE
    stations["STATION; MT LEBANON"] = 77;
    stations["STATION; POPLAR"] = 88;
    stations["STATION; CASTLE SHANNON"] = 96;
    stations["STATION; DORMONT"] = 105; //USED TWICE
    stations["STATION; GLENBURY"] = 114; //USED TWICE
    stations["STATION; OVERBROOK"] = 122; //USED TWICE
    stations["STATION; INGLEWOOD"] = 131; //USED TWICE
    stations["STATION; CENTRAL"] = 140; //USED TWICE
}

int ScheduleManager::getDestinationBlock(std::string stationName){
    return stations[stationName];
}

std::string ScheduleManager::displaySchedule(){
 	std::string rtn = "";
    for(CTCSchedule& s : schedule){
        rtn += s.train + " ";
        rtn += "to Block " + s.destination + " ";
        rtn += "at Time " + std::to_string(s.time) + "\n";
    }
    return rtn;
}

void ScheduleManager::loadSchedule(std::string filepath){
 	std::ifstream in(filepath);

    if(in.fail()){
        std::cout << "Could not load schedule " + filepath << std::endl;
        return;
    }
   
   	while(!in.eof()){
   		std::string line;
   		std::getline(in, line);
   		
        std::list<std::string> l = string_utils::separate_strings(line, ','); //the strings in the line, separated out

        try{
            auto itr = l.begin();
            std::string train = *(itr++);
            std::string stationName = *(itr++);
            int time = std::stoi(*(itr++));
            addSchedule(CTCSchedule(train, stationName, time));
        }catch(std::exception& e){
            std::cout << "Could not parse schedule " + filepath << std::endl;
        }
   	}

    in.close();
}

void ScheduleManager::addSchedule(CTCSchedule _schedule){
	schedule.push_back(_schedule);
}

CTCSchedule ScheduleManager::loadNextSchedule(){
	if(schedule.empty()){
        return CTCSchedule("", "", 0);
	}

	return schedule[0];
}

void ScheduleManager::popNextSchedule(){
    if(!schedule.empty()){
        schedule.erase(schedule.begin());
    }
}
