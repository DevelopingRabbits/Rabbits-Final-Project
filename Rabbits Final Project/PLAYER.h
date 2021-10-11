#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<vector>

#include"Item.h"

using namespace std;

class Player
{
private:
  int MAX_STRING_SIZE = 25;
  string playerName;

  int playerRow;
  int playerCol;

  vector<Item> inventory;

public:
 Player(); // Constructor

 void setPlayerLocation(int row, int col);
 int getPlayerRow();
 int getPlayerCol();

 string getName();
 void setName();
 string nameInputValidation(string name);


 void addToInventory(Item item);
};
#endif