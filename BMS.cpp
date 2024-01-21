#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Bank_Account
{
private:
    int total;
    string name, ID, address;
    int contactNumber, cash;
    struct user
    {
        string name, ID, address;
        int contactNumber, cash;
        user *prev;
        user *next;
    };

    user *Head = NULL;

public:
    Bank_Account()
    {
        total = 0;
    }
    void choice();
    void createUser();
    void setUser(user *newUser);
    void showUser();
    //   void update();
    //     void search();
    //     void transaction();
};

int main()
{

    cout << "\t\t --------------------------------------------------" << endl;
    cout << "\t\t |       Welcome To Bank Management System        |" << endl;
    cout << "\t\t --------------------------------------------------" << endl
         << endl;

    Bank_Account executeProgram;
    executeProgram.choice();
    return 0;
}

void Bank_Account::choice()
{
    char ch;
    while (1)
    {
        cout << "\t---- Main Menu----" << endl;
        cout << "\t 1. Create Account " << endl;
        cout << "\t 2. Show All Users" << endl;
        cout << "\t 3. Modify an Account " << endl;
        cout << "\t 4. Balance Enquiry " << endl;
        cout << "\t 5. Deposit Money " << endl;
        cout << "\t 6. Withdraw Money " << endl;
        cout << "\t 7. Close Existing Account " << endl;
        cout << "\t 8. Exit " << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            Bank_Account::createUser();
            break;
        case '2':
            Bank_Account::showUser();
            break;
        // case '3':
        //     Bank_Account::update();
        //     break;
        // case '4':
        //     Bank_Account::search();
        //     break;
        default:
            break;
        }
    }
}

void Bank_Account::createUser()
{
    if (Head == NULL)
    {
        user *newUser = new user();
        cout << "\t\t Enter User Information : \n\n";
        cout << "\t Name: ";
        cin >> name;
        newUser->name = name;
        cout << "\t ID: ";
        cin >> ID;
        newUser->ID = ID;
        cout << "\t Address: ";
        cin >> address;
        newUser->address;
        cout << "\t Contact Number: ";
        cin >> contactNumber;
        newUser->contactNumber = contactNumber;
        cout << "\t Deposit cash amount: ";
        cin >> cash;
        newUser->cash = cash;
        newUser->prev = NULL;
        newUser->next = NULL;
        Head = newUser;
        cout << endl
             << endl;
    }
    else
    {
        user *newUser = new user();
        cout << "\t\t Enter User Information : \n\n";
        cout << "\t Name: ";
        cin >> name;
        newUser->name = name;
        cout << "\t ID: ";
        cin >> ID;
        newUser->ID = ID;
        cout << "\t Address: ";
        cin >> address;
        newUser->address;
        cout << "\t Contact Number: ";
        cin >> contactNumber;
        newUser->contactNumber = contactNumber;
        cout << "\t Deposit cash amount: ";
        cin >> cash;
        newUser->cash = cash;
        newUser->prev = NULL;
        newUser->next = NULL;

        setUser(newUser);
    }
}

void Bank_Account::setUser(user *newUser)
{
    user *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newUser;
}

void Bank_Account::showUser()
{
    user *temp = Head;
    while (temp != NULL)
    {
        cout << "Name of the User: " << temp->name << endl;
        temp = temp->next;
    }
}
