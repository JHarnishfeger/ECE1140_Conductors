#ifndef CTC_HPP
#define CTC_HPP

#include "Block.h"
#include <vector>

//A schedule consists of a train ID, a destination block, and an arrival time.
struct CTCSchedule{

    CTCSchedule(int _train, int _destination, double _time);
    int train;
    int destination;
    double time;
};

/*
 * The primary CTC module class.
 */
class CTC{
    private:

        //The current mode for the CTC:
        //True = automatic, False = manual
        bool mode;

        //Time of day.
        double time;

        //FIFO queue containing list of schedules from file.
        std::vector<CTCSchedule> schedule;

        //Vector containing block information.
        std::vector<Block> track;

        //Blocks that are closed for maintenence
        std::vector<Block> closedForMaintenence;

        //Blocks that will have their switch direction changed
        std::vector<Block> tochangeDirection;

    public:

        CTC();
        void loadSchedule(std::string filepath);
        void addSchedule(CTCSchedule _schedule);
        std::string displaySchedule();
        void update(std::vector<Block> trackData, double current_time);
        void setTrackMaintenence(int blockId, bool isBroken);
        void setTrackSwitch(int blockId, char direction);
        void setCTCMode(bool _mode);
        std::vector<Block> getSwitches();
        void dispatchTrain(CTCSchedule schedule);
        std::vector<Block> getBlocksClosedForMaintenence();
        std::vector<Block> getNewTrackSwitchChanges();
        double getSuggestedSpeed();
        bool getTrackMaintenence(int blockId);
        bool getBlockHasTrainPresent(int blockId);
        char getBlockDirection(int blockId);
};

#endif
