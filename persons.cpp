#include "persons.h"
#include <iomanip>

Persons::Persons()
{

    name = " ";
    gender = ' ';
    birthYear = 1980;
    deathYear = 0;
    alive = true;
}

Persons::Persons(string n, char g, int bY, int dY)
{
    name = n;
    birthYear = bY;
    deathYear = dY;
    gender = g;
    if (dY == 0) {
        alive = true;
    }
    else {
        alive = false;
    }
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
    out.width(15);
    out << left << p.getName();
    out <<  p.getGender() << "\t" << p.getBirthYear() << "\t";
    if (!p.getAlive()) {
        out << " - " << p.getDeathYear() << endl;
    }
    else {
        out << "Alive" << endl;
    }
    return out;
}

istream& operator >> (istream& in, Persons& p) {
    string a = " ";
    in >> p.name >> p.gender >> p.birthYear >> a;
    if (a == "Alive") {
        p.alive = true;
        p.deathYear = 0;
    }
    else if (a == "-"){
        p.alive = false;
        in >> p.deathYear;
    }
    return in;
}
