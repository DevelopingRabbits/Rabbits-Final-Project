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
#include "OceanMap.h"


using namespace std;
// INIT Options
Game::Game()
{
  gameOver = false;
	cannotMoveMessage = "\n\nI can't go this way.\nI should try something else.\n\n\n";
	playerMovedMessage = "\n\nYou go through the ";
};
void Game::createGame(Player &playerArg, Submarine &sub)
{
	player = &playerArg;
	submarine = &sub;
}
void Game::startGame()
{
	cout << "\nWelcome to a Developing Rabbits Production!\n\n";
	cout << "Start Game!\n\n";
	cout << "What is your name? ";
	cin >> stringUserInput;
	
	stringUserInput=gameSystemsProgramming.stringInputValidation(stringUserInput);
	player->setName(stringUserInput);
	cout << "\nWelcome Aboard Captain " << player->getName() << endl << endl;
};

// Set Options
void Game::setGameOver(bool state)
{
	gameOver = state;
};

// Get Options
void Game::getCurrentRoom()
{
// Retrieve room address
	currentRoom = submarine->getRoom(player->getPlayerRow(), player->getPlayerCol());

}
void Game::getRoomInventory()
{
	item1 = currentRoom->getRoomInventory();
}
void Game::getRoomDoors()
{
	upDoor = currentRoom->getUpDoor();
	downDoor = currentRoom->getDownDoor();
	rightDoor = currentRoom->getRightDoor();
	leftDoor = currentRoom->getLeftDoor();
}
bool Game::getGameOver()
{
	return gameOver;
};

// Display Options
void Game::displayRoomDetails()
{
	getCurrentRoom();
	displayRoomDescription();
}
void Game::displayPlayerInventory()
{
	playerInventorySize = player->getInvetorySize();
	inventory.clear();
	cout << "\n\nYou have the following items:\n\n";
	for (int i = 0; i < playerInventorySize; i++)
	{
		int x = i + 1;
		inventory.push_back(player->getInventory(i));
		cout << "(" << x << ") " << inventory[i]->getItemName() << endl;
	}
}

void Game::displayRoomActionItems()
{
	roomActionItemsSize = currentRoom->getActionItemsSize();
	actionItems.clear();
	cout << "\n\nYou see the following items:\n\n";
	for (int i = 0; i < roomActionItemsSize; i++)
	{
		int x = i + 1;
		actionItems.push_back(currentRoom->getRoomActionItems(i));
		cout << "(" << x << ") " << actionItems[i]->getItemName() << endl;
	}
}
void Game::displayItems()
{
	getRoomInventory();
	cout << "You see the following items.\n";
	cout << "1. " << item1->getItemName() << endl;
}
void Game::displayDoors()
{
	getRoomDoors();
	if (currentRoom->getIsDark() == false)
	{
		cout << "You see the following doors:\n";
		cout << "1. " << upDoor->GetDoorName() << endl;
		cout << "2. " << leftDoor->GetDoorName() << endl;
		cout << "3. " << rightDoor->GetDoorName() << endl;
		cout << "4. " << downDoor->GetDoorName() << endl;
	}
	else
	{
		if (currentRoom->getRoomID() == 1)
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
			cout << currentRoom->getRoomName();
		}
		cout << "*";
	}
	cout << endl << currentRoom->getRoomDescription() << endl;
	for (int i = 0; i < 61; i++)
	{
		if (i == 30)
		{
			cout << currentRoom->getRoomName();
		}
		cout << "*";
	}
	cout << endl;
}

// Player Turn
void Game::playerTurn()
{

	updatePlayer();
	updateRoom();
	displayRoomDetails();
	userInputValid = false;
	do {
		cout << "Do you want to:\n(1) Look for Items\n(2) Move\n(3) Inventory\n(4) Interact\n";
		// Items or Move
		cin >> userInput;
		userInput=gameSystemsProgramming.integerInputValidation(userInput);
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
		case 4:
			interactWithRoom();
			updateRoom();
			userInputValid = true;
			break;

		default:
			cout << "Invalid Option. The program is currently in Game::playerTurn()\n";
			break;
		}
	} while (userInputValid == false);

};

