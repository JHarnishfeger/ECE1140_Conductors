#ifndef WAYSTRUCT_H
#define WAYSTRUCT_H

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <sstream>
#include "Block.h"

struct WayStruct
{
    int id;
    vector<Block>* sector; //Holds all info about each block associated with the current wayside
}
