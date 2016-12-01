#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include "datalayer.h"
#include "sortings.h"

using namespace std;

class ServiceLayer
{
    DataLayer dl;
public:
    ServiceLayer();
    vector<Persons> list();
<<<<<<< HEAD
    vector<int> removeByName();
=======
    Sortings sorter;

>>>>>>> e09d9e10884eab8e70db941ec52e0503c06f2715
    vector<int> searchByYear(const int year);
    vector<int> searchByName(const string name);
    vector<int> searchByGender(const char gender);
    void add(const Persons& p);
    void sorting(int type, int order);
    void sortByName(int order);
    void sortByBirthYear(int order);
    void sortByDeathYear(int order);
    void sortByGender(int order);
};

#endif // SERVICELAYER_H
