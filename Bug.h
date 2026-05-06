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
        char type;
        int id;
        std::pair<int, int> position;
        int direction;
        int health;
        bool alive;
        std::list<std::pair<int,int>> path;
        int eatenBy = -1;
        int amountEaten = 0;

    public:
        virtual void move() = 0;
        virtual void displayInformation() = 0;
        bool isWayBlocked();
        int getId() const { return id; }
        std::pair<int,int> getPosition() const { return position; }
        int getDirection() const { return direction; }
        int getHealth() const { return health; }
        bool isAlive() const { return alive; }
        const std::list<std::pair<int,int>>& getPath() const { return path; }
        char getType() const { return type; }
        int getEatenBy() const { return eatenBy; }
        void setEatenBy(int id);
        void takeDamage(int damage);
        int getAmountEaten() const { return amountEaten; }
        void increaseAmountEaten();

};


#endif //BUGS_LIFE_BUG_H