#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H
#include <string>

//A schedule consists of a train ID, a destination block, and an arrival time.
struct CTCSchedule{

    CTCSchedule(std::string _train, int _destination, int _time);
    std::string train;
    int destination;
    int time;
};

class ScheduleManager{

	public:
	
	    void loadSchedule(std::string filepath);
	    
        void addSchedule(CTCSchedule _schedule);
        
        CTCSchedule loadNextSchedule();
        
        std::string displaySchedule();
	
	private:

		//FIFO queue containing list of schedules from file.
        std::vector<CTCSchedule> schedule;
};

#endif
