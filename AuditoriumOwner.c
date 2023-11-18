#include <stdio.h>
#include <stdlib.h>
#include "AuditoriumOwner.h"

//bütün salonların sahibi auditoriumOwner diye bütün arrayleri burada tuttum
ConferenceHall saloonsKnowledge[500];
Reservation reservations[500];
Customer customers[500];

/*#define SALOON1_CAPACITY 50
#define SALOON2_CAPACITY 100
#define SALOON3_CAPACITY 150

bool saloon1_full = false;
bool saloon2_full = false;
bool saloon3_full = false;*/

// enum forReservationID {ID = 100};

int resId = 100;

Reservation createReservation(int reservationId, int price, char *purpose,int date, int hour, Customer customer, ConferenceHall conferenceHall)
{

//Reservation reservation = {.conferenceHall = conferenceHall,.customer = customer vs vs} böyle de olur
Reservation reservation;
reservation.reservationId = reservationId;
reservation.price = price;
reservation.purpose = purpose;
reservation.date = date;
reservation.hour = hour;
reservation.customer = customer;
reservation.conferenceHall = conferenceHall;

reservations[reservationId-resId] = reservation;

return reservation;
}
