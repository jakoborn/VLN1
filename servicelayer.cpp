#include <algorithm>
#include "servicelayer.h"
#include "sortings.h"


ServiceLayer::ServiceLayer()
{

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
        for (size_t p = 0; p <= (list()[i].getName().length() - name.length()); p++) {
            if(list()[i].getName().substr(p, name.length()) == name) {
                v.push_back(i);
                break;
            }
        }
    }
    return v;
}

vector<int> ServiceLayer::searchByGender(const char gender)
{
    vector<int> v;

    for(unsigned int i = 0; i < list().size(); i++)
    {
        if(list()[i].getGender() == gender)
        {
            v.push_back(i);
        }
    }
    return v;
}

void ServiceLayer::add(const Persons& p)
{
    dl.addPerson(p);
}

void ServiceLayer::sorting(int type, int order)
{    
    switch (type) {
    case 1:
        sortByName(order);
        break;
    case 2:
        sortByBirthYear(order);
        break;
    case 3:
        sortByDeathYear(order);
        break;
    case 4:
        sortByGender(order);
        break;

    default:
        break;
    }


}

//regular sorting
bool sortByName2(const Persons &lhs, const Persons &rhs) { return lhs.getName() < rhs.getName(); } //reyndi að nota klasaföll, en það vill þýðandinn ekki.
bool sortByGender2(const Persons &lhs, const Persons &rhs) { return lhs.getGender() < rhs.getGender(); }
bool sortByBirthYear2(const Persons &lhs, const Persons &rhs) { return lhs.getBirthYear() < rhs.getBirthYear(); }
bool sortByDeathYear2(const Persons &lhs, const Persons &rhs) { return lhs.getDeathYear() < rhs.getDeathYear(); }

//reverse sorting
bool rSortByName2(const Persons &lhs, const Persons &rhs) { return lhs.getName() > rhs.getName(); } //reyndi að nota klasaföll, en það vill þýðandinn ekki.
bool rSortByGender2(const Persons &lhs, const Persons &rhs) { return lhs.getGender() > rhs.getGender(); }
bool rSortByBirthYear2(const Persons &lhs, const Persons &rhs) { return lhs.getBirthYear() > rhs.getBirthYear(); }
bool rSortByDeathYear2(const Persons &lhs, const Persons &rhs) { return lhs.getDeathYear() > rhs.getDeathYear(); }

void ServiceLayer::sortByName(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //sort(people.begin(), people.end(), sorter.sortByName);
        sort(people.begin(), people.end(), sortByName2);
    }
    else
    {
        //sort(people.begin(), people.end(), sorter.rSortByName);
        sort(people.begin(), people.end(), rSortByName2);
    }
    dl.setVector(people);
}

void ServiceLayer::sortByBirthYear(int order)
{

    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //sort(people.begin(), people.end(), sorter.sortByBirthYear);
        sort(people.begin(), people.end(), sortByBirthYear2);
    }
    else
    {
        //sort(people.begin(), people.end(), sorter.rSortByBirthYear);
        sort(people.begin(), people.end(), rSortByBirthYear2);
    }
    dl.setVector(people);
}

void ServiceLayer::sortByDeathYear(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //sort(people.begin(), people.end(), sorter.sortByDeathYear);
        sort(people.begin(), people.end(), sortByDeathYear2);
    }
    else
    {
        //sort(people.begin(), people.end(), sorter.rSortByDeathYear);
        sort(people.begin(), people.end(), rSortByDeathYear2);
    }
    dl.setVector(people);
}

void ServiceLayer::sortByGender(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //sort(people.begin(), people.end(), sorter.sortByGender);
        sort(people.begin(), people.end(), sortByGender2);
    }
    else
    {
        //sort(people.begin(), people.end(), sorter.rSortByGender);
        sort(people.begin(), people.end(), rSortByGender2);
    }
    dl.setVector(people);
}
