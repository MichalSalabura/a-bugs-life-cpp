//
// Created by micsa on 30/04/2026.
//

#include "Board.h"
#include <iostream>
using namespace std;

int main()
{
    Board board;
    board.loadBugs("bugs.txt");
    // board.displayAllBugs();
    // board.findBug();
    // board.lifeHistory();
    // board.exit();
    // board.displayAllCells();
    board.runSimulation();
}