#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
private:
    ServiceLayer serve;
    void showData();
    void sortData();
    void addData();
    void addPersonManually();
    void addPeopleFromFile();
    void searchData();
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
