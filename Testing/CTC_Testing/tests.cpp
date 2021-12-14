#include "tests.h"
#include "ctcwindow.h"
#include <QtTest/QtTest>

WaystructInputs Tests::getBasicTestInput(){
    //These are test values, not to be used in integration
    std::vector<WayStruct> sw_controller;
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
    WayStruct hw_controller;
    hw_controller.id = 14;
    hw_controller.sector = sector;
    hw_controller.auth = authorities;
    hw_controller.suggestedSpeed = 0;

    return WaystructInputs{sw_controller, hw_controller};
}

void Tests::CTCWindowConstructor(){
    auto inputs = getBasicTestInput();
    try{
        CTCWindow ctcWindow(&inputs.sw_waystructs, &inputs.hw_waystruct);
    }catch(std::exception& e){
        QVERIFY(false);
    }
    QVERIFY(true);
}
