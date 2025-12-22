#include "SaveReservations.h"
#include <sstream>

// Save reservations to a CSV file
void SaveReservations::saveToFile(const std::string& filename, const std::vector<Reservation>& reservations) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    // Write header
    file << "reservationID,studentID,resourceID,date,startTime,endTime\n";

    for (const Reservation& r : reservations) {
        file << r.getReservationID() << ","
             << r.getStudentID() << ","
             << r.getResourceID() << ","
             << r.getDate() << ","
             << r.getStartTime() << ","
             << r.getEndTime() << "\n";
    }

    file.close();
}

// Load reservations from a CSV file
void SaveReservations::loadFromFile(const std::string& filename, std::vector<Reservation>& reservations) {
    reservations.clear();

    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string resID, stuID, resrcID, dateStr, startStr, endStr;

        std::getline(ss, resID, ',');
        std::getline(ss, stuID, ',');
        std::getline(ss, resrcID, ',');
        std::getline(ss, dateStr, ',');
        std::getline(ss, startStr, ',');
        std::getline(ss, endStr, ',');

        int date = std::stoi(dateStr);
        int start = std::stoi(startStr);
        int end = std::stoi(endStr);

        reservations.emplace_back(resID, stuID, resrcID, date, start, end);
    }

    file.close();
}
