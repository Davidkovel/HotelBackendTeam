#ifndef ROOM_H
#define ROOM_H

#include "domain.h"

class Room {
private:
    int roomNumber;
    double price;
    bool isAvailable;

public:
    Room();
    Room(int roomNumber, double price);
    ~Room();

    int getRoomNumber() const;
    double getPrice() const;
    bool getAvailability() const;
    void bookRoom();
    void freeRoom();
    void displayRoomInfo() const;
};

#endif