#include "Room.h"

Room::Room() = default;

Room::Room(int roomNumber, double price)
    : roomNumber(roomNumber), price(price), isAvailable(true) {}

Room::~Room() {};

int Room::getRoomNumber() const {
    return roomNumber;
}

double Room::getPrice() const {
    return price;
}

bool Room::getAvailability() const {
    return isAvailable;
}

void Room::bookRoom() {
    if (isAvailable) {
        isAvailable = false;
        cout << "Room " << roomNumber << " has been booked." << endl;
    }
    else {
        cout << "Room " << roomNumber << " is already booked." << endl;
    }
}

void Room::freeRoom() {
    if (!isAvailable) {
        isAvailable = true;
        cout << "Room " << roomNumber << " has been freed." << endl;
    }
    else {
        cout << "Room " << roomNumber << " is already free." << endl;
    }
}

void Room::displayRoomInfo() const {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Price: " << price << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Booked") << endl;
}
