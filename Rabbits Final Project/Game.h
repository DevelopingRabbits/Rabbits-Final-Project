#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>

#include "PLAYER.h"

using namespace std;


class Game
{
private:
  vector<Player> players;
  bool gameOver;
  int userInput;
  bool userInputValid;

  enum class Location { TopSide = 0, ControlRoom = 1 };
  Location location = Location::TopSide;
  int locationIndex;

public:
  Game();
  bool getGameOver();
  void AddPlayer(Player newPlayer);
  void startGame();
  void setGameOver(bool state);
  void displayOptions(string rooms[], int size);
  int setUserInput(); /////CHANGE FUNCTION NAME
  bool checkUserInput();
  int getUserInput();

};



#endif
