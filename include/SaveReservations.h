#ifndef SAVERESERVATIONS_H
#define SAVERESERVATIONS_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Reservation.h"
using namespace std;

class SaveReservations{

    public:
    // Save a vector of Reservation objects to a CSV file
    static void saveToFile(const string& filename, const vector<Reservation>& reservations);

    // Load reservations from a CSV file into a vector
    static void loadFromFile(const string& filename, vector<Reservation>& reservations);
};




#endif