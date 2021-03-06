#ifndef CTC_HPP
#define CTC_HPP

#include "Block.h"
#include <vector>
#include <list>
#include "WayStruct.h"
#include "TrackNodes.h"
#include "WaysideManager.h"
#include "ScheduleManager.h"
#include "TrainTracker.h"


/*
 * The primary CTC module class.
 */
class CTC{
    private:

        //The current mode for the CTC:
        //True = automatic, False = manual
        bool mode;

        //Time of day, in seconds.
        int time;
        
        //Schedule Manager
        ScheduleManager scheduleManager;
        
        //Track routing system
        TrackNodes track;

        TrainTracker trainTracker;

    public:

        CTC(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct);
        ~CTC();
        std::string displaySchedule();
        WaysideManager waysideManager;
        void update(int current_time);
        void setTrackMaintenence(int blockId, bool isBroken);
        void setTrackSwitch(int blockId, bool direction);
        void setCTCMode(bool _mode);
        std::list<int> getSwitches();
        void dispatchTrain(CTCSchedule schedule, bool hw=false);
        double getSuggestedSpeed();
        bool getTrackMaintenence(int blockId);
        bool getBlockHasTrainPresent(int blockId);
        std::list<std::string> getBranchesWithTrainsPresent();
        bool getBlockDirection(int blockId);
        void addSchedule(CTCSchedule _schedule);
        void loadSchedule(std::string filepath);
        bool blockExists(int blockId);
};

#endif
