//
// Created by micsa on 30/04/2026.
//

#include "Hopper.h"
using namespace std;

Hopper::Hopper(int id, int x, int y, int direction, int health, int hopLength)
{
    this->id = id;
    this->position = {x, y};
    this->direction = direction;
    this->health = health;
    this->alive = true;
    this->hopLength = hopLength;
    this->path.push_back(this->position);
}

void Hopper::move()
{
    while (isWayBlocked())
    {
        direction = rand() % 4 + 1;
    }

    if (direction == 1)
    {
        position.second = (position.second - hopLength < 0) ? 0 : position.second - hopLength;
    }
    else if (direction == 2)
    {
        position.first = (position.first + hopLength > 9) ? 9 : position.first + hopLength;
    }
    else if (direction == 3)
    {
        position.second = (position.second + hopLength > 9) ? 9 : position.second + hopLength;
    }
    else
    {
        position.first = (position.first - hopLength < 0) ? 0 : position.first - hopLength;
    }

    path.push_back(this->position);
}