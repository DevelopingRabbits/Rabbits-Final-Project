#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "PLAYER.h"
#include "SUBMARINE.h"
#include "Room.h"
#include "Door.h"
#include "OceanMap.h"
#include "Enemy.h"
#include "GameSystemsProgramming.h"
#include "GameFunctions.h"


using namespace std;


class Player;
class Room;
class Door;
class Item;
class Submarine;
class OceanMap;
class Enemy;
class GameFunctions;
class Game
{
private:
  GameSystemsProgramming gameSystemsProgramming;
  GameFunctions lightsOut;
  Game* game;
  Player* player;
  Submarine* submarine;
  Room* currentRoom;
  Door* upDoor;
  Door* downDoor;
  Door* rightDoor;
  Door* leftDoor;
  Item* item1;
  OceanMap* ocean;
  Enemy* kraken;
  int playerInventorySize;
  int roomActionItemsSize;
  vector<Item*> inventory;
  vector<Item*> actionItems;


  string cannotMoveMessage;
  string playerMovedMessage;
  bool gameOver;
  bool userInputValid;
  int userInput;
  string stringUserInput;



public:
  // INIT Options
  Game();
  void createGame(Player &player, Submarine &sub, Game &gameArg, OceanMap &oceanarg, Enemy &enemyarg);
  void startGame();

  // Set Options
  void setGameOver(bool state);

  // Get Options
  void getCurrentRoom();
  void getRoomDoors();
  void getRoomInventory();
  bool getGameOver();

  // Display Options
  void displayRoomDetails();
  void displayDoors();
  void displayRoomDescription();
  void displayItems();
  void displayPlayerInventory();
  void displayRoomActionItems();

  // Player Turn
  void playerTurn(Game* gameArg);

  // Player Options
  void moveFunction();
  void lookForItems();
  void interactWithInventory();
  void interactWithRoom();
  void getHelp();

  // Update Options
  void updateRoom();
  void updatePlayer();

  //submarine
  void moveSubFunction();
  void displayCurrentSubLocation();
  bool checkSubWin();
 

 
};
#endif
