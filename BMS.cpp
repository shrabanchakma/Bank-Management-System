#include <iostream>
#include <conio.h>

using namespace std;

class Bank_Account
{
private:
    int total;
    string id;
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
    void update();
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
        case '1':
            Bank_Account::userData();
            break;
        case '2':
            Bank_Account::show();
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

void Bank_Account::show()
{
    for (int i = 0; i < total; i++)
    {
        cout << "Data of User " << i + 1 << endl;
        cout << "Name: " << user[i].name << endl;
        cout << "ID: " << user[i].ID << endl;
        cout << "Address: " << user[i].address << endl;
        cout << "Balance: " << user[i].cash << endl;
    }
}

void Bank_Account::update()
{
    cout << "\t---- Update Info----" << endl;
    cout << "Enter User Id: " << endl;
    cin >> id;
    for (int i = 0; i < total; i++)
    {
        if (id == user[i].ID)
        {
            cout << "Previous Data" << endl;
            cout << "Data of User " << i + 1 << endl;
            cout << "Name: " << user[i].name << endl;
            cout << "ID: " << user[i].ID << endl;
            cout << "Address: " << user[i].address << endl;
            cout << "Balance: " << user[i].cash << endl
                 << endl;
            cout << "Enter New Data: " << endl;
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
        }
    }
}