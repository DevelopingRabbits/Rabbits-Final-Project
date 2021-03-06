#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Game.h"
#include "Item.h"


#include<iostream>
#include<string>


using namespace std;

int main()
{
    bool restart = true;
    string choice;
    int choiceInt;
    do {
            cout << "Welcome to a Developing Rabbits Production!\n\n";
            cout << "\nSubmarine Adventure Game\n";
            cout << "\n1. Start Game\n2. Help\n3. Quit\nYour choice:" << endl;
            cin >> choice;

            GameSystemsProgramming gameSystemsProgramming;
            choiceInt=gameSystemsProgramming.stringToIntegerInputValidation(choice);

            switch (choiceInt)
            {

            case 1:
            {
                //INIT PLAYER
                Player player1;
                player1.setPlayerLocation(0, 3); // Hardcoding Topside Room Coordinates **TEMP**

                // INIT SUBMARINE
                Submarine submarine;

        //INIT OCEANMAP
        OceanMap ocean;
        ocean.setSubPosition(submarine.getXSubLoc(), submarine.getYSubLoc());
        //INIT NULL DOORS
        Door NULLDOOR;
        NULLDOOR.createDoor("Inaccessible", false, NULLDOOR);

    //INIT ENEMY
    Enemy kraken;
    kraken.setEnemyType("Kraken");
    kraken.setEnemyHealth(100);
    kraken.setEnemyLocation(1, 1);

    Enemy nessie;
    nessie.setEnemyType("Nessie of Loch Ness");
    nessie.setEnemyHealth(100);
    nessie.setEnemyLocation(2, 2);

    Enemy hostileSub;
    hostileSub.setEnemyType("Hostile Submarine");
    hostileSub.setEnemyHealth(100);
    hostileSub.setEnemyLocation(3, 3);

    // INIT GAME
    Game game;
    game.createGame(player1, submarine, game, ocean, NULLDOOR);
    game.addEnemy(&kraken);
    game.addEnemy(&hostileSub);
    game.addEnemy(&nessie);


              

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

              // How to INIT Action Item Objects
              /*
              *****************************************************************
              1. Create the item object
              2. createActionItem(string name, int id, Item& iPtr, bool subPower, bool needKey)
              3. room.addItem(room object, room row, room col)
              Example:
                Item captainsLog;
                captainsLog.createActionItem("Captain's Log", 9998, captainsLog, false, false);
                captainsRoom.addActionItem(&captainsLog);
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
                  // *****************************************************************


                      // START: Control Room Room/Door Objects
                      // *****************************************************************

                      //Door Creation
                Door nuclearPowerRoomDoor;
                nuclearPowerRoomDoor.createDoor("Nuclear Power Room", true, nuclearPowerRoomDoor);
                Door captainsRoomDoor;
                captainsRoomDoor.createDoor("Captain's State Room", true, captainsRoomDoor);
                Door berthingDoor;
                berthingDoor.createDoor("Berthing Room", true, berthingDoor);

                // Room Creation
                Room controlRoom;
                controlRoom.createRoom("Control Room", 1, topSideHatch.getDoorPtr(), berthingDoor.getDoorPtr(), nuclearPowerRoomDoor.getDoorPtr(), captainsRoomDoor.getDoorPtr(), 1, 3);
                controlRoom.setDarkRoomDescription("You enter a dark room. You are unsure where you are.\nThe only light you see is from the hatch above.");
                controlRoom.setRoomDescription("The room has plenty of computer terminals. This seems to be the control room of the submarine.");
                submarine.addRoom(controlRoom, controlRoom.getRoomRow(), controlRoom.getRoomCol());

                // Player Items
                Item battleLantern;
                battleLantern.createItem("Battle Lantern", 0, 0, battleLantern);
                controlRoom.addItem(&battleLantern);

                // Action Items
                Item controlRoomComputerTerminal;
                controlRoomComputerTerminal.createActionItem("Computer Terminal", 9999, controlRoomComputerTerminal, true, false);
                controlRoom.addActionItem(&controlRoomComputerTerminal);
                // *****************************************************************
                // END: Control Room Room/Door Objects


                  // START: Nuclear Power Room/Door Objects
                // *****************************************************************

                // Door Creation
                Door controlRoomDoor;
                controlRoomDoor.createDoor("Control Room", true, controlRoomDoor);
                Door weaponsRoomDoor;
                weaponsRoomDoor.createDoor("Weapons Room", true, weaponsRoomDoor);
                Door messdeckDoor;
                messdeckDoor.createDoor("Mess Deck", true, messdeckDoor);
                Door combatsystemDoor;
                combatsystemDoor.createDoor("Machinist Room", true, combatsystemDoor);

                // Room Creation
                Room nuclearPowerRoom;
                nuclearPowerRoom.createRoom("Nuclear Power Room", 2, messdeckDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), weaponsRoomDoor.getDoorPtr(), controlRoomDoor.getDoorPtr(), 1, 2);
                nuclearPowerRoom.setRoomDescription("You are in the nuclear power room.");
                nuclearPowerRoom.setDarkRoomDescription("You can't see anything. It's pitch black.");
                submarine.addRoom(nuclearPowerRoom, nuclearPowerRoom.getRoomRow(), nuclearPowerRoom.getRoomCol());

                // Player Items
                Item controlRods;
                controlRods.createItem("Control Rods", 1, 1, controlRods);
                controlRods.setKeyCode(0001);
                nuclearPowerRoom.addItem(&controlRods);

                // Action Items
                Item reactor;
                reactor.createActionItem("Reactor", 0, reactor, false, true);
                reactor.setActionItemKeyCode(0001);
                nuclearPowerRoom.addActionItem(&reactor);

                // *****************************************************************
                // END: Nuclear Power Room/Door Objects


              // START: Captain's Room Objects

              // Door Creation
                Door repairRoomDoor;
                repairRoomDoor.createDoor("Repair Room", true, repairRoomDoor);
                Door propellerRoomDoor;
                propellerRoomDoor.createDoor("Propeller Room", true, propellerRoomDoor);

        // Room Creation
        Room captainsRoom;
        captainsRoom.createRoom("Captain's Room", 8, NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), controlRoomDoor.getDoorPtr(), repairRoomDoor.getDoorPtr(), 1, 4);
        captainsRoom.setRoomDescription("You are in the Captain's State Room.");
        captainsRoom.setDarkRoomDescription("You can't see anything. It's pitch black.");
        submarine.addRoom(captainsRoom, captainsRoom.getRoomRow(), captainsRoom.getRoomCol());
        // Action Items
        Item captainsLog;
        captainsLog.createActionItem("Captain's Log", 9998, captainsLog, false, false);
        captainsRoom.addActionItem(&captainsLog);
        captainsLog.storeWinningCoordinates(ocean.getWinX(), ocean.getWinY());
        // *****************************************************************
        // END: Captain's Room Objects

                // START: WEAPONS ROOM Objects
                // Room Creation
                Room weaponsRoom;
                weaponsRoom.createRoom("Weapons Room", 3, NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), nuclearPowerRoomDoor.getDoorPtr(), 1, 1);
                weaponsRoom.setRoomDescription("You are in the Weapons Room Room.");
                weaponsRoom.setDarkRoomDescription("You can't see anything. It's pitch black.");
                submarine.addRoom(weaponsRoom, weaponsRoom.getRoomRow(), weaponsRoom.getRoomCol());
                // Action Items
                Item weaponSystem;
                weaponSystem.createActionItem("Weapon System Mainframe", 9997, weaponSystem, true, false);
                weaponsRoom.addActionItem(&weaponSystem);
                // *****************************************************************
                // END: Weapon's Room Room Objects

                // Brandon's Rooms
                Room repairRoom;
                repairRoom.createRoom("Repair Room", 4, NULLDOOR.getDoorPtr(), propellerRoomDoor.getDoorPtr(), captainsRoomDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), 1, 5);
                repairRoom.setRoomDescription("You are in the repair room.");
                repairRoom.setDarkRoomDescription("You can't see anything. It's pitch black.");
                submarine.addRoom(repairRoom, repairRoom.getRoomRow(), repairRoom.getRoomCol());

                Room propellerRoom;
                propellerRoom.createRoom("Propeller Room", 5, repairRoomDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), 2, 5);
                propellerRoom.setRoomDescription("You are in the propeller room.");
                propellerRoom.setDarkRoomDescription("You can't see anything. It's pitch black.");
                submarine.addRoom(propellerRoom, propellerRoom.getRoomRow(), propellerRoom.getRoomCol());

                Room messDeck;
                messDeck.createRoom("Mess Deck", 6, NULLDOOR.getDoorPtr(), nuclearPowerRoomDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), 0, 2);
                messDeck.setRoomDescription("You are in the mess deck.");
                messDeck.setDarkRoomDescription("You can't see anything. It's pitch black.");
                submarine.addRoom(messDeck, messDeck.getRoomRow(), messDeck.getRoomCol());

                Room berthing;
                berthing.createRoom("Berthing", 7, controlRoomDoor.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), NULLDOOR.getDoorPtr(), 2, 3);
                berthing.setRoomDescription("You are in the berthing section.");
                berthing.setDarkRoomDescription("You can't see anything. It's pitch black.");
                submarine.addRoom(berthing, berthing.getRoomRow(), berthing.getRoomCol());

        // Action Items
        Item captainChair;
        captainChair.createActionItem("Captain's Chair", 9996, captainChair, false, false);
        captainsRoom.addActionItem(&captainChair);
       
        Item snack;
        snack.createActionItem("Snack", 9995, snack, false, false);
        messDeck.addActionItem(&snack);

        Item berthingBed;
        berthingBed.createActionItem("Berthing Bed", 9994, berthingBed, false, false);
        berthing.addActionItem(&berthingBed);

        Item propellerWire;
        propellerWire.createActionItem("Propeller Wire", 9993, propellerWire, false, false);
        propellerRoom.addActionItem(&propellerWire);

        Item repairTool;
        repairTool.createActionItem("Repair Tool Kit", 9992, repairTool, false, false);
        repairRoom.addActionItem(&repairTool);



        /******************************************************************
        GAME STARTS BELOW
        ******************************************************************/

        //playerName=ui.getPlayerName();
        //playerName=ui.stringInputValidation(playerName);
        

        game.startGame();

        ////DEBUGGING MODE - SET EVERYTHING TO TRUE
        //game.enemyEncounter(1);
        //player1.setCanSeeInDarkRoom(true);
        //submarine.setPowerOn(true);
        //submarine.setWeaponStatus(true);
        do
        {
            // Initalize the turn.
            game.playerTurn(&game);
        } while (game.getGameOver() == false);
        

                int restartInput;
                cout << "\nWould you like to play the game again?\n1. Yes\n2. No" << endl;
                cin >> restartInput;


                if (restartInput == 2) {
                    restart = false;
                    cout << "The game has ended, thank you for playing!" << endl;
                    system("pause");
                }
                break;
            }
            case 2:
            {
                cout << "You chose to ask for help:\n\n";
                cout << "This is a text based adventure game that is based in a submarine. ";
                cout << "Your objective is to beat the game\nand get to the winning location, but watch out, there may be something dangerous in the water. ";
                cout << "\nPress 1 to start the game, 2 to see this message again, or 3 to quit the game.\n";
                break;
            }
            case 3:
            {
                cout << "The game has ended." << endl;
                system("pause");
                return 0;
                break;
            }
            default:
                cout << "That is not a valid choice, please choose 1-3\n";
                break;
            }

        

    }while (restart == true);

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