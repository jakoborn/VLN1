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
};

#endif // DATALAYER_H
