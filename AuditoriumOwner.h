#include "Reservation.h"


typedef struct AuditoriumOwner
{
    Reservation reservation;
    Reservation (*createReservation)(int reservationId,int price, char *purpose,int date, int hour, Customer customer,ConferenceHall conferenceHall); //??

}AuditoriumOwner;


 Reservation createReservation(int reservationId,int price, char *purpose,int date, int hour, Customer customer,ConferenceHall conferenceHall);