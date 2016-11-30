#include "servicelayer.h"
#include "datalayer.h"

ServiceLayer::ServiceLayer()
{
    dl.loadFromFile();
}

vector<Persons> ServiceLayer::list()
{
   return dl.getVector();
}

vector<int> ServiceLayer::searchByYear(const int year) {
    vector<int> v;
    for (unsigned int i = 0; i < list().size(); i++) {
        if (list()[i].getBirthYear() == year) {
            v.push_back(i);
        }
    }
    return v;
}

vector<int> ServiceLayer::searchByName(const string name) {
    vector<int> v;
    for (unsigned int i = 0; i < list().size(); i++) {
        if(list()[i].getName() == name) {
            v.push_back(i);
        }
    }
    return v;
}

void ServiceLayer::add(const Persons& p)
{
    dl.addPerson(p);
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

