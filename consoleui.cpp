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
       cout << " Press 5 to remove scientist"     << endl;
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
                removeData();
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
    cout << endl;
    printLine();
    for(size_t i = 0; i < serve.list().size();i++)
    {
        cout << serve.list()[i];
    }
     cout << "_____________________________________________________" << endl;

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
                vector<int> v_n = serve.searchByName(n);
                if (v_n.size() == 0) {
                    cout << "No results found\n";
                }
                else {
                    printLine();
                    for (unsigned int i = 0; i < v_n.size(); i++)
                    {
                        cout << serve.list()[v_n[i]];
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
                        cout << serve.list()[v_y[i]];
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
    char input = '0';
    int choice = 0;
    int choice2 = 0;
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

        cin >> input;
        choice = input - '0';
        choice2 = 0;
        input = '1';



            switch (choice)
                 {
                 case 1:
                    do
                    {
                        if (input != '1' && input != '2' && input != '3')
                        {
                            cout << "Error! Invalid input" << endl;
                        }
                        cout << "Regular or Reversed sorting?" << endl;
                        cout << " ================================" << endl;
                        cout << "Press 1 for regular sorting" << endl;
                        cout << "Press 2 for reversed sorting" << endl;
                        cout << "Press 3 to cancel" << endl;
                        cout << " ================================" << endl;

                        cin >> input;
                    }
                    while (input != '1' && input != '2' && input != '3');
                    choice2 = input - '0';

                    if (choice2 == 1 || choice2 == 2)
                    {
                        serve.sorting(choice, choice2);
                        error = false;
                    }
                    else
                    {
                        error = true;
                    }
                    break;
                 case 2:
                    do
                    {
                        if (input != '1' && input != '2' && input != '3')
                        {
                            cout << "Error! Invalid input" << endl;
                        }
                        cout << "Regular or Reversed sorting?" << endl;
                        cout << " ================================" << endl;
                        cout << "Press 1 for regular sorting" << endl;
                        cout << "Press 2 for reversed sorting" << endl;
                        cout << "Press 3 to cancel" << endl;
                        cout << " ================================" << endl;

                        cin >> input;
                    }
                    while (input != '1' && input != '2' && input != '3');
                    choice2 = input - '0';

                    if (choice2 == 1 || choice2 == 2)
                    {
                        serve.sorting(choice, choice2);
                        error = false;
                    }
                    else
                    {
                        error = true;
                    }
                    break;
                 case 3:
                    do
                    {
                        if (input != '1' && input != '2' && input != '3')
                        {
                            cout << "Error! Invalid input" << endl;
                        }
                        cout << "Regular or Reversed sorting?" << endl;
                        cout << " ================================" << endl;
                        cout << "Press 1 for regular sorting" << endl;
                        cout << "Press 2 for reversed sorting" << endl;
                        cout << "Press 3 to cancel" << endl;
                        cout << " ================================" << endl;

                        cin >> input;
                    }
                    while (input != '1' && input != '2' && input != '3');
                    choice2 = input - '0';

                    if (choice2 == 1 || choice2 == 2)
                    {
                        serve.sorting(choice, choice2);
                        error = false;
                    }
                    else
                    {
                        error = true;
                    }
                    break;
                 case 4:
                    do
                    {
                        if (input != '1' && input != '2' && input != '3')
                        {
                            cout << "Error! Invalid input" << endl;
                        }
                        cout << "Sort by Males or Females?" << endl;
                        cout << " ================================" << endl;
                        cout << "Press 1 for sorting by Females first" << endl;
                        cout << "Press 2 for sorting by Males first" << endl;
                        cout << "Press 3 to cancel" << endl;
                        cout << " ================================" << endl;

                        cin >> input;
                    }
                    while (input != '1' && input != '2' && input != '3');
                    choice2 = input - '0';

                    if (choice2 == 1 || choice2 == 2)
                    {
                        serve.sorting(choice, choice2);
                        error = false;
                    }
                    else
                    {
                        error = true;
                    }
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

    if (choice != 5) //if you press cancel, you don't want to see the list, do you?
    {
        showData();
    }
}

void ConsoleUI::printLine()
{
    cout.width(16);
    cout << left << "Name";
    cout <<  "\tGender\tBorn\tDied" << endl;
    cout << "_____________________________________________________" << endl;
}
void ConsoleUI::removeData()
{
    string str;
    cout << "Enter the name of the scientist you want to remove: ";
    cin  >> str;


}
