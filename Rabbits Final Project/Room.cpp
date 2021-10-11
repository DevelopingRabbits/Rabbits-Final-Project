#include "Room.h"

using namespace std;
Room::Room()
{
  //roomDescription[0] = { "You are standing on the topside of the submarine.\nThe weather outside is quite nice. The sea is calm and the sky is clear.\nThe reflection of the sun glimmers." };
  //roomDescription[1] = { "You enter a dark room. You are unsure where you are.\n The only light you see is from the hatch above." };
  //roomDescription[2] = { "The room has plenty of computer terminals. This seems to be the control room of the submarine." };
}

void Room::createRoom(string name, int rID, Door* up, Door* down, Door* left, Door* right, int rowArg, int colArg)
{
  roomName = name;
  darkRoomName = "UNKOWN: Dark Room";
  roomID = rID;
  upDoorPtr = up;
  downDoorPtr = down;
  leftDoorPtr = left;
  rightDoorPtr = right;
  row = rowArg;
  col = colArg;
}

void Room::setIsDark(bool state)
{
  isDark = state;
}

void Room::setDarkRoomDescription(string description)
{
  darkRoomDescription = description;
}

void Room::setRoomDescription(string description)
{
  roomDescription = description;
}

string Room::getRoomName()
{
  switch (isDark)
  {
  case true:
    return darkRoomName;
  case false:
    return roomName;
  }
}

string Room::getRoomDescription()
{
  if (isDark == true)
  {
    return darkRoomDescription;
  };
  return roomDescription;
}

Door* Room::getUpDoor()
{
  return upDoorPtr;
}

Door* Room::getDownDoor()
{
  return downDoorPtr;
}

Door* Room::getRightDoor()
{
  return rightDoorPtr;
}

Door* Room::getLeftDoor()
{
  return leftDoorPtr;
}

int Room::getRoomRow()
{
  return row;
}

int Room::getRoomCol()
{
  return col;
}

int Room::getRoomID()
{
  return roomID;
}

bool Room::getIsDark()
{
  return isDark;
}

void Room::addItem(Item* item)
{
  roomInventory.push_back(item);
}

void Room::removeItem()
{
  roomInventory.pop_back();
}

Item* Room::getRoomInventory()
{
  if (roomInventory.empty() == false)
  {
    return roomInventory[0];
  }
  else
  {
    return NULL;
  }
}

bool Room::getRoomEmpty()
{
  if (roomInventory.empty() == true)
    return true;
  else
    return false;
}
