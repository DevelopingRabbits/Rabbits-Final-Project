#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Game
{
private:
  bool gameOver;

public:
  Game();
  bool getGameOver();
  void setGameOver(bool state);

};



#endif
