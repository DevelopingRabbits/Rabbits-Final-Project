#pragma once
#ifndef GameBoard_H
#define GameBoard_H
#include<iostream>
using namespace std;


class GameBoard
{

private:

public:
	char gameBoardArray[9];

	void GameBoardInit();                              // Resets/Initializes the GameBoard, will be useful for rematches.
	void GameBoardDisplay();                           // Display the GameBoard to the user.
	void GameBoardUpdate(char input, int space);        // Add X's and O's to the gameboard as the game progresses.
	void GameBoardReset();                             // Resets the GameBoard as needed.
};
#endif
