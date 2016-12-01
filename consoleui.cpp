#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::OnlyTakeOneInput()
{
    cin.clear();
    fflush(stdin);
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
       OnlyTakeOneInput();
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

    cout << "Enter name: ";
    cin >> ws;
    getline(cin,name);
    if(!isupper(name[0]))
    {
        name[0] = toupper(name[0]);
    }
    cout << "Enter gender (M/F): ";
    cin >> gender;
    OnlyTakeOneInput();
    if(genderCheck(gender) == false)
    {
        if(check() == false)
        {
            return;
        }
    }
    cout << "Enter birth year: ";
    cin >> birthYear;
    OnlyTakeOneInput();
    cout << "Enter death year (0 for living person): ";
    cin >> deathYear;
    OnlyTakeOneInput();
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
bool ConsoleUI::genderCheck(char& gender)
{

   if(gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F')
   {
        if(gender == 'm')
        {
            gender = 'M';
        }
        if(gender == 'f')
        {
            gender = 'F';
        }

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
        return true;
    }
    else
    {
       return false;
    }
}

void ConsoleUI::deleteData()
{
    cout << "Enter name of scientist you would like to delete: ";
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
bool ConsoleUI::birthChecks(int birthYear, int deathYear)
{
    if(!isdigit(birthYear) && !isdigit(deathYear))
    {

        cout << "Please do not input letter" << endl;
        return false;
    }
    if(birthYear < 0 )
    {
        cout << "The scientist can not be born before the year zero." << endl;
        return false;

    }
    if(birthYear > 2016)
    {
        cout << "The scientist can not be born after the year 2016" << endl;

        return false;

    }
    if(deathYear < birthYear && deathYear != 0)
    {
        cout << "The scientist cannot die before they are born!" << endl;
        return false;

    }
    if(deathYear > 2016 )
    {

        cout << "The scientist is still alive.";
        return false;
    }
    if(deathYear - birthYear > 123)
    {
        cout << "That is to old, the oldest man was 122 years old!" << endl;
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
        cout << " Press 3 to search for gender" << endl;
        cout << " Press 4 to search by birth year range" << endl;
        cout << " Press 5 to cancel" << endl;
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
            {
                char gender;
                cout << "Enter gender (M/F): ";
                cin >> gender;
                if(genderCheck(gender) == false)
                {
                    searchData();
                }
                vector<int> v_g = serve.searchByGender(gender);
                if (v_g.size() == 0)
                {
                    cout << "No results found" << endl;
                }
                else
                {
                    printLine();
                    for (unsigned int i = 0; i < v_g.size(); i++)
                    {
                        cout << serve.list()[v_g[i]];
                    }
                }
                break;
            }
            case 4:
            {
                int f = 0, l = 0;
                cout << "Enter first year in range: ";
                cin >> f;
                cout << "Enter last year in range: ";
                cin >> l;

                vector<int> v_r = serve.searchByRange(f,l);
                if (v_r.size() == 0)
                {
                    cout << "No results found" << endl;
                }
                else
                {
                    printLine();
                    for (unsigned int i = 0; i < v_r.size(); i++)
                    {
                        cout << serve.list()[v_r[i]];
                    }
                }
                break;
            }

            case 5:
                error = false;
                break;
            default:
            {
                cout << "Error! Invalid input" << endl;
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
        cout << " Press 5 to Cancel" << endl;
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
                        cout << "Press 1 for sorting by females first" << endl;
                        cout << "Press 2 for sorting by males first" << endl;
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
