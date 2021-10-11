#pragma once
#ifndef Room_h
#define Room_h
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

#include "Door.h"
#include "SUBMARINE.h"
#include "PLAYER.h"
#include "Item.h"

using namespace std;

class Door;
class Submarine;
class Room
{
private:
  string roomName;
  string darkRoomName;
  Door* upDoorPtr;
  Door* downDoorPtr;
  Door* rightDoorPtr;
  Door* leftDoorPtr;
  vector<Item*> roomInventory;
  Submarine* submarinePtr;
  string darkRoomDescription;
  string roomDescription;

  bool isDark;

  int roomID;
  int itemSelection;
  int row;
  int col;

public:
  Room();
  void createRoom(string name, int rID, Door* up, Door* down, Door* left, Door* right, int row, int col);
  void setDarkRoomDescription(string description);
  void setRoomDescription(string description);
  void setIsDark(bool state);
  void addItem(Item* item);

  int getRoomID();
  int getRoomRow();
  int getRoomCol();
  bool getIsDark();
  Item* getRoomInventory();

  string getRoomDescription();
  string getRoomName();

  Door* getUpDoor();
  Door* getDownDoor();
  Door* getLeftDoor();
  Door* getRightDoor();

  //Item interactWithItems();
  //void displayDescription();
  //void displayDoors();
  //void displayLocation();
  //void displayItems();

};



#endif
