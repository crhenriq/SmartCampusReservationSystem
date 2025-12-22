#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <vector>
#include <string>

#include "CampusResource.h"
#include "StudyRoom.h"
#include "SportsCourt.h"
#include "Reservation.h"
#include "Student.h"
#include "Administrator.h"

using namespace std;

class ReservationSystem
{
private:
    vector<CampusResource*> resources;
    vector<Reservation> reservations;
    vector<Student*> students;
    vector<Administrator*> admins;

    // Helper method for time conflict detection
    bool hasTimeConflict(const string& resourceID, int date, int startTime, int endTime, const string& excludeReservationID = "") const;
    
    // Helper method to find reservation by ID
    Reservation* findReservationByID(const string& reservationID);
    const Reservation* findReservationByID(const string& reservationID) const;
    
    // Helper method to generate unique reservation IDs
    string generateReservationID() const;

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

    // User Management
    void addStudent(Student* student);
    void addAdministrator(Administrator* admin);
    Student* findStudentByID(const string& studentID) const;
    
    // Resource Management
    void addResource(CampusResource* resource);
    void removeResource(const string& resourceID);
    CampusResource* findResourceByID(const string& resourceID) const;
    
    // Reservation Methods
    bool createReservation(const string& studentID, const string& resourceID, 
                          int date, int startTime, int endTime);
    bool cancelReservation(const string& reservationID, const string& studentID);
    bool modifyReservation(const string& reservationID, const string& studentID,
                          int newDate, int newStartTime, int newEndTime);
    vector<Reservation> getReservationsForResource(const string& resourceID) const;
    bool isResourceAvailable(const string& resourceID, int date, int startTime, int endTime) const;
};

#endif