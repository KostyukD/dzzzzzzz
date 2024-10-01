#include <iostream> 
using namespace std;

struct Empl
{
    char first_name[50];
    char last_name[50];
    char phone_numb[15];
    double salary;
};

Empl empl_s[100];
int empl_count = 0;

bool phone_numb_valid(const char* phone_numb)
{
    int length = 0;
    while (phone_numb[length] != '\0')
    {
        length++;
    }
    return length == 10;
}

void add_empl()
{
    if (empl_count < 100)
    {
        Empl& emp = empl_s[empl_count];
        cout << '\n' << "enter empl name:\t";
        cin >> emp.first_name;
        cout << "enter the empl_s last_name:\t";
        cin >> emp.last_name;
        cout << "enter the empl_s phone number (10 digits):\t";
        cin >> emp.phone_numb;

        while (!phone_numb_valid(emp.phone_numb))
        {
            cout << "invalid number format. re-enter number:\t";
            cin >> emp.phone_numb;
        }

        cout << "enter the employee's salary:\t";
        cin >> emp.salary;

        empl_count++;
    }
    else
    {
        cout << "can't add more employees.\n";
    }
}

void display_empl()
{
    for (int i = 0; i < empl_count; ++i)
    {
        Empl& emp = empl_s[i];
        cout << '\n' << "name: " << emp.first_name
            << '\t' << "lastName: " << emp.last_name
            << '\t' << "phone number: " << emp.phone_numb
            << '\t' << "salary: " << emp.salary << "\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << '\n' << "menu:\n";
        cout << "1. add an employee\n";
        cout << "2. show all employees\n";
        cout << "3. exit\n";
        cout << "your choice:\t";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_empl();
            break;
        case 2:
            display_empl();
            break;
        case 3:
            cout << "exit\n";
            break;
        default:
            cout << "wrong choice\n";
            break;
        }
    } while (choice != 3);

    return 0;
}