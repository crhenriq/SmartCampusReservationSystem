#include "SportsCourt.h"
#include <iostream>

using namespace std;

// Default constructor
SportsCourt::SportsCourt() : CampusResource(), sport(""), indoor(false) {}


// Parameterized constructor
SportsCourt::SportsCourt(string id, string name, string sport, bool indoor) : CampusResource(id, name), sport(sport), indoor(indoor) {}


// Displays court info
void SportsCourt::display() const 
{
    cout << "Sports Court: " << name << "\n";
    cout << "Court Type: " << sport << "\n"; 
    cout << "Indoor: " << (indoor ? "Yes\n" : "No\n");
}


// Checks if court is indoors
bool SportsCourt::isIndoors() const {
    return indoor;
}


// Provides the sport
string SportsCourt::getSport() const {
    return sport;
}