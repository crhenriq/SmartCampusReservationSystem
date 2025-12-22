#include "SaveUsers.h"
#include <sstream> 
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void SaveUsers::saveToFile(const std::string& filename, const std::vector<User*>& users) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    // Write CSV header
    file << "type,id,username\n";

    for (User* u : users) {
        std::string type = "User";
        if (dynamic_cast<Student*>(u)) type = "Student";
        else if (dynamic_cast<Administrator*>(u)) type = "Administrator";

        file << type << "," << u->getUserID() << "," << u->getUsername() << "\n";
    }

    file.close();
}


void SaveUsers::loadFromFile(const string& filename, vector<User*>& users) {
    // Clear existing vector and delete pointers
    //for (User* u : users) delete u;
    users.clear();

    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type, idStr, username;

        std::getline(ss, type, ',');
        std::getline(ss, idStr, ',');
        std::getline(ss, username, ',');

        if (type == "Student") {
            users.push_back(new Student(idStr, username));
        } 
        else if (type == "Administrator") {
            users.push_back(new Administrator(idStr, username));
        } 
        //else {
            //users.push_back(new User(idStr, username));
        //}
    }

    file.close();
}
