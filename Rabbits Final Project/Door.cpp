#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstring>

#include "Door.h"

using namespace std;

Door::Door() 
{  

}

void Door::createDoor(string name, bool state, Door &d)
{
  doorName = name;
  isOpen = state;
  doorPtr = &d;
}

string Door::GetDoorName()
{

  return doorName;
}

Door* Door::getDoorPtr()
{
  return doorPtr;
}

bool Door::getIsOpen()
{
  return isOpen;
}