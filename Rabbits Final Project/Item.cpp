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

int Item::interactWithActionItem(Player* player, Submarine* sub, Item* item, Game* game)
{
  switch (item->requiresKey)
  {
  case true:
    cout << "This item reuqires a key\n\n";
    //player->getInventory
    //check if player has key
    for (int i = 0; i < player->getKeySize(); i++)
    {
        key = player->getKeys(i);
        cout << key->getItemName();
        if (actionItemKeyCode == key->getKeyCode());
        {
            switch (actionItemKeyCode)
            {
            case 0001:
                sub->setPowerOn(true);
                cout << "\n\nThe power is now on.\n\n";
                return 0001;

            default:
                cout << "Default statement in Item::interactWithActionItem\n\n";
            }
        }
    }
    break;

  //Check if computer terminal
  // Check if sub power is on
  //Interact with computer terminal

  case false:
    switch (itemID)
    {
    case 9999:
      cout << "You chose the computer terminal.\n\n";
      return 9999;
    }
    //Check if computer terminal
    // Check if sub power is on
    //Interact with computer terminal
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