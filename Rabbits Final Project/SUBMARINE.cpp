#include "SUBMARINE.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Submarine::Submarine()
{
  isDark = false;
  isSurfaced = true;
	choice = NULL;
	gameOver = false;
	enum class Location {TopSide, ControlRoom};
	Location location = Location::TopSide;
}


void Submarine::playerLocation()
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
	cout << "\n\n*********************************LOCATION: CONTROL ROOM**********************************\n"
		<< "The room is pitch black. The only light that enters the room is from the open hatch you just entered.\n"
		<< "You don't see much and only hear the faint sounds of gentle waves crashing topside of the submarine.\n"
		<< "*********************************LOCATION: CONTROL ROOM**********************************\n";

	cout << "You see: "
		   << "\n1. Hatch\n"
			 << "2. Battle Lantern\n"
			 << "Your Choice: ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		cout << "You climb the ladder to go topside.\n";
		location = Location::TopSide;
		clearBuffer();
		break;
	case 2:
		cout << "You pick up the battle lantern\n";
		clearBuffer();
	default:
		cout << "Invalid Choice.";
		clearBuffer();
	}
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

	switch (choice)
	{
	case 1:
		cout << "You open the hatch and climb down the ladder.\n";
		cout << "You have entered the submarine...\n";
		location = Location::ControlRoom;
		clearBuffer();
		break;
	default:
		cout << "Invalid Choice.";
		clearBuffer();
	}
};


void Submarine::clearBuffer()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
};