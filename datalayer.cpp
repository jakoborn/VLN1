#include "datalayer.h"
#include "persons.h"

#include <string>
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
vector<Persons> DataLayer::getVector()
{
    vector<Persons> myV;

    for(int i = 0; i < people.size();i++)
    {
       // vector<Persons> myV = people;
        myV.push_back(people[i]);

    }
       return myV;
}

void DataLayer::loadFromFile()
{

    Persons p;
    ifstream inStream;

    inStream.open("textFile.txt");



    while(inStream >> p)
    {
        people.push_back(p);
        cout << p;
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
