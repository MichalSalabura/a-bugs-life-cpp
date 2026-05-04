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

void displayAllBugs(vector<Bug*>& bug_vector);
void findBug(vector<Bug*>& bug_vector);

int main()
{
    Board board;
    board.loadBugs("bugs.txt");

}

void displayAllBugs(vector<Bug*>& bug_vector)
{
    for (Bug* bug : bug_vector)
    {
        cout << bug->getId() << " ";
        if (bug->getType() == 'C')
        {
            cout << "Crawler";
        } else
        {
            cout << "Hopper";
        }
        cout << " (" << bug->getPosition().first << ","
        << bug->getPosition().second << ") "
        << bug->getHealth() << " ";
        if (bug->getDirection() == 1)
        {
            cout << "North ";
        } else if (bug->getDirection() == 2)
        {
            cout << "East ";
        } else if (bug->getDirection() == 3)
        {
            cout << "South ";
        } else if (bug->getDirection() == 4)
        {
            cout << "West ";
        }

        if (bug->getType() == 'H')
        {
            Hopper* hopper = dynamic_cast<Hopper*>(bug);
            cout << hopper->getHopLength() << " ";
        }

        if (bug->isAlive())
        {
            cout << "Alive ";
        } else
        {
            cout << "Dead ";
        }
        cout << endl;
    }
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