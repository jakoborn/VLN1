#include "datalayer.h"
#include <fstream>
#include <algorithm>

using namespace std;

const string FILENAME = "science.txt";

DataLayer::DataLayer()
{
    loadFromFile();
}
vector<Persons> DataLayer::getVector()
{
    saveToFile();
    return people;
}

void DataLayer::loadFromFile()
{

    Persons p;
    ifstream in;

    in.open(FILENAME);
    in.seekg(89);

    while(in >> p)
    {
        addPerson(p);
    }
    in.close();
 }

void DataLayer::saveToFile()
{
    fstream out;

    out.open(FILENAME);

    out.width(16);
    out << left << "Name";
    out <<  "\tGender\tBorn\tDied" << endl;
    out << "_____________________________________________________" << endl;

    for (size_t i = 0; i < people.size(); i++)
    {
        out << people[i].getName() << ";\t" << people[i].getGender() << "\t" << people[i].getBirthYear() << "\t";
        if(people[i].getAlive()) {
            out << "Alive\n";
        }
        else {
            out << people[i].getDeathYear() << endl;
        }
    }

    out.close();
}

void DataLayer::addPerson(const Persons& p) {
    people.push_back(p);
    saveToFile();
}

