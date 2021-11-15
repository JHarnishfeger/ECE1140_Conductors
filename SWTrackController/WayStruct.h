#ifndef WAYSTRUCT_H
#define WAYSTRUCT_H

#include <vector>

struct WayStruct
{
    int id;
    std::vector<Authority> auth;
    std::vector<Block> sector;
}
