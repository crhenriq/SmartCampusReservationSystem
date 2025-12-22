#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <vector>
#include <string>

#include "CampusResource.h"
#include "StudyRoom.h"
#include "SportsCourt.h"
#include "Reservation.h"

using namespace std;

class ReservationSystem
{
private:
    vector<CampusResource*> resources;
    vector<Reservation> reservations;

public:
    ReservationSystem();
    ~ReservationSystem();

    // LIST
    void listAllResources() const;

    // SEARCH
    CampusResource* searchResourceByID(const string& id) const;
    CampusResource* searchResourceByName(const string& name) const;

    // FILTER
    void filterByType(const string& type) const;
    void filterByAttribute(const string& key, const string& value) const;

    // VIEW UPCOMING RESERVATIONS
    void viewReservationsForStudent(const string& studentID) const;
};

#endif