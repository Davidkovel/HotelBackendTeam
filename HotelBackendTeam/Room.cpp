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
        Logger::info("Room " + to_string(roomNumber) + " has been booked.");
    }
    else {
        Logger::warning("Room " + to_string(roomNumber) + " is already booked.");
    }
}

void Room::freeRoom() {
    if (!isAvailable) {
        isAvailable = true;
        Logger::info("Room " + to_string(roomNumber) + " has been freed.");
    }
    else {
        Logger::warning("Room " + to_string(roomNumber) + " is already free.");
    }
}

void Room::displayRoomInfo() const {
    cout << "Room Number: " << roomNumber << endl;
    cout << "Price: " << price << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Booked") << endl;
}