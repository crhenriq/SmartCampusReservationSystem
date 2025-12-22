#include "Student.h"
#include <iostream>

using namespace std;


// Default constructor
Student::Student() : User() {}

// Parameterized constructor
Student::Student(string id, string name) : User(id, name) {}

// Adds a reservation ID to the student's reservation list
void Student::addReservation(const string& reservationID)
{
    reservationIDs.push_back(reservationID);
}


// Removes a reservation ID from the student's reservation list
void Student::removeReservation(const string& reservationID)
{
    for (int i = 0; i < reservationIDs.size(); i++)
    {
        if (reservationIDs[i] == reservationID)
        {
            reservationIDs.erase(reservationIDs.begin() + i);
            return;
        }
    }
}


// Views the student's reservation list
void Student::viewReservations() const
{
    cout << "Reservations for " << username << ":\n";
    for (int i = 0; i < reservationIDs.size(); i++)
    {
        cout << reservationIDs[i] << "\n";
    }
}

// Displays the student's info
void Student::display() const
{
    cout << "Student: " << username << "\n";
    cout << "ID: " << userID << "\n";
}