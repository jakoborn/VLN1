#include "datalayer.h"
#include "persons.h"

#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

DataLayer::DataLayer()
{


}

vector <Persons> DataLayer::loadFromFile()
{
    vector<Persons> myVec;
    string input, name;
    int bY, dY;
    char gender;
    bool alive;
    ifstream inStream;
    inStream.open("textFile.txt");
    int counter = 0;

    while(inStream >> input)
    {
        //TODO:
        if(counter % 5 == 0 )    // Name
        {
            name = input;

        }
        if(counter % 5 == 1)    // birthYear
        {
            int value = atoi(input.c_str());
          bY = value;

        }
        if(counter % 5 == 2)    //deathYear
        {
            int value = atoi(input.c_str());
            dY= value;
        }
        if(counter % 5 == 3)    //gender
        {
            int value = atoi(input.c_str());
            gender = value;

        }
        if(counter % 5 == 4)    //Alive
        {
            if (input == "true")
            {
               alive = true;
            }
            else
            {
                alive = false;
            }

            Persons newPerson(name, bY, dY, gender, alive);
            myVec.push_back(newPerson);
        }
        counter++;
    }

    return myVec;
}

