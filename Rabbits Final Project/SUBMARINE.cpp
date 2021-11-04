#include "SUBMARINE.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

Submarine::Submarine()
{
	powerOn = false;
	surfaced = true;
	weaponSystem = false;//Should be set to false but is set to true till a weapon system room is implemented.
	subLocX = 0;
	subLocY = 0;

	submarineHealth = 100;
}

void Submarine::createSubmarine(Submarine &s)
{
	submarinePtr = &s;
}

void Submarine::addRoom(Room &newRoom, int newRoomRow, int newRoomCol)
{
	map[newRoomRow][newRoomCol] = &newRoom;
};

Room* Submarine::getRoom(int row, int col)
{
	return map[row][col];
}

bool Submarine::getSurfaced()
{
	return surfaced;
};

void Submarine::setSurfaced(bool state)
{
	surfaced = state;
};

bool Submarine::getPowerOn()
{
	return powerOn;
};

void Submarine::setPowerOn(bool state)
{
	powerOn = state;
};

int Submarine::getXSubLoc()
{
	return subLocX;
}

int Submarine::getYSubLoc()
{
	return subLocY;
}


void Submarine::setSubmarineLocation(int x, int y)
{
	subLocX = x;
	subLocY = y;
	
}

bool Submarine::getWeaponStatus()
{
	return weaponSystem;
}

void Submarine::setWeaponStatus(bool status)
{
	weaponSystem = status;
}