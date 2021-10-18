#pragma once
#ifndef OceanMap_h
#define OceanMap_h

#include "Room.h"
#include "SUBMARINE.h"
#include <iostream>
using namespace std;

Submarine* submarine;
class OceanMap
{
private:
    Room* oceanMap[4][4];
    int winX;
    int winY;

public:
   
    bool checkWin();
    void setWinX();
    void setWinY();

};
#endif
