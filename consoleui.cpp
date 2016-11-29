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
                sortData();

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
                cout << "Error! Invalid Input" << endl;
            }

    }

}

void ConsoleUI::showData()
{
    fstream file("textFile.txt");
    string content;
    while (getline(file, content))
    {
        cout << content << endl;
    }
}

void ConsoleUI::sortData()
{
    cout << "How would you like to sort the list?" << endl;
    cout << " ================================" << endl;
    cout << "Press 1 for Name" << endl;
    cout << "Press 2 for Birth Year" << endl;
    cout << "Press 3 for Death Year (Living Persons will not be shown)" << endl; //eða hvernig viljum við hafa þetta?
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
