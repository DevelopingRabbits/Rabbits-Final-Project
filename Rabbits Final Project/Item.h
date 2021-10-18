#pragma once
#ifndef Item_H
#define Item_H
#include <string>
#include <iostream>
#include "PLAYER.h"
#include "Room.h"
#include "SUBMARINE.h"

using namespace std;

class Submarine;
class Room;
class Player;
class Item
{
private:
  string itemName;
  int itemID;
  enum class ItemType { light = 0, key = 1, actionItem = 2};
  ItemType itemType;
  bool isOn;
  bool canBeAddedToInventory;
  bool requiresSubPower;
  bool requiresKey;
  bool isKey;
  int keyCode;
  int actionItemKeyCode;
  Item* itemPtr;
  Item* key;

public:
  Item();
  void createItem(string name, int id, int itemType, Item& iPtr);
  void setKeyCode(int code);
  void setActionItemKeyCode(int code);
  void createActionItem(string name, int id, Item& iPtr, bool subPower, bool needKey);
  string getItemName();

  int getKeyCode();

  Item* getItemPtr();
  void interactWithItem(Player* player);
  void interactWithActionItem(Player* player, Submarine* sub);

  bool checkIsKey();


};

#endif