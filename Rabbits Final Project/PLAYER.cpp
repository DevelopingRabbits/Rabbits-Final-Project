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

string Player::nameInputValidation(string name)
{
    int stringSize;
    bool flag = false;

    while (name.length() >= MAX_STRING_SIZE) //check that the length of the name is less than 25 characters
    {
        cout << "Your name should be less than 25 characters." << endl;
        
        name.clear();
        cout << "What is your name?\n";
        cin >> name;
    }
        
   
    while (flag == false)
    {
        stringSize = name.length();
   
        for (int i = 0; i <= stringSize; i++)//iterate through the string and check that there is only letters.
        {
            
            if (!isalpha(name[i]))
            {
                cout << "Your name may only consist of letters. Try again." << endl;
                cin.clear(); //reset the buffer

                cin.ignore(numeric_limits<streamsize>::max(), '\n');//empty the buffer
                cin >> name;
                break;
            }
            else if (i == stringSize-1)//if a string is fully iterated through and only letters were found, set the flag to true in order to break out of the while loop.
            {
                flag = true;
                break;
            }

        }
    }

    return name;//return the name that now only consists of letters

}

string Player::getName()
{
  return playerName;
};

void Player::setName()
{
    cout << "What is your name?\n";
    cin >> playerName;
  
    playerName=nameInputValidation(playerName);
};



//void Player::clearBuffer()
//{
//  cin.ignore(numeric_limits<streamsize>::max(), '\n');
//};

