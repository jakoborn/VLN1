#ifndef PERSONS_H
#define PERSONS_H

#include <iostream>

using namespace std;

class Persons
{
private:
    string name;
    int birthYear;
    int deathYear;
    char gender;
    bool alive;

public:
    Persons();
    Persons(string n, int bY, int dY, char g, bool a);
};

#endif // PERSONS_H
