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
    if(genderCheck(gender) == false)
    {
        if(check() == false)
        {
            return;
        }
    }
    cout << "Enter birth year: ";
    cin >> birthYear;
    cout << "Enter death year (0 for living person): ";
    cin >> deathYear;
    if(birthChecks(birthYear, deathYear) == false)
    {
        check();    // Checks if you want to try to input again.
    }
    else
    {
        Persons newPerson(name, gender, birthYear, deathYear);
        serve.add(newPerson);
    }

}
bool ConsoleUI::genderCheck(char gender)
{

   if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
   {

       return true;
   }
   else
   {
       cout << "Wrong input for gender!" << endl;
       return false;
   }

}

bool ConsoleUI::check()
{
    char continuel;
    cout << "Do you want to try again? (Y for yes and N for No)" ;
    cin  >> continuel;
    if(continuel == 'Y' || continuel == 'y')
    {
        addData();
    }
    else
    {
       return false;
    }
}

bool ConsoleUI::birthChecks(int birthYear, int deathYear)
{

    if(birthYear < 0 )
    {
        cout << "You can not be born before the year zero." << endl;
        return false;

    }
    if(birthYear > 2016)
    {
        cout << "You can not be born after the year 2016" << endl;
        return false;

    }
    if(deathYear < birthYear)
    {
        cout << "You cannot die before you are born!" << endl;
        return false;

    }
    if(deathYear > 2016)
    {

        cout << "You are Still alive.";
        return false;
    }
        return true;
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
void ConsoleUI::removeData()
{
    string str;
    cout << "Enter the name of the scientist you want to remove: " << endl;

}
