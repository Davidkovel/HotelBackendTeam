#include "Booking.h"

Booking::Booking() = default;

Booking::Booking(int id, const string& guest, int room)
    : bookingId(id), guestName(guest), roomNumber(room) {}

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
    std::cout << "Booking confirmed for guest: " << guestName << " in room " << roomNumber << std::endl;
}