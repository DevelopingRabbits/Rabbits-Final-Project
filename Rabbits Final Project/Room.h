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

using namespace std;

class Door;
class Room
{
private:
  string roomName;
  Door* upDoor;
  Door* downDoor;
  Door* rightDoor;
  Door* leftDoor;
  string roomDescription;


  int roomID;
  int itemSelection;
  int row;
  int col;

public:
  Room();
  void createRoom(string name, int rID, Door* up, Door* down, Door* left, Door* right, int row, int col);

  void setRoomDescription(string description);

  int getRoomID();
  int getRoomRow();
  int getRoomCol();

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
