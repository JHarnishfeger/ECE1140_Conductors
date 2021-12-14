#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H
#include <string>
#include <vector>
#include <unordered_map>

//A schedule consists of a train ID, a destination block, and an arrival time.
struct CTCSchedule{

    CTCSchedule(std::string _train, int _destination, int _time);
    std::string train;
    int destination;
    int time;
};

class ScheduleManager{

	public:

        ScheduleManager();
	
	    void loadSchedule(std::string filepath);
	    
        void addSchedule(CTCSchedule _schedule);
        
        CTCSchedule loadNextSchedule(); //get schedule without removing from list

        void popNextSchedule(); //remove next schedule from list
        
        std::string displaySchedule();
	
	private:

		//FIFO queue containing list of schedules from file.
        std::vector<CTCSchedule> schedule;

        std::unordered_map<std::string, int> stations;
};

#endif
