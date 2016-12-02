#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
    ServiceLayer serve;
    // Lists the data from the vector.
    void listData();
    void sortData();
    void sortByName(char input, int order, bool &error);
    void sortByGender(char input, int order, bool& error);
    void sortByBirthYear(char input, int order, bool &error);
    void sortByDeathYear(char input, int order, bool& error);
    void addData();
    void addPersonManually();
    void addPeopleFromFile();
    void searchData();
    void searchByName();
    void searchByGender();
    void searchByBirthYear();
    void searchByYearRange();
    void deleteData();
    bool validYear(const string& s, int& year);
    bool birthChecks(int birthYear, int deathYear);

    bool check();
    bool genderCheck(char &gender);
    void OnlyTakeOneInput();
    void printLine();
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
