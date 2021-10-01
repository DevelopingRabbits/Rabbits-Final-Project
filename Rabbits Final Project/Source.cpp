#include "PLAYER.h"
#include<iostream>

using namespace std;

int main()
{
  cout << "Hello Developing Rabbits!\n";
  Player player1;

  player1.setName();
  cout << "\nHello " << player1.getName() << endl;

}