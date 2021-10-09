#pragma once
#ifndef Room_H
#define Room_h
#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "Door.h"
#include "Item.h"

using namespace std;


class Room
{
private:
  string roomName;
  vector<Door> doorList;
  vector<Item> itemList;
  string roomDescription[3];
  int roomID;
  int itemSelection;

public:
  Room();
  void createRoom(string name, int roomID);
  void addDoor(Door door);
  void addItem(Item item);
  int getRoomID();

  Item interactWithItems();
  void displayToUser();
  void displayDescription();
  void displayDoors();
  void displayLocation();
  void displayItems();


  // void addItem(string );

};



#endif
