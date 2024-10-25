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

    bool bookRoom(int roomNumber, const Guest& guest) {
        Room* room = hotel.findRoomByNumber(roomNumber);
        if (room && room->getAvailability()) {
            room->bookRoom();
            bookings.emplace_back(nextBookingId++, guest.getName(), roomNumber);
            Logger::info("Room " + to_string(roomNumber) + " booked for " + guest.getName());
            return true;
        }
        Logger::warning("Room " + to_string(roomNumber) + " is not available for " + guest.getName());
        return false;
    }
    /*
     push_back добавляет копию объекта (или обеспечивает перемещение, если возможно), а emplace_back создает объект непосредственно в конце вектора, т.е. без лишнего копирования (или перемещения).
    */


    bool deleteGuestRoom(const Guest& guest) {
        auto it = find_if(bookings.begin(), bookings.end(),
            [&guest](const Booking& booking) {
                return booking.getGuestName() == guest.getName();
            });

        if (it != bookings.end()) {
            int roomNumber = it->getRoomNumber();
            hotel.findRoomByNumber(roomNumber)->freeRoom();
            bookings.erase(it);
            Logger::info("Room " + to_string(roomNumber) + " freed for " + guest.getName());
            return true;
        }

        Logger::warning("No booking found for " + guest.getName());
        return false;
    }

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