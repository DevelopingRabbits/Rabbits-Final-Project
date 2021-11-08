#include "GameBoard.h"
#include <iostream>



void GameBoard::GameBoardInit()
{
	for (int x = 0; x < 9; x++)//reset the array to blank spaces
	{
		gameBoardArray[x] = ' ';
	}
};

void GameBoard::GameBoardDisplay()
{
	cout << "\n\n";
	std::cout << "   ";
	for (int x = 0; x < 3; x++)//display the first row of the gameboard
	{
		std::cout << gameBoardArray[x];
		if (x < 2)//print out the first two bars in the game board
		{
			cout << " | ";
		}

	}
	//formatting for the board to display correctly in the console
	std::cout << std::endl;
	std::cout << "  ";
	std::cout << "------------" << std::endl;
	std::cout << "   ";
	for (int x = 3; x < 6; x++)//display the second row of the gameboard
	{
		std::cout << gameBoardArray[x];
		if (x < 5)//print out the second two bars in the game board
		{
			cout << " | ";
		}
	}
	//formatting for the board to display correctly in the console
	std::cout << std::endl;
	std::cout << "  ";
	std::cout << "------------" << std::endl;
	std::cout << "   ";
	for (int x = 6; x < 9; x++)//display the third row of the gameboard
	{
		std::cout << gameBoardArray[x];
		if (x < 8)
		{
			cout << " | ";//print out the third two bars in the game board
		}
	}

	std::cout << std::endl;

};
void GameBoard::GameBoardUpdate(char input, int space) {

	switch (space + 1)
	{
	case 1:
		if (gameBoardArray[0] == ' ')
		{
			gameBoardArray[0] = input;
		}
		else
		{
			gameBoardArray[0] = ' ';
		};
		if (gameBoardArray[1] == ' ')
		{
			gameBoardArray[1] = input;

		}
		else
		{
			gameBoardArray[1] = ' ';
		};
		if (gameBoardArray[3] == ' ')
		{
			gameBoardArray[3] = input;
		}
		else
		{
			gameBoardArray[3] = ' ';
		};
		break;
	case 2:
		if (gameBoardArray[0] == ' ')
		{
			gameBoardArray[0] = input;
		}
		else
		{
			gameBoardArray[0] = ' ';
		};
		if (gameBoardArray[1] == ' ')
		{
			gameBoardArray[1] = input;
		}
		else
		{
			gameBoardArray[1] = ' ';
		};
		if (gameBoardArray[2] == ' ')
		{
			gameBoardArray[2] = input;
		}
		else
		{
			gameBoardArray[2] = ' ';
		};
		if (gameBoardArray[4] == ' ')
		{
			gameBoardArray[4] = input;
		}
		else
		{
			gameBoardArray[4] = ' ';
		};
		break;
	case 3:
		if (gameBoardArray[5] == ' ')
		{
			gameBoardArray[5] = input;
		}
		else
		{
			gameBoardArray[5] = ' ';
		};
		if (gameBoardArray[1] == ' ')
		{
			gameBoardArray[1] = input;
		}
		else
		{
			gameBoardArray[1] = ' ';
		};
		if (gameBoardArray[2] == ' ')
		{
			gameBoardArray[2] = input;
		}
		else
		{
			gameBoardArray[2] = ' ';
		};
		break;
	case 4:
		if (gameBoardArray[0] == ' ')
		{
			gameBoardArray[0] = input;
		}
		else
		{
			gameBoardArray[0] = ' ';
		};
		if (gameBoardArray[4] == ' ')
		{
			gameBoardArray[4] = input;
		}
		else
		{
			gameBoardArray[4] = ' ';
		};
		if (gameBoardArray[3] == ' ')
		{
			gameBoardArray[3] = input;
		}
		else
		{
			gameBoardArray[3] = ' ';
		};
		if (gameBoardArray[6] == ' ')
		{
			gameBoardArray[6] = input;
		}
		else
		{
			gameBoardArray[6] = ' ';
		};
		break;
	case 5:
		if (gameBoardArray[4] == ' ')
		{
			gameBoardArray[4] = input;
		}
		else
		{
			gameBoardArray[4] = ' ';
		};
		if (gameBoardArray[1] == ' ')
		{
			gameBoardArray[1] = input;
		}
		else
		{
			gameBoardArray[1] = ' ';
		};
		if (gameBoardArray[3] == ' ')
		{
			gameBoardArray[3] = input;
		}
		else
		{
			gameBoardArray[3] = ' ';
		};
		if (gameBoardArray[5] == ' ')
		{
			gameBoardArray[5] = input;
		}
		else
		{
			gameBoardArray[5] = ' ';
		};
		if (gameBoardArray[7] == ' ')
		{
			gameBoardArray[7] = input;
		}
		else
		{
			gameBoardArray[7] = ' ';
		};
		break;
	case 6:
		if (gameBoardArray[2] == ' ')
		{
			gameBoardArray[2] = input;
		}
		else
		{
			gameBoardArray[2] = ' ';
		};
		if (gameBoardArray[4] == ' ')
		{
			gameBoardArray[4] = input;
		}
		else
		{
			gameBoardArray[4] = ' ';
		};
		if (gameBoardArray[5] == ' ')
		{
			gameBoardArray[5] = input;
		}
		else
		{
			gameBoardArray[5] = ' ';
		};
		if (gameBoardArray[8] == ' ')
		{
			gameBoardArray[8] = input;
		}
		else
		{
			gameBoardArray[8] = ' ';
		};
		break;
	case 7:
		if (gameBoardArray[6] == ' ')
		{
			gameBoardArray[6] = input;
		}
		else
		{
			gameBoardArray[6] = ' ';
		};
		if (gameBoardArray[7] == ' ')
		{
			gameBoardArray[7] = input;
		}
		else
		{
			gameBoardArray[7] = ' ';
		};
		if (gameBoardArray[3] == ' ')
		{
			gameBoardArray[3] = input;
		}
		else
		{
			gameBoardArray[3] = ' ';
		};
		break;
	case 8:
		if (gameBoardArray[4] == ' ')
		{
			gameBoardArray[4] = input;
		}
		else
		{
			gameBoardArray[4] = ' ';
		};
		if (gameBoardArray[6] == ' ')
		{
			gameBoardArray[6] = input;
		}
		else
		{
			gameBoardArray[6] = ' ';
		};
		if (gameBoardArray[7] == ' ')
		{
			gameBoardArray[7] = input;
		}
		else
		{
			gameBoardArray[7] = ' ';
		};
		if (gameBoardArray[8] == ' ')
		{
			gameBoardArray[8] = input;
		}
		else
		{
			gameBoardArray[8] = ' ';
		};
		break;
	case 9:

		if (gameBoardArray[5] == ' ')
		{
			gameBoardArray[5] = input;
		}
		else
		{
			gameBoardArray[5] = ' ';
		};
		if (gameBoardArray[7] == ' ')
		{
			gameBoardArray[7] = input;
		}
		else
		{
			gameBoardArray[7] = ' ';
		};
		if (gameBoardArray[8] == ' ')
		{
			gameBoardArray[8] = input;
		}
		else
		{
			gameBoardArray[8] = ' ';
		};
		break;
	default:
		break;
	}
};
void GameBoard::GameBoardReset()
{
	for (int x = 0; x < 9; x++)//reset the array to blank spaces
	{
		this->gameBoardArray[x] = ' ';
	}

};
