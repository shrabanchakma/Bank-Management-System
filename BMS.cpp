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

    user *Root;

public:
    Bank_Account()
    {
        Root = NULL;
    }
    void choice();
    void createUser();
    void loginUser();
    void validateCredentials(user *root, string name, int ID, long long password);
    void setUser(user *&root, int ID);
    void showUser(user *root);
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
        cout << "\t\t ----------------------" << endl;
        cout << "\t\t |       Main Menu    |" << endl;
        cout << "\t\t ----------------------" << endl
             << endl;
        cout << "\t 1. Login  " << endl;
        cout << "\t 2. Create New Account" << endl;
        cout << "\t 3. Show User" << endl;
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
            break;
        case '2':
            Bank_Account::createUser();
            break;
        case '3':
            Bank_Account::showUser(Root);
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

void Bank_Account::setUser(user *&root, int ID)
{
    if (!root)
    {
        root = new user();
        root->ID = ID;
        cout << "\t Name: ";
        cin >> name;
        root->name = name;
        cout << "\t Address: ";
        cin >> address;
        root->address = address;
        cout << "\t Contact Number: ";
        cin >> contactNumber;
        cout << "\t Set Password: ";
        cin >> password;
        while (countDigits(password) < 5 || countDigits(password) > 5)
        {
            cout << "Please input a five digit password: ";
            cin >> password;
        }
        root->password = password;
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

    cout << "\t\t ----------------------" << endl;
    cout << "\t\t |       Login        |" << endl;
    cout << "\t\t ----------------------" << endl
         << endl;

    cout << "\t Name: ";
    cin >> name;
    cout << "\t ID: ";
    cin >> ID;
    cout << "\t PASSWORD: ";
    cin >> password;

    validateCredentials(Root, name, ID, password);
}
void Bank_Account::validateCredentials(user *root, string name, int ID, long long password)
{
    if (!root)
    {
        cout << endl;
        cout << "Invalid Credentials, Please Try Again";
        cout << endl;
        return;
    }

    if (root->name == name && root->ID == ID && root->password == password)
    {
        cout << "\t\t ---------------------------------" << endl;
        cout << "\t\t |       USER INFORMATION        |" << endl;
        cout << "\t\t ---------------------------------" << endl
             << endl;

        cout << "ID: " << root->ID << endl;
        cout << "Name: " << root->name << endl;
        cout << "Address: " << root->address << endl;
        cout << "Contact Number: " << root->contactNumber << endl;
        cout << "Balance: " << root->cash << endl
             << endl;
        return;
    }
    else
    {
        if (root->ID > ID)
        {

            validateCredentials(root->left, name, ID, password);
        }
        else
        {

            validateCredentials(root->right, name, ID, password);
        }
    }
}

void Bank_Account::showUser(user *root)
{
    if (root != NULL)
    {
        cout << "entered";

        cout << "name of the user: " << root->name << endl;
        cout << "diposit amount: " << root->cash << endl
             << endl;
        showUser(root->left);
        showUser(root->right);
    }
}
