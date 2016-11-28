#include "persons.h"

Persons::Persons()
{

    name = "";
    birthYear = 1980;
    deathYear = 0;
    alive = true;
    gender = 'M';
}

Persons::Persons(string n, int bY, int dY, char g, bool a)
{
    name = n;
    birthYear = bY;
    deathYear = dY;
    gender = g;
    alive = a;
}
