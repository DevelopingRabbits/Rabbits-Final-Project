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


using namespace std;


class Game
{
private:
  Player* players;
  Submarine* submarine;
  Room* room;
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



public:
  Game();

  // Game Functions
  void createGame(Player &player, Submarine &sub);
  void startGame();
  bool checkUserInput();

  void getCurrentRoom();
  void getCurrentRoomName();
  void getRoomDoors();
  void getRoomInventory();

  void displayRoomDetails();
  void displayDoors();
  void displayRoomDescription();
  void displayItems();

  void updateRoom();

  void playerTurn();

  // Set Private Member Variables
  void setGameOver(bool state);


  void moveFunction();
  void lookForItems();

  // Get Private Member Variables
  bool getGameOver();
  int getUserInput();

};
#endif
