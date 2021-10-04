#pragma once
#ifndef TOPSIDE_H
#define TOPSIDE_H
#include<iostream>
using namespace std;

class TopSide
{
private:
  bool surfaced;
public:

  TopSide(); // Constructor
  void TopSideSurfaced();
  void CheckSubSurfaced(bool state);

};
#endif