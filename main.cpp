//
// Created by micsa on 30/04/2026.
//

#include "Board.h"
#include <iostream>
using namespace std;

int main()
{
    Board board;

    int choice = 0;
    while (choice != 8) {
        cout << "\n1. Initialise Bug Board" << endl;
        cout << "2. Display All Bugs" << endl;
        cout << "3. Find a Bug" << endl;
        cout << "4. Tap the Bug Board" << endl;
        cout << "5. Display Life History" << endl;
        cout << "6. Display All Cells" << endl;
        cout << "7. Run Simulation" << endl;
        cout << "8. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            board.loadBugs("bugs.txt");
        } else if (choice == 2) {
            board.displayAllBugs();
        } else if (choice == 3) {
            board.findBug();
        } else if (choice == 4) {
            board.tapBoard();
        } else if (choice == 5) {
            board.lifeHistory();
        } else if (choice == 6) {
            board.displayAllCells();
        } else if (choice == 7) {
            board.runSimulation();
        } else if (choice == 8) {
            board.exit();
        } else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}