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
    void sortByName(int order);
    void sortByGender(int order);
    void sortByBirthYear(int order);
    void sortByDeathYear(int order);
    void add(const Persons& p);
    bool addFromFile(string input);
    vector<int> searchByName(const string name);
    vector<int> searchByGender(const char gender);
    vector<int> searchByYear(const int year);
    vector<int> searchByRange(const int f, const int l);
    void deletePerson(int n);
    bool saveToOtherFile(string input);
};

#endif // SERVICELAYER_H
