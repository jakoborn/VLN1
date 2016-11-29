#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "servicelayer.h"

class ConsoleUI
{
private:
    ServiceLayer serve;

public:
    ConsoleUI();

    void run();
    void showData();
};

#endif // CONSOLEUI_H
