#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
private:
    ServiceLayer serve;
    void showData();
public:
    ConsoleUI();

    void run();
};

#endif // CONSOLEUI_H
