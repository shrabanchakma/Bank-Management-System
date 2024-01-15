#include <iostream>
#include <conio.h>

using namespace std;

class Bank_Account
{
private:
    int total;
    struct user
    {
        string name, ID, address;
        int contact, cash;
    } user[100];

public:
    Bank_Account()
    {
        total = 0;
    }
    void choice();
    void userData();
    void show();
};

int main()
{
    // char ch;
    // int num;

    // cout << "\t\t --------------------------------------------------" << endl;
    // cout << "\t\t |       Welcome To Bank Management System        |" << endl;
    // cout << "\t\t --------------------------------------------------" << endl;

    // cout << endl;

    return 0;
}

void Bank_Account::choice()
{
    char ch;
    while (1)
    {
        cout << "\t---- Main Menu----" << endl;
        cout << "\t 1. Create Account " << endl;
        cout << "\t 2. All Account Holder List " << endl;
        cout << "\t 3. Modify an Account " << endl;
        cout << "\t 4. Balance Enquiry " << endl;
        cout << "\t 5. Deposit Money " << endl;
        cout << "\t 6. Withdraw Money " << endl;
        cout << "\t 7. Close Existing Account " << endl;
        cout << "\t 8. Exit " << endl;
        ch = getchar();
        switch (ch)
        {
        case 1:
            Bank_Account::userData();
            break;

        default:
            break;
        }
    }
}

void Bank_Account::userData()
{
    cout << "\t\t Enter User Information : \n\n";
    cout << "\t Name: ";
    cin >> user[total].name;
    cout << "\t ID: ";
    cin >> user[total].ID;
    cout << "\t Address: ";
    cin >> user[total].address;
    cout << "\t Contact Number: ";
    cin >> user[total].contact;
    cout << "\t Deposit cash amount: ";
    cin >> user[total].cash;
    total++;
    cout << endl
         << endl;
}

void Bank::show()
{
}
