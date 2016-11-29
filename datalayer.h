#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include "persons.h"

using namespace std;

class DataLayer
{
public:
    DataLayer();

    vector <Persons> loadFromFile();

};

#endif // DATALAYER_H
