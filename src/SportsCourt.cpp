#include "SportsCourt.h"
#include <iostream>

using namespace std;

SportsCourt::SportsCourt() : CampusResource(), sport(""), indoor(false) {}

SportsCourt::SportsCourt(string id, string name, string sport, bool indoor) : CampusResource(id, name), sport(sport), indoor(indoor) {}

void SportsCourt::display() const 
{
    cout << "Sports Court: " << name << "\n";
    cout << "Sport: " << sport << "\n"; // should I do Court Type: instead of Sport:? Is it redundant?
    cout << "Indoor: " << (indoor ? "Yes\n" : "No\n");
}