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
#include "GameSystemsProgramming.h"


using namespace std;



class Game
{
private:
  GameSystemsProgramming gameSystemsProgramming;
  Player* player;
  Submarine* submarine;
  Room* currentRoom;
  Door* upDoor;
  Door* downDoor;
  Door* rightDoor;
  Door* leftDoor;
  Item* item1;
  int playerInventorySize;
  vector<Item*> inventory;

  string cannotMoveMessage;
  string playerMovedMessage;
  bool gameOver;
  bool userInputValid;
  int userInput;
  string stringUserInput;



public:
  // INIT Options
  Game();
  void createGame(Player &player, Submarine &sub);
  void startGame();

  // Set Options
  void setGameOver(bool state);

  // Get Options
  void getCurrentRoom();
  void getRoomDoors();
  void getRoomInventory();
  void getPlayerInventory();
  bool getGameOver();

  // Display Options
  void displayRoomDetails();
  void displayDoors();
  void displayRoomDescription();
  void displayItems();
  void displayPlayerInventory();

  // Player Turn
  void playerTurn();

  // Player Options
  void moveFunction();
  void lookForItems();
  void interactWithInventory();
  void interactWithRoom();

  // Update Options
  void updateRoom();
  void updatePlayer();

};
#endif
