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
  /*
  First Switch requiresKey
  Second Switch requiresSubPower

  */

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
    switch (item->requiresSubPower)
    {
      case true:
       switch (sub->getPowerOn()) // Does the sub have power?
        {
       case true:
          switch (itemID)
          {
          case 9999:
            cout << "You chose the computer terminal.\n\n";
            return 9999;
            break;
          case 9997:
            cout << "You chose the weapon system mainframe.\n\n";
            return 9997;
          }
        case false:
          cout << "The submarine has no power. You need power to use " << item->getItemName() << ".\n\n";
          return -1;
          break;
        default:
          cout << "Error in Item::interactWithActionItem\n";
        }
    case false:
      //Action Items of value should be added here. Match the ItemID to what you would like to be displayed.
      switch (itemID)
      {
      case 9998:
        cout << "The captain's log reads 'Alas, I believe that Atlantis could be at X: " << winX << " Y: " << winY << "'" << endl; // Hardcoded Winning Location TEMP
      }
      switch (itemID)
      {
      case 9996:
          cout << "I am the Captain Now!\n";
      }
      switch (itemID)
      {
      case 9995:
          cout << "Man that looks so tasty\n";
      }
      switch (itemID)
      {
      case 9994:
          cout << "There is no time for a nap right now I need to focus!\n";
      }
      switch (itemID)
      {
      case 9993:
          cout << "I probably shouldn't touch that, the submarine might sink!\n";
      }
      switch (itemID)
      {
      case 9992:
          cout << "This might be useful in the near future, I should come back to it if I need it.\n";
      }
    }
  }
}

void Item::storeWinningCoordinates(int x, int y)
{
  winX = x;
  winY = y;
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