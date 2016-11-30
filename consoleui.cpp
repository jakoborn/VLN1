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
    string name;
    char gender;
    int birthYear;
    int deathYear;

    cout << "Enter Name: ";
    cin >> ws;
    getline(cin,name);
    cout << "Enter gender (M/F): ";
    cin >> gender;
    cout << "Enter birth year: ";
    cin >> birthYear;
    cout << "Enter death year (0 for living person): ";
    cin >> deathYear;

    Persons newPerson(name, gender, birthYear, deathYear);
    serve.add(newPerson);
}


void ConsoleUI::showData()
{
    for(size_t i = 0; i < serve.list().size();i++)
    {
        cout << serve.list()[i] ;
    }

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
    {
        string n = " ";
        cout << "Enter name: ";
        cin >> n;
        vector<int> v_n = serve.searchByName(n);
        for (unsigned int i = 0; i < v_n.size(); i++) {
            cout << serve.list()[v_n[i]];
        }
        if (v_n.size() == 0) {
            cout << "No results found\n";
        }
        break;
    }
    case 2:
    {
        int y = 0;
        cout << "Enter year: ";
        cin >> y;
        vector<int> v_y = serve.searchByYear(y);
        for (unsigned int i = 0; i < v_y.size(); i++) {
            cout << serve.list()[v_y[i]];
        }
        if (v_y.size() == 0) {
            cout << "No results found\n";
        }
        break;
    }
    default:
    {
        cout << "Error! invalid input" << endl;
    }
}
}

void ConsoleUI::sortData()
{

    bool error = false;

    do
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
            error = false;
            break;
         case 2:
            serve.sort(choice);
            error = false;
            break;
         case 3:
            serve.sort(choice);
            error = false;
            break;
         case 4:
            serve.sort(choice);
            error = false;
            break;
         default:
             cout << "Error! Invalid input!" << endl;
             error = true;
         }
    }

    while (error);

    showData();
}
