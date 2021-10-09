#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Room.h"
using namespace std;


class Submarine
{
private:
  bool powerOn;
  bool surfaced;

  int choice;
  enum class Location { TopSide, ControlRoom };
  Location location = Location::TopSide;
  
  vector<Room> listOfRooms;

protected:

public:

  void addRoom(Room newRoom);

  bool getPowerOn();
  void setPowerOn(bool state);

  bool getSurfaced();
  void setSurfaced(bool state);

  Submarine();

  void clearBuffer();
  void delay();
};
#endif