#include <bits/stdc++.h>
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
    void validateCredentials(user *&root, string name, int ID, long long password);
    void setUser(user *&root, int ID);
    void showUser(user *root);
    void userProfilePage(user *&user);
    void updateUserProfile(user *&user);
    // delete user
    user *deleteUser(user *&root, string name, int ID, long long password);
    user *inOrderPredecessor(user *&root);
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

void Bank_Account::validateCredentials(user *&root, string name, int ID, long long password)
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
        userProfilePage(root);
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

void Bank_Account::userProfilePage(user *&user)
{
    cout << "\t\t ---------------------------------" << endl;
    cout << "\t\t |       USER LoggedIn        |" << endl;
    cout << "\t\t ---------------------------------" << endl
         << endl;
    Sleep(2000);
    cout << "\r";
    char ch;
    while (1)
    {
        cout << "\t\t ----------------------------------" << endl;
        cout << "\t\t |       Welcome Back: " << user->name << "|" << endl;
        cout << "\t\t ----------------------------------" << endl
             << endl
             << endl;
        cout << "Go to: " << endl;

        cout << "\t 1. Profile Details  " << endl;
        cout << "\t 2. Update Profile" << endl;
        cout << "\t 3. Delete Profile" << endl;
        cout << "\t 4. Deposit Money" << endl;
        cout << "\t 5. Send Money" << endl;
        cout << "\t 6. Go to Homepage" << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            showUser(user);
            break;
        case '2':
            updateUserProfile(user);
            break;
        case '3':
            deleteUser(user, user->name, user->ID, user->password);
            return;
            break;
        case '4':
            // deposit money;
            break;
        case '5':
            // Send money;
            break;
        case '6':
            // exit;
            break;
        default:
            break;
        }
    }
}

void Bank_Account::showUser(user *user)
{
    cout << "\t\t ---------------------------------" << endl;
    cout << "\t\t |       USER INFORMATION        |" << endl;
    cout << "\t\t ---------------------------------" << endl
         << endl;

    cout << "ID: " << user->ID << endl;
    cout << "Name: " << user->name << endl;
    cout << "Address: " << user->address << endl;
    cout << "Contact Number: " << user->contactNumber << endl;
    cout << "Balance: " << user->cash << endl
         << endl;
}

void Bank_Account::updateUserProfile(user *&user)
{
    cout << "____OPTIONS____" << endl;
    cout << "Name" << endl;
    cout << "Address" << endl;
    cout << "Contact Number" << endl;
    cout << "password" << endl
         << endl;
    cout << "\t What do you want to change? ";
    string field, newData;
    int newNumber;
    cin >> field;
    cin.ignore();

    transform(field.begin(), field.end(), field.begin(), ::tolower);

    if (field == "name")
    {
        // change name
        cout << "Change name: ";
        getline(cin, newData);
        user->name = newData;
        cout << "name updated successfully" << endl;
    }
    else if (field == "address")
    {
        // change address
        cout << "Change address: ";
        getline(cin, newData);
        user->address = newData;
        cout << "address updated successfully" << endl;
    }
    else if (field == "contact number")
    {
        // change contact number
        cout << "Change contact number: ";
        getline(cin, newData);
        user->contactNumber = newNumber;
        cout << "contact number updated successfully" << endl;
    }
    else if (field == "password")
    {
        // change password
        cout << "Change password: ";
        cin >> newNumber;
        user->contactNumber = newNumber;
        cout << "password updated successfully" << endl;
    }
    else
    {
        cout << "Invalid Input" << endl;
        return;
    }
    showUser(user);
}

Bank_Account::user *Bank_Account::inOrderPredecessor(user *&root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Bank_Account::user *Bank_Account::deleteUser(user *&root, string name, int ID, long long password)
{
    user *pre;
    if (!root)
    {
        return NULL;
    }
    else if (root->name == name && root->ID == ID && root->password == password)
    {
        free(root);
        return NULL;
    }

    if (ID < root->ID)
    {
        root->left = deleteUser(root->left, name, ID, password);
    }
    else if (ID > root->ID)
    {
        root->right = deleteUser(root->right, name, ID, password);
    }
    else
    {
        pre = inOrderPredecessor(root);
        root->ID = pre->ID;
        root->name = pre->name;
        root->address = pre->address;
        root->password = pre->password;
        root->contactNumber = pre->contactNumber;
        root->cash = pre->cash;
        root->left = deleteUser(root->left, pre->name, pre->ID, pre->password);
    }

    return root;
}