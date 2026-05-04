//
// Created by micsa on 30/04/2026.
//

#ifndef BUGS_LIFE_HOPPER_H
#define BUGS_LIFE_HOPPER_H

#include "Bug.h"

class Hopper : public Bug
{
    private:
        int hopLength;

    public:
        Hopper(char t, int id, int x, int y, int direction, int health, int hopLength);
        int getHopLength() const { return hopLength; }
        void move() override;
};


#endif //BUGS_LIFE_HOPPER_H