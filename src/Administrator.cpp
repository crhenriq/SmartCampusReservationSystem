#include "Administrator.h"
#include <iostream>

using namespace std;

// Default Constructor
Administrator::Administrator() : User() {}

// Parameterized Constructor
Administrator::Administrator(string id, string name) : User(id, name) {}

// Displays admin info
void Administrator::display() const 
{
    cout << "Administrator: " << username << "\n";
    cout << "ID: " << userID << "\n";
}