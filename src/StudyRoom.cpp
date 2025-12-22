#include "StudyRoom.h"
#include <iostream>

using namespace std;

// Default constructor
StudyRoom::StudyRoom() : CampusResource(), seats(0), hasWhiteboard(false) {}

// Parameterized constructor
StudyRoom::StudyRoom(string id, string name, bool hasWhiteboard, int seats) : CampusResource(id, name), seats(seats), hasWhiteboard(hasWhiteboard) {}


// Displays study room info
void StudyRoom::display() const 
{
    cout << "Study Room: " << name << "\n";
    cout << "# Of Seats: " << seats << "\n";
    cout << "Whiteboard: " << (hasWhiteboard ? "Yes\n" : "No\n");
}

// Provides number of seats
int StudyRoom::getNumberOfSeats() const {
    return seats;
}

// Checks if white board exists in study room
bool StudyRoom::whiteboardExists() const {
    return hasWhiteboard;
}