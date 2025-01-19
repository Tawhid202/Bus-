#include<stdio.h>
#include<stdlib.h>
#include "bus.h"

int main()
{
    FILE *fp;
     // to save bus info.

    struct Bus bus;
    int num_buses,i;
    printf("Enter The Number Of Buses: ");
    scanf("%d",&num_buses);

    fp= fopen("bus_data.txt","w");

    for(i=0; i<num_buses; i++)
    {
        printf("\nBus %d\n",i+1);

        printf("Enter Bus Id: ");
        scanf("%s",&bus.bus_id);

        printf("Enter Source: ");
        scanf("%s",&bus.source);

        printf("Enter Destiation:");
        scanf("%s",&bus.destination);

        printf("Enter Total Seats:");
        scanf("%d",&bus.seats);
        bus.available_seats=bus.seats;

        printf("Enter Price:");
        scanf("%f",&bus.price);

        printf("Enter Departure time(HH:MM): ");
        scanf("%s",bus.departure_time);

        printf("Enter Arrival time(HH:MM): ");
        scanf("%s",bus.arrival_time);


        fprintf(fp,"Bus id:%s\nFrom: %s\nDestination: %s\nBus seats:%d\nPrice: %.2f\nDeparture Time: %s\nArrival Time:%s\n",bus.bus_id, bus.source, bus.destination,
                bus.seats, bus.price,bus.departure_time, bus.arrival_time);

    }
    fclose(fp);
    printf("Bus data saved\n");

    return 0;

}
