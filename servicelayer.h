#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "datalayer.h"
#include "sortings.h"

using namespace std;

class ServiceLayer
{
    DataLayer dl;
    Sortings sorter;
public:
    ServiceLayer();
    vector<Persons> list();
    vector<int> searchByYear(const int year);
    vector<int> searchByName(const string name);
    vector<int> searchByGender(const char gender);
    vector<int> searchByRange(const int f, const int l);
    void add(const Persons& p);
    void erase(int n);
    void sorting(int type, int order);
    void sortByName(int order);
    void sortByBirthYear(int order);
    void sortByDeathYear(int order);
    void sortByGender(int order);
};

#endif // SERVICELAYER_H
