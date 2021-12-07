#include "ctcwindow.h"
#include <vector>
#include "WayStruct.h"
#include <QApplication>
#include <QTime>

struct CTCTestWaysides{

    //Constructor for test data
    CTCTestWaysides(){
        for(int i = 0; i < 13; i++){
            std::vector<Block> sector;
            for(int j = 0; j < 10; j++){
                sector.push_back(Block());
                sector[j].setTrainPresent(false);
            }
            std::vector<Authority> authorities;
            authorities.push_back(Authority());

            WayStruct waystruct;
            waystruct.id = i;
            waystruct.sector = sector;
            waystruct.suggestedSpeed = 0;
            waystruct.auth = authorities;
            sw_controller.push_back(waystruct);
        }
        std::vector<Block> sector;
        for(int j = 0; j < 11; j++){
            sector.push_back(Block());
            sector[j].setTrainPresent(true);
        }
        std::vector<Authority> authorities;
        authorities.push_back(Authority());
        hw_controller.id = 14;
        hw_controller.sector = sector;
        hw_controller.auth = authorities;
        hw_controller.suggestedSpeed = 0;
    }

    //Internal data
    std::vector<WayStruct> sw_controller;
    WayStruct hw_controller;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CTCTestWaysides testWaysides;
    CTCWindow w(&testWaysides.sw_controller, &testWaysides.hw_controller);
    w.show();
    w.update();
    return a.exec();
}
