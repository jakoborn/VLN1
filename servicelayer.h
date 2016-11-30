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

    vector<int> searchByYear(const int year);
    vector<int> searchByName(const string name);
    void add(const Persons& p);
    void sort(int type);
};

#endif // SERVICELAYER_H
