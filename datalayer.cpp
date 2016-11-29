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

}

void DataLayer::loadFromFile()
{
    Persons p;
    fstream inStream;
    inStream.open("textFile.txt");

    while(inStream >> p)
    {
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
    int i = 0, j = people.size();
    Persons tmp;
    int pivot = people[people.size() / 2].getBirthYear();

  while (i <= j)
  {
        while (people[i].getBirthYear() < pivot)
        {
              i++;
        }
        while (people[j].getBirthYear() > pivot)
        {
              j--;
        }
        if (i <= j)
        {
              tmp = people[i];
              people[i] = people[j];
              people[j] = tmp;
              i++;
              j--;
        }
  }
}

void DataLayer::sortByDeathYear()
{

}

void DataLayer::sortByGender()
{

}
