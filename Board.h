//
// Created by micsa on 04/05/2026.
//

#ifndef BUGS_LIFE_BOARD_H
#define BUGS_LIFE_BOARD_H


#include <vector>
#include <string>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs;
    std::vector< std::vector<std::vector<Bug*>>> cells;

public:
    Board();
    ~Board();
    void loadBugs(std::string filename);
    void displayAllBugs();
    void findBug();
    void tapBoard();
    void lifeHistory();
    void exit();
    void buildCells();
    void displayAllCells();
};

#endif //BUGS_LIFE_BOARD_H