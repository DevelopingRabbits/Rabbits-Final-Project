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
  bool weaponSystem;
  Room* map[4][7];
  Submarine* submarinePtr;
  int subLocX;
  int subLocY;
  int submarineHealth;
 
public:
  Submarine();
  void addRoom(Room &newRoom, int newRoomRow, int newRoomCol);

  Room* getRoom(int row, int col);
  
  void createSubmarine(Submarine &s);

  bool getPowerOn();
  void setPowerOn(bool state);

  bool getSurfaced();
  void setSurfaced(bool state);

  int getXSubLoc();
  int getYSubLoc();

  void setSubmarineLocation(int,int);

  bool getWeaponStatus();
  void setWeaponStatus(bool status);
  

};
#endif