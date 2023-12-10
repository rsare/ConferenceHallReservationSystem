#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AuditoriumOwner.c"
#include "Customer.c"
#include "ConferenceHall.c"
#include "Reservation.c"

int test()
{
  ConferenceHall ch1 = {.capacity = 50, .id = 5, .isHallFull = isHallFull, .hallName = "sa"};
  ConferenceHall ch2 = {.capacity = 60, .id = 6, .isHallFull = isHallFull, .hallName = "jhsgf"};
  ConferenceHall ch3 = {.capacity = 70, .id = 8, .isHallFull = isHallFull, .hallName = "jkfghdj"};

  int rID;
  int price;
  char *aim;
  int date;
  int hours;
  /*  printf("Please enter your ID:");
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
    Reservation reservationScanf = createReservation(rID,price,aim,date,hours,customer1,conferenceHall1);*/

  /* Reservation reservation1 = createReservation(100, 500, "Birthday", 251220, 12, customer1, ch1);
   Reservation reservation2 = createReservation(101, 500, "Engagement", 250422, 13, customer1, ch1);
   Reservation reservation3 = createReservation(102, 1000, "Wedding", 251220, 16, customer1, ch1);*/

  if (isHallFull(&ch1, 251220, 12))
  {
    printf("Salon dolu.\n");
  }
  else
  {
    printf("salon boş");
  }

  /* AuditoriumOwner auditoriumOwner;
   auditoriumOwner.createReservation = createReservation;
   auditoriumOwner.reservation = reservation1;*/

  /* printf("%d\n",conferenceHall.id);
   printf("%d\n",customer.id);
   printf("%s\n",reservation.customer.name);
   printf("%d\n",auditoriumOwner.reservation.conferenceHall.capacity);*/
  /*  printf("%s\n",reservation1.purpose);
    printf("%s\n",reservation2.customer.name);
    printf("%s\n",reservation3.conferenceHall.hallName);
    printf("%s\n",reservations->conferenceHall.hallName);
    printf("%d\n",reservations[2].reservationId);
    printf("%s\n",reservationScanf.purpose);*/

  writeConferenceHall(ch1);
  writeConferenceHall(ch2);
  writeConferenceHall(ch3);

  readConferenceHall();
  printf("%s\n", saloonsKnowledge[0].hallName);
  printf("%s\n", saloonsKnowledge[1].hallName);
  printf("%s\n", saloonsKnowledge[2].hallName);

  /* */

  return 0;
}

int main()
{

  Customer *account;
  createCustomer(100, "Sare", "Bayram", "123", "sare", true);
  char customerName[50];
  char customerSurname[50];
  char customerMail[50];
  char username[50];
  char password[10];
  char hallName[80];
  char purpose[500];
  int date;
  int hour;
  saloonsType saloonType;
  int option;
  int isLoggedIn = 0;

  while (true)
  {
    int choice;
    int index;
    char usagePurpose[100];
    if (isLoggedIn && account->isAdmin)
    {
      printf("-------------------WELCOME ADMIN %s-------------------\n", account->name);

      printf("What do you want as an admin ?\n");
      printf("1 - Click 1 to create a new reservation.\n"); 
      printf("2 - Click 2 to create a new customer.\n");
      printf("3 - Click 3 to create a new conference hall.\n");
      printf("4 - Click 4 to update a reservation.\n");
      printf("5 - Click 5 to delete a reservation.\n");
      printf("6 - Click 6 to see total profit.\n");
      printf("7 - Click 7 to log out.\n");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
        printf("Please enter your purpose:");
        scanf("%s\n", purpose);
        fflush(stdin);
        printf("Please enter your date:");
        scanf("%d\n", &date);
        printf("Please enter your hour:");
        scanf("%d\n", &hour);
        printf("Please choose one customer : \n");
        for (int i = 0; i < customerCount; i++)
        {
          printf("%d - ", (i + 1));
          printf("Customer's Name and Surname : %s %s \n", customers[i].name, customers[i].surname);
        }
        scanf("%d\n", &choice);

        printf("Please choose a saloon :\n");
        for (int i = 0; i < conferenceHallCount; i++)
        {
          printf("%d - ", (i + 1));
          printf("Saloon Knowledge : %s , %d", saloonsKnowledge[i].hallName, saloonsKnowledge[i].capacity);
        }
        scanf("%d\n", &index);
        createReservation((resId + reservationCount), setPriceAccToCapacity(saloonType), purpose, date, hour, customers[choice-1], saloonsKnowledge[index-1]);
        break;
      case 2:
        printf("Please enter customer's name :\n");
        scanf("%s\n", customerName);
        printf("Please enter customer's surname :\n");
        scanf("%s\n", customerSurname);
        printf("Please enter customer's e-mail :\n");
        scanf("%s\n", customerMail);
        createCustomer((idC + customerCount), customerName, customerSurname, "456", customerName, 0);

        break;
      case 3:
        printf("Please enter hall name which you want :\n");
        scanf("%s", hallName);
        printf("Please select conference hall capacity :\n");
        printf("1 - Select 1 to Small Saloon.\n");
        printf("2 - Select 2 to Medium Saloon.\n");
        printf("3 - Select 3 to Large Saloon.\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
          saloonType = SMALL_SALOON;
        }
        else if (choice == 2)
        {
          saloonType = MEDIUM_SALOON;
        }
        else if (choice == 3)
        {
          saloonType = LARGE_SALOON;
        }
        createConferenceHall((idCH + conferenceHallCount), hallName, saloonType);
        break;
      case 4:
        CALCULATE_TOTAL_PROFIT(reservations, reservationCount);
        break;
      case 5:
        account = NULL;
        isLoggedIn = 0;
        printf("You logged out successfuly.\n");
        break;

      default:
        break;
      }
    }
    else
    {
      printf("What do you want to login as? \n");
      printf("1 - Click 1 to login.\n");
      printf("2 - Click 2 to register.\n");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1: // login
        printf("Please Enter Username : \n");
        scanf("%s", username);
        printf("Please Enter Password : \n");
        scanf("%s", password);

        account = login(username, password);
        if (account != NULL)
        {
          printf("You logged in successfuly.\n");
          isLoggedIn = 1;
        }
        else
        {
          printf("User not found. Something went wrong !!\n");
        }

        break;

      default:
        break;
      }
    }
  }

  return 0;
}
