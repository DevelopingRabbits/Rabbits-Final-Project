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

	subLocX = 0;
	subLocY = 0;

	
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

int Submarine::getXCord()
{
	return subLocX;
}

int Submarine::getYCord()
{
	return subLocY;
}


void Submarine::setSubmarineLocation(int x, int y)
{
	subLocX = x;
	subLocY = y;
	
}
