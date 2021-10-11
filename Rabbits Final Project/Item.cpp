#include "Item.h"

Item::Item()
{
  itemName = "";
}

void Item::createItem(string name, int id, Item &iPtr)
{
  itemName = name;
  itemID = id;
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