#include "ScheduleManager.h"
#include <fstream>
#include <iostream>
#include "string_utils.hpp"

CTCSchedule::CTCSchedule(std::string _train, int _destination, int _time){
    train = _train;
    destination = _destination;
    time = _time;
}

std::string ScheduleManager::displaySchedule(){
 	std::string rtn = "";
    for(CTCSchedule s : schedule){
        rtn += s.train + " ";
        rtn += "to Block " + std::to_string(s.destination) + " ";
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
            int destination = std::stoi(*(itr++));
            int time = std::stoi(*(itr++));
            addSchedule(CTCSchedule(train, destination, time));
        }catch(std::exception){
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
		return CTCSchedule("", 0, 0);
	}

	return schedule[0];
	schedule.erase(schedule.begin());
}
