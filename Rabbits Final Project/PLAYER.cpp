#include "PLAYER.h"
#include <iostream>
using namespace std;

Player::Player()
{
  playerName = "";
  playerLocation = 0;

};

string Player::getName()
{
  return playerName;
};

void Player::setName()
{
  do
  {
    if (playerName.length() >= MAX_STRING_SIZE)
    {
      cout << "Your name should be less than 25 characters." << endl;
    }
    playerName.clear();
    cout << "What is your name?\n";
    cin >> playerName;
  } while (playerName.length() >= MAX_STRING_SIZE);

  clearBuffer();
};

string Player::getLocation()
{
    return playerLocation;
}

void Player::setLocation(string currentLocation)
{

    playerLocation = currentLocation;
}

void Player::clearBuffer()
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
};