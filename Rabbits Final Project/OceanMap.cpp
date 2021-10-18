#include "OceanMap.h"
#include"Room.h"

#include <iostream>

using namespace std;


OceanMap::OceanMap()
{
    winX = 4;
    winY = 4;
}
bool OceanMap::checkWin()
{
    if (submarine->getXCord() == winX && submarine->getXCord() == winY)
    {
        cout << "You have naviagated the sub to the winning location. Congrats!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void OceanMap::setWinX()
{

}

void OceanMap::setWinY()
{

}