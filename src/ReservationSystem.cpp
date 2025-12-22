#include "ReservationSystem.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

ReservationSystem::ReservationSystem() {}

ReservationSystem::~ReservationSystem()
{
    for (int i = 0; i < resources.size(); i++)
    {
        delete resources[i];
    }
    resources.clear();
}

// ---------------- LIST ----------------

void ReservationSystem::listAllResources() const
{
    cout << "---- All Available Resources ----\n";

    if (resources.size() == 0)
    {
        cout << "No resources available.\n";
        return;
    }

    for (int i = 0; i < resources.size(); i++)
    {
        resources[i]->display();
        cout << "-------------------------------\n";
    }
}

// ---------------- SEARCH ----------------

CampusResource* ReservationSystem::searchResourceByID(const string& id) const
{
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i]->getID() == id)
        {
            return resources[i];
        }
    }
    return nullptr;
}

CampusResource* ReservationSystem::searchResourceByName(const string& name) const
{
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i]->getName() == name)
        {
            return resources[i];
        }
    }
    return nullptr;
}

// ---------------- FILTER ----------------

void ReservationSystem::filterByType(const string& type) const
{
    cout << "---- Filter By Type: " << type << " ----\n";
    bool found = false;

    for (int i = 0; i < resources.size(); i++)
    {
        if (type == "StudyRoom" &&
            dynamic_cast<StudyRoom*>(resources[i]) != nullptr)
        {
            resources[i]->display();
            cout << "-------------------------------\n";
            found = true;
        }
        else if (type == "SportsCourt" &&
            dynamic_cast<SportsCourt*>(resources[i]) != nullptr)
        {
            resources[i]->display();
            cout << "-------------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No resources found for that type.\n";
    }
}

void ReservationSystem::filterByAttribute(const string& key, const string& value) const
{
    cout << "---- Filter By Attribute: "
        << key << " = " << value << " ----\n";

  
}

// ---------------- VIEW RESERVATIONS ----------------

void ReservationSystem::viewReservationsForStudent(const string& studentID) const
{
    cout << "---- Reservations for Student ID: "
        << studentID << " ----\n";

    bool found = false;

    for (int i = 0; i < reservations.size(); i++)
    {
        if (reservations[i].getStudentID() == studentID)
        {
            reservations[i].display();
            cout << "-------------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No upcoming reservations found.\n";
    }
}

// =============== HELPER METHODS ===============

bool ReservationSystem::hasTimeConflict(const string& resourceID, int date, 
                                       int startTime, int endTime, 
                                       const string& excludeReservationID) const 
{
    for (const Reservation& reservation : reservations) 
    {
        // Skip the reservation we're excluding
        if (reservation.getReservationID() == excludeReservationID) 
        {
            continue;
        }
        
        // Check if same resource and same date
        if (reservation.getResourceID() == resourceID && 
            reservation.getDate() == date) 
        {
            // Check for time overlap
            // Two time intervals overlap if newStart < existingEnd and newEnd > existingStart
            if (startTime < reservation.getEndTime() && 
                endTime > reservation.getStartTime()) 
            {
                return true; // Conflict found
            }
        }
    }
    return false; // No conflict
}

Reservation* ReservationSystem::findReservationByID(const string& reservationID) 
{
    for (int i = 0; i < reservations.size(); i++) 
    {
        if (reservations[i].getReservationID() == reservationID) 
        {
            return &reservations[i];
        }
    }
    return nullptr;
}

const Reservation* ReservationSystem::findReservationByID(const string& reservationID) const 
{
    for (int i = 0; i < reservations.size(); i++) 
    {
        if (reservations[i].getReservationID() == reservationID) 
        {
            return &reservations[i];
        }
    }
    return nullptr;
}

string ReservationSystem::generateReservationID() const 
{
    // Simple ID generation: RES-XXXX where X is a number
    static int counter = 1;
    return "RES-" + to_string(counter++);
}

// Helper function to validate MMDDYYYY date
bool isValidDateMMDDYYYY(int date) 
{
    if (date < 1012024 || date > 12312025) // Jan 1, 2024 to Dec 31, 2025
        return false;
    
    int month = date / 1000000;
    int day = (date / 10000) % 100;
    int year = date % 10000;
    
    // Check month range
    if (month < 1 || month > 12)
        return false;
    
    // Check day range based on month
    if (day < 1 || day > 31)
        return false;
    
    // Check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    // Check for February
    if (month == 2) 
    {
        // Simple leap year check
        bool isLeapYear = (year == 2024); // 2024 is a leap year
        if (isLeapYear && day > 29)
            return false;
        if (!isLeapYear && day > 28)
            return false;
    }
    
    return true;
}

// Helper function to format date for display
string formatDateMMDDYYYY(int date) 
{
    int month = date / 1000000;
    int day = (date / 10000) % 100;
    int year = date % 10000;
    
    // Format as MM/DD/YYYY
    stringstream ss;
    ss << setw(2) << setfill('0') << month << "/"
       << setw(2) << setfill('0') << day << "/"
       << year;
    return ss.str();
}

// =============== USER MANAGEMENT ===============

void ReservationSystem::addStudent(Student* student) 
{
    if (student != nullptr) 
    {
        students.push_back(student);
    }
}

void ReservationSystem::addAdministrator(Administrator* admin) 
{
    if (admin != nullptr) 
    {
        admins.push_back(admin);
    }
}

Student* ReservationSystem::findStudentByID(const string& studentID) const 
{
    for (int i = 0; i < students.size(); i++) 
    {
        if (students[i]->getUserID() == studentID) 
        {
            return students[i];
        }
    }
    return nullptr;
}

// =============== RESOURCE MANAGEMENT ===============

void ReservationSystem::addResource(CampusResource* resource) 
{
    if (resource != nullptr) 
    {
        resources.push_back(resource);
    }
}

void ReservationSystem::removeResource(const string& resourceID) 
{
    for (int i = 0; i < resources.size(); i++) 
    {
        if (resources[i]->getID() == resourceID) 
        {
            delete resources[i];
            resources.erase(resources.begin() + i);
            
            for (int j = reservations.size() - 1; j >= 0; j--) 
            {
                if (reservations[j].getResourceID() == resourceID) 
                {
                    reservations.erase(reservations.begin() + j);
                }
            }
            return;
        }
    }
}

CampusResource* ReservationSystem::findResourceByID(const string& resourceID) const 
{
    for (int i = 0; i < resources.size(); i++) 
    {
        if (resources[i]->getID() == resourceID) 
        {
            return resources[i];
        }
    }
    return nullptr;
}

// =============== RESERVATION METHODS ===============

bool ReservationSystem::createReservation(const string& studentID, 
                                         const string& resourceID,
                                         int date, int startTime, int endTime) 
{
    // 1. Validate input times
    if (startTime >= endTime || startTime < 0 || endTime > 2400) 
    {
        cout << "Error: Invalid time range. Use 24-hour format (0-2400).\n";
        return false;
    }
    
    // 2. Validate date
    if (!isValidDateMMDDYYYY(date)) 
    {
        cout << "Error: Invalid date. Use MMDDYYYY format.\n";
        cout << "Example: January 15, 2024 = 01152024\n";
        return false;
    }
    
    // 3. Check if student exists
    Student* student = findStudentByID(studentID);
    if (student == nullptr) 
    {
        cout << "Error: Student not found.\n";
        return false;
    }
    
    // 4. Check if resource exists
    CampusResource* resource = findResourceByID(resourceID);
    if (resource == nullptr) 
    {
        cout << "Error: Resource not found.\n";
        return false;
    }
    
    // 5. Check for time conflicts
    if (hasTimeConflict(resourceID, date, startTime, endTime)) 
    {
        cout << "Error: Time conflict with existing reservation.\n";
        return false;
    }
    
    // 6. Create reservation
    string reservationID = generateReservationID();
    Reservation newReservation(reservationID, studentID, resourceID, 
                              date, startTime, endTime);
    
    // 7. Add to system
    reservations.push_back(newReservation);
    
    // 8. Update student's reservation list
    student->addReservation(reservationID);
    
    cout << "Reservation created successfully!\n";
    cout << "Reservation ID: " << reservationID << "\n";
    cout << "Date: " << formatDateMMDDYYYY(date) << "\n";
    cout << "Time: " << setw(4) << setfill('0') << startTime << " to " 
         << setw(4) << setfill('0') << endTime << "\n";
    return true;
}

bool ReservationSystem::cancelReservation(const string& reservationID, 
                                         const string& studentID) 
{
    // 1. Find the reservation
    Reservation* reservation = findReservationByID(reservationID);
    if (reservation == nullptr) 
    {
        cout << "Error: Reservation not found.\n";
        return false;
    }
    
    // 2. Verify student ownership
    if (reservation->getStudentID() != studentID) 
    {
        cout << "Error: You can only cancel your own reservations.\n";
        return false;
    }
    
    // 3. Find the student
    Student* student = findStudentByID(studentID);
    if (student != nullptr) 
    {
        student->removeReservation(reservationID);
    }
    
    // 4. Remove from reservations vector
    for (int i = 0; i < reservations.size(); i++) 
    {
        if (reservations[i].getReservationID() == reservationID) 
        {
            // Display info before cancelling
            cout << "Cancelling reservation:\n";
            cout << "Resource: " << findResourceByID(reservations[i].getResourceID())->getName() << "\n";
            cout << "Date: " << formatDateMMDDYYYY(reservations[i].getDate()) << "\n";
            cout << "Time: " << setw(4) << setfill('0') << reservations[i].getStartTime() 
                 << " to " << setw(4) << setfill('0') << reservations[i].getEndTime() << "\n";
            
            reservations.erase(reservations.begin() + i);
            cout << "Reservation cancelled successfully.\n";
            return true;
        }
    }
    
    return false;
}

bool ReservationSystem::modifyReservation(const string& reservationID, 
                                         const string& studentID,
                                         int newDate, int newStartTime, 
                                         int newEndTime) 
{
    // 1. Validate input times
    if (newStartTime >= newEndTime || newStartTime < 0 || newEndTime > 2400) 
    {
        cout << "Error: Invalid time range. Use 24-hour format (0-2400).\n";
        return false;
    }
    
    // 2. Validate new date
    if (!isValidDateMMDDYYYY(newDate)) 
    {
        cout << "Error: Invalid date. Use MMDDYYYY format.\n";
        cout << "Example: January 15, 2024 = 01152024\n";
        return false;
    }
    
    // 3. Find the reservation
    Reservation* reservation = findReservationByID(reservationID);
    if (reservation == nullptr) 
    {
        cout << "Error: Reservation not found.\n";
        return false;
    }
    
    // 4. Verify student ownership
    if (reservation->getStudentID() != studentID) 
    {
        cout << "Error: You can only modify your own reservations.\n";
        return false;
    }
    
    // 5. Check for time conflicts (excluding current reservation)
    if (hasTimeConflict(reservation->getResourceID(), newDate, 
                       newStartTime, newEndTime, reservationID)) 
    {
        cout << "Error: Time conflict with existing reservation.\n";
        return false;
    }
    
    // 6. Update the reservation
    for (int i = 0; i < reservations.size(); i++) 
    {
        if (reservations[i].getReservationID() == reservationID) 
        {
            // Display old and new info
            cout << "Modifying reservation from:\n";
            cout << "Date: " << formatDateMMDDYYYY(reservations[i].getDate()) << "\n";
            cout << "Time: " << setw(4) << setfill('0') << reservations[i].getStartTime() 
                 << " to " << setw(4) << setfill('0') << reservations[i].getEndTime() << "\n";
            
            // Create a new reservation with updated times
            Reservation updatedReservation(reservationID, studentID, 
                                          reservation->getResourceID(),
                                          newDate, newStartTime, newEndTime);
            reservations[i] = updatedReservation;
            
            cout << "To:\n";
            cout << "Date: " << formatDateMMDDYYYY(newDate) << "\n";
            cout << "Time: " << setw(4) << setfill('0') << newStartTime 
                 << " to " << setw(4) << setfill('0') << newEndTime << "\n";
            cout << "Reservation modified successfully.\n";
            return true;
        }
    }
    
    return false;
}

vector<Reservation> ReservationSystem::getReservationsForResource(const string& resourceID) const 
{
    vector<Reservation> result;
    
    for (const Reservation& reservation : reservations) 
    {
        if (reservation.getResourceID() == resourceID) 
        {
            result.push_back(reservation);
        }
    }
    
    return result;
}

bool ReservationSystem::isResourceAvailable(const string& resourceID, 
                                           int date, int startTime, 
                                           int endTime) const 
{
    // Check if resource exists
    if (findResourceByID(resourceID) == nullptr) 
    {
        cout << "Error: Resource not found.\n";
        return false;
    }
    
    // Validate date
    if (!isValidDateMMDDYYYY(date)) 
    {
        cout << "Error: Invalid date format.\n";
        return false;
    }
    
    // Validate times
    if (startTime >= endTime || startTime < 0 || endTime > 2400) 
    {
        cout << "Error: Invalid time range.\n";
        return false;
    }
    
    // Check for time conflicts
    return !hasTimeConflict(resourceID, date, startTime, endTime);
}