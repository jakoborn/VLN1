#include "servicelayer.h"
#include "datalayer.h"

ServiceLayer::ServiceLayer()
{

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
    int deathYear;

    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the gender (M/F): ";
    cin >> gender;
    cout << "Enter the birth year: ";
    cin >> birthYear;
    cout << "Enter the death year (0 for living person): ";
    cin >> deathYear;

    Persons newPerson(name, gender, birthYear, deathYear);
    dl.addPerson(newPerson);
}

void ServiceLayer::sort(int type)
{
    switch (type) {
    case 1:
        dl.sortByName();
        break;
    case 2:
        dl.sortByBirthYear();
        break;
    case 3:
        dl.sortByDeathYear();
        break;
    case 4:
        dl.sortByGender();
        break;

    default:
        break;
    }


}

