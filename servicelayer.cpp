#include "servicelayer.h"
#include "datalayer.h"

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
    int birthYear;
    int DeathYear;
    char gender;
    bool alive;

    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the birth year: ";
    cin >> birthYear;
    cout << "Enter the death year (0 for living person): ";
    cin >> DeathYear;
    cout << "Enter the gender (M/L): ";
    cin >> gender;

    if (DeathYear == 0)
    {
        alive = true;
    }
    else
    {
        alive = false;
    }

    Persons newPerson(name, birthYear, DeathYear, gender, alive);
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

}

void ServiceLayer::sortByDeathYear()
{

}

void ServiceLayer::sortByGender()
{

}
