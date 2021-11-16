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
#include "Enemy.h"



using namespace std;
// INIT Options
Game::Game()
{
  gameOver = false;
	cannotMoveMessage = "\n\nI can't go this way.\nI should try something else.\n\n\n";
	playerMovedMessage = "\n\nYou go through the ";
	
};


void Game::createGame(Player &playerArg, Submarine &sub, Game &gameArg, OceanMap &oceanarg, Enemy &enemyArg)
{
	player = &playerArg;
	submarine = &sub;
	game = &gameArg;
	ocean = &oceanarg;
	kraken = &enemyArg;
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
	cout << "\n\nYou see the following items.\n";
	cout << "1. " << item1->getItemName() << endl;
}
void Game::displayDoors()
{
	getRoomDoors();
	if (currentRoom->getIsDark() == false)
	{
		cout << "\n\nYou see the following doors:\n";
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
void Game::playerTurn(Game* gameArg)
{

	updatePlayer();
	updateRoom();
	displayRoomDetails();


	userInputValid = false;
	do {
		cout << "Do you want to:\n(1) Look for Items\n(2) Move\n(3) Inventory\n(4) Interact\n(5) Get Help\n(6) Quit\n";
		// Items or Move
		gameSystemsProgramming.yourChoiceMessage();
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
		case 5:
			getHelp();
			updateRoom();
			userInputValid = true;
			break;
		case 6:
			gameArg->setGameOver(true);
			userInputValid = true;
			cout << "The game has successfully shut down"<<endl;
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
		cout << "You chose to Look For Items\n\n";
		displayItems();
		gameSystemsProgramming.yourChoiceMessage();
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cout << "You picked up the " << item1->getItemName() << endl << endl;
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
	cout << "You chose to Move out of " << currentRoom->getRoomName() << endl << endl;
	cout << "Which door would you like to go through?\n";
	displayDoors();
	gameSystemsProgramming.yourChoiceMessage();
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
	cout << "You chose to Interact with Inventory\n\n";
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
		gameSystemsProgramming.yourChoiceMessage();
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
	
	int actionReturn;
	cout << "You chose to Interact with Room\n\n";
	switch (player->getCanSeeInDarkRoom())
	{
	case true:
		switch (currentRoom->getRoomActionItemsEmpty())
		{
		case(true):
			cout << "There is nothing to interact with.\n\n";
			break;
		case(false):
			displayRoomActionItems();
			cout << "Which item would you like to interact with?\n\n";
			gameSystemsProgramming.yourChoiceMessage();
			cin >> userInput;
			switch (userInput)
			{
			case 1:
				userInput -= 1;
				actionReturn=actionItems[userInput]->interactWithActionItem(player, submarine, actionItems[userInput], game);
				switch (actionReturn)
				{
					case 0001:
						break;
					case 9999:
						moveSubFunction();
						break;
					case 9997:
						playLightsOut();
						submarine->setWeaponStatus(true);
						break;
					default:
						break;
				}
				break;
			default:
				cout << "\n\n *********Unexpected Input in Game::interactWithRoom() **********\n\n";
			}
		}
		break;
	case false:
		cout << "\n\n It's too dark in this room. You don't see anything.\n\n";
		break;
	default:
		cout << "\n\n *********Unexpected Input in Game::interactWithRoom() **********\n\n";

	}
}

bool Game::playLightsOut()
{
	lightsOut.StartGame();
	return true;
}


void Game::moveSubFunction()
{
	/*
	* Moves the submarine through the ocean map.
	* The users choice is tested to see if it is an allowable move. 
	* If the move is out of bounds the move is not made.
	* After making a valid move, the new location is set, and the map is updated accordingly.
	* After each turn the map is displayed to the user.
	* 
	* After each move the game checks to see if the player has moved to the winning location
	* If the submarine is at the winning location, the game ends and the map is output one final time.
	*/

	
	do
	{
	cout << "\n\nYou chose to move the submarine\n\n";
	cout << "\n\nWhich direction would you like to move the submarine?\n\n";
	cout << "1. North" << endl;
	cout << "2. South" << endl;
	cout << "3. East" << endl;
	cout << "4. West" << endl;
	gameSystemsProgramming.yourChoiceMessage();
	cin >> userInput;
	switch (userInput)
	{
	case 1:
		if (submarine->getYSubLoc() + 1 > ocean->getMaxY())
		{
			cout << "WARNING!! Submarine can't travel into uncharted waters" << endl;
			break;
		}
	
		ocean->setSeenPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		submarine->setSubmarineLocation(submarine->getXSubLoc(), submarine->getYSubLoc() + 1);

		if (checkEnemyLocation() == true)
		{
			if (checkWeaponSystem() == false)
			{
				submarine->setSubmarineLocation(submarine->getXSubLoc(), submarine->getYSubLoc() - 1);
				ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
				break;
			}
		}

		if (checkEnemyLocation() == true)
		{
			enemyEncounter();
		}

		ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		displayCurrentSubLocation();
		
		
		

		break;
	case 2:
		if (submarine->getYSubLoc() - 1 < 0)
		{
			cout << "WARNING!! Submarine can't travel into uncharted waters" << endl;
			break;
		}
		ocean->setSeenPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		submarine->setSubmarineLocation(submarine->getXSubLoc(), submarine->getYSubLoc() - 1);

		if (checkEnemyLocation() == true)
		{
			if (checkWeaponSystem() == false)
			{
				submarine->setSubmarineLocation(submarine->getXSubLoc(), submarine->getYSubLoc() + 1);
				ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
				break;
			}
		}

		if (checkEnemyLocation() == true)
		{
			enemyEncounter();
		}

		ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		displayCurrentSubLocation();
		

		

		break;
	case 3:
		if (submarine->getXSubLoc() + 1 > ocean->getMaxX())
		{
			cout << "WARNING!! Submarine can't travel into uncharted waters" << endl;
			break;
		}
		ocean->setSeenPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		submarine->setSubmarineLocation(submarine->getXSubLoc() + 1, submarine->getYSubLoc());

		if (checkEnemyLocation() == true)
		{
			if (checkWeaponSystem() == false)
			{
				submarine->setSubmarineLocation(submarine->getXSubLoc()-1, submarine->getYSubLoc());
				ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
				break;
			}
		}

		if (checkEnemyLocation() == true)
		{
			enemyEncounter();
		}

		ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		displayCurrentSubLocation();
		
		
	
		break;
	case 4:
		if (submarine->getXSubLoc() - 1 < 0)
		{
			cout << "WARNING!! Submarine can't travel into uncharted waters" << endl;
			break;
		}
		ocean->setSeenPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		submarine->setSubmarineLocation(submarine->getXSubLoc()-1, submarine->getYSubLoc());

		if (checkEnemyLocation() == true)
		{
			if (checkWeaponSystem() == false)
			{
				submarine->setSubmarineLocation(submarine->getXSubLoc()+1, submarine->getYSubLoc());
				ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
				break;
			}
		}

		if (checkEnemyLocation() == true)
		{
			enemyEncounter();
		}

		ocean->setSubPosition(submarine->getXSubLoc(), submarine->getYSubLoc());
		displayCurrentSubLocation();
		
	

		break;
	default:
		cout << "invalid";
		getCurrentRoom();
	}	

	if (checkSubWin() == true)
	{

		setGameOver(true);
		userInput = 2;
		break;
	}
	ocean->displayOceanMap();
	cout << "Would you like to move the submarine again?\n\n";
	cout << "(1) Yes! Full Speed Ahead!\n(2) No! Take me back to the control room.\n";
	cin >> userInput;
} while (userInput == 1);
}

void Game::displayCurrentSubLocation()
{
	cout << "The submarine is now located at: (" << submarine->getXSubLoc() << "," << submarine->getYSubLoc() << ")" << endl;

}

bool Game::checkSubWin()
{
	
	if (submarine->getYSubLoc() == ocean->getWinY() && submarine->getXSubLoc() == ocean->getWinX())
	{
		cout << "You have naviagated the sub to the winning location. Congrats!" << endl;
		return true;
	}
	else
	{
		return false;
	}
	
	
}


void Game::getHelp()
{
	cout << "HELP MENU" << endl;
	cout << "Select what you would like to get help with:" << endl;
	cout << "1. How to move between rooms." << endl;
	cout << "2. How to see your inventory." << endl;
	cout << "0. Quit Help." << endl;
	gameSystemsProgramming.yourChoiceMessage();
	cin >> userInput;
	switch (userInput)
	{
	case 0:
			cout << endl;
			cout << "Selected Exit." << endl;
			cout << "If you still need help just hit the help option again!" << endl;
		break;

	case 1:
			cout << endl;
			cout << "Selected How To Move Between Rooms" << endl;
			cout << "To move inbetween rooms you need to use the numbers that are provided on your screen for example: 1,2,3,4. By doing this you travel from each room that is selected" << endl;
		break;

	case 2:
			cout << endl;
			cout << "Selected How to View Inventory" << endl;
			cout << "To see your inventory select 3, when you select 3 you can view what is in your inventory and interact with the items" << endl;
		break;

	default:
		cout << "Invalid Option /n";
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

void Game::enemyEncounter()
{
	cout << "Captain! There is a " << kraken->getEnemyType() << "! Set General Quarters! Man your BATTLE STATION!" << endl;
	enemyHealth = kraken->getEnemyHealth();
	system("Pause");
	do
	{
		system("CLS");
		cout << "----------------------------------\n"
			<< "\tEnemy: " << kraken->getEnemyType() << endl << "\tHP: " << kraken->getEnemyHealth() << endl
			<< "----------------------------------\n\n"
			<< "***************WEAPON SYSTEM TERMINAL***************" << endl
			<< "1. Deploy Heat-Seeking Torpedos" << endl
			<< "2. Deploy Dummy Torpedos" << endl
			<< "3. Deploy Laser Railgun" << endl
			<< "4. Evasive Maneuvers" << endl
			<< "Your Choice: ";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			attackDamage = rand() % 10 + 6; // Low Damage, but high percentage to hit.
			hitChance = rand() % 100; // Any number 80 or below will do damage.
			if (hitChance <= 80)
			{
				enemyHealth -= attackDamage;
				kraken->setEnemyHealth(enemyHealth);
				//DO DAMAGE
				cout << "SUCCESS! Your Heat-Seeking Torpedos did " << attackDamage << " damage!\n";
			}
			else
			{
				cout << "FAIL! Your attack missed! No damage inflicted!\n";
			}
			system("Pause");
			break;
			// Deploy Heat-Seeking Torpedos
		case 2:
			attackDamage = rand() % 25 + 20; // Big Damage, but low percentage to hit.
			hitChance = rand() % 100; // Any number 40 or below will do damage.
			if (hitChance <= 40)
			{
				enemyHealth -= attackDamage;
				kraken->setEnemyHealth(enemyHealth);
				//DO DAMAGE
				cout << "SUCCESS! Your Dummy Torpedos did " << attackDamage << " damage!\n";
			}
			else
			{
				cout << "FAIL! Your attack missed! No damage inflicted!\n";
			}
			system("Pause");
			break;
			// Deploy Dummy Torpedos
		case 3:
			attackDamage = rand() % 8; // Constantly does 8 damage, very accurate.
			hitChance = rand() % 100; // Any number 90 or below will do damage.
			if (hitChance <= 90)
			{
				enemyHealth -= attackDamage;
				kraken->setEnemyHealth(enemyHealth);
				//DO DAMAGE
				cout << "SUCCESS! Your Laser Railgun did " << attackDamage << " damage!\n";
			}
			else
			{
				cout << "FAIL! Your attack missed! No damage inflicted!\n";
			}
			system("Pause");
			break;
			// Deploy Laser Railgun
		case 4:
			evasiveChance = rand() % 3; // 25% chance that enemy will miss.
			if (evasiveChance == 1)
			{
				cout << "SUCCESS! You evaded the " << kraken->getEnemyType() << " and have tactical advantage!\n";
				do {
					system("Pause");
					system("CLS");
					cout << "Extra Attack for Successful Evasion!\n";
					cout << "----------------------------------\n"
						<< "\tEnemy: " << kraken->getEnemyType() << endl << "\tHP: " << kraken->getEnemyHealth() << endl
						<< "----------------------------------\n\n"
						<< "***************WEAPON SYSTEM TERMINAL***************" << endl
						<< "1. Deploy Heat-Seeking Torpedos" << endl
						<< "2. Deploy Dummy Torpedos" << endl
						<< "3. Deploy Laser Railgun" << endl
						<< "Your Choice: ";
					cin >> userInput;
					switch (userInput)
					{
					case 1:
						attackDamage = rand() % 10 + 6; // Low Damage, but high percentage to hit.
						hitChance = rand() % 100; // Any number 80 or below will do damage.
						if (hitChance <= 80)
						{
							enemyHealth -= attackDamage;
							kraken->setEnemyHealth(enemyHealth);
							//DO DAMAGE
							cout << "SUCCESS! Your Heat-Seeking Torpedos did " << attackDamage << " damage!\n";
						}
						else
						{
							cout << "FAIL! Your attack missed! No damage inflicted!\n";
						}
						system("Pause");
						userInputValid = true;
						break;
						// Deploy Heat-Seeking Torpedos
					case 2:
						attackDamage = rand() % 25 + 20; // Big Damage, but low percentage to hit.
						hitChance = rand() % 100; // Any number 40 or below will do damage.
						if (hitChance <= 40)
						{
							enemyHealth -= attackDamage;
							kraken->setEnemyHealth(enemyHealth);
							//DO DAMAGE
							cout << "SUCCESS! Your Dummy Torpedos did " << attackDamage << " damage!\n";
						}
						else
						{
							cout << "FAIL! Your attack missed! No damage inflicted!\n";
						}
						system("Pause");
						userInputValid = true;
						break;
						// Deploy Dummy Torpedos
					case 3:
						attackDamage = rand() % 8; // Constantly does 8 damage, very accurate.
						hitChance = rand() % 100; // Any number 90 or below will do damage.
						if (hitChance <= 90)
						{
							enemyHealth -= attackDamage;
							kraken->setEnemyHealth(enemyHealth);
							//DO DAMAGE
							cout << "SUCCESS! Your Laser Railgun did " << attackDamage << " damage!\n";
						}
						else
						{
							cout << "FAIL! Your attack missed! No damage inflicted!\n";
						}
						system("Pause");
						userInputValid = true;
						break;
						// Deploy Laser Railgun
					default:
						cout << "Invalid Input!\n";
						userInputValid = false;
					}
				} while (userInputValid == false);
			}
			else
			{
				cout << "Evasion unsuccessful!\n";
				system("Pause");
				break;
			}
			break;
			// Evasive Maneuvers
		default:
			cout << "Invalid Input!\n";
			system("Pause");
		}
	} while (kraken->getEnemyHealth() > 0);
}

bool Game::checkWeaponSystem()
{	
	if (submarine->getWeaponStatus() == false)
	{
		cout << "The weapons systems are currently offline and there seems to be something dangerous ahead." << endl;
		cout << "Turn on the weapons system to progress to this area." << endl;
		return false;
		
	}
	else
	{
		return true;
	}

	

}

bool Game::checkEnemyLocation()
{

	if (kraken->getEnemyLocationX() == submarine->getXSubLoc() && kraken->getEnemyLocationY() == submarine->getYSubLoc())
	{
		return true;
	}
	else
	{
		return false;
	}

}



