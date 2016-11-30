#include "sortings.h"

Sortings::Sortings()
{

}

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
