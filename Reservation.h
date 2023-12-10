#ifndef RESERVATION_H
#define RESERVATION_H

#include "Customer.h"
#include "ConferenceHall.h"


typedef struct Reservation
{
    int reservationId;
    int price;  
    char purpose[200];
    int date;
    int hour;
    Customer customer;  // struct Customer *customer;
    ConferenceHall conferenceHall;
        

}Reservation;

Reservation createReservation(int reservationId, int price, char *purpose, int date, int hour, Customer customer, ConferenceHall conferenceHall);
Reservation updateReservation(int newReservationId, int newDate, int newHour); //kendim
void deleteReservetion(Reservation reservations[], int deletedResId);

#endif