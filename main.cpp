//
// Created by micsa on 30/04/2026.
//

#include "Board.h"
using namespace std;

int main()
{
    Board board;
    board.loadBugs("bugs.txt");
    // board.displayAllBugs();
    // board.findBug();
    board.tapBoard();
    board.tapBoard();
    board.tapBoard();
    board.tapBoard();
    board.tapBoard();
    board.lifeHistory();
}