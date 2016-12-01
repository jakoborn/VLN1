#include "consoleui.h"

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
       cout << " Press 5 to delete" << endl;
       cout << " Press 6 to exit"     << endl;
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
                deleteData();
                break;
            case 6:
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
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter birth year: ";
    cin >> birthYear;
    cout << "Enter death year (0 for living person): ";
    cin >> deathYear;

    Persons newPerson(name, gender, birthYear, deathYear);
    serve.add(newPerson);
}

void ConsoleUI::deleteData()
{
    cout << "Enter name of person you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    int a = 0;
    for (unsigned int i = 0; i < serve.list().size(); i++) {
        if(n == serve.list()[i].getName()) {
            a = i;
            break;
        }
    }
    serve.erase(a);
}

void ConsoleUI::showData()
{
    printLine();
    for(size_t i = 0; i < serve.list().size();i++)
    {
        cout << serve.list()[i];
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
        cout << " ======================================"  << endl;

        char input = '0';
        cin >> input;
        int choice = input - '0';

        switch(choice)
        {
            case 1:
            {
                string n = " ";
                cout << "Enter name: ";
                cin >> ws;
                getline(cin, n);
                vector<int> vN = serve.searchByName(n);
                if (vN.size() == 0) {
                    cout << "No results found\n";
                }
                else {
                    printLine();
                    for (unsigned int i = 0; i < vN.size(); i++)
                    {
                        cout << serve.list()[vN[i]];
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
                vector<int> vY = serve.searchByYear(y);
                if (vY.size() == 0) {
                    cout << "No results found\n";
                }
                else {
                    printLine();
                    for (unsigned int i = 0; i < vY.size(); i++)
                    {
                        cout << serve.list()[vY[i]];
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
    cout << " Press 1 for Name" << endl;
    cout << " Press 2 for Birth Year" << endl;
    cout << " Press 3 for Death Year " << endl;
    cout << " Press 4 for Gender" << endl;
    cout << " Press 5 to cancel" << endl;
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
    cout << left << "Name";
    cout <<  "\tGender\tBorn\tDied" << endl;
    cout << "_____________________________________________________" << endl;
}
