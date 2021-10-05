#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Game.h"
#include "TOPSIDE.h"
#include<iostream>

using namespace std;

int main()
{
  Player player1;
  Submarine submarine;
  Game game;
  TopSide topside;
  enum class Location { TopSide = 0, ControlRoom = 1 };
  Location location = Location::TopSide;
  int locationIndex;


  cout << "\nWelcome to a Developing Rabbits Production!\n\n";


  player1.setName();
  cout << "\nWelcome Aboard Captain " << player1.getName() << endl << endl;

  game.startGame();

  do
  {
    locationIndex = player1.getLocation();
    location = static_cast<Location>(locationIndex);
    switch (location)
    {
    case Location::TopSide:
      topside.setSurfaced(submarine.getSurfaced());
      player1.setLocation(topside.playScenario());
      //game.displayOptions(topside.getAdjacentRooms(), topside.getRoomAmount());

      return 0;
      break;
    case Location::ControlRoom:

      //controlRoom.playerScenario();
      break;


    default:
      cout << "Game Error!";
    }

  } while (game.getGameOver() == false);
};


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