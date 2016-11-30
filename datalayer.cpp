#include "datalayer.h"
#include "persons.h"
#include "sortings.h"

#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string FILENAME = "science.txt";

DataLayer::DataLayer()
{
   // loadFromFile();
}
vector<Persons> DataLayer::getVector()
{
    saveToFile();
    return people;
}

void DataLayer::loadFromFile()
{

    Persons p;
    ifstream inStream;

    inStream.open(FILENAME);

    while(inStream >> p)
    {
        addPerson(p);
    }
    inStream.close();
 }

void DataLayer::saveToFile()
{
    fstream out;

    out.open(FILENAME);

    for (size_t i = 0; i < people.size(); i++)
    {
        out << people[i];
    }

    out.close();
}

void DataLayer::addPerson(const Persons& p) {
    people.push_back(p);
    saveToFile();
}

bool sortByName2(const Persons &lhs, const Persons &rhs) { return lhs.getName() < rhs.getName(); } //reyndi að nota klasaföll, en það vill þýðandinn ekki.
bool sortByGender2(const Persons &lhs, const Persons &rhs) { return lhs.getGender() < rhs.getGender(); }
bool sortByBirthYear2(const Persons &lhs, const Persons &rhs) { return lhs.getBirthYear() < rhs.getBirthYear(); }
bool sortByDeathYear2(const Persons &lhs, const Persons &rhs) { return lhs.getDeathYear() < rhs.getDeathYear(); }

void DataLayer::sortByName()
{
    sort(people.begin(), people.end(), sortByName2);
}

void DataLayer::sortByBirthYear()
{
    sort(people.begin(), people.end(), sortByBirthYear2);
}

void DataLayer::sortByDeathYear()
{
    sort(people.begin(), people.end(), sortByDeathYear2);
}

void DataLayer::sortByGender()
{
    sort(people.begin(), people.end(), sortByGender2);
}
