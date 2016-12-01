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
<<<<<<< HEAD
   void removeData(int &x);
=======
   void setVector(vector <Persons> p);
>>>>>>> e09d9e10884eab8e70db941ec52e0503c06f2715

   void addPerson(const Persons& p);
};

#endif // DATALAYER_H
