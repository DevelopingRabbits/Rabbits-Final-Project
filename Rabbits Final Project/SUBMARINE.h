#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Room.h"
using namespace std;

class Room;
class Submarine
{
private:
  bool powerOn;
  bool surfaced;
  Room* map[4][7];
 
public:
  Submarine();
  void addRoom(Room &newRoom, int newRoomRow, int newRoomCol);

  Room* getRoom(int row, int col);

  bool getPowerOn();
  void setPowerOn(bool state);

  bool getSurfaced();
  void setSurfaced(bool state);

};
#endif