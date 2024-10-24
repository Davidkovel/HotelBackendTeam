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
        return hotel.getAvailableRooms();
    }

    void displayAllRooms() const {
        hotel.displayAllRooms();
    }
};

#endif // HOTEL_SERVICE_H
