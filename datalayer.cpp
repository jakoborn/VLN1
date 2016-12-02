#include "datalayer.h"
#include <fstream>
#include <algorithm>

using namespace std;

//The Default filename which to load from and save to.
const string DEFAULT_FILENAME = "science.txt";

//Default constructor.
DataLayer::DataLayer()
{
    loadFromFile();
}

//Loads from the Default file.
//The File we expect to load from has a header, which will be ignored
//when reading from it. Then reads in the people by name, gender, birth
//year, death year (Alive for living persons).
void DataLayer::loadFromFile()
{

    Persons p;
    ifstream in;

    in.open(DEFAULT_FILENAME);

    if (in.fail())
    {
        //If it fails to load, the programme will still run
        //with a notification that it couldn't load.
        //The User could still for example load from a certain directory
        //or add people manually.
    }
    else
    {
    in.seekg(90);

    while(in >> p)
    {
        people.push_back(p);
    }
    in.close();
    }
 }

//Very similar to loadFromFile().
//The input string is the directory from which the file should be loaded.
//If it cannot open the selected file, will return false.
//Otherwise, it will read in the people the same way loadFromFile() does.
//If you have a list, you may want to check whether it has the header.
bool DataLayer::loadFromOtherFile(string input)
{

    Persons p;
    ifstream in;

    in.open(input);

    if (in.fail())
    {
        in.close();
        return false;
    }
    else
    {
        in.seekg(90);

        while(in >> p)
        {
            people.push_back(p);
        }
        in.close();

        saveToFile();

        return true;
    }
 }

//The Default saving function.
//Writes a header, and then the people by
//name, gender, birthyear, deathyear (alive for living persons).
void DataLayer::saveToFile()
{
    ofstream out;
    out.open(DEFAULT_FILENAME);

    out.width(26);
    out << left << "Name";
    out <<  "\tGender\tBorn\tDied" << endl;
    out << "_____________________________________________________" << endl;

    out.seekp(90);
    for (size_t i = 0; i < people.size(); i++)
    {
        out.width(26);
        out << people[i].getName() << ";\t" << people[i].getGender() << "\t" << people[i].getBirthYear() << "\t";
        if(people[i].getAlive())
        {
            out << "Alive\n";
        }
        else
        {
            out << people[i].getDeathYear() << endl;
        }
    }

    out.close();
}

//Similar to the saveToFile() function.
//The difference lies in the input string, which gives the
//directory in which to save.
//returns true, if successful, and false, if opening the file fails.
bool DataLayer::saveToOtherFile(string input)
{
    ofstream out;
    out.open(input);

    if (out.fail())
    {
        return false;
    }
    else
    {
        out.width(26);
        out << left << "Name";
        out <<  "\tGender\tBorn\tDied" << endl;
        out << "_____________________________________________________" << endl;

        out.seekp(90);
        for (size_t i = 0; i < people.size(); i++)
        {
            out.width(26);
            out << people[i].getName() << ";\t" << people[i].getGender() << "\t" << people[i].getBirthYear() << "\t";
            if(people[i].getAlive())
            {
                out << "Alive\n";
            }
            else
            {
                out << people[i].getDeathYear() << endl;
            }
        }

        out.close();
        return true;
    }
}

//Returns a vector containing the people.
vector<Persons> DataLayer::getVector()
{
    return people;
}

//Sets the vector to the given value.
void DataLayer::setVector(vector <Persons> p)
{
    people = p;
}

//Adds the given person to the vector.
//Note the autosave.
void DataLayer::addPerson(const Persons& p)
{
    people.push_back(p);
    saveToFile();
}

//Deletes the person in place n in the vector.
//Note the autosave.
void DataLayer::deletePerson(int n)
{
    people.erase(people.begin() + n);

    /*
    vector<Persons> v;
    Persons p;
    ifstream in;

    in.open(DEFAULT_FILENAME);
    in.seekg(90);

    while(in >> p)
    {
        v.push_back(p);
    }
    in.close();
    v.erase(v.begin()+n);
    people.resize(v.size());
    for (unsigned int i = 0; i < v.size(); i++)
    {
        people[i] = v [i];
    }*/
    /*
    ofstream out(DEFAULT_FILENAME);

    out.width(16);
    out << left << "Name";
    out <<  "\tGender\tBorn\tDied" << endl;
    out << "_____________________________________________________" << endl;

    out.seekp(90);
    for (size_t i = 0; i < people.size(); i++)
    {
        out << people[i].getName() << ";\t" << people[i].getGender() << "\t" << people[i].getBirthYear() << "\t";
        if(people[i].getAlive())
        {
            out << "Alive\n";
        }
        else
        {
            out << people[i].getDeathYear() << endl;
        }
    }

    out.close();
    */
    saveToFile();
}
