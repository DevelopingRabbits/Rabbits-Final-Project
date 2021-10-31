#include "Enemy.h"
#include <iostream>
#include<iomanip>

using namespace std;

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
    return enemyType;
}

void Enemy::setEnemyType(string type)
{
    enemyType = type;
}

int Enemy::getEnemyLocationX()
{
    return enemyLocationX;
}

int Enemy::getEnemyLocationY()
{
    return enemyLocationY;
}

void Enemy::setEnemyLocation(int x, int y)
{
    enemyLocationX = x;
    enemyLocationY = y;
}