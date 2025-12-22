#include "SaveCampusResources.h"
#include "StudyRoom.h"
#include "SportsCourt.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Save all resources to CSV
void SaveCampusResources::saveToFile(const string& filename, const vector<CampusResource*>& resources) {
    ofstream file(filename);
    if (!file.is_open()) return;

    file << "type,resourceID,name,attr1,attr2\n"; // header

    for (CampusResource* r : resources) {
        if (SportsCourt* sc = dynamic_cast<SportsCourt*>(r)) {
            file << "SportsCourt" << ","
                 << sc->getID() << ","
                 << sc->getName() << ","
                 << sc->getSport() << ","        // sport
                 << (sc->isIndoors() ? "Yes" : "No") << "\n"; // indoor
        }
        else if (StudyRoom* sr = dynamic_cast<StudyRoom*>(r)) {
            file << "StudyRoom" << ","
                 << sr->getID() << ","
                 << sr->getName() << ","
                 << (sr->whiteboardExists() ? "Yes" : "No") << "," // whiteboard
                 << sr->getNumberOfSeats() << "\n";                // seats
        }
        else {
            file << "CampusResource" << ","
                 << r->getID() << ","
                 << r->getName() << "," << "\n";
        }
    }

    file.close();
}

// Load resources from CSV
void SaveCampusResources::loadFromFile(const string& filename, vector<CampusResource*>& resources) {
    resources.clear();

    ifstream file(filename);
    if (!file.is_open()) return;

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        stringstream ss(line);
        string type, resourceID, name, attr1, attr2;

        getline(ss, type, ',');
        getline(ss, resourceID, ',');
        getline(ss, name, ',');
        getline(ss, attr1, ',');
        getline(ss, attr2, ',');

        if (type == "SportsCourt") {
            string sport = attr1;                   
            bool indoor = (attr2 == "Yes");          
            resources.push_back(new SportsCourt(resourceID, name, sport, indoor));
        }
        else if (type == "StudyRoom") {
            bool whiteboard = (attr1 == "Yes");     
            int seats = 0;
            try {
                seats = stoi(attr2);                 
            } catch (...) {
                seats = 0;
            }
            resources.push_back(new StudyRoom(resourceID, name, whiteboard, seats));
        }
        else {
            resources.push_back(new CampusResource(resourceID, name));
        }
    }

    file.close();
}
