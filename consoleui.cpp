#include "consoleui.h"
#include "servicelayer.h"
#include <iostream>

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{

       cout << " ================================" << endl;
       cout << " Press 1 for sorting" << endl;
       cout << " Press 2 for listing" << endl;
       cout << " Press 3 for search"  << endl;
       cout << " ================================" << endl;

       int choice = 0;
       cin >> choice;

       bool error = false;

       while (!error)
       {
            switch (choice)
            {
            case 1:

            case 2:

            case 3:
            //serve.search();

            default:
                cout << "error!" << endl;
                error = true;
            }
       }

}

void ConsoleUI::showData()
{

}
