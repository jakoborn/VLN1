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
    return people;
}

void DataLayer::setVector(vector <Persons> p)
{
    people = p;
}


void DataLayer::loadFromFile()
{

    Persons p;
    ifstream in;

    in.open(FILENAME);
    in.seekg(90);

    while(in >> p)
    {
        people.push_back(p);
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

    out.seekp(90);
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

void DataLayer::addPerson(const Persons& p)
{
    people.push_back(p);
    saveToFile();
}

void DataLayer::deletePerson(int n) {
    vector<Persons> v;
    Persons p;
    ifstream in;

    in.open(FILENAME);
    in.seekg(90);

    while(in >> p)
    {
        v.push_back(p);
    }
    in.close();
    v.erase(v.begin()+n);
    people.resize(v.size());
    for (unsigned int i = 0; i < v.size(); i++) {
        people[i] = v[i];
    }
    saveToFile();
}
