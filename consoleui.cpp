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

       char input = '0';
       cin >> input;
       int choice = input - '0';

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
    printLine();
    for(size_t i = 0; i < serve.list().size();i++)
    {
        cout << serve.list()[i].getName() << "\t " << serve.list()[i].getGender() << "\t" << serve.list()[i].getBirthYear() << "\t";
        if (serve.list()[i].getAlive()) {
            cout << "Alive\n";
        }
        else {
            cout << serve.list()[i].getDeathYear() << endl;
        }
    }

}

void ConsoleUI::searchData()
{
    bool error = false;
    do
    {
        cout << "How would you like to search the data?" << endl;
        cout << " =====================================" << endl;
        cout << " Press 1 to search by name" << endl;
        cout << " Press 2 to search by birth year" << endl;
        cout << " Press 3 to cancel" << endl;
        cout << "======================================"  << endl;

        char input = '0';
        cin >> input;
        int choice = input - '0';

        switch(choice)
        {
            case 1:
            {
                string n = " ";
                cout << "Enter name: ";
                cin >> n;
                vector<int> v_n = serve.searchByName(n);
                if (v_n.size() == 0) {
                    cout << "No results found\n";
                }
                else {
                    printLine();
                    for (unsigned int i = 0; i < v_n.size(); i++)
                    {
                        cout << serve.list()[v_n[i]].getName() << "\t " << serve.list()[v_n[i]].getGender() << "\t" << serve.list()[v_n[i]].getBirthYear() << "\t";
                        if (serve.list()[v_n[i]].getAlive())
                        {
                                    cout << "Alive\n";
                        }
                        else
                        {
                            cout << serve.list()[v_n[i]].getDeathYear() << endl;
                        }
                    }
                }
                error = false;
                break;
            }
            case 2:
            {
                int y = 0;
                cout << "Enter year: ";
                cin >> y;
                vector<int> v_y = serve.searchByYear(y);
                if (v_y.size() == 0) {
                    cout << "No results found\n";
                }
                else {
                    printLine();
                    for (unsigned int i = 0; i < v_y.size(); i++)
                    {
                        cout << serve.list()[v_y[i]].getName() << "\t " << serve.list()[v_y[i]].getGender() << "\t" << serve.list()[v_y[i]].getBirthYear() << "\t";
                        if (serve.list()[v_y[i]].getAlive())
                        {
                                    cout << "Alive\n";
                        }
                        else
                        {
                            cout << serve.list()[v_y[i]].getDeathYear() << endl;
                        }
                    }
                }
                error = false;
                break;
            }
            case 3:
                error = false;
                break;
            default:
            {
                cout << "Error! invalid input" << endl;
                error = true;
            }
        }
    } while (error);
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
    cout << "Press 5 to cancel" << endl;
    cout << " ================================" << endl;

    char input = '0';
    cin >> input;
    int choice = input - '0';

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
         case 5:
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

void ConsoleUI::printLine()
{
    cout.width(16);
    cout << left << "Name\t";
    cout <<  "\tGender" << "\t" << "Born" << "\t" << "Died" << endl;
    cout << "_____________________________________________________" << endl;
}
