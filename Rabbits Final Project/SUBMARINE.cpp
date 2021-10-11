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
