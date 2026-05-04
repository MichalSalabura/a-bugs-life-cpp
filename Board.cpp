//
// Created by micsa on 04/05/2026.
//

#include "Board.h"

#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Board::~Board() { for (Bug* b : bugs) delete b; }

void Board::loadBugs(string filename) {
    ifstream fin(filename);
    if (fin) {
        string line;
        getline(fin, line);
        while (fin) {
            string bugParameters[8];
            int i = 0;
            stringstream ss(line);
            string value;
            while (getline(ss, value, ';')) {
                bugParameters[i] = value;
                i++;
            }

            if (bugParameters[0] == "C") {
                Crawler* c = new Crawler(bugParameters[0][0], stoi(bugParameters[1]),
                    stoi(bugParameters[2]), stoi(bugParameters[3]),
                    stoi(bugParameters[4]), stoi(bugParameters[5]));
                bugs.push_back(c);
            } else if (bugParameters[0] == "H") {
                Hopper* h = new Hopper(bugParameters[0][0], stoi(bugParameters[1]),
                    stoi(bugParameters[2]), stoi(bugParameters[3]),
                    stoi(bugParameters[4]), stoi(bugParameters[5]),
                    stoi(bugParameters[6]));
                bugs.push_back(h);
            }
            getline(fin, line);
        }
        fin.close();
        cout << "Loaded " << bugs.size() << " bugs." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void Board::displayAllBugs()
{
    for (Bug* bug : bugs)
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