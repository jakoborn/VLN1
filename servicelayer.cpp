#include "servicelayer.h"
#include "datalayer.h"
#include <algorithm>

ServiceLayer::ServiceLayer()
{
    DataLayer dl;
}

int ServiceLayer::search()
{
    int placement = 0;

    return placement;
}

void ServiceLayer::add()
{
    string name;
    char gender;
    int birthYear;
    int DeathYear;
    bool alive;

    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the gender (M/F): ";
    cin >> gender;
    cout << "Enter the birth year: ";
    cin >> birthYear;
    cout << "Enter the death year (0 for living person): ";
    cin >> DeathYear;

    if (DeathYear == 0)
    {
        alive = true;
    }
    else
    {
        alive = false;
    }

    Persons newPerson(name, gender, birthYear, DeathYear);
}

void ServiceLayer::sort(int type)
{
    switch (type) {
    case 1:
        sortByName();
        break;
    case 2:
        sortByBirthYear();
        break;
    case 3:
        sortByDeathYear();
        break;
    case 4:
        sortByGender();
        break;

    default:
        break;
    }


}

void ServiceLayer::sortByName()
{

}

void ServiceLayer::sortByBirthYear()
{
    //std::sort ( );
}

void ServiceLayer::sortByDeathYear()
{
    //std::sort ( );
}

void ServiceLayer::sortByGender()
{

}
