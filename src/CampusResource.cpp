#include "CampusResource.h"
#include <iostream>

using namespace std;

// Default Constructor
CampusResource::CampusResource()
{
    resourceID = "";
    name = "";
}

// Parameterized Constructor
CampusResource::CampusResource(string id, string name)
{
    resourceID = id;
    this->name = name;
}


// Provides resourceID
string CampusResource::getID() const 
{
    return resourceID;
}


// Provides name of resource
string CampusResource::getName() const 
{
    return name;
}


// Displays the campus resource info
void CampusResource::display() const 
{
    cout << "Resource: " << name << "\n";
    cout << "ID: " << resourceID << "\n";
}



