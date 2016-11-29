#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include "persons.h"

using namespace std;

class DataLayer
{
    vector<Persons> people;
public:
   DataLayer();

   void loadFromFile();
   void saveToFile();
   void addPerson(const Persons& p);
   void listPersons();
   void sortByName();
   void sortByBirthYear();
   void sortByDeathYear();
   void sortByGender();
};

#endif // DATALAYER_H
