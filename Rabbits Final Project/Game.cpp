#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#include "Door.h"
#include "SUBMARINE.h"
#include "PLAYER.h"
#include "Room.h"
#include "Item.h"
#include "Game.h"

using namespace std;

Game::Game()
{
  gameOver = false;
};

void Game::createGame(Player &player, Submarine &sub)
{
	players = &player;
	submarine = &sub;
}

void Game::startGame()
{
	cout << "Start Game!\n\n";

};


void Game::getCurrentRoom()
{
// Retrieve room address
	room = submarine->getRoom(players->getPlayerRow(), players->getPlayerCol());

}

void Game::displayRoomDetails()
{
	getCurrentRoom();
	displayRoomDescription();
	displayDoors();
}

void Game::displayDoors()
{
	upDoor = room->getUpDoor();
	downDoor = room->getDownDoor();
	rightDoor = room->getRightDoor();
	leftDoor = room->getLeftDoor();

	cout << "You see the following doors:\n";
	cout << "1. " << upDoor->GetDoorName() << endl;
	cout << "2. " << leftDoor->GetDoorName() << endl;
	cout << "3. " << rightDoor->GetDoorName() << endl;
	cout << "4. " << downDoor->GetDoorName() << endl;
}

void Game::displayRoomDescription()
{
	for (int i = 0; i < 61; i++)
	{
		if (i == 30)
		{
			cout << room->getRoomName();
		}
		cout << "*";
	}
	cout << endl << room->getRoomDescription() << endl;
	for (int i = 0; i < 61; i++)
	{
		if (i == 30)
		{
			cout << room->getRoomName();
		}
		cout << "*";
	}
	cout << endl;
}

bool Game::getGameOver()
{
	return gameOver;
};

void Game::setGameOver(bool state)
{
	gameOver = state;
};


//bool Game::checkUserInput()
//{
//	switch (userInput)
//	{
//	case 1:
//		cout << "You chose to look at Items\n";
//		return true;
//		break;
//
//	case 2:
//		cout << "You chose to Move\n";
//		cout << "Which door would you like to go through?";
//		return true;
//		break;
//
//	case 3:
//		cout << "You chose to Interact with Inventory";
//		return true;
//		break;
//
//	default:
//		cout << "Invalid Option.\n";
//		return false;
//		break;
//	}
//}

void Game::setUserInput()
{
	userInputValid = false;
	do {
		cout << "Look for Items(1), Move(2) or Interact with Inventory(3)?: ";
		// Items or Move
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			break;

		case 2:
			moveFunction();
			userInputValid = true;
			break;

		case 3:
			cout << "You chose to Interact with Inventory";
			break;

		default:
			cout << "Invalid Option.\n";
			break;
		}
	} while (userInputValid == false);

};

void Game::moveFunction()
{
	cout << "You chose to Move\n";
	cout << "Which door would you like to go through?";
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		if (upDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow() - 1, players->getPlayerCol());
		}
		else
			cout << "I can't go this way.";
		break;
	case 2:
		if (leftDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow(), players->getPlayerCol() - 1);
		}
		else
			cout << "I can't go this way.";
		break;
	case 3:
		if (rightDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow(), players->getPlayerCol() + 1);
		}
		else
			cout << "I can't go this way.";
		break;
	case 4:
		if (downDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow() + 1, players->getPlayerCol());
		}
		else
			cout << "I can't go this way.";
		break;
	default:
		cout << "invalid";
	};
}

//
//int Game::getUserInput()
//{
//	return userInput;
//};