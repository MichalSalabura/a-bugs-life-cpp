//
// Created by micsa on 30/04/2026.
//

#ifndef BUGS_LIFE_BUG_H
#define BUGS_LIFE_BUG_H

#include <utility>
#include <list>

class Bug
{
    protected:
        int id;
        pair<int, int> position;
        int direction;
        int health;
        bool alive;
        list<pair<int,int>> path;

    public:
        virtual void move() = 0;
        bool isWayBlocked();
};


#endif //BUGS_LIFE_BUG_H