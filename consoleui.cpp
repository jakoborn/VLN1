#include "consoleui.h"
#include "servicelayer.h"
#include <iostream>

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    bool run = true;
    while (run)
    {
       cout << " ================================" << endl;
       cout << " Press 1 for sorting" << endl;
       cout << " Press 2 for listing" << endl;
       cout << " Press 3 for search"  << endl;
       cout << " Press 4 to exit"     << endl;
       cout << " ================================" << endl;

       int choice = 0;
       cin >> choice;

            switch (choice)
            {
            case 1:

                break;
            case 2:
                showData();
                break;
            case 3:
            //serve.search();
                break;
            case 4:
                run = false;
                break;
            default:
                cout << "error!" << endl;
            }

    }

}

void ConsoleUI::showData()
{

}
