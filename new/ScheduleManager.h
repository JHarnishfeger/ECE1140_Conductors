#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H
#include <string>
#include <vector>
#include <unordered_map>

//A schedule consists of a train ID, a destination block, and an arrival time.
struct CTCSchedule{

    CTCSchedule(std::string _train, std::string _destination, int _time);
    std::string train;
    std::string destination;
    int time;
};

class ScheduleManager{

	public:

        ScheduleManager();
	
	    void loadSchedule(std::string filepath);
	    
        void addSchedule(CTCSchedule _schedule);
        
        CTCSchedule loadNextSchedule(); //get schedule without removing from list

        void popNextSchedule(); //remove next schedule from list

        int getDestinationBlock(std::string stationName); //Get the block number of a given station
        
        std::string displaySchedule();
	
	private:

		//FIFO queue containing list of schedules from file.
        std::vector<CTCSchedule> schedule;

        std::unordered_map<std::string, int> stations;
};

#endif
