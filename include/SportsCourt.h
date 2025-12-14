#ifndef SPORTSCOURT_H
#define SPORTSCOURT_H

#include "CampusResource.h"
#include <string>

using namespace std;

class SportsCourt : public CampusResource 
{
private:
    string sport;
    bool indoor;

public:
    SportsCourt();
    SportsCourt(string id, string name, string sport, bool indoor);

    void display() const;
};

#endif