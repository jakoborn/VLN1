#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include <string>
#include "persons.h"

using namespace std;

class DataLayer
{
    vector<Persons> people;
public:
   DataLayer(); //Default Constructor, which runs the function loadFromFile().

   void loadFromFile(); //Default loading from the same directory as the program from the default file "science.txt".
   bool loadFromOtherFile(string input); //When you want to load from a different file. If successful, it will return true, add the people from the file, and autosave.
   void saveToFile(); //The Autosave function. Will save the people in the vector to the file "science.txt". This will delete whatever was in it before.
   bool saveToOtherFile(string input); //Custom Save function. Will try to save to the given file directory. Returns true with success.
   vector<Persons> getVector();
   void setVector(vector <Persons> p);
   void addPerson(const Persons& p);
   void deletePerson(int n);
};

#endif // DATALAYER_H
