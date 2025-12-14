#include "User.h"
#include <iostream>

using namespace std;

User::User()
{
    userID = "";
    username = "";
}

User::User(string id, string name)
{
    userID = id;
    username = name; 
}

string User::getUserID() const
{
    return userID;
}

string User::getUsername() const
{
    return username;
}

void User::display() const
{
    cout << "Username: " << username << "\n";
    cout << "ID: " << userID << "\n";
}