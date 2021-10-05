#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Game.h"
#include "TOPSIDE.h"
#include<iostream>

using namespace std;

int main()
{
  cout << "Hello Developing Rabbits!\n";
  Player player1;
  Submarine submarine;
  Game game;
  TopSide topside;
  

  enum class Location {TopSide, ControlRoom};
  Location location = Location::TopSide;

  player1.setName();
  cout << "\nHello " << player1.getName() << endl << endl;

  int playerChoice;

  game.startGame();
  do
  {
    location = player1.getLocation(); //WIP
    switch (location)
    {
    case Location::TopSide:
      topside.setSurfaced(submarine.getSurfaced());
      topside.playScenario();
      game.displayOptions(topside.getAdjacentRooms(), topside.getRoomAmount());
      cin >> playerChoice;
      game.setUserInput(playerChoice);

      // if userInput == 1, set player Location to Control Room.
      //userInput = 1;
      //1 == Player1.setLocation(ControlRoom);
      //
      break;
    case Location::ControlRoom:


    default:
      cout << "Game Error!";
    }

  } while (game.getGameOver() == false);


  /*
  Start Game - Loop that checks if gameOver = True;
  
  INIT TURN PHASE
  The Turn phase should consist of the following:

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