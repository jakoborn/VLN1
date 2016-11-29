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

   vector <Persons>  loadFromFile();
   void loadIntoFile();

};

#endif // DATALAYER_H
