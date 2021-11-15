#include "ScheduleManager.h"
#include <fstream>

CTCSchedule::CTCSchedule(std::string _train, int _destination, int _time){
    train = _train;
    destination = _destination;
    time = _time;
}

std::string ScheduleManager::displaySchedule(){
 	std::string rtn = "";
    for(auto s : schedule){
        rtn += s.train + " ";
        rtn += "to Block " + std::to_string(s.destination) + " ";
        rtn += "at Time " + std::to_string(s.time) + "\n";
    }
    return rtn;
}

void ScheduleManager::loadSchedule(std::string filepath){
 	std::ifstream in(filepath);

    if(in.fail()){
        return;
    }
   
   	while(!in.eof()){
   		std::string line;
   		std::getline(in, line);
   		
   		std::vector<std::string> l; //the strings in the line, separated out
   		std::string current;
   		for(char i : line){
   			if(i == ','){
   				l.push_back(current);
   				current.clear();
   			}else{
   				current += i;
   			}
   		}
   		l.push_back(current);
   		
        std::string train = l[0];
   		int destination = std::stoi(l[1]);
   		int time = std::stoi(l[2]);
   		
   		addSchedule(CTCSchedule(train, destination, time));
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
