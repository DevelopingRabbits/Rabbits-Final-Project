#pragma once
#ifndef OceanMap_h
#define OceanMap_h

#include "Room.h"
#include "SUBMARINE.h"
#include <iostream>
using namespace std;

const int mapSizeX = 4;
const int mapSizeY = 4;
class Room;
class Submarine;
class OceanMap
{
private:
    Room* oceanMap[mapSizeX][mapSizeY];
    int winXCord;
    int winYCord;

public:
    OceanMap();
    void setWinX();
    void setWinY();

    int getWinX();
    int getWinY();

    int getMaxX();
    int getMaxY();

};
#endif
