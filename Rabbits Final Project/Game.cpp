#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
  gameOver = false;
};

void Game::startGame()
{

	cout << "\n\n************************************LOCATION: TOPSIDE************************************\n"
				<< "You are topside of the submarine. The weather outside is quite nice.\n"
				<< "The sea is calm and the sky is clear. The reflection of the sun glimmers.\n"
				<< "************************************LOCATION: TOPSIDE************************************\n";
}

void Game::displayOptions(string rooms[],int size)
{
	int choice = 1;
	
	
	cout << "You see:"<<endl;
	for (int i = 0; i < size; i++)
	{
		cout << "(" << choice << ")" << rooms[i]<<endl;
		choice++;
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