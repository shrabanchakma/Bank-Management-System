#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

class Bank_Account
{
private:
    int total;
    struct person
    {
        string name, ID, address;
        int contact, cash;
    } person[100];

public:
    Bank_Account()
    {
        total = 0;
    }
    void choice();
};

void Bank_Account::create_account()
{
    system("cls");
    cout << "\t Enter the account number: ";
    cin >> account_number;
    cout << "\t Enter the name of the account holder: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\t Enter the type of the account (C/S): ";
    cin >> type;
    type = toupper(type);
    cout << "\t Enter the initial amount (>= 500 for saving and >=1000 for current): ";
    cin >> Money_Deposit;
    cout << "\t Account Created....... :)";
    cout << endl
         << endl;
}
void Bank_Account::display_account()
{
    cout << "\t Bank Account Number: " << account_number << endl;
    cout << "\t Account Holder Name: " << name << endl;
    cout << "\t Type of Account: " << type << endl;
    cout << "\t Balance Amount: " << Money_Deposit << endl;
}

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
    cout << "\t---- Main Menu----" << endl;
    cout << "\t 1. Create Account " << endl;
    cout << "\t 5. All Account Holder List " << endl;
    cout << "\t 7. Modify an Account " << endl;
    cout << "\t 4. Balance Enquiry " << endl;
    cout << "\t 2. Deposit Money " << endl;
    cout << "\t 3. Withdraw Money " << endl;
    cout << "\t 6. Close Existing Account " << endl;
    cout << "\t 8. Exit " << endl;
}