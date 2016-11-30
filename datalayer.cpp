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

    for(size_t i = 0; i < people.size();i++)
    {
       /// vector<Persons> myV = people;
        myV.push_back(people[i]);

    }
       return myV;
}

void DataLayer::loadFromFile()
{

    Persons p;
    ifstream inStream;

    inStream.open("science.txt");

    if(!inStream.is_open())
    {
        cout << "We could not find the text file!." << endl;
    }
    if(inStream.is_open())
        cout << "Right" << endl;
    while(inStream >> p)
    {

        people.push_back(p);
        cout << p;

        addPerson(p);

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

void DataLayer::addPerson(const Persons& p) {
    people.push_back(p);
}

void DataLayer::listPersons()
{

}

void DataLayer::sortByName()
{

}

void DataLayer::sortByBirthYear()
{
    for (size_t index = 1; index < people.size(); index++)
    {
        for (int i = index; i > 0; i--)
        {
            if (people[i].getBirthYear() < people[i - 1].getBirthYear())
            {
                Persons temp;
                temp = people[i];
                people[i] = people[i - 1];
                people[i - 1] = temp;
            }
        }
    }
}

void DataLayer::sortByDeathYear()
{
    for (size_t index = 1; index < people.size(); index++)
    {
        for (int i = index; i > 0; i--)
        {
            if (people[i].getDeathYear() < people[i - 1].getDeathYear())
            {
                Persons temp;
                temp = people[i];
                people[i] = people[i - 1];
                people[i - 1] = temp;
            }
        }
    }
}

void DataLayer::sortByGender()
{

}
