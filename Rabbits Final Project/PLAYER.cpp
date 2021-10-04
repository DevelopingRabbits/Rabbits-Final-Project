#include "PLAYER.h"
#include <iostream>
using namespace std;

Player::Player()
{
  playerName = "";

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

void Player::clearBuffer()
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
};