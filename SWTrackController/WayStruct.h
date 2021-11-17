#ifndef WAYSTRUCT_H
#define WAYSTRUCT_H
//#include <string>

#include <vector>
#include "Authority.h"
#include "Block.h"

struct WayStruct
{
    int id;
    double suggestedSpeed;
    std::vector<Authority> auth;
    std::vector<Block> sector;
};

#endif
