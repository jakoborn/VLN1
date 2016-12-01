#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "datalayer.h"

using namespace std;

class ServiceLayer
{
    DataLayer dl;
public:
    ServiceLayer();
    vector<Persons> list();
    vector<int> removeByName();
    vector<int> searchByYear(const int year);
    vector<int> searchByName(const string name);
    void add(const Persons& p);
    void sort(int type);
};

#endif // SERVICELAYER_H
