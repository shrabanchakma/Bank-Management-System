#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Bank_Account
{
private:
    string name, address;
    int contactNumber, cash, ID;
    long long int password;
    struct user
    {
        string name, address;
        int contactNumber, cash, ID;
        long long int password;
        user *left;
        user *right;
    };

    user *Root = NULL;

public:
    void choice();
    void createUser();
    void loginUser();
    void setUser(user *newUser, int ID);
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
        cout << "\t 1. Login  " << endl;
        cout << "\t 2. Create New Account" << endl;
        // cout << "\t 2. Show All Users" << endl;
        // cout << "\t 3. Modify an Account " << endl;
        // cout << "\t 4. Balance Enquiry " << endl;
        // cout << "\t 5. Deposit Money " << endl;
        // cout << "\t 6. Withdraw Money " << endl;
        // cout << "\t 7. Close Existing Account " << endl;
        cout << "\t 8. Exit " << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            Bank_Account::loginUser();
        case '2':
            Bank_Account::createUser();
            break;
        // case '1':
        //     Bank_Account::showUser();
        //     break;
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

int countDigits(int number)
{
    string numString = to_string(number);
    return numString.length();
}

void Bank_Account::createUser()
{
    cout << "\t\t Enter User Information : \n\n";
    cout << "\t Input ID: ";
    cin >> ID;
    while (countDigits(ID) < 6 || countDigits(ID) > 6)
    {
        cout << "Please input a six digit ID: ";
        cin >> ID;
    }
    setUser(Root, ID);
    cout << endl
         << endl;
}

void Bank_Account::setUser(user *root, int ID)
{
    if (!root)
    {
        user *root = new user();
        root->ID = ID;
        cout << "\t Name: ";
        cin >> name;
        root->name = name;
        cout << "\t Address: ";
        cin >> address;
        root->address = address;
        cout << "\t Contact Number: ";
        cin >> contactNumber;
        root->contactNumber = contactNumber;
        cout << "\t Deposit cash amount: ";
        cin >> cash;
        root->cash = cash;
        root->left = root->right = NULL;
    }
    else
    {
        if (ID < root->ID)
        {
            setUser(root->left, ID);
        }
        else
        {
            setUser(root->right, ID);
        }
    }
}

void Bank_Account::loginUser()
{
}
void Bank_Account::showUser()
{
    user *temp = Root;
    while (temp != NULL)
    {
        cout << "Name of the User: " << temp->name << endl;
        temp = temp->next;
    }
}
