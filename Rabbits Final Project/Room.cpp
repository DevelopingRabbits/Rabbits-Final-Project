#include "Room.h"
using namespace std;


Room::Room()
{
  vector<Door> doorList;
  vector<Item> itemList;
  roomName = "";
  roomDescription[0] = { "You are standing on the topside of the submarine.\nThe weather outside is quite nice. The sea is calm and the sky is clear.\nThe reflection of the sun glimmers." };
  roomDescription[1] = { "You enter a dark room. You are unsure where you are.\n The only light you see is from the hatch above." };
  roomDescription[2] = { "The room has plenty of computer terminals. This seems to be the control room of the submarine." };
}

void Room::createRoom(string name, int rID)
{
  roomName = name;
  roomID = rID;

}

void Room::addItem(Item item)
{
  itemList.push_back(item);
}

void Room::displayItems()
{

  for (int i = 0; i < itemList.size(); i++)
  {
    cout << endl << i + 1 << ". ";
    itemList[i].displayItem();
  }
}
void Room::addDoor(Door door)
{
  doorList.push_back(door);
}


Item Room::interactWithItems()
{
  displayItems();
  cin >> itemSelection;
  return itemList[itemSelection -1];
}
void Room::displayToUser()
{
  displayDescription();
  cout << "\nYou see the following doors: \n";
  displayDoors();
  cout << "\nYou see the following items: \n";
  displayItems();
};
void Room::displayDescription()
{
  displayLocation();
  cout << endl <<  roomDescription[getRoomID()] << endl;
  displayLocation();
}

void Room::displayDoors()
{

  for (int i = 0; i < doorList.size(); i++)
  {
    cout << endl << i + 1 << ". ";
    doorList[i].DisplayDoor();
  }
}

int Room::getRoomID()
{
  return roomID;
}

void Room::displayLocation()
{
  for (int i = 0; i < 61; i++)
  {
    cout << "*";
    if (i == 30)
    {
      cout << " Location: " << roomName << " ";
    }
  }
}