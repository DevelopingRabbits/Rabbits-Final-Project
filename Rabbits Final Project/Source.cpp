#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Game.h"
#include "TOPSIDE.h"
#include "Room.h"
#include "Item.h"

#include<iostream>

using namespace std;

int main()
{
  Player player1;
  Submarine submarine;
  Game game;
  //TopSide topside;
  enum class Location { TopSide = 0, DarkControlRoom = 1, ControlRoom = 2 };
  Location location = Location::TopSide;
  int locationIndex;
  int action;



  // INITALIZE TOPSIDE ROOM OBJECT
  Room topSide;
  Door topSideHatch;
  topSideHatch.SetDoorName("Topside Hatch");
  topSide.createRoom("Topside", 0);
  topSide.addDoor(topSideHatch);
  submarine.addRoom(topSide);

  // INITALIZE DARK CONTROL ROOM OBJECT
  Room darkControlRoom;
  darkControlRoom.createRoom("Dark Unkown Room", 1);
  darkControlRoom.addDoor(topSideHatch);
  submarine.addRoom(darkControlRoom);

  Item BattleLantern;
  BattleLantern.createItem("Battle Lantern", 0);
  darkControlRoom.addItem(BattleLantern);


  // INITIALIZE CONTROL ROOM OBJECT
  Room controlRoom;
  controlRoom.createRoom("Control Room", 2);
  controlRoom.addDoor(topSideHatch);
  submarine.addRoom(controlRoom);



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
      topSide.displayToUser();
      action = game.setUserInput();
      //USER INTERACTION
      switch (action)
      {
      case 1: // Interact with room items
        topSide.interactWithItems();
      case 2: // Move to new room
        //topSide.moveRooms();
      ////////  player1.setLocation(topSide.moveRooms());
      ////////case 3: // Interact with inventory
      ////////  player1.interactWithInventory();
        //game.displayOptions(topside.getAdjacentRooms(), topside.getRoomAmount());
        break;
      }
    case Location::DarkControlRoom:
      darkControlRoom.displayToUser();

      //controlRoom.playerScenario();
      break;
    case Location::ControlRoom:
      controlRoom.displayToUser();
      game.setUserInput();
      player1.setLocation(game.getUserInput());

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