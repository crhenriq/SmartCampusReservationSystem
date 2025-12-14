#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <string>

using namespace std;

class Administrator: public User
{
public:
    Administrator();
    Administrator(string id, string name);

    void display() const;
};


#endif