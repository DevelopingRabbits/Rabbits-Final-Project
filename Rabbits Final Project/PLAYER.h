#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
using namespace std;

class Player
{
private:
  int MAX_STRING_SIZE = 25;
  string playerName;
  const int PLAYER_LOCATION[2] =
  {
    0, // TOPSIDE
    1  // CONTROL ROOM
  };
  int playerLocationIndex;


public:
  Player(); // Constructor

  string getName();
  void setName();
 string nameInputValidation(string name);

  int getLocation();
  void setLocation(int currentLocation);

  void clearBuffer();
};
#endif