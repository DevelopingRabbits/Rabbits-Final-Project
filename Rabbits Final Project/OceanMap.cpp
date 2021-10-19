#include "OceanMap.h"
#include"Room.h"

#include <iostream>

using namespace std;


OceanMap::OceanMap()
{
    winXCord = 4;
    winYCord = 4;
}

void OceanMap::setWinX()
{
    
}

void OceanMap::setWinY()
{
    
}

int OceanMap::getWinX()
{
    //cout << winXCord; continues to throw exceptio for nullptr
    return 4;
}

int OceanMap::getWinY()
{
    return 4;
}

int OceanMap::getMaxX()
{
    return mapSizeX;
}

int OceanMap::getMaxY()
{
    return mapSizeY;
}