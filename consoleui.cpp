#include "consoleui.h"
#include "servicelayer.h"
#include <fstream>
#include <string>
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
       cout << " Press 1 to add" << endl;
       cout << " Press 2 to sort" << endl;
       cout << " Press 3 to list" << endl;
       cout << " Press 4 to search"  << endl;
       cout << " Press 5 to exit"     << endl;
       cout << " ================================" << endl;

       int choice = 0;
       cin >> choice;

            switch (choice)
            {
            case 1:
                addData();
                break;
            case 2:
                sortData();

                break;
            case 3:
                showData();
                break;
            case 4:
                searchData();
                break;
            case 5:
                run = false;
                break;
            default:
                cout << "Error! Invalid Input" << endl;
            }

    }

}


void ConsoleUI::addData()
{

}


void ConsoleUI::showData()
{

}

void ConsoleUI::searchData()
{
    cout << "How would you like to search the data?" << endl;
    cout << " =====================================" << endl;
    cout << " Press 1 to search by name" << endl;
    cout << " Press 2 to search by birth year" << endl;
    cout << "====================================="  << endl;

    int choice = 0;
    cin >> choice;

    switch(choice)
    {
    case 1:
        // Todo: search by name.
        break;
    case 2:
        // Todo:: search by birth year.
        break;

    default:
        cout << "Error! invalid input" << endl;
    }
}

void ConsoleUI::sortData()
{
    cout << "How would you like to sort the list?" << endl;
    cout << " ================================" << endl;
    cout << "Press 1 for Name" << endl;
    cout << "Press 2 for Birth Year" << endl;
    cout << "Press 3 for Death Year " << endl;
    cout << "Press 4 for Gender" << endl;
    cout << " ================================" << endl;

    int choice = 0;
    cin >> choice;

    switch (choice)
         {
         case 1:
        serve.sort(choice);
             break;
         case 2:
        serve.sort(choice);
             break;
         case 3:
        serve.sort(choice);
             break;
         case 4:
        serve.sort(choice);
             break;
         default:
             cout << "Error! Invalid input!" << endl;
         }


    //showData(); viljum við láta hann sýna listann strax?

}
