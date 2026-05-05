//
// Created by micsa on 30/04/2026.
//

#ifndef BUGS_LIFE_CRAWLER_H
#define BUGS_LIFE_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug
{
    public:
        void move() override;
        Crawler(char t, int id, int x, int y, int direction, int health);
        void displayInformation();
};


#endif //BUGS_LIFE_CRAWLER_H