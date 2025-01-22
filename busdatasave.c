#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#define MAX_BUSES 10  // Maximum number of buses  
#define MAX_SEATS 10  // Maximum number of seats per bus  
#define FILE_NAME "buses.dat"  // Filename to store bus information  

typedef struct {  
    char busNumber[10];  
    char driver[50];  
    char startTime[10];   // Format: HH:MM  
    char reachTime[10];   // Format: HH:MM  
    char destination[50];  
    char place[50];  
    int seats[MAX_SEATS];  
} Bus;  

typedef struct {  
    char name[50];  
    char id[10];  
    char phone[15];  
} Customer;  

Bus buses[MAX_BUSES];              // Array to store bus data  
Customer customers[MAX_BUSES];     // Array to store customer data  
int busCount = 0;                  // Keep track of the number of buses  
int customerCount = 0;             // Keep track of customers  

void addBusInfo() {  
    if (busCount >= MAX_BUSES) {  
        printf("Cannot add more buses. Maximum limit reached.\n");  
        return;  
    }  

    printf("Enter bus number: ");  
    scanf("%s", buses[busCount].busNumber);  
    printf("Enter driver's name: ");  
    scanf("%s", buses[busCount].driver);  
    printf("Enter starting time (HH:MM): ");  
    scanf("%s", buses[busCount].startTime);  
    printf("Enter reaching time (HH:MM): ");  
    scanf("%s", buses[busCount].reachTime);  
    printf("Enter destination: ");  
    scanf("%s", buses[busCount].destination);  
    printf("Enter place: ");  
    scanf("%s", buses[busCount].place);  
    
    // Initialize seats as available (0)  
    for (int j = 0; j < MAX_SEATS; j++) {  
        buses[busCount].seats[j] = 0; // Initialize seats as available  
    }  

    busCount++; // Increment the count of buses  
    printf("Bus information added successfully!\n");  
}  

void viewBuses() {  
    printf("Available Buses:\n");  
    for (int i = 0; i < busCount; i++) {  
        printf("Bus Number: %s, Driver: %s, Start Time: %s, Reach Time: %s, Destination: %s, Place: %s\n",  
               buses[i].busNumber, buses[i].driver, buses[i].startTime, buses[i].reachTime,  
               buses[i].destination, buses[i].place);  
    }  
}  

void showBusStatus() {  
    printf("Bus Booking Status:\n");  
    for (int i = 0; i < busCount; i++) {  
        printf("Bus Number: %s to %s: ", buses[i].busNumber, buses[i].destination);  
        for (int j = 0; j < MAX_SEATS; j++) {  
            printf("%s ", buses[i].seats[j] == 0 ? "Available" : "Booked");  
        }  
        printf("\n");  
    }  
}  

void customerInfo() {  
    if (customerCount >= MAX_BUSES) {  
        printf("Cannot add more customers. Maximum limit reached.\n");  
        return;  
    }  
    
    printf("Enter customer name: ");  
    scanf("%s", customers[customerCount].name);  
    printf("Enter customer ID: ");  
    scanf("%s", customers[customerCount].id);  
    printf("Enter customer phone number: ");  
    scanf("%s", customers[customerCount].phone);  

    customerCount++; // Increment the count of customers  
    printf("Customer information added successfully!\n");  
}  

void bookTicket() {  
    char busNumber[10];  
    int seatNumber;  

    printf("Enter bus number to book (e.g., Bus1): ");  
    scanf("%s", busNumber);  

    printf("Enter seat number (1-%d): ", MAX_SEATS);  
    if (scanf("%d", &seatNumber) != 1) {  
        printf("Invalid input! Please enter a number.\n");  
        return;  
    }  
    seatNumber--; // Adjust to array index  

    for (int i = 0; i < busCount; i++) {  
        if (strcmp(buses[i].busNumber, busNumber) == 0) {  
            if (seatNumber >= 0 && seatNumber < MAX_SEATS) {  
                if (buses[i].seats[seatNumber] == 0) {  
                    buses[i].seats[seatNumber] = 1; // Mark seat as booked  
                    printf("Ticket booked successfully for %s on bus %s!\n", customers[customerCount - 1].name, busNumber);  
                    return;  
                } else {  
                    printf("Seat already booked!\n");  
                    return;  
                }  
            } else {  
                printf("Invalid seat number!\n");  
                return;  
            }  
        }  
    }  
    printf("Bus not found!\n");  
}  

void cancelBooking() {  
    char busNumber[10];  
    int seatNumber;  

    printf("Enter bus number to cancel ticket (e.g., Bus1): ");  
    scanf("%s", busNumber);  

    printf("Enter seat number (1-%d): ", MAX_SEATS);  
    if (scanf("%d", &seatNumber) != 1) {  
        printf("Invalid input! Please enter a number.\n");  
        return;  
    }  
    seatNumber--; // Adjust to array index  

    for (int i = 0; i < busCount; i++) {  
        if (strcmp(buses[i].busNumber, busNumber) == 0) {  
            if (seatNumber >= 0 && seatNumber < MAX_SEATS) {  
                if (buses[i].seats[seatNumber] == 1) {  
                    buses[i].seats[seatNumber] = 0; // Mark seat as available  
                    printf("Booking canceled successfully!\n");  
                    return;  
                } else {  
                    printf("No booking found for this seat!\n");  
                    return;  
                }  
            } else {  
                printf("Invalid seat number!\n");  
                return;  
            }  
        }  
    }  
    printf("Bus not found!\n");  
}  

int main() {  
    int option;  

    // Main loop  
    do {  
        printf("\nBus Reservation System\n");  
        printf("1. View Buses\n");  
        printf("2. Add Bus Info\n");  
        printf("3. Customer Info\n");  
        printf("4. Book Ticket\n");  
        printf("5. Cancel Booking\n");  
        printf("6. Show Bus Status\n");  
        printf("7. Exit\n");  
        printf("Choose an option: ");  

        if (scanf("%d", &option) != 1) {  
            printf("Invalid input! Please enter a number.\n");  
            while (getchar() != '\n'); // Clear input buffer  
            continue;  
        }  

        switch (option) {  
            case 1: viewBuses(); break;  
            case 2: addBusInfo(); break;  
            case 3: customerInfo(); break; // Adding customer information  
            case 4: bookTicket(); break;  
            case 5: cancelBooking(); break;  
            case 6: showBusStatus(); break;  
            case 7: printf("Exiting...\n"); break;  
            default: printf("Invalid option!\n"); break;  
        }  
    } while (option != 7);  

    return 0;  
}
