#ifndef DATALAYER_H
#define DATALAYER_H

#include <vector>
#include <string>
#include "persons.h"

using namespace std;

class DataLayer
{
    vector<Persons> people; //A vector which holds the People on the list.
public:
   DataLayer(); //Default Constructor, which runs the function loadFromFile().

   void loadFromFile(); //Default loading from the same directory as the programme from the default file "science.txt".
   bool loadFromOtherFile(string input); //When you want to load from a different file. If successful, it will return true, add the people from the file, and autosave.
   void saveToFile(); //The Autosave function. Will save the people in the vector to the file "science.txt". This will delete whatever was in it before.
   bool saveToOtherFile(string input); //Custom Save function. Will try to save to the given file directory. Returns true with success.
   vector<Persons> getVector(); //Returns the vector with all the scientists in it.
   void setVector(vector <Persons> p); //Sets the vector of People to the given. Does not Autosave.
   void addPerson(const Persons& p); //Adds the given Person to the vector of people. Autosaves afterwards.
   void deletePerson(int n); //Removes the person in the vector in place n. Autosaves afterwards.
};

#endif // DATALAYER_H
