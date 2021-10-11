#include "Item.h"

Item::Item()
{
  itemName = "";
  bool isOn = false;
}

void Item::createItem(string name, int id, int itemTypeArg, Item& iPtr)
{
  itemName = name;
  itemID = id;
  switch (itemTypeArg)
  {
  case 0:
    itemType = ItemType::light;
    break;
  default:
    cout << "\n\n****Error in Item::createItem****\n\n";
    break;
  }
  itemPtr = &iPtr;
}

string Item::getItemName()
{
  return itemName;
}

Item* Item::getItemPtr()
{
  return itemPtr;
}

void Item::interactWithItem(Player* player)
{
  switch(itemType)
  {
  case(ItemType::light):
    {
      switch (isOn)
      {
      case true:
        isOn = false;
        player->setCanSeeInDarkRoom(isOn);
        cout << "You turn off the " << itemName << ".\n\n";
        break;
      case false:
        isOn = true;
        player->setCanSeeInDarkRoom(isOn);
        cout << "You turn on the " << itemName << ".\n\n";
        break;
      }
      break;
    }
    default:
      cout << "\n\n****Error in Item::interactWithItems****\n\n";
      break;
  }
}