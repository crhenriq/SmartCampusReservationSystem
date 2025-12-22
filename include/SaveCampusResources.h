#ifndef SAVECAMPUSRESOURCES_H
#define SAVECAMPUSRESOURCES_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CampusResource.h"
#include "SportsCourt.h"
#include "StudyRoom.h"
using namespace std;

class SaveCampusResources{
public:
    //saves a vector of campus resources to csv
    static void saveToFile(const string& filename, const vector<CampusResource*>& resources);

    //load a vector of campus resources to a csv
    //wherever it's called is where the vector is stored.
    static void loadFromFile(const string& filename, vector<CampusResource*>& resources);


};


#endif //SAVECAMPUSRESOURCES.H