#include "TOPSIDE.h"
#include <iostream>
using namespace std;

TopSide::TopSide()
{
	bool surfaced = NULL;
	Location = "TopSide";

	adjacentRooms[0] = "Hatch";

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


//void TopSide::TopSideSurfaced()
//{
//	cout << "\n\n************************************LOCATION: TOPSIDE************************************\n"
//			<< "You are topside of the submarine. The weather outside is quite nice.\n"
//			<< "The sea is calm and the sky is clear. The reflection of the sun glimmers.\n"
//			<< "************************************LOCATION: TOPSIDE************************************\n";
//
//		cout << "You see: \n1. Hatch\n"
//			<< "Your Choice: ";
//};