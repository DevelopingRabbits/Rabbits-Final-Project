#include "PlayerFunctions.h"
#include <iostream>

PlayerFunctions::PlayerFunctions() //Default Constructor
{
	for (int i = 0; i < 9; i++) {
		player1Tracker[i] = -1;
		player1Choice[i] = ' ';
		gameBoardArray[i] = ' ';
	}
	player1ChoiceTemp = -1;
}

// Initialize all arrays for a new game. This will be important for a rematch feature.
void PlayerFunctions::playerFunctionsInit() {
	for (int i = 0; i < 9; i++) {
		gameBoardArray[i] = ' ';
		player1Tracker[i] = -1;
	}
};
int PlayerFunctions::Player1Turn() {
	bool valid = false;
loop:
	do {

		std::cout << "\nPlayer 1 (X) Make your move: ";
		std::cin >> player1ChoiceTemp;

		if (cin.good())
		{
			//the input is a valid integer, break out of the loop.
			valid = true;
		}
		else
		{
			cin.clear(); //reset the buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//empty the buffer
			cout << "** Invalid Input ** Enter a number from 1 - 9." << endl;
			valid = false;
		}
	} while (!valid);

	if (player1ChoiceTemp <= 0 || player1ChoiceTemp >= 10)//test to see if the input that has been validated to be a number is either 1 or 2
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "** Choice out of number range. Select a number between 1 & 9. **" << endl;
		goto loop;//if the number is not 1 or 2, go back to attempting to get an input
	}
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		player1ChoiceTemp -= 1;
		gameBoardArray[player1ChoiceTemp] = 'x';
		player1Choice[player1TurnCount] = player1ChoiceTemp;
		player1TurnCount++;

		switch (player1ChoiceTemp + 1) {
		case 1:
			if (player1Tracker[0] != 1)
			{
				player1Tracker[0] = 1;
			}
			else
			{
				player1Tracker[0] = -1;
			};
			if (player1Tracker[1] != 1)
			{
				player1Tracker[1] = 1;
			}
			else
			{
				player1Tracker[1] = -1;
			};
			if (player1Tracker[3] != 1)
			{
				player1Tracker[3] = 1;
			}
			else
			{
				player1Tracker[3] = -1;
			}; break;
		case 2:
			if (player1Tracker[2] != 1)
			{
				player1Tracker[2] = 1;
			}
			else
			{
				player1Tracker[2] = -1;
			};
			if (player1Tracker[1] != 1)
			{
				player1Tracker[1] = 1;
			}
			else
			{
				player1Tracker[1] = -1;
			};
			if (player1Tracker[4] != 1)
			{
				player1Tracker[4] = 1;
			}
			else
			{
				player1Tracker[4] = -1;
			};
			if (player1Tracker[0] != 1)
			{
				player1Tracker[0] = 1;
			}
			else
			{
				player1Tracker[0] = -1;
			}; break;
		case 3:
			if (player1Tracker[1] != 1)
			{
				player1Tracker[1] = 1;
			}
			else
			{
				player1Tracker[1] = -1;
			};
			if (player1Tracker[2] != 1)
			{
				player1Tracker[2] = 1;
			}
			else
			{
				player1Tracker[2] = -1;
			};
			if (player1Tracker[5] != 1)
			{
				player1Tracker[5] = 1;
			}
			else
			{
				player1Tracker[5] = -1;
			}; break;
		case 4:
			if (player1Tracker[0] != 1)
			{
				player1Tracker[0] = 1;
			}
			else
			{
				player1Tracker[0] = -1;
			};
			if (player1Tracker[3] != 1)
			{
				player1Tracker[3] = 1;
			}
			else
			{
				player1Tracker[3] = -1;
			};
			if (player1Tracker[4] != 1)
			{
				player1Tracker[4] = 1;
			}
			else
			{
				player1Tracker[4] = -1;
			};
			if (player1Tracker[6] != 1)
			{
				player1Tracker[6] = 1;
			}
			else
			{
				player1Tracker[6] = -1;
			}; break;
		case 5:
			if (player1Tracker[1] != 1)
			{
				player1Tracker[1] = 1;
			}
			else
			{
				player1Tracker[1] = -1;
			};
			if (player1Tracker[3] != 1)
			{
				player1Tracker[3] = 1;
			}
			else
			{
				player1Tracker[3] = -1;
			};
			if (player1Tracker[4] != 1)
			{
				player1Tracker[4] = 1;
			}
			else
			{
				player1Tracker[4] = -1;
			};
			if (player1Tracker[5] != 1)
			{
				player1Tracker[5] = 1;
			}
			else
			{
				player1Tracker[5] = -1;
			};
			if (player1Tracker[7] != 1)
			{
				player1Tracker[7] = 1;
			}
			else
			{
				player1Tracker[7] = -1;
			}; break;
		case 6:
			if (player1Tracker[2] != 1)
			{
				player1Tracker[2] = 1;
			}
			else
			{
				player1Tracker[2] = -1;
			};
			if (player1Tracker[4] != 1)
			{
				player1Tracker[4] = 1;
			}
			else
			{
				player1Tracker[4] = -1;
			};
			if (player1Tracker[5] != 1)
			{
				player1Tracker[5] = 1;
			}
			else
			{
				player1Tracker[5] = -1;
			};
			if (player1Tracker[8] != 1)
			{
				player1Tracker[8] = 1;
			}
			else
			{
				player1Tracker[8] = -1;
			}; break;
		case 7:
			if (player1Tracker[3] != 1)
			{
				player1Tracker[3] = 1;
			}
			else
			{
				player1Tracker[3] = -1;
			};
			if (player1Tracker[6] != 1)
			{
				player1Tracker[6] = 1;
			}
			else
			{
				player1Tracker[6] = -1;
			};
			if (player1Tracker[7] != 1)
			{
				player1Tracker[7] = 1;
			}
			else
			{
				player1Tracker[7] = -1;
			}; break;
		case 8:
			if (player1Tracker[4] != 1)
			{
				player1Tracker[4] = 1;
			}
			else
			{
				player1Tracker[4] = -1;
			};
			if (player1Tracker[6] != 1)
			{
				player1Tracker[6] = 1;
			}
			else
			{
				player1Tracker[6] = -1;
			};
			if (player1Tracker[7] != 1)
			{
				player1Tracker[7] = 1;
			}
			else
			{
				player1Tracker[7] = -1;
			};
			if (player1Tracker[8] != 1)
			{
				player1Tracker[8] = 1;
			}
			else
			{
				player1Tracker[8] = -1;
			}; break;
		case 9:
			if (player1Tracker[5] != 1)
			{
				player1Tracker[5] = 1;
			}
			else
			{
				player1Tracker[5] = -1;
			};
			if (player1Tracker[7] != 1)
			{
				player1Tracker[7] = 1;
			}
			else
			{
				player1Tracker[7] = -1;
			};
			if (player1Tracker[8] != 1)
			{
				player1Tracker[8] = 1;
			}
			else
			{
				player1Tracker[8] = -1;
			}; break;
		default:
			break;
		}

		return player1Choice[player1TurnCount - 1];
	}


};


int PlayerFunctions::CheckWin()
{
	/* For Debugging Purposes
	for (int i = 0; i < 8; i++) {
		cout <<this-> player1Tracker[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		cout << this-> player2Tracker[i] << endl;
	}
	For Debugging Purposes*/


	/*
		This function checks both player's arrays and determines if they have a combination that satisfies 1 of 8 different
		combinations of TicTacToe.
	*/


	// If every space is filled, the game is won
	for (int i = 0; i < 9; i += 3)
	{

		if (this->player1Tracker[0] == 1 && this->player1Tracker[1] == 1 && this->player1Tracker[2] == 1 && this->player1Tracker[3] == 1 && this->player1Tracker[4] == 1 && this->player1Tracker[5] == 1 && this->player1Tracker[6] == 1 && this->player1Tracker[7] == 1 && this->player1Tracker[8] == 1)
		{

			return 1;//the board is full
		}
	}

	return NULL;
};