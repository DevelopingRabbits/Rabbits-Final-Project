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
  bool powerOn;
  bool surfaced;
  bool gameOver;
  int choice;

  enum class Location { TopSide, ControlRoom };
  Location location = Location::TopSide;

public:

  bool getPowerOn();
  void setPowerOn(bool state);

  bool getSurfaced();
  void setSurfaced(bool state);

  Submarine();
  void playGame();
  void topSide();
  void controlRoom();
  void clearBuffer();
  void delay();
};
#endif