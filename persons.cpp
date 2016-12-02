#include "persons.h"
#include <iomanip>


//Default Constructor.
//Not actually used.
Persons::Persons()
{
    name = " ";
    gender = ' ';
    birthYear = 1980;
    deathYear = 0;
    alive = true;
}

//Constructor.
//if deathyear == 0, the person will be alive.
Persons::Persons(string n, char g, int bY, int dY)
{
    name = n;
    birthYear = bY;
    deathYear = dY;
    gender = g;
    if (dY == 0)
    {
        alive = true;
    }
    else
    {
        alive = false;
    }
}

string Persons::getName() const
{
    return name;
}

int Persons::getBirthYear() const
{
    return birthYear;
}

int Persons::getDeathYear() const
{
    return deathYear;
}

char Persons::getGender() const
{
    return gender;
}

bool Persons::getAlive() const
{
    return alive;
}

//Overloads the = operator. Basic stuff.
void Persons::operator = (const Persons& p)
{
    name = p.name;
    gender = p.gender;
    birthYear = p.birthYear;
    deathYear = p.deathYear;
    alive = p.alive;
}

//Overloads the == operator.
//Two persons are equal if and only if each
//Parameter is equal.
bool Persons::operator == (const Persons& p)
{
    return name == p.name && gender == p.gender && birthYear == p.birthYear && deathYear == p.deathYear;
}

//Overloads the << (output) operator.
//writes out the name, gender, and birthyear.
//Writes out the deathyear or, if the person is alive
//writes "Alive".
ostream& operator << (ostream& out, const Persons& p)
{
    out.width(26);
    out << left << p.getName() << "\t" <<  p.getGender() << "\t" << p.getBirthYear() << "\t";
    if (!p.getAlive())
    {
        out << p.getDeathYear() << endl;
    }
    else
    {
        out << "Alive " << endl;
    }
    return out;
}

//Overloads the >> (input) operator.
//Reads the name which we know ends at a ;
//Then reads the gender and birthyear.
//Reads either "Alive" or the deathyear.
istream& operator >> (istream& in, Persons& p)
{
    string a = " ";
    in >> ws;
    getline(in, p.name, ';');
    in >> p.gender >> p.birthYear >> a;
    if (a == "Alive")
    {
        p.alive = true;
        p.deathYear = 0;
    }
    else
    {
        p.alive = false;
        p.deathYear = atoi(a.c_str());
    }
    return in;
}
