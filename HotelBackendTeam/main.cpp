#include "domain.h"
#include "Room.h"
#include "Hotel.h"
#include "HotelService.h"
#include "BookingService.h"
#include "ConsoleUI.h"

void printHeader(const string& title) {
    cout << "\n" << string(50, '-') << endl;
    cout << setw(25) << right << title << endl;
    cout << string(50, '-') << endl;
}

int main() {
    ConsoleUI ui;

    Guest guest1("David", "Bob", "+380684185576", 25, 2);
    Guest guest2("Mikita", "Bob", "+434434324", 35, 2);
    Guest guest3("John", "Bob", "+423423", 30, 2);

    Staff staff1("Alice", "Smith", "+123456789", "Manager", 5, 3000);
    Staff staff2("Bob", "Johnson", "+987654321", "Receptionist", 3, 2000);

    Hotel hotel;
    hotel.addRoom(Room(101, 100.0));
    hotel.addRoom(Room(102, 150.0));
    hotel.addRoom(Room(103, 200.0));

    HotelService hotelService(hotel);
    BookingService bookingService(hotel);

    printHeader("All Rooms:");
    ui.displayMessage("All Rooms:");
    hotelService.displayAllRooms();

    bookingService.bookRoom(101, guest1);
    bookingService.deleteGuestRoom(guest1);

    bookingService.bookRoom(102, guest2);

    printHeader("Current Bookings:");
    ui.displayMessage("\nCurrent Bookings:");
    bookingService.displayBookings();

    printHeader("Available Rooms:");
    ui.displayMessage("\nAvailable Rooms:");
    vector<Room> availableRooms = hotelService.getAvailableRooms();
    for (const auto& room : availableRooms) {
        room.displayRoomInfo();
    }

    printHeader("Staff Information:");
    ui.displayMessage("\nStaff Information:");
    staff1.printInfo();
    staff2.printInfo();


    return 0;
}