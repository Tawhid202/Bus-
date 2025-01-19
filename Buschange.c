
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bus.h"

int main() {
    struct Bus buses[MAX_BUSES];
    int num_buses = 0;
    char search_bus_id[10];
    int choice, i;

    // Load buses from file (if available)
    num_buses = load_buses(buses, MAX_BUSES);

    do {
        printf("\nBus Management System\n");
        printf("1. Add Bus\n");
        printf("2. Display All Buses\n");
        printf("3. Find Bus\n");
        printf("4. Modify Bus Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_buses < MAX_BUSES) {
                    create_bus(&buses[num_buses]);
                    num_buses++;
                    printf("Bus added successfully!\n");
                } else {
                    printf("Maximum number of buses reached.\n");
                }
                break;

            case 2:
                printf("\nBus Information:\n");
                for (i = 0; i < num_buses; i++) {
                    display_bus(&buses[i]);
                    printf("\n");
                }
                break;

            case 3:
                printf("Enter Bus ID to find: ");
                scanf("%s", search_bus_id);
                struct Bus* found_bus = find_bus(search_bus_id, buses, num_buses);
                if (found_bus != NULL) {
                    printf("\nBus Found:\n");
                    display_bus(found_bus);
                } else {
                    printf("Bus not found.\n");
                }
                break;

            case 4:
                printf("Enter Bus ID to modify: ");
                scanf("%s", search_bus_id);
                struct Bus* bus_to_modify = find_bus(search_bus_id, buses, num_buses);

                if (bus_to_modify != NULL) {
                    // Get new data from user
                    printf("\nEnter new Source: ");
                    scanf("%s", bus_to_modify->source);

                    printf("Enter new Destination: ");
                    scanf("%s", bus_to_modify->destination);

                    printf("Enter new Total Seats: ");
                    scanf("%d", &bus_to_modify->seats);
                    bus_to_modify->available_seats = bus_to_modify->seats;

                    printf("Enter new Price: ");
                    scanf("%f", &bus_to_modify->price);

                    printf("Enter new Departure Time (HH:MM): ");
                    scanf("%s", bus_to_modify->departure_time);

                    printf("Enter new Arrival Time (HH:MM): ");
                    scanf("%s", bus_to_modify->arrival_time);

                    printf("Bus data modified successfully!\n");
                } else {
                    printf("Bus not found.\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    // Save updated bus data to file
    save_buses(buses, num_buses);

    return 0;
}
