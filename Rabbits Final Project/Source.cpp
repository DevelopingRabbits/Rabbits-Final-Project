#include "PLAYER.h"
#include "SUBMARINE.h"
#include<iostream>

using namespace std;

int main()
{
  cout << "Hello Developing Rabbits!\n";
  Player player1;
  Submarine submarine;
 

  player1.setName();
  cout << "\nHello " << player1.getName() << endl << endl;

  /*
  Start Game - Loop that checks if gameOver = True;
  
  INIT TURN PHASE
  The Turn phas should consist of the following:

  - Outputting Information related to space
      - Location of the player
      - State of the Sub
      - State of the room
  - Provide the player a choice

  ACTION PHASE
  - Take the choice and determine consequences of choice
  - Resets the loop

  CONSEQUENCE PHASE
  */


}