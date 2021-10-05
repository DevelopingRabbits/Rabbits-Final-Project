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
  int playerLocation;

public:
  Player(); // Constructor

  string getName();
  void setName();

  int getLocation();
  void setLocation(string currentLocation);

  void clearBuffer();
};
#endif