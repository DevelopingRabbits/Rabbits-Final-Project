#include "PLAYER.h"
#include<iostream>
#include<vector>
using namespace std;

Player::Player()
{
  playerName = "";
  canSeeInDarkRoom = false;
  inventoryEmpty = true;

};

void Player::setPlayerLocation(int row, int col)
{
  playerRow = row;
  playerCol = col;
}

int Player::getPlayerRow()
{
  return playerRow;
}

int Player::getPlayerCol()
{
  return playerCol;
}

void Player::addToInventory(Item* item)
{
  inventory.push_back(item);
  if (item->checkIsKey() == true)
  {
    keys.push_back(item);
  }
}

// battle lantern inventory[0]
// control rods inventory[0] battlelantern inventory[1]

string Player::getName()
{
  return playerName;
};

void Player::setName(string input)
{
    playerName = input;
 
};

int Player::getInvetorySize()
{
  return inventory.size();
}

int Player::getKeySize()
{
  return keys.size();
}

Item* Player::getInventory(int i)
{
    return inventory[i];
}

Item* Player::getKeys(int i)
{
  return inventory[i];
}

bool Player::getInventoryEmpty()
{
  return inventoryEmpty;
}

void Player::setInventoryEmpty()
{
  switch (inventory.empty())
  {
  case true:
    inventoryEmpty = true;
    break;
  case false:
    inventoryEmpty = false;
    break;
  default:
    cout << "\n\n****Error in Player::setInventoryEmpty*****\n\n";
    break;
  }
}

void Player::setCanSeeInDarkRoom(bool state)
{
  canSeeInDarkRoom = state;
}

bool Player::getCanSeeInDarkRoom()
{
  return canSeeInDarkRoom;
}


