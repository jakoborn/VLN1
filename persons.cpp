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

string Persons::getName() const{
    return name;
}

int Persons::getBirthYear() const{
    return birthYear;
}

int Persons::getDeathYear() const{
    return deathYear;
}

char Persons::getGender() const{
    return gender;
}

bool Persons::getAlive() const{
    return alive;
}

ostream& operator << (ostream& out, const Persons& p) {
    out << "Name: " << p.getName() << endl << "Birth year: " << p.getBirthYear() << endl << "Death year: " << p.getDeathYear() << endl;
    out << "Gender: " << p.getGender() << endl << "Alive: ";
    if (p.getAlive()) {
        out << "true" << endl;
    }
    else {
        out << "false" << endl;
    }
    return out;
}

istream& operator >> (istream& in, Persons& p) {
    string a = " ";
    in >> p.name >> p.birthYear >> p.deathYear >> p.gender >> a;
    if (a == "true") {
        p.alive = true;
    }
    else if (a == "false") {
        p.alive = false;
    }
    return in;
}
