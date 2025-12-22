#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

using namespace std;

class Reservation
{
private:
    string reservationID;
    string studentID;
    string resourceID;

    int date;        
    int startTime;   
    int endTime;     

public:
    Reservation();
    Reservation(string resID, string stuID, string resrcID,
        int date, int start, int end);

    string getReservationID() const;
    string getStudentID() const;
    string getResourceID() const;

    int getDate() const;
    int getStartTime() const;
    int getEndTime() const;

    void display() const;
};

#endif
