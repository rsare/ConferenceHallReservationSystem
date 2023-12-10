#include <stdio.h>
#include <stdlib.h>
#include "Reservation.h"

int resId = 100;

struct Reservation createReservation(int reservationId, int price, char *purpose, int date, int hour, Customer customer, ConferenceHall conferenceHall)
{

    // Reservation reservation = {.conferenceHall = conferenceHall,.customer = customer vs vs} böyle de olur
    Reservation reservation;
    reservation.reservationId = reservationId;
    reservation.price = price;
    strcpy(reservation.purpose, purpose);
    reservation.date = date;
    reservation.hour = hour;
    reservation.customer = customer;
    reservation.conferenceHall = conferenceHall;

    reservations[reservationId - resId] = reservation;
    reservationCount++;

    return reservation;
}

struct Reservation updateReservation(int newReservationId, int newDate, int newHour)
{ // kendim

    Reservation updateReservation;
    updateReservation.reservationId = newReservationId;
    updateReservation.date = newDate;
    updateReservation.hour = newHour;

    reservations[newReservationId - resId] = updateReservation;

    return updateReservation;
}

void deleteReservetion(Reservation reservations[], int deletedResId)
{

    for (int i = 0; i < reservationCount; i++)
    {
        if (reservations[i].reservationId == deletedResId)
        {

            for (int j = i; j < reservationCount - 1; j++)
            {
                reservations[j] = reservations[j + 1];
            }

            reservationCount--;
        }
    }
}