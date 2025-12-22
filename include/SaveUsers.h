#ifndef SAVEUSERS_H
#define SAVEUSERS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "User.h"
#include "Student.h"
#include "Administrator.h"
using namespace std;

class SaveUsers{
public:
static void saveToFile(const string& filename, const vector<User*>& users);
static void loadFromFile(const string& filename, vector<User*>& users);



};

#endif //SAVEUSERS_H