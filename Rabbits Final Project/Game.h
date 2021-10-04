#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


class Game
{
private:
  bool gameOver;

public:
  Game();
  bool getGameOver();
  void startGame();
  void setGameOver(bool state);

  void displayOptions(string rooms[], int size);

};



#endif
