#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>

class Student: public User
{
private:
    vector<string> reservationIDs;

public:
    Student();
    Student(string id, string name);

    void addReservation(const string& reservationID);
    void removeReservation(const string& reservationID);
    void viewReservations() const;

    void display() const;
};


#endif