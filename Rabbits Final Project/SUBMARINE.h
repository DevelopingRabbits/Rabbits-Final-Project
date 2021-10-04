#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Submarine
{
private:
  bool isDark;
  bool gameOver;
  int choice;

  enum class Location {TopSide, ControlRoom};
  Location location = Location::TopSide;

public:

  Submarine();
  void playGame();
  void topSide();
  void controlRoom();
  void clearBuffer();
  void delay();
};
#endif