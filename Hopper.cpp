//
// Created by micsa on 30/04/2026.
//

#include "Hopper.h"

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