// Player Options
void Game::lookForItems()
{
	switch (currentRoom->getRoomEmpty())
	{
	case false:
		cout << "You chose to Look For Items\n";
		displayItems();
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cout << "You picked up the " << item1->getItemName() << endl;
			player->addToInventory(item1->getItemPtr());
			currentRoom->removeItem();
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
void Game::moveFunction()
{
	cout << "\n\nYou chose to Move\n\n";
	cout << "\n\nWhich door would you like to go through?\n\n";
	displayDoors();
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		if (upDoor->getIsOpen() == true)
		{
			player->setPlayerLocation(player->getPlayerRow() - 1, player->getPlayerCol());
			cout << playerMovedMessage << upDoor->GetDoorName() << endl << endl;;
		}
		else
			cout << cannotMoveMessage;
		break;
	case 2:
		if (leftDoor->getIsOpen() == true)
		{
			player->setPlayerLocation(player->getPlayerRow(), player->getPlayerCol() - 1);
			cout << playerMovedMessage << leftDoor->GetDoorName() << endl << endl;;
		}
		else
			cout << cannotMoveMessage;
		break;
	case 3:
		if (rightDoor->getIsOpen() == true)
		{
			player->setPlayerLocation(player->getPlayerRow(), player->getPlayerCol() + 1);
			cout << playerMovedMessage << rightDoor->GetDoorName() << endl << endl;;
		}
		else
			cout << cannotMoveMessage;
		break;
	case 4:
		if (downDoor->getIsOpen() == true)
		{
			player->setPlayerLocation(player->getPlayerRow() + 1, player->getPlayerCol());
			cout << playerMovedMessage << downDoor->GetDoorName() << endl << endl;
		}
		else
			cout << cannotMoveMessage;
		break;
	default:
		cout << "invalid";
		getCurrentRoom();
	};
}
void Game::interactWithInventory()
{
	cout << "\n\n You chose to Interact with Inventory\n\n";
	switch (player->getInventoryEmpty())
	{
	case true:
	{
		cout << "\n\nYour inventory is empty.\n\n";
		break;
	}
	case false:
	{
		displayPlayerInventory();
		cout << "\n\nWhich item would you like to use?\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			userInput -= 1;
			inventory[userInput]->interactWithItem(player);
			break;
		case 2:
			userInput -= 1;
			inventory[userInput]->interactWithItem(player);
			break;
		default:
			cout << "\n\n*********Unexpected Input in Game::interactWithInventory()**********\n\n";
			break;
		}
	}
	break;
	}
}
void Game::interactWithRoom()
{
	cout << "\nYou chose to Interact with Room\n\n";
	switch (currentRoom->getRoomActionItemsEmpty())
	{
	case(true):
		cout << "\nThere is nothing to interact with.\n\n";
		break;
	case(false):
		displayRoomActionItems();
		cout << "\n\nWhich item would you like to interact with?\n\n";
		cin >> userInput;

		switch (userInput)
		{
		case 1:
			moveSubFunction();
			if (checkSubWin() == true)
			{
				exit;
			}
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}
}




void Game::moveSubFunction()
{
	cout << "\n\nYou chose to move the submarine\n\n";
	cout << "\n\nWhich direction would you like to move the submarine?\n\n";
	cout << "1. North" << endl;
	cout << "2. South" << endl;
	cout << "3. East" << endl;
	cout << "4. West" << endl;
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		if (submarine->getYCord() + 1 > ocean->getMaxY())
		{
			cout << "The submarine cannot travel any further in this direciton" << endl;
			break;
		}
		submarine->setSubmarineLocation(submarine->getXCord(), submarine->getYCord() + 1);
		displayCurrentSubLocation();
		break;
	case 2:
		if (submarine->getYCord() - 1 < 0)
		{
			cout << "The submarine cannot travel any further in this direciton" << endl;
			break;
		}
		submarine->setSubmarineLocation(submarine->getXCord(), submarine->getYCord() - 1);
		displayCurrentSubLocation();
		break;
	case 3:
		if (submarine->getXCord() + 1 > ocean->getMaxX())
		{
			cout << "The submarine cannot travel any further in this direciton" << endl;
			break;
		}
		submarine->setSubmarineLocation(submarine->getXCord() + 1, submarine->getYCord());
		displayCurrentSubLocation();
		break;
	case 4:
		if (submarine->getXCord() - 1 < 0)
		{
			cout << "The submarine cannot travel any further in this direciton" << endl;
			break;
		}
		submarine->setSubmarineLocation(submarine->getXCord()-1, submarine->getYCord());
		displayCurrentSubLocation();
		break;
	default:
		cout << "invalid";
		getCurrentRoom();
	};
}

void Game::displayCurrentSubLocation()
{
	cout << "The submarine is now located at: (" << submarine->getXCord() << "," << submarine->getYCord() << ")" << endl;

}

bool Game::checkSubWin()
{
	
	if (submarine->getXCord() == ocean->getWinX() && submarine->getXCord() == ocean->getWinY())
	{
		cout << "You have naviagated the sub to the winning location. Congrats!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}


// Update Options
void Game::updateRoom()
{
	getCurrentRoom();
	if (currentRoom->getRoomID() != 0)
	{
		switch (submarine->getPowerOn())
		{
		case true:
			currentRoom->setIsDark(false);
			break;
		case false:
			currentRoom->setIsDark(true);
			break;
		}
		switch (player->getCanSeeInDarkRoom())
		{
		case true:
			currentRoom->setIsDark(false);
			break;
		case false:
			currentRoom->setIsDark(true);
			break;
		}
	}
}
void Game::updatePlayer()
{
	player->setInventoryEmpty();

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