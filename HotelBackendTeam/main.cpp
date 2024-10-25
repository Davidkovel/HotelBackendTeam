#include "domain.h"
#include "Room.h"
#include "Hotel.h"
#include "HotelService.h"
#include "BookingService.h"
#include "ConsoleUI.h"

int main() {
    ConsoleUI ui;

    Hotel hotel;
    hotel.addRoom(Room(101, 100.0));
    hotel.addRoom(Room(102, 150.0));
    hotel.addRoom(Room(103, 200.0));

    HotelService hotelService(hotel);
    BookingService bookingService(hotel);

    ui.displayMessage("All Rooms:");
    hotelService.displayAllRooms();

    bookingService.bookRoom(101, "John Doe");
    bookingService.bookRoom(102, "John Doe 2");
    bookingService.bookRoom(103, "John Doe 3");

    ui.displayMessage("\nCurrent Bookings:");
    bookingService.displayBookings();

    ui.displayMessage("\nAvailable Rooms:");
    vector<Room> availableRooms = hotelService.getAvailableRooms();
    for (const auto& room : availableRooms) {
        room.displayRoomInfo();
    }

    return 0;
}