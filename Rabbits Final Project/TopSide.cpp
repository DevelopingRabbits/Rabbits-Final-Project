#include "TOPSIDE.h"
#include <iostream>
using namespace std;

TopSide::TopSide()
{
	bool surfaced = NULL;
	battleLanternAvailable = true;
	Location = "TopSide";
	adjacentRooms[0] = "Hatch";

};

void TopSide::setSurfaced(bool state)
{
	surfaced = state;
};

void TopSide::CheckSubSurfaced(bool state)
{
	surfaced = state;
};

string TopSide::getLocation()
{
	return Location;
}

string* TopSide::getAdjacentRooms()
{
	return adjacentRooms;
}

int TopSide::getRoomAmount()
{
	return ADJACENTROOMS;
}

bool TopSide::getBattleLantern()
{
	battleLanternAvailable = false;
	return true;
}

int TopSide::playScenario()
{
	cout << "\n\n************************************LOCATION: TOPSIDE************************************\n"
		<< "You are topside of the submarine. The weather outside is quite nice.\n"
		<< "The sea is calm and the sky is clear. The reflection of the sun glimmers.\n"
		<< "************************************LOCATION: TOPSIDE************************************\n"
	  << "You see: \n1. Hatch\n";
	if (battleLanternAvailable == true) 
	{
		cout << "2. Battle lantern\n"
			<< "Your Choice: ";
	}
	else
	{
		cout << "Your Choice: ";
	}
	cin >> playerChoice;
		switch (playerChoice)
		{
		case 1:
			return 1;
			// changePlayerLocation;
		case 2:
			if (battleLanternAvailable == true)
			{
				cout << "You pick up the battle lantern.";
			}
			else
			{
				cout << "Invalid Input";
			}
			return 0; //player does not change locations. stays topside.

		default:
			cout << "Game Error";
		}
};