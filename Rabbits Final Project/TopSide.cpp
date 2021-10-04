#include "TOPSIDE.h"
#include <iostream>
using namespace std;

TopSide::TopSide()
{
	bool surfaced = NULL;
};


void TopSide::CheckSubSurfaced(bool state)
{
	surfaced = state;
};

void TopSide::TopSideSurfaced()
{
	cout << "\n\n************************************LOCATION: TOPSIDE************************************\n"
			<< "You are topside of the submarine. The weather outside is quite nice.\n"
			<< "The sea is calm and the sky is clear. The reflection of the sun glimmers.\n"
			<< "************************************LOCATION: TOPSIDE************************************\n";

		cout << "You see: \n1. Hatch\n"
			<< "Your Choice: ";
};