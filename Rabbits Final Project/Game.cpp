#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
  gameOver = false;
	userInput = NULL;
};

void Game::startGame()
{
}


void Game::displayOptions(string rooms[],int size)
{
	int options = 1;
	
	
	cout << "You see:"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << "(" << options << ")" << rooms[i]<<endl;
		options++;
	}


}

bool Game::getGameOver()
{
	return gameOver;
};

void Game::setGameOver(bool state)
{
	gameOver = state;
};


void Game::setUserInput(int choice)
{
	userInput = choice;
};

int Game::getUserInput()
{
	return userInput;
};