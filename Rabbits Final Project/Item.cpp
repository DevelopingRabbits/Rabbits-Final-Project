#include "Item.h"

Item::Item()
{
  itemName = "";
}

void Item::createItem(string name, int id)
{
  itemName = name;
  itemID = id;
}

void Item::displayItem()
{
  cout << itemName << endl;
}