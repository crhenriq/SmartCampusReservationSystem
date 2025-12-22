#include "StudyRoom.h"
#include <iostream>

using namespace std;

StudyRoom::StudyRoom() : CampusResource(), seats(0), hasWhiteboard(false) {}


StudyRoom::StudyRoom(string id, string name, bool hasWhiteboard, int seats) : CampusResource(id, name), hasWhiteboard(hasWhiteboard), seats(seats) {}

void StudyRoom::display() const 
{
    cout << "Study Room: " << name << "\n";
    cout << "# Of Seats: " << seats << "\n";
    cout << "Whiteboard: " << (hasWhiteboard ? "Yes\n" : "No\n");
}

int StudyRoom::getNumberOfSeats() const {
    return seats;
}

bool StudyRoom::whiteboardExists() const {
    return hasWhiteboard;
}