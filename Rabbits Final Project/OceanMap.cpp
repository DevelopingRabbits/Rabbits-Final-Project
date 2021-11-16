#include "OceanMap.h"
#include"Room.h"
#include"SUBMARINE.h"

#include <iostream>
#include<iomanip>

using namespace std;


OceanMap::OceanMap()
{
    //Current method for setting the win cordinates. May be changed later to be randomly generated.
    winXOcean = 0;
    winYOcean = 1;
    
    //Traverse the entire 2d array and set each value to an unseen(+) value.
    for (int i = 0; i < mapSizeY; i++)
    {
        for(int j = 0; j < mapSizeX; j++)
        {

        oceanMapArray[j][i] = '+';
        
        
        }  
        
    }
    
    //By default the winning location is not accesible to the player
    winLocationLocked = true;
}

void OceanMap::displayOceanMap()
{
  /*
  * Dynamically output the 2d array
  * 
  * Through this function the ocean map is displayed to the user in a grid
  * Using the for loops allows for the map size to be changed without requiring for the output to be changed
  * If the map size is changed, the output will cleanly reflect that change.
  
  */
    int count = 0;
   
    cout << "=";
    for (int k = 0; k < mapSizeX; k++)
    {
        cout << "======";
    }
    cout <<"="<< endl;
    for (int i = mapSizeY-1; i >=0; i--)
    {
        cout << "|  ";
        for (int j = 0; j < mapSizeX; j++)
        {
            cout << oceanMapArray[j][i] << "  |  ";
            
        }
        cout << endl;
        count++;
        if (count <= mapSizeY)
        {
            
            cout << "=";
            for (int k = 0; k < mapSizeX; k++)
            {
                cout << "======";
            }
            cout << "=" << endl;
        }
        
        
        
    }
    cout << "=";
    for (int k = 0; k <= mapSizeX; k++)
    {
        cout << "======";
    }
    cout << "=" << endl;
}
   

void OceanMap::setWinX()
{
   //For later use. To possible set the win cordinate randomly.
}

void OceanMap::setWinY()
{
   //For later use. To possible set the win cordinate randomly.
}

void OceanMap::setSeenPosition(int x, int y)
{
    //cordinates that have been visited are marked by a blank space
    oceanMapArray[x][y] = ' ';
}

void OceanMap::setSubPosition(int x, int y)
{
    //The current space the submarine is on is marked by an @ symbol
    oceanMapArray[x][y] = '@';
}

int OceanMap::getWinX()
{
    
    
   return winXOcean;
}

int OceanMap::getWinY()
{
    
  return winYOcean;
    
}

int OceanMap::getMaxX()
{
   
    return mapSizeX-1;
}

int OceanMap::getMaxY()
{
    
    return mapSizeY-1;
}

bool OceanMap::getWinLocLocked()
{
    return winLocationLocked;
}

void OceanMap::setWinLocLocked(bool flag)
{
    winLocationLocked = flag;
}
