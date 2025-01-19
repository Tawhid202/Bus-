#ifndef BUS_H
#define BUS_H

#include<stdio.h>
#include<string.h>

#define MAX_BUSES 80
#define MAX_SEATS 50

 struct Bus{

     char bus_id[12];
     char source[20];
     char destination[20];
     int seats;
     int available_seats;
     float price;
     char departure_time[10];
     char arrival_time[10];
 };

  void create_bus(struct Bus* bus);
  void display_bus(struct Bus* bus);
  struct Bus* find_bus(char* bus_id, struct Bus buses[], int num_buses);
  int is_bus_full(struct Bus* bus);
  int load_buses(struct Bus buses[], int max_buses);
  void save_buses(struct Bus buses[], int num_buses);

  #endif
