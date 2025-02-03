#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 5

// Structure to store room details
typedef struct {
    int room_number;
    int is_reserved;
    char guest_name[100];
    int stay_duration; // in days
} Room;

// Function prototypes
void displayRooms(Room rooms[], int size);
void reserveRoom(Room rooms[], int size);
void checkAvailability(Room rooms[], int size);

int main() {
    // Array to store room information (for simplicity, max 5 rooms)
    Room rooms[MAX_ROOMS] = {
        {101, 0, "", 0},
        {102, 0, "", 0},
        {103, 0, "", 0},
        {104, 0, "", 0},
        {105, 0, "", 0}
    };

    int choice;

    while (1) {
        // Display the menu
        printf("\nHotel Reservation System\n");
        printf("1. View Available Rooms\n");
        printf("2. Reserve a Room\n");
        printf("3. Check Room Availability\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, MAX_ROOMS);
                break;
            case 2:
                reserveRoom(rooms, MAX_ROOMS);
                break;
            case 3:
                checkAvailability(rooms, MAX_ROOMS);
                break;
            case 4:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display available rooms
void displayRooms(Room rooms[], int size) {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < size; i++) {
        if (rooms[i].is_reserved == 0) {
            printf("Room %d is available.\n", rooms[i].room_number);
        }
    }
}

// Function to reserve a room
void reserveRoom(Room rooms[], int size) {
    int roomNumber, stayDuration;
    char guestName[100];

    printf("Enter room number to reserve: ");
    scanf("%d", &roomNumber);

    // Check if room number is valid
    if (roomNumber < 101 || roomNumber > 105) {
        printf("Invalid room number!\n");
        return;
    }

    int index = roomNumber - 101;

    // Check if room is already reserved
    if (rooms[index].is_reserved == 1) {
        printf("Sorry, Room %d is already reserved.\n", roomNumber);
        return;
    }

    printf("Enter guest name: ");
    getchar(); // To consume the newline left by scanf
    fgets(guestName, sizeof(guestName), stdin);
    guestName[strcspn(guestName, "\n")] = 0; // Remove the trailing newline

    printf("Enter stay duration (in days): ");
    scanf("%d", &stayDuration);

    // Assign reservation details
    rooms[index].is_reserved = 1;
    strcpy(rooms[index].guest_name, guestName);
    rooms[index].stay_duration = stayDuration;

    printf("Reservation successful! Room %d has been reserved for %s for %d days.\n", roomNumber, guestName, stayDuration);
}

// Function to check the availability of rooms
void checkAvailability(Room rooms[], int size) {
    int roomNumber;
    printf("Enter room number to check availability: ");
    scanf("%d", &roomNumber);

    // Check if room number is valid
    if (roomNumber < 101 || roomNumber > 105) {
        printf("Invalid room number!\n");
        return;
    }

    int index = roomNumber - 101;

    if (rooms[index].is_reserved == 1) {
        printf("Room %d is reserved by %s for %d days.\n", roomNumber, rooms[index].guest_name, rooms[index].stay_duration);
    } else {
        printf("Room %d is available.\n", roomNumber);
    }
}

