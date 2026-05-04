//
// Created by micsa on 04/05/2026.
//

#ifndef BUGS_LIFE_BOARD_H
#define BUGS_LIFE_BOARD_H


#include <vector>
#include <string>
#include "Bug.h"
#include <cstdlib>
#include <ctime>

class Board {
private:
    std::vector<Bug*> bugs;

public:
    ~Board();
    void loadBugs(std::string filename);
    void displayAllBugs();
    void findBug();
    void tapBoard();
};

#endif //BUGS_LIFE_BOARD_H