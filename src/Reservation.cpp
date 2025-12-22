#include "Reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation()
{
    reservationID = "";
    studentID = "";
    resourceID = "";
    date = 0;
    startTime = 0;
    endTime = 0;
}

Reservation::Reservation(string resID, string stuID, string resrcID,
    int d, int start, int end)
{
    reservationID = resID;
    studentID = stuID;
    resourceID = resrcID;
    date = d;
    startTime = start;
    endTime = end;
}

string Reservation::getReservationID() const
{
    return reservationID;
}

string Reservation::getStudentID() const
{
    return studentID;
}

string Reservation::getResourceID() const
{
    return resourceID;
}

int Reservation::getDate() const
{
    return date;
}

int Reservation::getStartTime() const
{
    return startTime;
}

int Reservation::getEndTime() const
{
    return endTime;
}

void Reservation::display() const
{
    cout << "Reservation ID: " << reservationID << "\n";
    cout << "Student ID: " << studentID << "\n";
    cout << "Resource ID: " << resourceID << "\n";
    cout << "Date: " << date << "\n";
    cout << "Time: " << startTime << " - " << endTime << "\n";
}