#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include <string>
#include "sortings.h"

using namespace std;

class DataLayer
{
    vector<Persons> people;

public:
   DataLayer();

   void loadFromFile();
   bool loadFromOtherFile(string input);
   void saveToFile();
   vector<Persons> getVector();
   void removeData(int &x);
   void setVector(vector <Persons> p);

   void addPerson(const Persons& p);
   void deletePerson(int n);
};

#endif // DATALAYER_H
