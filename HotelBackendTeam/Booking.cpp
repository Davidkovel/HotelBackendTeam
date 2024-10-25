#include "Booking.h"

// Booking::Booking() = default;
Booking::Booking() {
    int id = 0;
    string guestName = "NULL";
    int room = 0;
}

Booking::Booking(int id, const string& guest, int room)
    : bookingId(id), guestName(guest), roomNumber(room) 
{
    cout << "sdfsdf" << endl;
}

Booking::Booking(const Booking& other)
    : guest(other.guest), room(other.room) {}

Booking::~Booking() {
    // empty
}

int Booking::getBookingId() const {
    return bookingId;
}

string Booking::getGuestName() const {
    return guestName;
}

int Booking::getRoomNumber() const {
    return roomNumber;
}

void Booking::confirmBooking() {
    cout << "Booking confirmed for guest: " << guestName << " in room " << roomNumber << endl;
}