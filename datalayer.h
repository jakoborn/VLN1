#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include <string>
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
   void setVector(vector <Persons> p);

   void addPerson(const Persons& p);
};

#endif // DATALAYER_H
