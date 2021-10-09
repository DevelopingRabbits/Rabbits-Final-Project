#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
  gameOver = false;
	userInput = NULL;
};


void Game::AddPlayer(Player newPlayer)
{
	players.push_back(newPlayer);
};

void Game::startGame()
{
	cout << "Start Game!\n\n";

	// add newPlayer to vector
	// add newSubmarine to vector
	// 

};


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


bool Game::checkUserInput()
{
	switch (userInput)
	{
	case 1:
		cout << "You chose to look at Items\n";
		return true;
		break;

	case 2:
		cout << "You chose to Move\n";
		return true;
		break;

	case 3:
		cout << "You chose to Interact with Inventory";
		return true;
		break;

	default:
		cout << "Invalid Option.\n";
		return false;
		break;
	}
}
int Game::setUserInput()
{
	userInputValid = false;
	do {
		cout << "Look for Items(1), Move(2) or Interact with Inventory(3)?: ";
		// Items or Move
		cin >> userInput;
		userInputValid = checkUserInput();
	} while (userInputValid == false);

	switch (userInput)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	}
};

int Game::getUserInput()
{
	return userInput;
};