#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include "datalayer.h"
#include "persons.h"

using namespace std;

class ServiceLayer
{
private:

    vector <Persons> persons;

public:
    ServiceLayer();

    int search();
    void add(string n, int bY, int dY, char g, bool a);
};

#endif // SERVICELAYER_H
