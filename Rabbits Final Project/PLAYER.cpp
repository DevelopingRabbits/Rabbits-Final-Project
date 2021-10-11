#include "PLAYER.h"
#include<iostream>
#include<vector>
using namespace std;

Player::Player()
{
  playerName = "";

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



//void Player::clearBuffer()
//{
//  cin.ignore(numeric_limits<streamsize>::max(), '\n');
//};

