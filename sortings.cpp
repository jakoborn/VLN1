#include "sortings.h"

Sortings::Sortings()
{

}
//regular sorting
bool Sortings::sortByName(const Persons &lhs, const Persons &rhs)
{
    return lhs.getName() < rhs.getName();
}
bool Sortings::sortByGender(const Persons &lhs, const Persons &rhs)
{
    return lhs.getGender() < rhs.getGender();
}

bool Sortings::sortByBirthYear(const Persons &lhs, const Persons &rhs)
{
    return lhs.getBirthYear() < rhs.getBirthYear();
}

bool Sortings::sortByDeathYear(const Persons &lhs, const Persons &rhs)
{
    return lhs.getDeathYear() < rhs.getDeathYear();
}

//reverse sorting
bool Sortings::rSortByName(const Persons &lhs, const Persons &rhs)
{
    return lhs.getName() > rhs.getName();
}
bool Sortings::rSortByGender(const Persons &lhs, const Persons &rhs)
{
    return lhs.getGender() > rhs.getGender();
}

bool Sortings::rSortByBirthYear(const Persons &lhs, const Persons &rhs)
{
    return lhs.getBirthYear() > rhs.getBirthYear();
}

bool Sortings::rSortByDeathYear(const Persons &lhs, const Persons &rhs)
{
    return lhs.getDeathYear() > rhs.getDeathYear();
}
