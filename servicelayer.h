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
    void add(const Persons& p);
    bool addFromFile(string input);
    vector<int> searchByName(const string name);
    vector<int> searchByGender(const char gender);
    vector<int> searchByYear(const int year);
    vector<int> searchByRange(const int f, const int l);
    void erase(int n);
    void sorting(int type, int order);
    void sortByName(int order);
    void sortByBirthYear(int order);
    void sortByDeathYear(int order);
    void sortByGender(int order);
};

#endif // SERVICELAYER_H
