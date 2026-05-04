//
// Created by micsa on 30/04/2026.
//

#include "Bug.h"

bool Bug::isWayBlocked()
{
    if (direction == 1 && position.second == 0) return true;
    if (direction == 2 && position.first == 9) return true;
    if (direction == 3 && position.second == 9) return true;
    if (direction == 4 && position.first == 0) return true;
    return false;
}

void Bug::setEatenBy(int id)
{
    eatenBy = id;
}

void Bug::takeDamage(int damage)
{
    health -= damage;
    if (health <= 0)
    {
        health = 0;
        alive = false;
    }
}