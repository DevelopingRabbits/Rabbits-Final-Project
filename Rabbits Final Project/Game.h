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

  string cannotMoveMessage;
  string playerMovedMessage;
  bool gameOver;
  bool userInputValid;
  int userInput;
  string stringUserInput;



public:
  Game();

  // Game Functions
  void createGame(Player &player, Submarine &sub);
  void startGame();

  void getCurrentRoom();
  void getRoomDoors();
  void getRoomInventory();
  void getPlayerInventory();

  void displayRoomDetails();
  void displayDoors();
  void displayRoomDescription();
  void displayItems();
  void displayPlayerInventory();

  void updateRoom();
  void updatePlayer();

  void playerTurn();

  // Set Private Member Variables
  void setGameOver(bool state);


  void moveFunction();
  void lookForItems();
  void interactWithInventory();

  // Get Private Member Variables
  bool getGameOver();
  int getUserInput();

};
#endif
