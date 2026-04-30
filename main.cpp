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

int main()
{
    vector<Bug*> bug_vector;


    loadBugs( bug_vector);

    cout << "loaded " << bug_vector.size() << " bugs" << endl;
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
                Crawler* c = new Crawler(stoi(bugParameters[1]), stoi(bugParameters[2]), stoi(bugParameters[3]), stoi(bugParameters[4]), stoi(bugParameters[5]));
                bug_vector.push_back(c);
            } else if (bugParameters[0] == "H")
            {
                Hopper* h = new Hopper(stoi(bugParameters[1]), stoi(bugParameters[2]), stoi(bugParameters[3]), stoi(bugParameters[4]), stoi(bugParameters[5]), stoi(bugParameters[6]));
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