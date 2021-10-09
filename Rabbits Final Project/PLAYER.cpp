#include "PLAYER.h"
#include <iostream>
using namespace std;

Player::Player()
{
  playerName = "";
  playerLocationIndex = 0;
  hasBattleLantern = false;


};

void Player::addToInventory(Item item)
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

int Player::getLocation()
{
    return PLAYER_LOCATION[playerLocationIndex];
}

void Player::setLocation(int currentLocation)
{

    playerLocationIndex = currentLocation;
}

void Player::clearBuffer()
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
};

void Player::setBattleLantern(bool state)
{
  hasBattleLantern = state;
}