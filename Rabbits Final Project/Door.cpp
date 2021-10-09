#include "Door.h"
using namespace std;



Door::Door() 
{  
}

void Door::SetDoorName(string name)
{
  doorName = name;
}
void Door::DisplayDoor()
{
  cout << doorName << endl;
}