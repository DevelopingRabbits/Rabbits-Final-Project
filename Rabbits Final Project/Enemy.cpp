#include "Enemy.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Enemy::Enemy()
{
    enemyHealth = 100;
    enemyName = "";
}

int Enemy::getEnemyHealth()
{
    return enemyHealth;
}

void Enemy::setEnemyHealth(int currentHealthPts)
{
    enemyHealth = currentHealthPts;
}

string Enemy::getEnemyType()
{
    return enemyName;
}

void Enemy::setEnemyType(string type)
{
    enemyName = type;
}

int Enemy::getEnemyLocationX()
{
    return enemyLocationX;
}

int Enemy::getEnemyLocationY()
{
    return enemyLocationY;
}

void Enemy::setEnemyLocation(int min, int max)
{
  srand(time(NULL));

  //Current method for setting the win cordinates. May be changed later to be randomly generated.
  enemyLocationX = rand() % 3 + 0;
  enemyLocationY = max;

  cout << enemyName << enemyLocationX << enemyLocationY << endl;
}