//
// Created by micsa on 04/05/2026.
//

#include "Board.h"

#include "Crawler.h"
#include "Hopper.h"
#include "Slider.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

Board::Board()
{
    srand(time(nullptr));
    cells.resize(10, vector<vector<Bug*>>(10));
}

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
            } else if (bugParameters[0] == "S")
            {
                Slider* s = new Slider(bugParameters[0][0], stoi(bugParameters[1]),
                    stoi(bugParameters[2]), stoi(bugParameters[3]),
                    stoi(bugParameters[4]), stoi(bugParameters[5]));
                bugs.push_back(s);
            }
            getline(fin, line);
        }
        fin.close();
        cout << "Loaded " << bugs.size() << " bugs." << endl;
        buildCells();
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
        } else if (bug->getType() == 'H')
        {
            cout << "Hopper";
        } else if (bug->getType() == 'S')
        {
            cout << "Slider";
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
            cout << "Alive";
        } else
        {
            cout << "Eaten by: " << bug->getEatenBy();
        }
        cout << endl;
    }
}

void Board::findBug()
{
    int id;
    cout << "Please enter bug id: " << endl;
    cin >> id;

    for (Bug* bug : bugs) {
        if (bug->getId() == id) {
            bug->displayInformation();
            return;
        }
    }
    cout << "Bug " << id << " not found" << endl;
}

void Board::tapBoard()
{
    vector<Bug*> aliveBugs;
    for (Bug* bug : bugs)
    {
        if (bug->isAlive())
        {
            aliveBugs.push_back(bug);
        }
    }

    if (aliveBugs.size() == 0) return;

    Bug* frozen = aliveBugs[rand() % aliveBugs.size()];

    for (Bug* bug : aliveBugs)
    {
        if (bug != frozen)
        {
            bug->move();
        }
    }
    buildCells();
    manageFights();
    buildCells();

    cout << "All bugs except for " << frozen->getId() << " moved" << endl;
    drawBoard();
}

void Board::lifeHistory()
{
    for (Bug* bug : bugs)
    {
        cout << "Bug " << bug->getId();
        if (bug->getType() == 'C')
        {
            cout << " Crawler";
        } else if (bug->getType() == 'H')
        {
            cout << " Hopper";
        } else if (bug->getType() == 'S')
        {
            cout << " Slider";
        }

        cout << " Path: ";
        const list<pair<int,int>>& path = bug->getPath();
        for (list<pair<int, int>>::const_iterator it = path.begin(); it != path.end(); ++it)
        {
            cout << "(" << it->first << "," << it->second << ")";
            if (next(it) != path.end())
            {
                cout << ",";
            }
        }

        if  (bug->isAlive())
        {
            cout << " Alive!" << endl;
        } else
        {
            cout << " Eaten by " << bug->getEatenBy() << endl;
        }
    }
}

void Board::exit()
{
    time_t t = time(nullptr);
    char buf[32];
    strftime(buf, sizeof(buf), "%d.%m.%Y_%H-%M-%S", localtime(&t));

    string filename = string("bugs_life_history_") + buf + ".txt";

    ofstream fout(filename);
    for (Bug* bug : bugs)
    {
        fout << bug->getId() << " ";
        if (bug->getType() == 'C')
        {
            fout << "Crawler";
        } else if (bug->getType() == 'H')
        {
            fout << "Hopper";
        } else if (bug->getType() == 'S')
        {
            fout << "Slider";
        }
        fout << " Path: ";
        const list<pair<int,int>>& path = bug->getPath();
        for (list<pair<int, int>>::const_iterator it = path.begin(); it != path.end(); ++it)
        {
            fout << "(" << it->first << "," << it->second << ")";
            if (next(it) != path.end())
            {
                fout << ",";
            }
        }
        if (bug->isAlive())
        {
            fout << " Alive!" << endl;
        } else
        {
            fout << " Eaten by " << bug->getEatenBy() << endl;
        }
    }
    fout.close();
    cout << "Life history written to: " << filename << endl;
}

void Board::buildCells()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cells[y][x].clear();
        }
    }

    for (Bug* bug : bugs)
    {
        if (!bug->isAlive())
        {
            continue;
        }
        int x = bug->getPosition().first;
        int y = bug->getPosition().second;
        cells[y][x].push_back(bug);
    }
}

void Board::displayAllCells()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << "(" << x << "," << y << "): ";
            if (cells[y][x].size() == 0)
            {
                cout << "empty";
            } else
            {
                for (int i = 0; i < cells[y][x].size(); i++)
                {
                    Bug* bug = cells[y][x][i];

                    if (bug->getType() == 'C')
                    {
                        cout << "Crawler ";
                    }
                    else if (bug->getType() == 'H')
                    {
                        cout << "Hopper ";
                    } else if (bug->getType() == 'S')
                    {
                        cout << "Slider ";
                    }
                    cout << bug->getId();

                    if (i + 1 < cells[y][x].size())
                    {
                        cout << ", ";
                    }
                }
            }
            cout << endl;
        }
    }
}

void Board::manageFights()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            vector<Bug*>& cell = cells[y][x];

            if (cell.size() < 2)
            {
                continue;
            }

            for (size_t i = 0; i + 1 < cell.size(); i += 2)
            {
                Bug* b1 = cell[i];
                Bug* b2 = cell[i + 1];
                fight(b1, b2);
            }
        }
    }
}

void Board::fight(Bug* a, Bug* b)
{
    cout << "Fight: " << a->getId() << " vs " << b->getId() << endl;

    for (int round = 1; round <= 3; round++)
    {
        if (!a->isAlive() || !b->isAlive())
        {
            break;
        }

        int dmgA = rand() % 6;
        int dmgB = rand() % 6;

        a->takeDamage(dmgB);
        b->takeDamage(dmgA);

        cout << "Round: " << round
             << " " << a->getId() << " takes " << dmgB
             << ", " << b->getId() << " takes " << dmgA << endl;

        if (!a->isAlive() || !b->isAlive())
        {
            break;
        }
    }

    if (!a->isAlive() && b->isAlive())
    {
        a->setEatenBy(b->getId());
    }

    if (!b->isAlive() && a->isAlive())
    {
        b->setEatenBy(a->getId());
    }
}

void Board::runSimulation()
{
    int taps = 0;
    int alive = bugs.size();

    while (alive > 1)
    {
        cout << "\n=== Tap " << ++taps << " ===" << endl;
        tapBoard();
        displayAllCells();

        alive = 0;
        for (Bug* bug : bugs)
        {
            if (bug->isAlive()) alive++;
        }
        Sleep(1000);
    }

    for (Bug* bug : bugs) {
        if (bug->isAlive()) {
            cout << "\nLast Bug Standing: Bug " << bug->getId() << endl;
            break;
        }
    }
    exit();
}

void Board::drawBoard()
{
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (cells[y][x].size() > 0)
            {
                cout << cells[y][x].size();
            }
            else
            {
                cout << "_";
            }
        }
        cout << endl;
    }
}