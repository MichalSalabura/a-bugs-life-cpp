//
// Created by micsa on 05/05/2026.
//

#ifndef BUGS_LIFE_SLIDER_H
#define BUGS_LIFE_SLIDER_H

#include "Bug.h"

class Slider : public Bug
{
    public:
        Slider(char t, int id, int x, int y, int direction, int health);
        void move() override;
};


#endif //BUGS_LIFE_SLIDER_H