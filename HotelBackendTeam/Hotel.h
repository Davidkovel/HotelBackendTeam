#ifndef HOTEL_H
#define HOTEL_H

#include "Room.h"

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel();
    Hotel(const vector<Room>& rooms);
    Hotel(const Hotel& other);
    ~Hotel();

    void addRoom(const Room& room);
    vector<Room> getAvailableRooms();
    bool bookRoom(int roomNumber);
    void displayAllRooms() const;
    Room* findRoomByNumber(int roomNumber);
};

#endif