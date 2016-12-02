#include "persons.h"
#include <iomanip>


//Default Constructor.
//Not actually used.
Persons::Persons()
{
    name = "John Doe";
    gender = 'M';
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

//Overloads the == and != operators.
//Two persons are equal if and only if each
//Parameter is equal.
bool Persons::operator == (const Persons& p)
{
    return name == p.name && gender == p.gender && birthYear == p.birthYear && deathYear == p.deathYear;
}
bool Persons::operator != (const Persons& p)
{
    return name != p.name || gender != p.gender || birthYear != p.birthYear || deathYear != p.deathYear;
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

bool validName(const string& s)
{
    //Checks if 's' is empty or contains characters other than letters and spaces
    string::const_iterator it = s.begin();
    while (it != s.end() && (isalpha(*it) || *it == ' '))
    {
        ++it;
    }

    return !s.empty() && it == s.end();
}
bool genderCheck(char& gender)
{

    if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
    {
        if(gender == 'm')
        {
            gender = 'M';
        }
        if(gender == 'f')
        {
            gender = 'F';
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool validYear(const string& s, int& year)
{
    string::const_iterator it = s.begin();
    //Checks if the string 's' is a number
    while (it != s.end() && isdigit(*it)) ++it;
    if (s.empty() || it != s.end())
    {
        return false;
    }
    //Checks if 'year' is positive and lower than current year
    year = atoi(s.c_str());
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;

    return year >= 0 && year <= currentYear;
}
bool birthChecks(int birthYear, int deathYear)
{
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;
    return ((deathYear - birthYear) >= 0 && (deathYear -birthYear) < 123) ||(deathYear == 0 && (currentYear - birthYear) < 123);
}

//Overloads the >> (input) operator.
//Reads the name which we know ends at a ;
//Then reads the gender and birthyear.
//Reads either "Alive" or the deathyear.
istream& operator >> (istream& in, Persons& p)
{
    string n = " ", gdr = " ", b = " ", d = " ";
    char g = ' ';
    int bY = 0, dY =0;
    Persons def;
    in >> ws;
    getline(in, n, ';');
    in >> gdr >> b >> d;
    if (validName(n)) {
        if (gdr.length() == 1) {
            g = gdr.at(0);
            if (genderCheck(g)) {
                if (validYear(b, bY)) {
                    if (d == "Alive" && birthChecks(bY, dY))
                    {
                        p.name = n;
                        p.gender = g;
                        p.birthYear = bY;
                        p.alive = true;
                        p.deathYear = 0;
                    }
                    else if(validYear(d, dY) && birthChecks(bY, dY)) {
                        p.name = n;
                        p.gender = g;
                        p.birthYear = bY;
                        p.deathYear = dY;
                        p.alive = false;
                    }
                    else p = def;
                }
                else p = def;
            }
            else p = def;
        }
        else p = def;
    }
    else p = def;
    return in;
}
