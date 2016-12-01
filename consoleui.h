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


public:
    ConsoleUI();

    void run();
};

#endif // CONSOLEUI_H
