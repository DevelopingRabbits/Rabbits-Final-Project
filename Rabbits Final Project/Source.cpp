#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Game.h"
#include "Item.h"


#include<iostream>
#include<string>


using namespace std;

int main()
{
  Player player1;
  player1.setPlayerLocation(0, 3); // Hardcoding Topside Room Coordinates **TEMP**

  // INIT SUBMARINE
  Submarine submarine;

  // INIT GAME
  Game game;
  game.createGame(player1, submarine);


  //INIT NULL DOORS
  Door NULLDOOR;
  NULLDOOR.createDoor("Null Door", false, NULLDOOR);

  // How to INIT Room Objects
  /*
*****************************************************************
1. Create the room object
2. Create the doors for the object.
3. room.createRoom(string name, int rID, UP door, DOWN door,
                    LEFT door, RIGHT door, int row, int col);
                    UP DOWN LEFT RIGHT
4. submarine.addRoom(room object, room row, room col)
*****************************************************************
*/
  // START: Topside Room/Door Objects
  Room topSide;
  Door topSideHatch;
  topSideHatch.createDoor("Topside Hatch", true, topSideHatch);
  topSide.createRoom("Topside", 0, NULLDOOR.getDoorPtr(), topSideHatch.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), 0, 3);
  topSide.setRoomDescription("You are standing on the topside of the submarine.\nThe weather outside is quite nice. The sea is calm and the sky is clear.\nThe sun glimmers on the calm ocean waves.");
  topSide.setIsDark(false);
  submarine.addRoom(topSide, topSide.getRoomRow(), topSide.getRoomCol());
  // END: Topside Room/Door Objects


  // START: Control Room Room/Door Objects
  // *****************************************************************

  //Door Creation
  Door nuclearPowerRoomDoor;
  nuclearPowerRoomDoor.createDoor("Nuclear Power Room", true, nuclearPowerRoomDoor);

  // Room Creation
  Room controlRoom;
  controlRoom.createRoom("Control Room", 1, topSideHatch.getDoorPtr(), NULLDOOR.getDoorPtr(), nuclearPowerRoomDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), 1, 3);
  controlRoom.setDarkRoomDescription("You enter a dark room. You are unsure where you are.\nThe only light you see is from the hatch above.");
  controlRoom.setRoomDescription("The room has plenty of computer terminals. This seems to be the control room of the submarine.");
  submarine.addRoom(controlRoom, controlRoom.getRoomRow(), controlRoom.getRoomCol());

  // Player Items
  Item battleLantern;
  battleLantern.createItem("Battle Lantern", 0, 0, battleLantern);
  controlRoom.addItem(&battleLantern);

  // Action Items
  Item controlRoomComputerTerminal;

 
  // END: Control Room Room/Door Objects
  // *****************************************************************

    // START: Nuclear Power Room/Door Objects
  // *****************************************************************
  Room nuclearPowerRoom;
  Door controlRoomDoor;
  Item controlRods;
  controlRods.createItem("Control Rods", 1, 1, controlRods);
  nuclearPowerRoom.addItem(&controlRods);
  controlRoomDoor.createDoor("Control Room", true, controlRoomDoor);
  nuclearPowerRoom.createRoom("Nuclear Power Room", 2, NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), controlRoomDoor.getDoorPtr(), 1, 2);
  nuclearPowerRoom.setRoomDescription("You are in the nuclear power room.");
  nuclearPowerRoom.setDarkRoomDescription("You can't see anything. It's pitch black.");
  submarine.addRoom(nuclearPowerRoom, nuclearPowerRoom.getRoomRow(), nuclearPowerRoom.getRoomCol());


    // END: Nuclear Power Room/Door Objects
  // *****************************************************************






  /******************************************************************
  GAME STARTS BELOW
  ******************************************************************/
  
  //playerName=ui.getPlayerName();
  //playerName=ui.stringInputValidation(playerName);

  game.startGame();
  do
  {
    // Initalize the turn.
    game.playerTurn();
  } while (game.getGameOver() == false);
  return 0;
}




//Turn Sequence Explanation
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

CONSEQUENCE/Update PHASE
*/ // Turn Sequence