#ifndef CAMPUSRESOURCE_H
#define CAMPUSRESOURCE_H

#include <string>

using namespace std;

class CampusResource
{
protected:
    string resourceID;
    string name;
    
public:
    CampusResource();
    CampusResource(string id, string name);

    string getID() const;
    string getName() const;

    virtual void display() const;
};


#endif