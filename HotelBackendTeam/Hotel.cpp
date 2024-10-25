#include "Hotel.h"

Hotel::Hotel() {}

Hotel::Hotel(const vector<Room>& rooms) : rooms(rooms) {}

Hotel::Hotel(const Hotel& other) : rooms(other.rooms) {}

Hotel::~Hotel() {
}

void Hotel::addRoom(const Room& room) {
    rooms.push_back(room);
    Logger::info("Room added: " + std::to_string(room.getRoomNumber()));
}

vector<Room> Hotel::getAvailableRooms() {
    vector<Room> availableRooms;
    for (const auto& room : rooms) {
        if (room.getAvailability()) {
            availableRooms.push_back(room);
        }
    }
    if (availableRooms.empty()) {
        Logger::info("There are no available rooms.");
    }
    return availableRooms;
}

bool Hotel::bookRoom(int roomNumber) {
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            if (room.getAvailability()) {
                room.bookRoom();
                Logger::info("Room " + std::to_string(roomNumber) + " booked.");
                return true;
            }
            else {
                Logger::warning("Room " + std::to_string(roomNumber) + " is not available.");
                return false;
            }
        }
    }
    Logger::error("Room " + std::to_string(roomNumber) + " not found.");
    return false;
}

void Hotel::displayAllRooms() const {
    for (const Room& room : rooms) {
        room.displayRoomInfo();
    }
}

Room* Hotel::findRoomByNumber(int roomNumber) {
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            return &room;
        }
    }
    Logger::error("Room " + std::to_string(roomNumber) + " not found.");
    return nullptr;
}