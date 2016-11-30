#include "servicelayer.h"
#include "datalayer.h"

ServiceLayer::ServiceLayer()
{
    dl.loadFromFile();
}

vector<Persons> ServiceLayer::list()
{
   // int placement = 0;

   return dl.getVector();

    //return placement;
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

