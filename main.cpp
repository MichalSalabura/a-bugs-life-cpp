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

void loadBugs();

int main()
{

    loadBugs();
}

void loadBugs()
{

    ifstream fin("bugs.txt");
    if(fin)
    {
        string line;
        getline(fin, line);
        while(fin)
        {
            char bugParameters[8];
            stringstream ss(line);
            string value;
            while(getline(ss, value, ';'))
            {
                cout << value << endl;
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