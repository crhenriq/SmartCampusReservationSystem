#include "User.h"
#include <iostream>

using namespace std;

// Default constructor
User::User()
{
    userID = "";
    username = "";
}

// Parameterized constructor
User::User(string id, string name)
{
    userID = id;
    username = name; 
}

// Provides userID
string User::getUserID() const
{
    return userID;
}

// Provides username
string User::getUsername() const
{
    return username;
}

// Displays user info
void User::display() const
{
    cout << "Username: " << username << "\n";
    cout << "ID: " << userID << "\n";
}