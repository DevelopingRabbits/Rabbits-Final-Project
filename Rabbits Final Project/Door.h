#pragma once
#ifndef Door_H
#define Door_h
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Room.h"

using namespace std;


class Door
{
private:
  string doorName;
  bool isOpen;

  Door* doorPtr;


public:
  Door();
  void createDoor(string name, bool state, Door &d);

  bool getIsOpen();
  string GetDoorName();

  Door* getDoorPtr();
};

#endif