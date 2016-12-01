#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
private:
    ServiceLayer serve;
    void addData();
    void deleteData();
    void showData();
    void sortData();
    void searchData();
    void printLine();
    bool birthChecks(int birthYear, int deathYear);
    bool check();
    bool genderCheck(char &gender);


public:
    ConsoleUI();

    void run();
};

#endif // CONSOLEUI_H
