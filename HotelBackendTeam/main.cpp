#include "domain.h"
#include "Room.h"
#include "Hotel.h"
#include "HotelService.h"
#include "BookingService.h"

int main() {
    // Создаем отель и номера
    Hotel hotel;

    hotel.addRoom(Room(101, 100.0));
    hotel.addRoom(Room(102, 150.0));
    hotel.addRoom(Room(103, 200.0));

    // Создаем сервисы
    HotelService hotelService(hotel);
    BookingService bookingService(hotel);

    // Показать все номера
    cout << "All Rooms:" << endl;
    hotelService.displayAllRooms();

    // Попробовать забронировать номер
    bookingService.bookRoom(101, "John Doe");

    // Показать все бронирования
    cout << "\nCurrent Bookings:" << endl;
    bookingService.displayBookings();

    // Показать доступные номера
    cout << "\nAvailable Rooms:" << endl;
    vector<Room> availableRooms = hotelService.getAvailableRooms();
    for (const auto& room : availableRooms) {
        room.displayRoomInfo();
    }

    return 0;
}