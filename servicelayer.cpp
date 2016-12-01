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
        if (name.length() <= list()[i].getName().length()) {
            if (list()[i].getName() == name) {
                v.push_back(i);
                break;
            }
            else {
                for (unsigned int p = 0; p <=(list()[i].getName().length() - name.length()); p++) {
                    if(name == list()[i].getName().substr(p, name.length())) {
                        v.push_back(i);
                        break;
                    }
                }
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

vector<int> ServiceLayer::searchByRange(const int f, const int l)
{
    vector<int> v;

    for(unsigned int i = 0; i < list().size(); i++)
    {
        if(list()[i].getBirthYear() >= f && list()[i].getBirthYear() <= l)
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

void ServiceLayer::erase(int n)
{
    dl.deletePerson(n);
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

//regular sorting. Reyndi að nota klasaföll, en það vill þýðandinn ekki.
bool sortByName2(const Persons &lhs, const Persons &rhs)
{ return lhs.getName() < rhs.getName(); }
bool sortByGender2(const Persons &lhs, const Persons &rhs)
{ return lhs.getGender() < rhs.getGender(); }
bool sortByBirthYear2(const Persons &lhs, const Persons &rhs)
{ return lhs.getBirthYear() < rhs.getBirthYear(); }
bool sortByDeathYear2(const Persons &lhs, const Persons &rhs)
{ return lhs.getDeathYear() < rhs.getDeathYear(); }

//reverse sorting. Reyndi að nota klasaföll, en það vill þýðandinn ekki.
bool rSortByName2(const Persons &lhs, const Persons &rhs)
{ return lhs.getName() > rhs.getName(); }
bool rSortByGender2(const Persons &lhs, const Persons &rhs)
{ return lhs.getGender() > rhs.getGender(); }
bool rSortByBirthYear2(const Persons &lhs, const Persons &rhs)
{ return lhs.getBirthYear() > rhs.getBirthYear(); }
bool rSortByDeathYear2(const Persons &lhs, const Persons &rhs)
{ return lhs.getDeathYear() > rhs.getDeathYear(); }

void ServiceLayer::sortByName(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //stable_sort(people.begin(), people.end(), sorter.sortByName);
        stable_sort(people.begin(), people.end(), sortByName2);
    }
    else //order == 2
    {
        //stable_sort(people.begin(), people.end(), sorter.rSortByName);
        stable_sort(people.begin(), people.end(), rSortByName2);
    }
    dl.setVector(people);
}

void ServiceLayer::sortByBirthYear(int order)
{

    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //stable_sort(people.begin(), people.end(), sorter.sortByBirthYear);
        stable_sort(people.begin(), people.end(), sortByBirthYear2);
    }
    else //order == 2
    {
        //stable_sort(people.begin(), people.end(), sorter.rSortByBirthYear);
        stable_sort(people.begin(), people.end(), rSortByBirthYear2);
    }
    dl.setVector(people);
}

void ServiceLayer::sortByDeathYear(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //stable_sort(people.begin(), people.end(), sorter.sortByDeathYear);
        stable_sort(people.begin(), people.end(), sortByDeathYear2);
    }
    else //order == 2
    {
        //stable_sort(people.begin(), people.end(), sorter.rSortByDeathYear);
        stable_sort(people.begin(), people.end(), rSortByDeathYear2);
    }
    dl.setVector(people);
}

void ServiceLayer::sortByGender(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //stable_sort(people.begin(), people.end(), sorter.sortByGender);
        stable_sort(people.begin(), people.end(), sortByGender2);
    }
    else //order == 2
    {
        //stable_sort(people.begin(), people.end(), sorter.rSortByGender);
        stable_sort(people.begin(), people.end(), rSortByGender2);
    }
    dl.setVector(people);
}

bool ServiceLayer::addFromFile(string input)
{
    return dl.loadFromOtherFile(input);

}
