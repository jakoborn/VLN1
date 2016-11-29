#include "datalayer.h"
#include "persons.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

DataLayer::DataLayer()
{
    loadFromFile();

}

void DataLayer::loadFromFile()
{
    Persons p;
    ifstream inStream;
    inStream.open("textFile.txt");

    while(!inStream.eof()) {
        inStream >> p;
        if(!inStream.eof()) {
            people.push_back(p);
        }
    }
    inStream.close();
}

void DataLayer::saveToFile()
{
    ofstream out;

    out.open("textFile.txt");

    for (size_t i = 0; i < people.size(); i++)
    {
        out << people[i] << endl;
    }

    out.close();
}
