#include <ctime>
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
       cout << " Press 1 to list the scientists"   << endl;
       cout << " Press 2 to sort the scientists"   << endl;
       cout << " Press 3 to add a scientist"       << endl;
       cout << " Press 4 to search the list"       << endl;
       cout << " Press 5 to remove a scientist"    << endl;
       cout << " Press 6 to exit"                  << endl;
       cout << " ================================" << endl;

       char input = '0';
       cin >> input;
       OnlyTakeOneInput();
       int choice = input - '0';

            switch (choice)
            {
            case 1:
            {
                listData();
                break;
            }
            case 2:
            {
                sortData();
                break;
            }
            case 3:
            {
                addData();
                break;
            }
            case 4:
            {
                searchData();
                break;
            }
            case 5:
            {
                deleteData();
                break;
            }
            case 6:
            {
                run = false;
                break;
            }
            default:
            {
                cout << "Error! Invalid input" << endl;
            }
        }
    }
}

void ConsoleUI::listData()
{
    cout << endl;
    printLine();

    for(size_t i = 0; i < serve.list().size();i++)
    {
        cout << serve.list()[i];
    }
     cout << "_____________________________________________________" << endl;

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
        cout << " ================================"    << endl;
        cout << " Press 1 to sort by name"             << endl;
        cout << " Press 2 to sort by birth year"       << endl;
        cout << " Press 3 to sort by death year "      << endl;
        cout << " Press 4 to sort by gender"           << endl;
        cout << " Press 5 to Cancel"                   << endl;
        cout << " ================================"    << endl;

        cin >> input;
        OnlyTakeOneInput();
        choice = input - '0';
        choice2 = 0;
        input = '1';

            switch (choice)
            {
            case 1:
            {
                sortByName(input, choice, choice2, error);
                break;
            }
             case 2:
            {
                    sortByBirthYear(input, choice, choice2, error);
                    break;
            }
             case 3:
                {
                    sortByDeathYear(input, choice, choice2, error);
                    break;
                }
             case 4:
            {
                    sortByGender(input, choice, choice2, error);
                    break;
            }
             case 5:
            {
                error = false;
                break;
            }
             default:
            {
                 cout << "Error! Invalid input!" << endl;
                 error = true;
            }
        }
    }
    while (error);

    if (choice != 5) //if you press cancel, you don't want to see the list, do you?
    {
        listData();
    }
}
void ConsoleUI::sortByName(char input, int choice, int choice2, bool& error)
{
    do
    {
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
        cout << "Regular or Reversed sorting?"      << endl;
        cout << " ================================" << endl;
        cout << "Press 1 for regular sorting"       << endl;
        cout << "Press 2 for reversed sorting"      << endl;
        cout << "Press 3 to cancel"                 << endl;
        cout << " ================================" << endl;

        cin >> input;
        OnlyTakeOneInput();
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
}
void ConsoleUI::sortByBirthYear(char input, int choice, int choice2, bool& error)
{
    do
    {
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
        cout << "Ascending or Descending sorting?"    << endl;
        cout << " ================================"   << endl;
        cout << "Press 1 to sort by ascending order"  << endl;
        cout << "Press 2 to sort by descending order" << endl;
        cout << "Press 3 to cancel"                   << endl;
        cout << " ================================"   << endl;
        cin >> input;
        OnlyTakeOneInput();
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
}

void ConsoleUI::sortByDeathYear(char input, int choice, int choice2, bool& error)
{
    do
    {
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
        cout << "Ascended or Descended sorting?"      << endl;
        cout << " ================================"   << endl;
        cout << "Press 1 to sort by ascending order"  << endl;
        cout << "Press 2 to sort by descending order" << endl;
        cout << "Press 3 to cancel"                   << endl;
        cout << " ================================"   << endl;

        cin >> input;
        OnlyTakeOneInput();
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
}

void ConsoleUI::sortByGender(char input, int choice, int choice2, bool& error)
{
    do
    {
        if (input != '1' && input != '2' && input != '3')
        {
            cout << "Error! Invalid input" << endl;
        }
        cout << "Sort by Males or Females?"         << endl;
        cout << " ================================" << endl;
        cout << "Press 1 to sort by females first"  << endl;
        cout << "Press 2 to sort by males first"    << endl;
        cout << "Press 3 to cancel"                 << endl;
        cout << " ================================" << endl;

        cin >> input;
        OnlyTakeOneInput();
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
}

void ConsoleUI::addData()
{
    bool error = false;
    do
    {
        cout << " ================================" << endl;
        cout << " Press 1 to add manually"          << endl;
        cout << " Press 2 to add from file"         << endl;
        cout << " Press 3 to cancel"                << endl;
        cout << " ================================" << endl;

        char input = '0';
        cin >> input;
        OnlyTakeOneInput();
        int choice = input - '0';

        switch (choice)
        {
        case 1:
        {
            addPersonManually();
            error = false;
            break;
        }
        case 2:
        {
            addPeopleFromFile();
            error = false;
            break;
        }
        case 3:
        {
            error = false;
            break;
        }
        default:
        {
            cout << "Error! Invalid input" << endl;
            error = true;
            break;
        }
        }
    }
    while (error == true);
}

void ConsoleUI::addPersonManually()
{
    string name, year;
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
    if(!genderCheck(gender))
    {
        if(!check())
        {
            return;
        }
    }
    while(!validYear(year, birthYear))
    {
        cout << "Enter birth year: ";
        cin >> year;
        OnlyTakeOneInput();
        if (!validYear(year, birthYear))
        {
            cout << "Invalid input!\n";
        }
    }
    year = " ";
    while(!validYear(year, deathYear))
    {
        cout << "Enter death year (0 for living person): ";
        cin >> year;
        OnlyTakeOneInput();
        if (!validYear(year, deathYear))
        {
            cout << "Invalid input!\n";
        }
    }
    if(!birthChecks(birthYear, deathYear))
    {
        check();    // Checks if you want to try to input again.
    }
    else
    {
        Persons newPerson(name, gender, birthYear, deathYear);
        int a = 0;
        for (unsigned int i = 0; i < serve.list().size(); i++)
        {
            if (newPerson == serve.list()[i])
            {
                cout << "Scientist already on list!\n";
                a++;
                break;
            }
        }
        if (a ==0)
        {
            serve.add(newPerson);
            cout << "Scientist added\n";
        }
    }

}

void ConsoleUI::addPeopleFromFile()
{
    string fileName = "";
    bool fileOpenFail = false;

    do
    {
        cout << "Enter the full path of the file, or the name of the file, if the file is in the same directory: " << endl;
        cin >> fileName;
        if(serve.addFromFile(fileName))
        {
            cout << "Success!" << endl;
            fileOpenFail = false;
        }
        else
        {
            cout << "Error! Failed to open file" << endl;
            char continuel;
            cout << "Do you want to try again? (Y for yes and N for no) " ;
            cin  >> continuel;
            if(continuel != 'Y' && continuel != 'y')
            {
                fileOpenFail = false;
            }
            else
            {
                fileOpenFail = true;
            }
        }
    }
    while (fileOpenFail);
}

void ConsoleUI::searchData()
{
    bool error = false;
    do
    {
        cout << "How would you like to search the data?"  << endl;
        cout << " ====================================="  << endl;
        cout << " Press 1 to search by name"              << endl;
        cout << " Press 2 to search by birth year"        << endl;
        cout << " Press 3 to search by gender"            << endl;
        cout << " Press 4 to search by birth year range"  << endl;
        cout << " Press 5 to cancel"                      << endl;
        cout << " ======================================" << endl;

        char input = '0';
        cin >> input;
        OnlyTakeOneInput();
        int choice = input - '0';

        switch(choice)
        {
            case 1:
            {
                searchByName();
                error = false;
                break;
            }
            case 2:
            {
                searchByBirthYear();
                error = false;
                break;
            }
            case 3:
            {
                searchByGender();
                break;
            }
            case 4:
            {
                searchByYearRange();
                break;
            }

            case 5:
            {
                error = false;
                break;
            }
            default:
            {
                cout << "Error! Invalid input" << endl;
                error = true;
            }
        }
    }
    while (error);
}

void ConsoleUI::searchByName()
{
    string n = " ";
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, n);
    if(!isupper(n[0]))
    {
        n[0] = toupper(n[0]);
    }
    vector<int> vN = serve.searchByName(n);
    if (vN.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printLine();
        for (unsigned int i = 0; i < vN.size(); i++)
        {
            cout << serve.list()[vN[i]];
        }
    }

}

void ConsoleUI::searchByGender()
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
}

void ConsoleUI::searchByBirthYear()
{
    int y = 0;
    string s = " ";
    while (!validYear(s, y))
    {
        cout << "Enter year: ";
        cin >> s;
        if (!validYear(s, y))
        {
            cout << "Invalid input!\n";
        }
    }
    vector<int> vY = serve.searchByYear(y);
    if (vY.size() == 0)
    {
        cout << "No results found\n";
    }
    else
    {
        printLine();
        for (unsigned int i = 0; i < vY.size(); i++)
        {
            cout << serve.list()[vY[i]];
        }
    }

}

void ConsoleUI::searchByYearRange()
{
    int f = 0, l = 0;
    string s = " ";
    while(!validYear(s, f))
    {
        cout << "Enter first year in range: ";
        cin >> s;
        if(!validYear(s, f))
        {
            cout << "Invalid input!\n";
        }
    }
    s = " ";
    while(!validYear(s, l) || l < f)
    {
        cout << "Enter last year in range: ";
        cin >> s;
        if(!validYear(s, l) || l < f)
        {
            cout << "Invalid input!\n";
        }
    }
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

}

void ConsoleUI::deleteData()
{
    cout << "Enter name of scientist(s) you would like to delete: ";
    string n = " ";
    cin >> ws;
    getline(cin, n);
    if(!isupper(n[0]))
    {
        n[0] = toupper(n[0]);
    }
    vector<int> v = serve.searchByName(n);
    int s = v.size();
    if (s > 0)
    {
        bool d = false;
        while (!d)
        {
            cout << "Are you sure you would like to delete the following scientist(s)? (y/n)\n";
            for (int i = 0; i < s; i++)
            {
                cout << serve.list()[v[i]];
            }
            char a = ' ';
            cin >> a;
            if (a == 'y' || a == 'Y')
            {
                for (int i = s-1; i >= 0; i--)
                {
                    serve.deletePerson(v[i]);
                }
                cout << "Scientist(s) deleted\n";
                d = true;
            }
            else if (a == 'n' || a == 'N')
            {
                cout << "Delete cancelled\n";
                d = true;
            }
            else
            {
                cout << "Invalid input!\n";
            }
        }
    }
    else
    {
        cout << "No match for " << n << endl;
    }
}

bool ConsoleUI::validYear(const string& s, int& year)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    if (s.empty() || it != s.end()) return false;
    year = atoi(s.c_str());
    time_t t = time(NULL);
    tm* TimePtr = localtime(&t);
    int currentYear = TimePtr->tm_year + 1900;
    return year >= 0 && year <= currentYear;
}

bool ConsoleUI::birthChecks(int birthYear, int deathYear)
{
    if(deathYear < birthYear && deathYear != 0)
    {
        cout << "The scientist cannot die before they are born!" << endl;
        return false;
    }
    if(deathYear - birthYear > 123)
    {
        cout << "That is too old, the oldest woman was 122 years old!" << endl;
        return false;
    }
    return true;
}

bool ConsoleUI::check()
{
    char continuel;
    cout << "Do you want to try again? (Y for yes and N for no) " ;
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

void ConsoleUI::OnlyTakeOneInput()
{
    cin.clear();
    fflush(stdin);
}

void ConsoleUI::printLine()
{
    cout.width(16);
    cout << left << "Name";
    cout <<  "\tGender\tBorn\tDied" << endl;
    cout << "_____________________________________________________" << endl;
}
