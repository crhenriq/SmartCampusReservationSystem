#include <iostream>
#include <vector>
#include <string>
#include "ReservationSystem.h"
#include "SaveCampusResources.h"
#include "SaveUsers.h"
#include "SaveReservations.h"

using namespace std;

int main() {

    // Initialize system
    ReservationSystem system;


    // Load resources from CSV
    vector<CampusResource*> resources;
    SaveCampusResources::loadFromFile("data/resources.csv", resources);
    for (auto r : resources) system.addResource(r);


    // Load users from CSV
    vector<User*> users;
    SaveUsers::loadFromFile("data/users.csv", users);
    for (auto u : users) {
        if (dynamic_cast<Student*>(u)) system.addStudent(dynamic_cast<Student*>(u));
        else if (dynamic_cast<Administrator*>(u)) system.addAdministrator(dynamic_cast<Administrator*>(u));
    }

    // Load reservations from CSV
    vector<Reservation> reservations;
    SaveReservations::loadFromFile("data/reservations.csv", reservations);
    for (auto &res : reservations) {
        system.createReservation(res.getStudentID(), res.getResourceID(), res.getDate(), res.getStartTime(), res.getEndTime());
    }


    // List all resources
    cout << "\n--- All Resources ---\n";
    system.listAllResources();


    // Search resources by name and ID
    cout << "\n--- Search Resource by Name 'Study Room 1' ---\n";
    CampusResource* searchName = system.searchResourceByName("Study Room 1");
    if (searchName) searchName->display();

    cout << "\n--- Search Resource by ID 'SC001' ---\n";
    CampusResource* searchID = system.searchResourceByID("SC001");
    if (searchID) searchID->display();


    // Filter by type
    cout << "\n--- Filter Resources by Type 'StudyRoom' ---\n";
    system.filterByType("StudyRoom");

    cout << "\n--- Filter Resources by Type 'SportsCourt' ---\n";
    system.filterByType("SportsCourt");


    // View reservations for student
    cout << "\n--- View Reservations for Student S001 ---\n";
    system.viewReservationsForStudent("S001");


    // Test creating a reservation with conflict
    cout << "\n--- Attempt Conflicting Reservation ---\n";
    bool conflict = system.createReservation("S001", "SR001", 12212025, 10, 12);
    cout << (conflict ? "Reservation created!\n" : "Conflict detected!\n");


    // Step 10: Test creating a valid reservation
    cout << "\n--- Create Valid Reservation ---\n";
    bool success = system.createReservation("S001", "SC002", 12212025, 12, 14);
    cout << (success ? "Reservation created!\n" : "Conflict detected!\n");


    // Cancel a reservation
    cout << "\n--- Cancel Reservation R002 for Student S002 ---\n";
    system.cancelReservation("RES-2", "S002");


    // Modify a reservation
    cout << "\n--- Modify Reservation R001 for Student S001 ---\n";
    system.modifyReservation("RES-1", "S001", 12212025, 9, 11);


    // Check resource availability
    cout << "\n--- Check Resource Availability ---\n";
    bool available = system.isResourceAvailable("SC001", 12212025, 14, 16);
    cout << "SC001 available from 14:00 to 16:00? " << (available ? "Yes" : "No") << "\n";


    // Save all data
    SaveCampusResources::saveToFile("data/resources.csv", resources);
    SaveUsers::saveToFile("data/users.csv", users);
    SaveReservations::saveToFile("data/reservations.csv", reservations);

    cout << "\n--- Demo Complete ---\n";

    return 0;
}
