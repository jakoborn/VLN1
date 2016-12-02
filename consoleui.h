#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
private:
    ServiceLayer serve;
    void listData();

    void sortData();
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
    void sortByName(char input, int choice, int choice2, bool &error);
    void sortByBirthYear(char input, int choice, int choice2, bool &error);
    void sortByDeathYear(char input, int choice, int choice2, bool& error);
    void sortByGender(char input, int choice, int choice2, bool& error);
public:
    ConsoleUI();
    void run();
};

#endif // CONSOLEUI_H
