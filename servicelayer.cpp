#include <algorithm>
#include "servicelayer.h"

ServiceLayer::ServiceLayer()
{
    sortByName(1); //Defaults to sorting the list by name.
}

//Returns a vector containing the people
vector<Persons> ServiceLayer::list()
{
   return dl.getVector();
}

//regular sorting. For some unknown reason, these functions
// gave strange errors when we tried to put them in a class
//(both a separate class and this class). It was only okay if
// we used these global functions.
bool sortByName2(const Persons &lhs, const Persons &rhs)
{
    return lhs.getName() < rhs.getName();
}
bool sortByGender2(const Persons &lhs, const Persons &rhs)
{
    return lhs.getGender() < rhs.getGender();
}
bool sortByBirthYear2(const Persons &lhs, const Persons &rhs)
{
    return lhs.getBirthYear() < rhs.getBirthYear();
}
bool sortByDeathYear2(const Persons &lhs, const Persons &rhs)
{
    if (lhs.getDeathYear() == 0 && rhs.getDeathYear() == 0)
    {
        return lhs.getDeathYear() < rhs.getDeathYear();
    }
    else if (lhs.getDeathYear() == 0)
    {
        return lhs.getDeathYear() > rhs.getDeathYear();
    }
    else if (rhs.getDeathYear() == 0)
    {
        return lhs.getDeathYear() > rhs.getDeathYear();
    }
    else
    {
        return lhs.getDeathYear() < rhs.getDeathYear();
    }
}

//reverse sorting. Same with these as above.
bool rSortByName(const Persons &lhs, const Persons &rhs)
{
    return lhs.getName() > rhs.getName();
}
bool rSortByGender(const Persons &lhs, const Persons &rhs)
{
    return lhs.getGender() > rhs.getGender();
}
bool rSortByBirthYear(const Persons &lhs, const Persons &rhs)
{
    return lhs.getBirthYear() > rhs.getBirthYear();
}
bool rSortByDeathYear(const Persons &lhs, const Persons &rhs)
{
    if (lhs.getDeathYear() == 0 && rhs.getDeathYear() == 0)
    {
        return lhs.getDeathYear() > rhs.getDeathYear();
    }
    else if (lhs.getDeathYear() == 0)
    {
        return lhs.getDeathYear() < rhs.getDeathYear();
    }
    else if (rhs.getDeathYear() == 0)
    {
        return lhs.getDeathYear() < rhs.getDeathYear();
    }
    else
    {
        return lhs.getDeathYear() > rhs.getDeathYear();
    }
}

//Orders the people alphabetically
void ServiceLayer::sortByName(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //A-Z
        stable_sort(people.begin(), people.end(), sortByName2);
    }
    else //order == 2
    {
        //Z-A
        stable_sort(people.begin(), people.end(), rSortByName);
    }
    dl.setVector(people);
}

//Orders the people by gender
void ServiceLayer::sortByGender(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //Females first
        stable_sort(people.begin(), people.end(), sortByGender2);
    }
    else //order == 2
    {
        //Males first
        stable_sort(people.begin(), people.end(), rSortByGender);
    }
    dl.setVector(people);
}

//Orders the people by year of birth
void ServiceLayer::sortByBirthYear(int order)
{

    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //Ascending
        stable_sort(people.begin(), people.end(), sortByBirthYear2);
    }
    else //order == 2
    {
        //Descending
        stable_sort(people.begin(), people.end(), rSortByBirthYear);
    }
    dl.setVector(people);
}

//Orders the people by year of death
void ServiceLayer::sortByDeathYear(int order)
{
    vector <Persons> people = dl.getVector();
    if (order == 1)
    {
        //Ascending
        stable_sort(people.begin(), people.end(), sortByDeathYear2);
    }
    else //order == 2
    {
        //Descending
        stable_sort(people.begin(), people.end(), rSortByDeathYear);
    }
    dl.setVector(people);
}

//Adds a new person
void ServiceLayer::add(const Persons& p)
{
    dl.addPerson(p);
}

//Adds people from file
bool ServiceLayer::addFromFile(string input)
{
    return dl.loadFromOtherFile(input);
}

//Returns a vector containing places (in vector of people) of the people whose names contain 'name'
vector<int> ServiceLayer::searchByName(const string name)
{
    vector<int> v;
    for (unsigned int i = 0; i < list().size(); i++)
    {
        if (name.length() <= list()[i].getName().length())
        {
            //Checks if search term 'name' is a substring in name of person in place i
            for (unsigned int p = 0; p <=(list()[i].getName().length() - name.length()); p++)
            {
                if(name == list()[i].getName().substr(p, name.length()))
                {
                    v.push_back(i);
                    break;
                }
            }
        }
    }
    return v;
}

//Returns a vector containing places (in vector of people) of the people of the given gender
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

//Returns a vector containing places (in vector of people) of the people born in the given year
vector<int> ServiceLayer::searchByYear(const int year)
{
    vector<int> v;
    for (unsigned int i = 0; i < list().size(); i++)
    {
        if (list()[i].getBirthYear() == year)
        {
            v.push_back(i);
        }
    }
    return v;
}

//Returns a vector containing places (in vector of people) of the people born in the given year range
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

//Deletes person in place n (in vector of people)
void ServiceLayer::deletePerson(int n)
{
    dl.deletePerson(n);
}

//Saves list of people to file other than default
bool ServiceLayer::saveToOtherFile(string input)
{
    return dl.saveToOtherFile(input);
}
