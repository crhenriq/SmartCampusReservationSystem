#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User 
{
private:
    string userID;
    string username;
    string userType;

public:
    User();
    User(string id, string name, string type);

    string getUserID() const;
    string getUsername() const;
    string getUserType() const;

    virtual void display() const;
};


#endif