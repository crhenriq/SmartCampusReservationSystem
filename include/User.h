#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User 
{
// protected rather than private so that child classes can access    
protected:
    string userID;
    string username;

public:
    User();
    User(string id, string name);

    string getUserID() const;
    string getUsername() const;

    virtual void display() const;
};


#endif