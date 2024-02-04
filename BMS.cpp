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
    struct admin
    {
        string name;
        int ID;
        long long int password;
        user *left;
        user *right;
    };

    user *Root;
    admin *adminRoot = new admin();

public:
    Bank_Account()
    {
        Root = NULL;
        adminRoot->name = "iAmAdmin";
        adminRoot->ID = 111111;
        adminRoot->password = 22222;
        adminRoot->left = adminRoot->right = NULL;
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
    // deposit money
    void depositMoney(user *&root);
    void withdrawMoney(user *&root);
    // send money
    void sendMoneyPage(user *&user);
    void searchToSend(user *&receiver, user *&sender, string receiverName, int receiverId);
    void sendMoney(user *&sender, user *&receiver);
    // admin panel;
    void adminLogin();
    void validateAdminCredentials(admin *&adminRoot, string name, int ID, long long int password);
    void adminProfile(admin *&admin);
    void showAdminDetails(admin *admin);
    void createAdmin();
    void setAdmin(admin *adminRoot);
    void showAllUsers(user *root);
    void searchUser();
    void searchValidUser(user *root, string name, int ID);
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
    string ch;
    while (1)
    {
        cout << "\t\t ----------------------" << endl;
        cout << "\t\t |       Main Menu    |" << endl;
        cout << "\t\t ----------------------" << endl
             << endl;
        cout << "\t 1. Login  " << endl;
        cout << "\t 2. Create New Account" << endl;
        cout << "\t 3. Admin Login" << endl;
        cout << "\t 4. Exit " << endl;
        getline(cin, ch);
        if (ch == "1")
        {
            Bank_Account::loginUser();
        }
        else if (ch == "2")
        {
            Bank_Account::createUser();
        }
        else if (ch == "3")
        {
            adminLogin();
        }
        else if (ch == "4")
        {
            return;
        }
        else
        {
            cout << endl
                 << "Invalid Input \nPlease try again!" << endl;
        }
        // switch (ch)
        // {
        // case "1":
        //     Bank_Account::loginUser();
        //     break;
        // case "2":
        //     Bank_Account::createUser();
        //     break;
        // case "3":
        //     adminLogin();
        //     break;
        // case "4":
        //     return;
        // default:
        //     cout << endl
        //          << "Invalid Input \nPlease try again!" << endl;
        //     break;
        // }
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
        cin.ignore();
        getline(cin, name);
        root->name = name;
        cout << "\t Address: ";
        getline(cin, address);
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
    cin.ignore();
    getline(cin, name);
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
    cout << "\t\t User Logging In......"
         << endl;
    Sleep(2000);
    cout << "\r";
    char ch;
    while (1)
    {
        cout << "\t\t ----------------------------------" << endl;
        cout << "\t\t        Welcome Back: " << user->name << endl;
        cout << "\t\t ----------------------------------" << endl
             << endl
             << endl;
        cout << "Go to: " << endl;

        cout << "\t 1. Profile Details  " << endl;
        cout << "\t 2. Update Profile" << endl;
        cout << "\t 3. Delete Profile" << endl;
        cout << "\t 4. Deposit Money" << endl;
        cout << "\t 5. Withdraw Money" << endl;
        cout << "\t 6. send Money" << endl;
        cout << "\t 7. Go to Homepage" << endl;
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
            depositMoney(user);
            break;
        case '5':
            // withdraw money;
            withdrawMoney(user);
            break;
        case '6':
            sendMoneyPage(user);
            break;
        case '7':
            return;
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
    cout << "Balance: " << user->cash << "TK" << endl
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

void Bank_Account::depositMoney(user *&user)
{
    int newDepositAmount;
    cout << "How much money do you want to deposit? ";
    cin >> newDepositAmount;
    user->cash = user->cash + newDepositAmount;
    cout << "Loading...." << endl;
    Sleep(2000);
    cout << "\t\t ---------------------------------" << endl;
    cout << "\t\t |        Deposit Successful    |" << endl;
    cout << "\t\t ---------------------------------" << endl
         << endl;
}

void Bank_Account::withdrawMoney(user *&user)
{
    int amount;
    cout << "How much money do you want to withdraw? ";
    cin >> amount;
    cout << "Loading...." << endl;
    Sleep(2000);
    if (user->cash < amount)
    {
        cout << "Insufficient Balance" << endl;
    }
    else
    {
        user->cash = user->cash - amount;
        cout << "\t\t ---------------------------------" << endl;
        cout << "\t\t |        Withdraw Successful    |" << endl;
        cout << "\t\t ---------------------------------" << endl
             << endl;
    }
}

void Bank_Account::sendMoneyPage(user *&user)
{
    cout << "\t Receiver Information" << endl;
    cout << "\t----------------------" << endl;
    string receiverName;
    int receiverId;
    cout << "Receiver Name: ";
    cin.ignore();
    getline(cin, receiverName);
    cout << "Receiver ID: ";
    cin >> receiverId;
    cout << "Searching User..." << endl;
    Sleep(2000);
    searchToSend(Root, user, receiverName, receiverId);
}
void Bank_Account::searchToSend(user *&receiver, user *&sender, string receiverName, int receiverId)
{
    if (!receiver)
    {
        cout << endl;
        cout << "User Not Found, Please Try Again";
        cout << endl;
        return;
    }

    if (receiver->name == receiverName && receiver->ID == receiverId)
    {
        sendMoney(sender, receiver);
        return;
    }
    else
    {
        if (receiver->ID > ID)
        {

            searchToSend(receiver->left, sender, receiverName, receiverId);
        }
        else
        {

            searchToSend(receiver->right, sender, receiverName, receiverId);
        }
    }
}
void Bank_Account::sendMoney(user *&sender, user *&receiver)
{
    int amount;
    cout << "\t Amount: ";
    cin >> amount;
    while (amount > sender->cash)
    {
        cout << "Insufficient amount" << endl;
        cout << "You're balance is: " << sender->cash << endl;
        Sleep(1000);
        cout << "Amount: ";
        cin >> amount;
    }
    sender->cash = sender->cash - amount;
    receiver->cash = receiver->cash + amount;
    cout << endl
         << endl
         << "Transaction in process..." << endl;
    Sleep(2000);
    cout << "Send Money Successful" << endl;
}
// admin Login

void Bank_Account::adminLogin()
{
    cout << "\t\t ---------------------------" << endl;
    cout << "\t\t |       Admin Login        |" << endl;
    cout << "\t\t ---------------------------" << endl
         << endl;

    cout << "\t Name: ";
    cin >> name;
    cout << "\t ID: ";
    cin >> ID;
    cout << "\t PASSWORD: ";
    cin >> password;

    validateAdminCredentials(adminRoot, name, ID, password);
}
void Bank_Account::validateAdminCredentials(admin *&adminRoot, string name, int ID, long long int password)
{
    if (!adminRoot)
    {
        cout << endl;
        cout << "Invalid Credentials, Please Try Again";
        cout << endl;
        return;
    }

    if (adminRoot->name == name && adminRoot->ID == ID && adminRoot->password == password)
    {
        adminProfile(adminRoot);
        return;
    }
    else
    {
        if (adminRoot->ID > ID)
        {

            validateCredentials(adminRoot->left, name, ID, password);
        }
        else
        {

            validateCredentials(adminRoot->right, name, ID, password);
        }
    }
}

void Bank_Account::adminProfile(admin *&admin)
{
    cout << "\t\t ---------------------------------" << endl;
    cout << "\t\t |       Admin Logging in        |" << endl;
    cout << "\t\t ---------------------------------" << endl
         << endl;
    Sleep(2000);
    cout << "\r";
    char ch;
    while (1)
    {
        cout << "\t\t ----------------------------------" << endl;
        cout << "\t\t |       Welcome Back: " << admin->name << "|" << endl;
        cout << "\t\t ----------------------------------" << endl
             << endl
             << endl;
        cout << "Go to: " << endl;

        cout << "\t 1. Admin Profile Details  " << endl;
        cout << "\t 2. Add Admin" << endl;
        cout << "\t 3. All User Details" << endl;
        cout << "\t 4. Search User" << endl;
        cout << "\t 5. Go to Homepage" << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
            showAdminDetails(admin);
            break;
        case '2':
            createAdmin();
            break;
        case '3':
            showAllUsers(Root);
            break;
        case '4':
            searchUser();
            break;
        case '5':
            return;
        default:
            break;
        }
    }
}

void Bank_Account::showAdminDetails(admin *admin)
{
    cout << "\t\t ---------------------------------" << endl;
    cout << "\t\t |       ADMIN INFORMATION        |" << endl;
    cout << "\t\t ---------------------------------" << endl
         << endl;

    cout << "ID: " << admin->ID << endl;
    cout << "Name: " << admin->name << endl;
}

void Bank_Account::createAdmin()
{
    cout << "\t\t Enter Admin Information : \n\n";
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

void Bank_Account::setAdmin(admin *adminRoot)
{
    if (!adminRoot)
    {
        adminRoot = new admin();
        adminRoot->ID = ID;
        cout << "\t Name: ";
        cin >> name;
        adminRoot->name = name;
        cout << "\t Set Password: ";
        cin >> password;
        while (countDigits(password) < 5 || countDigits(password) > 5)
        {
            cout << "Please input a five digit password: ";
            cin >> password;
        }
        adminRoot->password = password;
        adminRoot->left = adminRoot->right = NULL;
    }
    else
    {
        if (ID < adminRoot->ID)
        {
            setUser(adminRoot->left, ID);
        }
        else
        {
            setUser(adminRoot->right, ID);
        }
    }
}

void Bank_Account::showAllUsers(user *user)
{
    if (!user)
    {
        return;
    }
    cout << "ID: " << user->ID << endl;
    cout << "Name: " << user->name << endl;
    cout << "Address: " << user->address << endl;
    cout << "Contact Number: " << user->contactNumber << endl;
    cout << "Balance: " << user->cash << endl
         << endl
         << endl;
    showAllUsers(user->left);
    showAllUsers(user->right);
}

void Bank_Account::searchUser()
{
    cout << "\t\t ----------------------" << endl;
    cout << "\t\t |       Search User        |" << endl;
    cout << "\t\t ----------------------" << endl
         << endl;

    cout << "\t Name: ";
    cin >> name;
    cout << "\t ID: ";
    cin >> ID;

    searchValidUser(Root, name, ID);
}

void Bank_Account::searchValidUser(user *root, string name, int ID)
{
    if (!root)
    {
        cout << endl
             << "User Not Found" << endl;
        return;
    }

    if (root->name == name && root->ID == ID)
    {
        showUser(root);
        return;
    }
    else
    {
        if (root->ID > ID)
        {

            searchValidUser(root->left, name, ID);
        }
        else
        {

            searchValidUser(root->right, name, ID);
        }
    }
}