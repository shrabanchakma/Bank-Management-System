#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

class Bank_Account
{
    int account_number;
    char name[50];
    char type;
    int Money_Deposit;

public:
    void create_account();
    void display_account();
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
}

int main()
{
    return 0;
}