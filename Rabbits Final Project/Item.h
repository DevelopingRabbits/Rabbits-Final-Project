#pragma once
#ifndef Item_H
#define Item_H
#include <string>
#include <iostream>

using namespace std;

class Item
{
private:
  string itemName;
  int itemID;

public:
  Item();
  void createItem(string name, int id);
  void displayItem();

};

#endif