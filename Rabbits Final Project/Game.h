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

  void displayRoomDetails();
  void displayDoors();
  void displayRoomDescription();

  // Set Private Member Variables
  void setGameOver(bool state);
  void setUserInput(); /////CHANGE FUNCTION NAME

  void moveFunction();

  // Get Private Member Variables
  bool getGameOver();
  int getUserInput();

};
#endif
