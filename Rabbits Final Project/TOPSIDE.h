#pragma once
#ifndef TOPSIDE_H
#define TOPSIDE_H
#include<iostream>
#include<vector>
using namespace std;

const int ADJACENTROOMS = 1;

class TopSide
{
private:
    string Location;
    bool surfaced;
    string adjacentRooms[ADJACENTROOMS];
    int playerChoice;

   
public:
  friend class Player;
  TopSide(); // Constructor
  void TopSideSurfaced();
  void CheckSubSurfaced(bool state);
  void setSurfaced(bool state);

  int playScenario();

  string getLocation();
  string* getAdjacentRooms();
  int getRoomAmount();

};
#endif