#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() : User() {}


Student::Student(string id, string name) : User(id, name) {}


void Student::addReservation(const string& reservationID)
{
    reservationIDs.push_back(reservationID);
}


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


void Student::viewReservations() const
{
    cout << "Reservations for " << username << ":\n";
    for (int i = 0; i < reservationIDs.size(); i++)
    {
        cout << reservationIDs[i] << "\n";
    }
}


void Student::display() const
{
    cout << "Student: " << username << "\n";
    cout << "ID: " << userID << "\n";
}