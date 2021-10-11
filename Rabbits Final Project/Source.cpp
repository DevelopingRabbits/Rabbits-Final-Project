#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Game.h"
#include "TOPSIDE.h"
#include "Item.h"
#include "Room.h"

int main()
{
  // INIT PLAYER
  Player player1;
  player1.setPlayerLocation(0, 3);

  // INIT SUBMARINE
  Submarine submarine;

  // INIT GAME
  Game game;
  game.createGame(player1, submarine);

  //INIT NULL DOORS
  Door NULLDOOR;
  NULLDOOR.createDoor("Null Door", false, NULLDOOR);

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
  topSide.setRoomDescription("You are standing on the topside of the submarine.\nThe weather outside is quite nice. The sea is calm and the sky is clear.\nThe reflection of the sun glimmers.");
  submarine.addRoom(topSide, topSide.getRoomRow(), topSide.getRoomCol());
  // END: Topside Room/Door Objects


  // START: Control Room Room/Door Objects
  // *****************************************************************
  Room controlRoom;
  Door nuclearPowerRoomDoor;
  nuclearPowerRoomDoor.createDoor("Nuclear Power Room", true, nuclearPowerRoomDoor);
  controlRoom.createRoom("Control Room", 1, topSideHatch.getDoorPtr(), NULLDOOR.getDoorPtr(), nuclearPowerRoomDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), 1, 3);
  controlRoom.setRoomDescription("You enter a dark room. You are unsure where you are.\n The only light you see is from the hatch above.");
  submarine.addRoom(controlRoom, controlRoom.getRoomRow(), controlRoom.getRoomCol());
  // END: Control Room Room/Door Objects
  // *****************************************************************



  /*
  *****************************************************************
  GAME STARTS BELOW
  *****************************************************************
  */
  cout << "\nWelcome to a Developing Rabbits Production!\n\n";
  player1.setName();
  cout << "\nWelcome Aboard Captain " << player1.getName() << endl << endl;

  game.startGame();
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
  do
  {
    // Initalize the turn.
    game.displayRoomDetails();
    game.setUserInput();

  } while (game.getGameOver() == false);
  return 0;
}



  //submarine.addRoom(topSide, topSide.getRoomRow(), topSide.getRoomCol());

  ////// INITALIZE DARK CONTROL ROOM OBJECT
  ////Room darkControlRoom;
  ////darkControlRoom.createRoom("Dark Unkown Room", 1);
  ////darkControlRoom.addDoor(topSideHatch);
  ////submarine.addRoom(darkControlRoom);

  ////Item BattleLantern;
  ////BattleLantern.createItem("Battle Lantern", 0);
  ////darkControlRoom.addItem(BattleLantern);


  ////// INITIALIZE CONTROL ROOM OBJECT
  ////Room controlRoom;
  ////controlRoom.createRoom("Control Room", 2);
  ////controlRoom.addDoor(topSideHatch);
  ////submarine.addRoom(controlRoom);


  //  do
  //  {
  //
  //    locationIndex = player1.getLocation();
  //    location = static_cast<Location>(locationIndex);
  //    switch (location)
  //    {
  //    case Location::TopSide:
  //      topSide.displayToUser();
  //      action = game.setUserInput();
  //      //USER INTERACTION
  //      switch (action)
  //      {
  //      case 1: // Interact with room items
  //        topSide.interactWithItems();
  //      case 2: // Move to new room
  //      //////// topSide.moveRooms();
  //      ////////  player1.setLocation(topSide.moveRooms());
  //      ////////case 3: // Interact with inventory
  //      ////////  player1.interactWithInventory();
  //        //game.displayOptions(topside.getAdjacentRooms(), topside.getRoomAmount());
  //        break;
  //      }
  //    case Location::DarkControlRoom:
  //      darkControlRoom.displayToUser();
  //
  //      //controlRoom.playerScenario();
  //      break;
  //    case Location::ControlRoom:
  //      controlRoom.displayToUser();
  //      game.setUserInput();
  //      player1.setLocation(game.getUserInput());
  //
  //    default:
  //      cout << "Game Error!";
  //    }
  //
  //  } while (game.getGameOver() == false);
  //};