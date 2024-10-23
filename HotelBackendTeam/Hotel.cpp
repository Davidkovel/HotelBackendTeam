#include "Hotel.h"

Hotel::Hotel() {}

Hotel::Hotel(const vector<Room>& rooms) : rooms(rooms) {}

Hotel::Hotel(const Hotel& other) : rooms(other.rooms) {}

Hotel::~Hotel() {
    // Destructor, clean up if necessary.
}

vector<Room*> Hotel::getAvailableRooms() {
    vector<Room*> availableRooms;
    for (Room& room : rooms) {
        if (room.getAvailability()) {
            availableRooms.push_back(&room);
        }
    }
    return availableRooms;
}

bool Hotel::bookRoom(int roomNumber) {
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            if (room.getAvailability()) {
                room.bookRoom();
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

void Hotel::displayAllRooms() const {
    for (const Room& room : rooms) {
        room.displayRoomInfo();
    }
}
