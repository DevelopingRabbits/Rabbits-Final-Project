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
  bool hasBattleLantern;
  const int PLAYER_LOCATION[3] =
  {
    0, // TOPSIDE
    1, // DARK CONTROL ROOM
    2  // CONTROL ROOM
  };
  int playerLocationIndex;

  vector<Item> inventory;

public:
 Player(); // Constructor

 string getName();
 void setName();
 string nameInputValidation(string name);

 void setBattleLantern(bool state);

 int getLocation();
 void setLocation(int currentLocation);

 void addToInventory(Item item);
 void clearBuffer();
};
#endif