#pragma once
#ifndef PlayerFunctions_H
#define PlayerFunctions_H
#include<iostream>
#include <array>
#include "GameBoard.h"
using namespace std;


class PlayerFunctions {

private:

public:
	PlayerFunctions(); // Default Constructor
	GameBoard gameBoard;
	int player1Choice[9];
	int player1ChoiceTemp;
	int player1TurnCount = 0;
	char gameBoardArray[9];
	const int MAX_TURN = 9;


	int player1Tracker[9];


	void playerFunctionsInit();  // Resets all the variables. Will be used for rematches.
	int Player1Turn();           // All input validation and steps for Player 1's turn
	int CheckWin();              // Check if a player has a winning move.
};
#endif

