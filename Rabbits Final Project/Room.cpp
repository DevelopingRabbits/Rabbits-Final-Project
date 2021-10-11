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
  roomID = rID;
  upDoor = up;
  downDoor = down;
  leftDoor = left;
  rightDoor = right;
  row = rowArg;
  col = colArg;
}

void Room::setRoomDescription(string description)
{
  roomDescription = description;
}
string Room::getRoomName()
{
  return roomName;
}

string Room::getRoomDescription()
{
  return roomDescription;
}

Door* Room::getUpDoor()
{
  return upDoor;
}

Door* Room::getDownDoor()
{
  return downDoor;
}

Door* Room::getRightDoor()
{
  return rightDoor;
}

Door* Room::getLeftDoor()
{
  return leftDoor;
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


//void Room::addItem(Item item)
//{
//  itemList.push_back(item);
//}

//void Room::displayItems()
//{
//
//  for (int i = 0; i < itemList.size(); i++)
//  {
//    cout << endl << i + 1 << ". ";
//    itemList[i].displayItem();
//  }
//}
//
//
//
//Item Room::interactWithItems()
//{
//  displayItems();
//  cin >> itemSelection;
//  return itemList[itemSelection -1];
//}
////void Room::displayToUser()
////{
////  displayDescription();
////  cout << "\nYou see the following doors: \n";
////  displayDoors();
////  if (itemList.empty() != true)
////  {
////    cout << "\nYou see the following items: \n";
////    displayItems();
////  }
////};
//void Room::displayDescription()
//{
//  displayLocation();
//  cout << endl <<  roomDescription[getRoomID()] << endl;
//  displayLocation();
//}
//
//void Room::displayDoors()
//{
//
//  for (int i = 0; i < doorList.size(); i++)
//  {
//    cout << endl << i + 1 << ". ";
//    //doorList[i].DisplayDoor();
//  }
//}

//
//void Room::displayLocation()
//{
//  for (int i = 0; i < 61; i++)
//  {
//    cout << "*";
//    if (i == 30)
//    {
//      cout << " Location: " << roomName << " ";
//    }
//  }
//}