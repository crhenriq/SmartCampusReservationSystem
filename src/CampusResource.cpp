#include "CampusResource.h"
#include <iostream>

using namespace std;

CampusResource::CampusResource()
{
    resourceID = "";
    name = "";
}

CampusResource::CampusResource(string id, string name)
{
    resourceID = id;
    name = name;
}


string CampusResource::getID() const 
{
    return resourceID;
}


string CampusResource::getName() const 
{
    return name;
}


void CampusResource::display() const 
{
    cout << "Resource: " << name << "\n";
    cout << "ID: " << resourceID << "\n";
}



