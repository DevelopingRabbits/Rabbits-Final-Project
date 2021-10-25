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

    //displays the ocean map in its current state to the user.
    void displayOceanMap();
 

    //updates submarines position and seen spaces on the map.
    void setSubPosition(int x,int y);
    void setSeenPosition(int x, int y);

    //Gets winning cordinates for the ocean map
    int getWinX();
    int getWinY();

    void setWinX();
    void setWinY();
    
    //Gets bounds for the ocean map
    int getMaxX();
    int getMaxY();

};
#endif
