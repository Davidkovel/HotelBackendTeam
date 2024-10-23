#include "Booking.h"

Booking::Booking() = default;

Booking::Booking(Guest* guest, Room* room)
    : guest(guest), room(room) {}

Booking::Booking(const Booking& other)
    : guest(other.guest), room(other.room) {}

Booking::~Booking() {
    // empty
}

void Booking::confirmBooking() {
    if (room->getAvailability()) {
        room->bookRoom();
        cout << "Room " << room->getRoomNumber() << " booked for guest " << guest->getName() << endl;
    }
    else {
        cout << "Room " << room->getRoomNumber() << " is already booked." << endl;
    }
}
