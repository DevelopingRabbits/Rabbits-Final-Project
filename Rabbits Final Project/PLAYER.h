#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<vector>
#include<string>
#include"Item.h"

using namespace std;

class Item;
class Player
{
private:
  int MAX_STRING_SIZE = 25;
  string playerName;

  int playerRow;
  int playerCol;

  bool canSeeInDarkRoom;
  bool inventoryEmpty;

  vector<Item*> inventory;

public:
 Player(); // Constructor

 void setPlayerLocation(int row, int col);
 int getPlayerRow();
 int getPlayerCol();

 string getName();
 void setName(string input);

 bool getInventoryEmpty();
 void setInventoryEmpty();
 void addToInventory(Item* item);
 int getInvetorySize();
 Item* getInventory(int i);

 void setCanSeeInDarkRoom(bool state);
 bool getCanSeeInDarkRoom();

};
#endif