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
	cannotMoveMessage = "\n\nI can't go this way.\nI should try something else.\n\n\n";
	playerMovedMessage = "\n\nI go through the door\n\n\n";
};

void Game::createGame(Player &player, Submarine &sub)
{
	players = &player;
	submarine = &sub;
}

void Game::startGame()
{
	cout << "\nWelcome to a Developing Rabbits Production!\n\n";
	cout << "Start Game!\n\n";
	cout << "What is your name? ";
	cin >> stringUserInput;
	players->setName(stringUserInput);
	cout << "\nWelcome Aboard Captain " << players->getName() << endl << endl;
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
}

void Game::getRoomInventory()
{
	item1 = room->getRoomInventory();
}

void Game::displayItems()
{
	getRoomInventory();
	cout << "You see the following items.\n";
	cout << "1. " << item1->getItemName() << endl;
}

void Game::getRoomDoors()
{
	upDoor = room->getUpDoor();
	downDoor = room->getDownDoor();
	rightDoor = room->getRightDoor();
	leftDoor = room->getLeftDoor();
}

void Game::displayDoors()
{
	getRoomDoors();
	if (room->getIsDark() == false)
	{
		cout << "You see the following doors:\n";
		cout << "1. " << upDoor->GetDoorName() << endl;
		cout << "2. " << leftDoor->GetDoorName() << endl;
		cout << "3. " << rightDoor->GetDoorName() << endl;
		cout << "4. " << downDoor->GetDoorName() << endl;
	}
	else
	{
		if (room->getRoomID() == 1)
		{
			cout << "You see the following doors:\n";
			cout << "1. " << upDoor->GetDoorName() << endl;
		}
		else
		{
			cout << "I can't see.\n";
		}
	}
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

void Game::playerTurn()
{
	updatePlayer();
	updateRoom();
	userInputValid = false;
	do {
		cout << "Do you want to:\n(1) Look for Items\n(2) Move\n(3) Inventory\n ";
		// Items or Move
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			lookForItems();
			updateRoom();
			userInputValid = true;
			break;

		case 2:
			moveFunction();
			updateRoom();
			userInputValid = true;
			break;

		case 3:
			interactWithInventory();
			updateRoom();
			userInputValid = true;
			break;

		default:
			cout << "Invalid Option.\n";
			break;
		}
	} while (userInputValid == false);

};

void Game::getPlayerInventory()
{
	item1 = players->getInventory();
}

void Game::displayPlayerInventory()
{
	cout << "You have the following items:\n";
	cout << "1. " << item1->getItemName()<< endl;
}

void Game::interactWithInventory()
{
	cout << "\n\n You chose to Interact with Inventory\n\n";
	switch (players->getInventoryEmpty())
	{
		case true:
		{
			cout << "\n\nYour inventory is empty.\n\n";
			break;
		}
		case false:
		{
			displayPlayerInventory();
			cout << "\n\n Which item would you like to use?\n";
			cin >> userInput;
			switch (userInput)
			{
			case 1:
				item1->interactWithItem(players);
				break;
			default:
				cout << "\n\n*********Unexpected Input in Game::interactWithInventory()**********\n\n";
				break;
			}
		}
		break;
	}
}

void Game::moveFunction()
{
	cout << "You chose to Move\n";
	cout << "Which door would you like to go through?\n";
	displayDoors();
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		if (upDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow() - 1, players->getPlayerCol());
			cout << playerMovedMessage;
		}
		else
			cout << cannotMoveMessage;
		break;
	case 2:
		if (leftDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow(), players->getPlayerCol() - 1);
			cout << playerMovedMessage;
		}
		else
			cout << cannotMoveMessage;
		break;
	case 3:
		if (rightDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow(), players->getPlayerCol() + 1);
			cout << playerMovedMessage;
		}
		else
			cout << cannotMoveMessage;
		break;
	case 4:
		if (downDoor->getIsOpen() == true)
		{
			players->setPlayerLocation(players->getPlayerRow() + 1, players->getPlayerCol());
			cout << playerMovedMessage;
		}
		else
			cout << cannotMoveMessage;
		break;
	default:
		cout << "invalid";
		getCurrentRoom();
	};
}

void Game::lookForItems()
{
	switch (room->getRoomEmpty())
	{
	case false:
		cout << "You chose to Look For Items\n";
		displayItems();
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cout << "You picked up the " << item1->getItemName() << endl;
			players->addToInventory(item1->getItemPtr());
			room->removeItem();
			break;
		default:
			cout << "Error in Game::lookForItems()";
		}
		break;
	case true:
		cout << "You don't see any items.\n\n";
		break;
	default:
		cout << "Error in Game::LookForItems";
		break;
	}
}

void Game::updateRoom()
{
	getCurrentRoom();
	if (room->getRoomID() != 0)
	{
		switch (submarine->getPowerOn())
		{
		case true:
			room->setIsDark(false);
			break;
		case false:
			room->setIsDark(true);
			break;
		}
		switch (players->getCanSeeInDarkRoom())
		{
		case true:
			room->setIsDark(false);
			break;
		case false:
			room->setIsDark(true);
			break;
		}
	}
}

void Game::updatePlayer()
{
	players->setInventoryEmpty();

}


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
//
//int Game::getUserInput()
//{
//	return userInput;
//};