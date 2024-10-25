#ifndef HOTEL_SERVICE_H
#define HOTEL_SERVICE_H

#include "Room.h"
#include "Hotel.h"

class HotelService {
private:
    Hotel& hotel;

public:
    HotelService(Hotel& h) : hotel(h) {}

    vector<Room> getAvailableRooms() {
        vector<Room> availableRooms = hotel.getAvailableRooms();
        if (availableRooms.empty()) {
            Logger::info("No available rooms.");
        }
        else {
            Logger::info("Fetched available rooms.");
        }
        return availableRooms;
    }

    void displayAllRooms() const {
        Logger::info("Displaying all rooms.");
        hotel.displayAllRooms();
    }
};

#endif // HOTEL_SERVICE_H
