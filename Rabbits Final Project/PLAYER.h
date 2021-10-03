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
  char str[250], ch;

public:
  Player(); // Constructor
  string getName();
  void setName();

  void clearBuffer();
};
#endif