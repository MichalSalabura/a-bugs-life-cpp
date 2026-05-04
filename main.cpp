//
// Created by micsa on 30/04/2026.
//

#include <iostream>
#include "Crawler.h"
#include "Hopper.h"
#include "Board.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void findBug(vector<Bug*>& bug_vector);

int main()
{
    Board board;
    board.loadBugs("bugs.txt");
    // board.displayAllBugs();
}

void findBug(vector<Bug*>& bug_vector)
{
    int id;
    cout << "Please enter bug id: (between 101 and 125 inclusive):" << endl;
    cin >> id;
    while (id < 101 || id > 125) {
        cout << "Please enter a proper value: " << endl;
        cin >> id;
    };


    for (Bug* bug : bug_vector)
    {
        if (bug->getId() == id)
        {
            if (bug->getType() == 'C')
            {
                Crawler* crawler = dynamic_cast<Crawler*>(bug);
                cout << crawler->getId() << " Crawler (" << crawler->getPosition().first << ", "
                << crawler->getPosition().second << ") " << crawler->getHealth() << " " << crawler->getDirection()
                << " " << crawler->isAlive() << endl;
            } else
            {
                Hopper* hopper = dynamic_cast<Hopper*>(bug);
                cout << hopper->getId() << " Hopper (" << hopper->getPosition().first << ", "
                << hopper->getPosition().second << ") " << hopper->getHealth() << " " << hopper->getDirection()
                << " " << hopper->getHopLength() << " " << hopper->isAlive() << endl;
            }
           return;
        }
    }
    cout << "bug " << id << " not found" << endl;
    return;
}