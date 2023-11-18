#include "Customer.h"
#include "ConferenceHall.c"


typedef struct Reservation
{
    int reservationId;
    int price;  
    char *purpose;
    int date;
    int hour;
    Customer customer;
    ConferenceHall conferenceHall;
        

}Reservation;
