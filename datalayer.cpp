#include "datalayer.h"
#include "persons.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

DataLayer::DataLayer()
{
    loadFromFile();

}

void DataLayer::loadFromFile()
{
    Persons p;
    fstream inStream;
    inStream.open("textFile.txt");

    while(inStream >> p)
    {
        people.push_back(p);
    }
    inStream.close();
}

void DataLayer::saveToFile()
{
    fstream out;

    out.open("textFile.txt");

    for (size_t i = 0; i < people.size(); i++)
    {
        out << people[i] << endl;
    }

    out.close();
}

void DataLayer::sortByName()
{

}

void DataLayer::sortByBirthYear()
{
    //std::sort (people.begin(), people.end());
}

void DataLayer::sortByDeathYear()
{
    //std::sort ( );
}

void DataLayer::sortByGender()
{

}
