#ifndef CTC_HPP
#define CTC_HPP

#include "Block.h"
#include <vector>
#include <list>
#include "WayStruct.h"
#include "TrackNodes.h"
#include "WaysideManager.h"
#include "ScheduleManager.h"


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
        
        //Wayside Manager
        WaysideManager waysideManager;
        
        //Schedule Manager
        ScheduleManager scheduleManager;
        
        //Track routing system
        TrackNodes track;

    public:

        CTC(std::vector<WayStruct>* sw_waystructs, WayStruct* hw_waystruct);
        ~CTC();
        std::string displaySchedule();
        void update(int current_time);
        void setTrackMaintenence(int blockId, bool isBroken);
        void setTrackSwitch(int blockId, bool direction);
        void setCTCMode(bool _mode);
        std::vector<Block> getSwitches();
        void dispatchTrain(CTCSchedule schedule);
        double getSuggestedSpeed();
        bool getTrackMaintenence(int blockId);
        bool getBlockHasTrainPresent(int blockId);
        bool getBlockDirection(int blockId);
        void addSchedule(CTCSchedule _schedule);
        void loadSchedule(std::string filepath);
};

#endif
