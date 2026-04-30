//
// Created by micsa on 30/04/2026.
//

#include <iostream>
#include "Crawler.h"
#include "Hopper.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void loadBugs(vector<Bug*>& bug_vector);
void displayAllBugs(vector<Bug*>& bug_vector);
void findBug(vector<Bug*>& bug_vector);

int main()
{
    vector<Bug*> bug_vector;


    loadBugs( bug_vector);
    cout << "loaded " << bug_vector.size() << " bugs" << endl;

    // displayAllBugs(bug_vector);

    findBug(bug_vector);
}

void loadBugs(vector<Bug*>& bug_vector)
{

    ifstream fin("bugs.txt");
    if(fin)
    {
        string line;
        getline(fin, line);
        while(fin)
        {
            string bugParameters[8];
            int i = 0;
            stringstream ss(line);
            string value;
            while(getline(ss, value, ';'))
            {
                bugParameters[i] = value;
                i++;
            }

            if (bugParameters[0] == "C")
            {
                Crawler* c = new Crawler(bugParameters[0][0] ,stoi(bugParameters[1]), stoi(bugParameters[2]), stoi(bugParameters[3]), stoi(bugParameters[4]), stoi(bugParameters[5]));
                bug_vector.push_back(c);
            } else if (bugParameters[0] == "H")
            {
                Hopper* h = new Hopper(bugParameters[0][0], stoi(bugParameters[1]), stoi(bugParameters[2]), stoi(bugParameters[3]), stoi(bugParameters[4]), stoi(bugParameters[5]), stoi(bugParameters[6]));
                bug_vector.push_back(h);
            }
            getline(fin, line);
        }
        fin.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
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