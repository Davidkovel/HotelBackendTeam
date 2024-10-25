#ifndef BOOKING_H
#define BOOKING_H

#include "Room.h"

class Booking {
private:
    int bookingId;
    string guestName;
    int roomNumber;
    Guest* guest;
    Room* room;

public:
    Booking();
    Booking(int id, const string& guest, int room);
    // Booking(Guest* guest, Room* room);
    Booking(const Booking& other);
    ~Booking();

    int getBookingId() const;
    string getGuestName() const;
    int getRoomNumber() const;

    void confirmBooking();
};

#endif
