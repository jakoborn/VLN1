#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include "persons.h"
#include "sortings.h"

using namespace std;

class DataLayer
{
    vector<Persons> people;
    Sortings sorter;
public:
   DataLayer();

   void loadFromFile();
   void saveToFile();
   vector<Persons> getVector();

   void addPerson(const Persons& p);
   void sortByName();
   void sortByBirthYear();
   void sortByDeathYear();
   void sortByGender();
};

#endif // DATALAYER_H
