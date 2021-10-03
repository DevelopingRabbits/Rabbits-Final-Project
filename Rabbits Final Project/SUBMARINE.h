#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <iostream>
#include <string>
using namespace std;

class Submarine
{
private:
  bool isDark;
  bool isSurfaced;
  int choice;

public:
  Submarine();
  void topSide();
};
#endif