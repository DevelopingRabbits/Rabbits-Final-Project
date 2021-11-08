#pragma once
#ifndef GameFunctions_H
#define GameFunctions_H
#include<iostream>
#include"GameBoard.h"
#include"PlayerFunctions.h"
using namespace std;


class GameFunctions {

private:

public:
	char player1Symbol = 'X';
	int player1Choice;
	int player1ChoiceTemp;
	GameBoard gameBoard;
	PlayerFunctions playerFunctions;

	bool rematch;
	int startingPlayer;
	int turnCounter = 0;
	int choice;
	int win;

	void StartGame(bool startGame); //Main Function that calls functions from various classes to make the game function.
	int PlayerTurn();     //A function that randomly selects either 1 or 2 to determine the starting player.
};
#endif