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
}

string Player::getName()
{
  return playerName;
};

void Player::setName(string input)
{
    playerName = input;
 
};

Item* Player::getInventory()
{
  return inventory[0];
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


