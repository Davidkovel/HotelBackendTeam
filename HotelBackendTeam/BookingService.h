#ifndef BOOKING_SERVICE_H
#define BOOKING_SERVICE_H

#include "Room.h"
#include "Hotel.h"
#include "Booking.h"

class BookingService {
private:
    Hotel& hotel;
    vector<Booking> bookings;
    int nextBookingId;

public:
    BookingService(Hotel& h) : hotel(h), nextBookingId(1) {}

    bool bookRoom(int roomNumber, const string& guestName) {
        Room* room = hotel.findRoomByNumber(roomNumber);
        if (room && room->getAvailability()) {
            room->bookRoom();
            bookings.emplace_back(nextBookingId++, guestName, roomNumber);
            Logger::info("Room " + std::to_string(roomNumber) + " booked for " + guestName);
            return true;
        }
        Logger::warning("Room " + std::to_string(roomNumber) + " is not available for " + guestName);
        return false;
    }
    /*
     push_back добавляет копию объекта (или обеспечивает перемещение, если возможно), а emplace_back создает объект непосредственно в конце вектора, т.е. без лишнего копирования (или перемещения).
    */

    void displayBookings() const {
        if (bookings.empty()) {
            Logger::info("No current bookings available.");
            return;
        }
        for (const auto& booking : bookings) {
            cout << "Booking ID: " << booking.getBookingId()
                << ", Guest Name: " << booking.getGuestName()
                << ", Room Number: " << booking.getRoomNumber() << endl;
        }
    }
};

#endif // BOOKING_SERVICE_H