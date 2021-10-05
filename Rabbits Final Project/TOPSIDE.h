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

   
public:

  TopSide(); // Constructor
  void TopSideSurfaced();
  void CheckSubSurfaced(bool state);
  void setSurfaced(bool state);

  void playScenario();

  string getLocation();
  string* getAdjacentRooms();
  int getRoomAmount();

};
#endif