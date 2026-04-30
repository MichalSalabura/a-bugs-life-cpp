//
// Created by micsa on 30/04/2026.
//

#include "Crawler.h"
using namespace std;

Crawler::Crawler(int id, int x, int y, int direction, int health) {
    this->id = id;
    this->position = {x, y};
    this->direction = direction;
    this->health = health;
    this->alive = true;
    this->path.push_back(this->position);
}

void Crawler::move()
{
    while (isWayBlocked())
    {
        direction = rand() % 4 + 1;
    };

    if (direction == 1)
    {
        position.second -= 1;
    }
    else if (direction == 2)
    {
        position.first += 1;
    }
    else if (direction == 3)
    {
        position.second += 1;
    }
    else if (direction == 4)
    {
        position.first -= 1;
    }

    path.push_back(position);

}