#include "GameFunctions.h"
#include <iostream>
#include <limits>
#include <random>
#include <ctime>

void GameFunctions::StartGame() {

	// When the startGame function is called, the playerFunctions library will be initialize, zeroing out all arrays.
	// The program will then select a starting player at random using the SelectStartingPlayer() function.
	// The GameBoardInit() function is called to reset and clear out the gameboard.
		playerFunctions.playerFunctionsInit();
		gameBoard.GameBoardInit();

		// If Player 1 is randomly selected to go first:
		cout << "Starting player is Player 1 (X)";
		gameBoard.GameBoardDisplay(); // Display the gameboard to the user.
		do {                          // Do while there is no winner.
			player1Choice = playerFunctions.Player1Turn(); // Allow player 1 to make a selection.
			gameBoard.GameBoardUpdate(player1Symbol, player1Choice); //Selection is made, update the board to the corresponding square.
			gameBoard.GameBoardDisplay(); //Display the board with the new move.
			turnCounter++;
			win = playerFunctions.CheckWin(); //Check if Player 1 won.
			if (win == 1)
			{
				cout << "\n\n*** The panel flickers a bit and you hear a speaker say, 'Weapon Systems Online'. ***\n\n";
				break;
			}
		} while (win != 1);
};