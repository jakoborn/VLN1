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
    void add();
};

#endif // SERVICELAYER_H
