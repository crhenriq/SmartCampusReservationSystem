#include <iostream>
#include <vector>
#include <string>
#include "ReservationSystem.h"
#include "SaveCampusResources.h"
#include "SaveUsers.h"
#include "SaveReservations.h"

using namespace std;

int main() {

    // Step 1: Initialize system
    ReservationSystem system;


    // Step 2: Load resources from CSV
    vector<CampusResource*> resources;
    SaveCampusResources::loadFromFile("data/resources.csv", resources);
    for (auto r : resources) system.addResource(r);


    // Step 3: Load users from CSV
    vector<User*> users;
    SaveUsers::loadFromFile("data/users.csv", users);
    for (auto u : users) {
        if (dynamic_cast<Student*>(u)) system.addStudent(dynamic_cast<Student*>(u));
        else if (dynamic_cast<Administrator*>(u)) system.addAdministrator(dynamic_cast<Administrator*>(u));
    }

    // Step 4: Load reservations from CSV
    vector<Reservation> reservations;
    SaveReservations::loadFromFile("data/reservations.csv", reservations);
    for (auto &res : reservations) {
        system.createReservation(res.getStudentID(), res.getResourceID(), res.getDate(), res.getStartTime(), res.getEndTime());
    }


    // Step 5: List all resources
    cout << "\n--- All Resources ---\n";
    system.listAllResources();


    // Step 6: Search resources by name and ID
    cout << "\n--- Search Resource by Name 'Study Room 1' ---\n";
    CampusResource* searchName = system.searchResourceByName("Study Room 1");
    if (searchName) searchName->display();

    cout << "\n--- Search Resource by ID 'SC001' ---\n";
    CampusResource* searchID = system.searchResourceByID("SC001");
    if (searchID) searchID->display();


    // Step 7: Filter by type
    cout << "\n--- Filter Resources by Type 'StudyRoom' ---\n";
    system.filterByType("StudyRoom");

    cout << "\n--- Filter Resources by Type 'SportsCourt' ---\n";
    system.filterByType("SportsCourt");


    // Step 8: View reservations for student
    cout << "\n--- View Reservations for Student S001 ---\n";
    system.viewReservationsForStudent("S001");


    // Step 9: Test creating a reservation with conflict
    cout << "\n--- Attempt Conflicting Reservation ---\n";
    bool conflict = system.createReservation("S001", "SR001", 20251221, 10, 12);
    cout << (conflict ? "Reservation created!\n" : "Conflict detected!\n");


    // Step 10: Test creating a valid reservation
    cout << "\n--- Create Valid Reservation ---\n";
    bool success = system.createReservation("S001", "SC002", 20251221, 12, 14);
    cout << (success ? "Reservation created!\n" : "Conflict detected!\n");


    // Step 11: Cancel a reservation
    cout << "\n--- Cancel Reservation R002 for Student S002 ---\n";
    system.cancelReservation("R002", "S002");


    // Step 12: Modify a reservation
    cout << "\n--- Modify Reservation R001 for Student S001 ---\n";
    system.modifyReservation("R001", "S001", 20251221, 9, 11);


    // Step 13: Check resource availability
    cout << "\n--- Check Resource Availability ---\n";
    bool available = system.isResourceAvailable("SC001", 20251221, 14, 16);
    cout << "SC001 available from 14:00 to 16:00? " << (available ? "Yes" : "No") << "\n";


    // Step 14: Save all data
    SaveCampusResources::saveToFile("data/resources.csv", resources);
    SaveUsers::saveToFile("data/users.csv", users);
    SaveReservations::saveToFile("data/reservations.csv", reservations);

    cout << "\n--- Demo Complete ---\n";

    return 0;
}
