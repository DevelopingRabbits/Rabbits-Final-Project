#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
  gameOver = false;
};

bool Game::getGameOver()
{
	return gameOver;
};

void Game::setGameOver(bool state)
{
	gameOver = state;
};