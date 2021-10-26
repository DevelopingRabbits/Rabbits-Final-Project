#include "OceanMap.h"
#include"Room.h"
#include"SUBMARINE.h"

#include <iostream>
#include<iomanip>

using namespace std;


OceanMap::OceanMap()
{
    winXOcean = 0;
    winYOcean = 1;
   
    
}

void OceanMap::setWinX()
{
   
}

void OceanMap::setWinY()
{
    
}

int OceanMap::getWinX()
{
    
    
   //return winXOcean; returning winXOcean causes exception stating nullptr. winXOcean and winYOcean cannnot be printed or passed.
    return 0;
}

int OceanMap::getWinY()
{
    
  //return winYOcean;
    return 1;
}

int OceanMap::getMaxX()
{
   
    return mapSizeX;
}

int OceanMap::getMaxY()
{
    
    return mapSizeY;
}

