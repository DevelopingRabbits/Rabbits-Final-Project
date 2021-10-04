#include "SUBMARINE.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Submarine::Submarine()
{
  isDark = true;
	choice = NULL;
	gameOver = false;


	enum class Location {TopSide, ControlRoom};
	Location location = Location::TopSide;
}


void Submarine::playGame()
{
	do
	{
		switch (location)
		{
		case Location::TopSide:
			topSide();
			break;
		case Location::ControlRoom:
			controlRoom();
			break;
		default:
			cout << "Game Error";
			break;
		}
	} while (gameOver == false);
};

void Submarine::controlRoom()
{
	switch (isDark)
	{
	case false:
	{
		cout << "\n\n*********************************LOCATION: CONTROL ROOM**********************************\n"
			<< "You notice water to drip from the open hatch above.\n"
			<< "*********************************LOCATION: CONTROL ROOM**********************************\n";

		cout << "You see: "
			<< "\n1. Hatch\n"
			<< "2. Computer Terminal\n"
			<< "Your Choice: ";
		cin >> choice;
		delay();

		switch (choice)
		{
		case 1:
			cout << "\nYou climb the ladder to go topside.\n";
			location = Location::TopSide;
			clearBuffer();
			break;
		case 2:
			clearBuffer();
			break;
		default:
			cout << "\nERROR: Invalid Choice.\n";
			clearBuffer();
			break;
		};
		break;
	}

	case true:
	{
		cout << "\n\n*********************************LOCATION: CONTROL ROOM**********************************\n"
			<< "The room is pitch black. The only light that enters the room is from the open hatch you just entered.\n"
			<< "You don't see much and only hear the faint sounds of gentle waves crashing topside of the submarine.\n"
			<< "*********************************LOCATION: CONTROL ROOM**********************************\n";

		cout << "You see: "
			<< "\n1. Hatch\n"
			<< "2. Battle Lantern\n"
			<< "Your Choice: ";
		cin >> choice;
		delay();


		switch (choice)
		{
		case 1:
			cout << "\nYou climb the ladder to go topside.\n";
			location = Location::TopSide;
			clearBuffer();
			break;
		case 2:
			cout << "\nYou pick up the battle lantern and turn it on.\n ****It illuminates the room.****\n";
			isDark = false;
			clearBuffer();
			break;
		default:
			cout << "\nERROR: Invalid Choice.\n";
			clearBuffer();
			break;
		};
		break;
	}
	};
};


void Submarine::topSide()
{
	cout << "\n\n************************************LOCATION: TOPSIDE************************************\n"
		<< "You are topside of the submarine. The weather outside is quite nice.\n"
		<< "The sea is calm and the sky is clear. The reflection of the sun glimmers.\n"
		<< "************************************LOCATION: TOPSIDE************************************\n";

	cout << "You see: \n1. Hatch\n"
	     << "Your Choice: ";

	cin >> choice;
	delay();

	switch (choice)
	{
	case 1:
		cout << "\nYou open the hatch and climb down the ladder.\n";
		cout << "You have entered the submarine...\n";
		location = Location::ControlRoom;
		clearBuffer();
		break;
	default:
		cout << "\nERROR: Invalid Choice.\n";
		clearBuffer();
	}
};


void Submarine::clearBuffer()
{
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
};




#include <Windows.h>
void Submarine::delay()
{
	for (int i = 0; i < 1; i++)
	{
		cout << i;
		Sleep(1000);
		system("cls");
	}
};