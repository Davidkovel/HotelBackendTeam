#ifndef BOOKING_H
#define BOOKING_H

#include "Room.h"

// TEMPORARY CLASS
class Guest {
public:
    string getName() const { return "Guest Name"; }
};

// -----
class Booking {
private:
    Guest* guest;
    Room* room;

public:
    Booking();
    Booking(Guest* guest, Room* room);
    Booking(const Booking& other);
    ~Booking();

    void confirmBooking();
};

#endif
