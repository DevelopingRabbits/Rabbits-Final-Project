#pragma once
#ifndef Item_H
#define Item_H
#include <string>
#include <iostream>
#include "PLAYER.h"

using namespace std;

class Player;
class Item
{
private:
  string itemName;
  int itemID;
  enum class ItemType { light = 0, key = 1, lockedItem = 2 };
  ItemType itemType;
  bool isOn;

  Item* itemPtr;

public:
  Item();
  void createItem(string name, int id, int itemType, Item& iPtr);
  string getItemName();

  Item* getItemPtr();
  void interactWithItem(Player* player);

};

#endif