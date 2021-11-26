#pragma once
#ifndef Enemy_h
#define Enemy_h
#include <string>
#include <iostream>
#include<iomanip>

using namespace std;


class Enemy
{
private:
    int enemyHealth;
    string enemyName;
    int enemyLocationX;
    int enemyLocationY;
    

public:
    Enemy();

    void createEnemy();

    int getEnemyHealth();
    void setEnemyHealth(int currentHealthPts);

    string getEnemyType();
    void setEnemyType(string type);

    int getEnemyLocationX();
    int getEnemyLocationY();
    void setEnemyLocation(int min, int max);
};
#endif // !Enemy_h
