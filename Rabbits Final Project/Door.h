#pragma once
#ifndef Door_H
#define Door_h
#include <string>
#include <iostream>

using namespace std;


class Door
{
private:
  string doorName;


public:
  Door();

  void SetDoorName(string name);
  void DisplayDoor();
};

#endif