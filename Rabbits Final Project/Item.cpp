#include "Item.h"

Item::Item()
{
  itemName = "";
  isOn = false;
  isKey = false;
}

void Item::createItem(string name, int id, int itemTypeArg, Item& iPtr)
{
  itemName = name;
  itemID = id;
  switch (itemTypeArg)
  {
  case 0:
    itemType = ItemType::light;
    isOn = false;
    canBeAddedToInventory = true;
    break;
  case 1:
    itemType = ItemType::key;
    canBeAddedToInventory = true;
    isKey = true;
    isOn = NULL;
    break;
  default:
    cout << "\n\n****Error in Item::createItem****\n\n";
    break;
  }
  itemPtr = &iPtr;
}

void Item::createActionItem(string name, int id, Item& iPtr, bool subPower, bool needKey)
{
  itemName = name;
  itemID = id;
  itemType = ItemType::actionItem;
  canBeAddedToInventory = false;
  requiresKey = needKey;
  requiresSubPower = subPower;
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
  case(ItemType::key):
    break;
    default:
      cout << "\n\n****Error in Item::interactWithItems****\n\n";
      break;
  }
}

int Item::getKeyCode()
{
  return keyCode;
}

void Item::interactWithActionItem(Player* player, Submarine* sub)
{
  switch (requiresKey)
  {
  case true:
    ////
    //////player->getInventory
    //////check if player has key
    ////for (int i = 0; i < player->getKeySize(); i++)
    ////{
    ////  key = player->getKeys(i);
    ////  cout << key->getKeyCode();
    ////  system("Pause");
    ////  if (actionItemKeyCode == key->getKeyCode());
    ////  {
    ////    switch (actionItemKeyCode)
    ////    {
    ////    case 0001:
    ////      sub->setPowerOn(true);
    ////      break;
    ////    default:
    ////      cout << "Default statement in Item::interactWithActionItem\n\n";
    //    }
    //  }
    //}

  case false:
    cout << "Nothing happened.\n\n";
    break;
  default:
    cout << "Default statement in Item::interactWithActionItem OUTSIDE LOOP\n\n";
  }
}

bool Item::checkIsKey()
{
  return isKey;
}

void Item::setKeyCode(int code)
{
  keyCode = code;
}

void Item::setActionItemKeyCode(int code)
{
  actionItemKeyCode = code;
}