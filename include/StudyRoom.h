#ifndef STUDYROOM_H
#define STUDYROOM_H

#include "CampusResource.h"

class StudyRoom : public CampusResource {
private:
    bool hasWhiteboard;
    int seats;

public:
    StudyRoom();
    StudyRoom(string id, string name, bool hasWhiteboard, int seats);

    void display() const;
};

#endif