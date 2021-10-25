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
    char oceanMapArray[mapSizeX][mapSizeY];
    int winXOcean;
    int winYOcean;

    

public:
    OceanMap();

    void displayOceanMap();
    void setWinX();
    void setWinY();

    void setSubPosition(int x,int y);
    void setSeenPosition(int x, int y);

    int getWinX();
    int getWinY();

    int getMaxX();
    int getMaxY();

};
#endif
