#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
private:
    ServiceLayer serve;
    void addData();
    void showData();
    void sortData();
    void searchData();
    void printLine();
    void removeData();


public:
    ConsoleUI();

    void run();
};

#endif // CONSOLEUI_H
