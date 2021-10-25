#include "OceanMap.h"
#include"Room.h"
#include"SUBMARINE.h"

#include <iostream>
#include<iomanip>

using namespace std;


OceanMap::OceanMap()
{
    winXOcean = 0;
    winYOcean = 1;
    

    for (int i = 0; i < mapSizeY; i++)
    {
        for(int j = 0; j < mapSizeX; j++)
        {

        oceanMapArray[j][i] = '+';
        
        
        }  
        
    }
    
}

void OceanMap::displayOceanMap()
{
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
   
}

void OceanMap::setWinY()
{
    
}

void OceanMap::setSeenPosition(int x, int y)
{
    oceanMapArray[x][y] = ' ';
}

void OceanMap::setSubPosition(int x, int y)
{
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
   
    return mapSizeX;
}

int OceanMap::getMaxY()
{
    
    return mapSizeY;
}

