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
    string gender;
    bool alive;

public:
    Persons();
};

#endif // PERSONS_H
