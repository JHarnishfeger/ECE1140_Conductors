#ifndef WAYSTRUCT_H
#define WAYSTRUCT_H
#include"Authority.h"
#include <vector>

struct WayStruct
{
    int id;
    double suggestedSpeed;
    std::vector<Authority> auth;
    std::vector<Block> sector;
};

#endif
