#include <stdio.h>
#include <stdlib.h>
#include "AuditoriumOwner.c"

int main()
{
    
    ConferenceHall conferenceHall1;
    conferenceHall1.capacity = 50;
    conferenceHall1.id = 5;
    conferenceHall1.isHallFull = isHallFull;
    conferenceHall1.hallName = "sa";

    Customer customer1;
    customer1.id = 2;
    customer1.name = "hd";
    customer1.surname = "jkd";
    
    int rID;
    int price;
    char *aim;
    int date;
    int hours;
    printf("Please enter your ID:");
    scanf("%d\n",&rID);
    printf("Please enter your price:");
    scanf("%d\n",&price);
    printf("Please enter your aim:");
    scanf("%s\n",aim);
    fflush(stdin);
    printf("Please enter your date:");
    scanf("%d\n",&date);
    printf("Please enter your hour:");
    scanf("%d\n",&hours);
    Reservation reservationScanf = createReservation(rID,price,aim,date,hours,customer1,conferenceHall1);



    Reservation reservation1 = createReservation(100,500,"Birthday",251220,12,customer1,conferenceHall1);
    Reservation reservation2 = createReservation(101,500,"Engagement",250422,13,customer1,conferenceHall1);
    Reservation reservation3 = createReservation(102,1000,"Wedding",251220,16,customer1,conferenceHall1);


    AuditoriumOwner auditoriumOwner;
    auditoriumOwner.createReservation = createReservation;
    auditoriumOwner.reservation = reservation1;

    /* printf("%d\n",conferenceHall.id);
     printf("%d\n",customer.id);
     printf("%s\n",reservation.customer.name);
     printf("%d\n",auditoriumOwner.reservation.conferenceHall.capacity);*/
    printf("%s\n",reservation1.purpose);
    printf("%s\n",reservation2.customer.name);
    printf("%s\n",reservation3.conferenceHall.hallName);
    printf("%s\n",reservations->conferenceHall.hallName);
    printf("%d\n",reservations[2].reservationId);
    printf("%s\n",reservationScanf.purpose);

    return 0;
}
