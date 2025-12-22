#include "SaveCampusResources.h"
#include "StudyRoom.h"
#include <sstream>

void SaveCampusResources::saveToFile(const string& filename, const vector<CampusResource*>& resources) {
    ofstream file(filename);
    if (!file.is_open()) return;

    //csv header
    file << "type,resourceID,name,attr1,attr2\n";

    for (CampusResource* r : resources) {
        if (SportsCourt* sc = dynamic_cast<SportsCourt*>(r)) {
            file << "SportsCourt" << "," 
                 << sc->getID() << "," 
                 << sc->getName() << "," 
                 << (sc->isIndoors() ? "1" : "0") << "," 
                 << sc->getName() << "\n";
        }
        else if (StudyRoom* sr = dynamic_cast<StudyRoom*>(r)) {
            file << "StudyRoom" << "," 
                 << sr->getID() << "," 
                 << sr->getName() << "," 
                 << (sr->whiteboardExists() ? "1" : "0") << "," 
                 << sr->getNumberOfSeats() << "\n";
        }
        else {
            // for any other campus resource
            file << "CampusResource" << "," 
                 << r->getID() << "," 
                 << r->getName() << ",,\n";
        }
    }

    file.close();
}

// Load resources from CSV
void SaveCampusResources::loadFromFile(const string& filename, vector<CampusResource*>& resources) {
    // Clean up existing pointers
    for (CampusResource* r : resources) delete r;
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
            string sport = attr2;
            bool indoor = (attr1 == "1");
            resources.push_back(new SportsCourt(resourceID, name, sport, indoor));
        }
        else if (type == "StudyRoom") {
            bool whiteboard = (attr1 == "1");
            int seats = stoi(attr2);
            resources.push_back(new StudyRoom(resourceID, name, whiteboard, seats));
        }
        else {
            resources.push_back(new CampusResource(resourceID, name));
        }
    }

    file.close();
}