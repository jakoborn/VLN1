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
    out.width(16);
    out << left << p.getName() << ";\t" <<  p.getGender() << "\t" << p.getBirthYear() << "\t";
    if (!p.getAlive()) {
        out << "\t" << "Died " << p.getDeathYear();
    }
    else {
        out << "\t" << "Alive " << p.getDeathYear();
    }
    return out;
}

istream& operator >> (istream& in, Persons& p) {
    string a = " ";
    getline(in, p.name, ';');
    in >> p.gender >> p.birthYear >> a;
    if (a == "Alive") {
        p.alive = true;
        in >> p.deathYear;
    }
    else if (a == "Died"){
        p.alive = false;
        in >> p.deathYear;
    }
    return in;
}
