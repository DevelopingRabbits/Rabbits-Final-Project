#include "SUBMARINE.h"
#include <iostream>
#include <string>
using namespace std;

Submarine::Submarine()
{
  isDark = false;
  isSurfaced = true;
	choice = NULL;

}

void Submarine::topSide()
{
	cout << "******************************************************************\n"
		<< "You are topside of the submarine. The weather outside is quite nice.\n"
		<< "The sea is calm and the sky is clear. The reflection of the sun glimmers.\n"
		<< "******************************************************************\n";

	cout << "You see: \n1. Hatch\n";

	cout << "Your Choice: ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		cout << "You open the hatch and climb down the ladder.\n";
		cout << "You have entered the submarine...\n";
		break;
	default:
		cout << "Invalid Choice.";
	}
};