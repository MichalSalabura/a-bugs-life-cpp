//
// Created by micsa on 05/05/2026.
//

#include "Slider.h"
#include <cstdlib>

using namespace std;

Slider::Slider(char t, int id, int x, int y, int direction, int health)
{
    this->type = t;
    this->id = id;
    this->position = {x, y};
    this->direction = direction;
    this->health = health;
    this->alive = true;
    this->path.push_back(this->position);
}

void Slider::move()
{
    int x = position.first;
    int y = position.second;
    int newX = x, newY = y;
    int sideways = (rand() % 2 == 0) ? -1 : 1;

    if (direction == 1)
    {
        newY = y - 2;
        newX = x + sideways;
    } else if (direction == 2)
    {
        newX = x + 2;
        newY = y + sideways;
    } else if (direction == 3)
    {
        newY = y + 2;
        newX = x + sideways;
    } else if (direction == 4)
    {
        newX = x - 2;
        newY = y + sideways;
    }

    if (newX < 0 || newX > 9 || newY < 0 || newY > 9) {
        direction = rand() % 4 + 1;
        move();
        return;
    }

    position = {newX, newY};
    path.push_back(position);
}
