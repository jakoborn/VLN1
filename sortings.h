#ifndef SORTINGS_H
#define SORTINGS_H

#include "persons.h"

class Sortings
{
public:
    Sortings();

    //regular sorting
    bool sortByName(const Persons &lhs, const Persons &rhs);
    bool sortByGender(const Persons &lhs, const Persons &rhs);
    bool sortByBirthYear(const Persons &lhs, const Persons &rhs);
    bool sortByDeathYear(const Persons &lhs, const Persons &rhs);

    //reverse sorting
    bool rSortByName(const Persons &lhs, const Persons &rhs);
    bool rSortByGender(const Persons &lhs, const Persons &rhs);
    bool rSortByBirthYear(const Persons &lhs, const Persons &rhs);
    bool rSortByDeathYear(const Persons &lhs, const Persons &rhs);
};

#endif // SORTINGS_H
