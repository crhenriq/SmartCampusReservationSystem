#include "Administrator.h"
#include <iostream>

using namespace std;

Administrator::Administrator() : User() {}


Administrator::Administrator(string id, string name) : User(id, name) {}


void Administrator::display() const 
{
    cout << "Administrator: " << username << "\n";
    cout << "ID: " << userID << "\n";
}