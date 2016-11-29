#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include "datalayer.h"
#include "persons.h"

using namespace std;

class ServiceLayer
{
    DataLayer dl;
public:
    ServiceLayer();
    vector<Persons> list();

    int search();
    void add();
    void sort(int type);
};

#endif // SERVICELAYER_H
