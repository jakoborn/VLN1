#ifndef SERVICELAYER_H
#define SERVICELAYER_H

#include <vector>
#include "datalayer.h"

using namespace std;

class ServiceLayer
{
private:

    vector <DataLayer> persons;

public:
    ServiceLayer();

    int search();
    void add();
};

#endif // SERVICELAYER_H
