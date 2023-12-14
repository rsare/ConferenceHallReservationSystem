#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AuditoriumOwner.c"
#include "Customer.c"
#include "ConferenceHall.c"
#include "Reservation.c"

int main()
{
  readConferenceHall();
  readCustomer();
  readReservation();
  Customer *account;
  // ConferenceHall conferenceHall;
  saloonsType saloonType;
  createCustomer(100, "Admin", "Admin", "123", "admin", true);
  char customerName[50];
  char customerSurname[50];
  char customerMail[50];
  char username[50];
  char password[10];
  char hallName[80];
  char purpose[500];
  int date;
  int hour;
  int option;
  int isLoggedIn = 0;
  int myResCount = 1;
  int reservCount = 1;
  int flag = 0;

  while (true)
  {
    int choice;
    int index;
    char usagePurpose[100];
    if (isLoggedIn && account->isAdmin)
    {
      printf("\n-------------------WELCOME ADMIN %s-------------------\n", account->name);

      printf("What do you want as an admin ?\n");
      printf("1 - Click 1 to create a new reservation.\n");
      printf("2 - Click 2 to create a new customer.\n");
      printf("3 - Click 3 to create a new conference hall.\n");
      printf("4 - Click 4 to update a reservation.\n");
      printf("5 - Click 5 to delete a reservation.\n");
      printf("6 - Click 6 to delete a customer.\n");
      printf("7 - Click 7 to delete a conference hall.\n");
      printf("8 - Click 8 to see total profit.\n");
      printf("9 - Click 9 to see all reservations.\n");
      printf("10 - Click 10 to log out. \n");
      fflush(stdin);
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
        printf("Please enter your purpose: ");
        fflush(stdin);
        scanf("%s", purpose);
        printf("Please enter your date: ");
        fflush(stdin);
        scanf("%d", &date);
        printf("Please enter your hour: ");
        fflush(stdin);
        scanf("%d", &hour);
        printf("Please choose one customer : \n");
        for (int i = 0; i < customerCount; i++)
        {
          printf("%d - ", (i + 1));
          printf("Customer's Name and Surname : %s %s \n", customers[i].name, customers[i].surname);
        }
        printf("Your choice : ");
        fflush(stdin);
        scanf("%d", &index);

        if (index < 1 || index > conferenceHallCount)
        {
          printf("Invalid choice. Conference hall does not exist.\n");
        }
        else
        {
          // printf("Your choice : ");
          // fflush(stdin);
          scanf("%d", &choice);
          printf("\nPlease choose a saloon :\n");
          for (int i = 0; i < conferenceHallCount; i++)
          {
            printf("%d - Saloon Knowledge : %s , %s \n", (i + 1), saloonsKnowledge[i].hallName, saloons_Type[saloonsKnowledge[i].capacity]);
          }
          printf("\nYour choice : ");
          fflush(stdin);
          scanf("%d", &index);
          createReservation((resId + reservationCount), setPriceAccToCapacity(saloonType), purpose, date, hour, customers[choice - 1], saloonsKnowledge[index - 1]);
          writeReservation(reservations[reservationCount - 1]);
          printf("\nCustomer's reservation created successfully.\n");
        }

        /*printf("Your choice : ");
         fflush(stdin);
         scanf("%d", &choice);
         printf("Please choose a saloon :\n");
         for (int i = 0; i < conferenceHallCount; i++)
         {
           printf("%d - Saloon Knowledge : %s , %s \n", (i + 1), saloonsKnowledge[i].hallName, saloons_Type[saloonsKnowledge[i].capacity]);
         }
         printf("Your choice : ");
         fflush(stdin);
         scanf("%d", &index);*/
        break;
      case 2:
        printf("Please enter customer's name :\n");
        fflush(stdin);
        gets(customerName);
        printf("Please enter customer's surname :\n");
        fflush(stdin);
        gets(customerSurname);
        createCustomer((idC + customerCount), customerName, customerSurname, "123", customerName, 0);
        writeCustomer(customers[customerCount - 1]);
        break;
      case 3:
        printf("Please enter hall name which you want :\n");
        fflush(stdin);
        gets(hallName);
        printf("Please select conference hall capacity :\n");
        printf("1 - Small Saloon.\n");
        printf("2 - Medium Saloon.\n");
        printf("3 - Large Saloon.\n");
        printf("\nYour choice : ");
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
        writeConferenceHall(saloonsKnowledge[conferenceHallCount - 1]);
        printf("\nCreated saloon name : %s \n", hallName);
        printf("\nConferecence Hall Created Successfuly.\n");
        break;
      case 4:

        for (int i = 0; i < reservationCount; i++)
        {
          printf("\n%d - Reservation's Owner Name Surname : %s  %s / Reservation ID : %d\n", (i + 1), reservations[i].customer.name, reservations[i].customer.surname, reservations[i].reservationId);
        }

        printf("\nPlease write the ID of the reservation you want to update :");
        scanf("%d", &choice);
        printf("\nPlease specify the date of your new reservation :");
        scanf("%d", &date);
        printf("\nPlease specify the time of your new reservation :");
        scanf("%d", &hour);
        printf("\nWe are checking whether the conference hall is full on the date and time you requested... We apologize for keeping you waiting....\n");
        if (isHallFull(&reservations[choice - 1].conferenceHall, date, hour) == false)
        {
          updateReservation(&reservations[choice - 1], date, hour);
          printf("Reservation updated successfuly.\n");
        }
        else
        {
          printf("\nOur hall is full on the date and time you entered, please enter another date and time...\n");
        }

        break;
      case 5:
        for (int i = 0; i < reservationCount; i++)
        {
          printf("\n%d - Reservation's Owner Name Surname : %s  %s / Reservation ID : %d\n", (i + 1), reservations[i].customer.name, reservations[i].customer.surname, reservations[i].reservationId);
        }
        if (reservationCount == 0)
        {
          printf("No reservations to delete were found !!\n");
          return 0;
        }
        printf("Please select reservation which you want to delete :\n");
        scanf("%d", &choice);
        deleteReservation(&reservations[choice - 1], reservations[choice - 1].reservationId);
        printf("Your reservation deleted successfuly... We wait again.");
        break;
      case 6:
        for (int i = 0; i < customerCount; i++)
        {
          printf("\n%d - Customer's Name Surname : %s  %s / Customer ID : %d\n", (i + 1), customers[i].name, customers[i].surname, customers[i].id);
        }
        printf("Please select customer which you want to delete :\n");
        scanf("%d", &choice);
        deleteFromFile(customers[choice - 1].id);
        readCustomer();
        printf("Selected customer deleted successfuly... We wait again.");

        break;
      case 7:
        for (int i = 0; i < conferenceHallCount; i++)
        {
          printf("\n%d - Conference Hall Name  : %s  / Conference Hall ID : %d\n", (i + 1), saloonsKnowledge[i].hallName, saloonsKnowledge[i].id);
        }
        printf("Please select conference hall which you want to delete :\n");
        scanf("%d", &choice);
        deleteConferenceHall(saloonsKnowledge[choice - 1].id);
        printf("Conference hall deleted successfuly...");
        break;

      default:
        break;
      case 8:
        CALCULATE_TOTAL_PROFIT(reservations, reservationCount);
        break;
      case 9:
        for (int i = 0; i < reservCount; i++)
        {
          if (reservations[i].customer.id == account->id)
          {
            printf("\n%d - Reservation's Owner Name Surname : %s  %s / Reservation ID : %d\n",
                   (i + 1), reservations[i].customer.name, reservations[i].customer.surname, reservations[i].reservationId);
            flag = 1;
            reservCount++;
          }
        }

        if (flag == 0)
        {
          printf("You don't have any reservation.\n");
        }

        break;
      case 10:

        account = NULL;
        isLoggedIn = 0;
        printf("You logged out successfuly...\n");
        printf("\n--------------WE WAIT AGAIN--------------\n");
        // main();
        break;
      }
    }
    else if (isLoggedIn && !account->isAdmin)
    {
      printf("\n-------------------WELCOME USER-------------------\n");
      printf("\nWhat would you like to do as a user? \n");
      printf("1 - Click 1 to create a new reservation.\n");
      printf("2 - Click 2 to see your reservations.\n");
      printf("3 - Click 3 to update a reservation.\n");
      printf("4 - Click 4 to delete a reservation.\n");
      printf("5 - Click 5 to log out.\n");

      printf("Your choice : ");
      fflush(stdin);
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
        printf("Please enter your purpose: ");
        fflush(stdin);
        scanf("%s", purpose);
        printf("Please enter your date: ");
        fflush(stdin);
        scanf("%d", &date);
        printf("Please enter your hour: ");
        fflush(stdin);
        scanf("%d", &hour);
        printf("Please choose a saloon :\n");
        for (int i = 0; i < conferenceHallCount; i++)
        {
          printf("%d - Saloon Knowledge : %s , %s \n", (i + 1), saloonsKnowledge[i].hallName, saloons_Type[saloonsKnowledge[i].capacity]);
        }
        printf("Your choice : ");
        fflush(stdin);
        scanf("%d", &index);
        createReservation((resId + reservationCount), setPriceAccToCapacity(saloonType), purpose, date, hour, *account, saloonsKnowledge[index]);
        writeReservation(reservations[reservationCount - 1]);
        break;
      case 2:
        myResCount = 1;
        bool flag = 0;
        for (int i = 0; i < reservationCount; i++)
        {
          if (reservations[i].customer.id == account->id)
          {
            printf("\n%d - Reservation's Owner Name Surname : %s  %s / Reservation ID : %d\n", myResCount, reservations[i].customer.name, reservations[i].customer.surname, reservations[i].reservationId);
            flag = 1;
            myResCount++;
          }
        }
        if (flag == 0)
        {
          printf("You don't have any reservation");
        }

        break;
      case 3:
        myResCount = 1;
        for (int i = 0; i < reservationCount; i++)
        {
          if (reservations[i].customer.id == account->id)
          {
            printf("\n%d - Reservation's Owner Name Surname : %s  %s / Reservation ID : %d\n", myResCount, reservations[i].customer.name, reservations[i].customer.surname, reservations[i].reservationId);
            myResCount++;
          }
        }

        printf("\nPlease write the ID of the reservation you want to update :");
        scanf("%d", &choice);
        printf("\nPlease specify the date of your new reservation :");
        scanf("%d", &date);
        printf("\nPlease specify the time of your new reservation :");
        scanf("%d", &hour);
        printf("\nWe are checking whether the conference hall is full on the date and time you requested... We apologize for keeping you waiting....\n");
        if (isHallFull(&reservations[choice - 1].conferenceHall, date, hour) == false)
        {
          for (int i = 0; i < reservationCount; i++)
          {
            if (reservations[i].customer.id == account->id && choice != 1)
            {
              choice--;
            }
            else if (reservations[i].customer.id == account->id && choice == 1)
            {
              updateReservation(&reservations[i], date, hour);
            }
          }
          printf("Reservation updated successfuly.\n");
          break;
        }
        else
        {
          printf("\nOur hall is full on the date and time you entered, please enter another date and time...\n");
        }
        break;
      case 4:
        myResCount = 1;
        for (int i = 0; i < reservationCount; i++)
        {
          if (reservations[i].customer.id == account->id)
          {
            printf("\n%d - Reservation's Owner Name Surname : %s  %s / Reservation ID : %d\n", myResCount, reservations[i].customer.name, reservations[i].customer.surname, reservations[i].reservationId);
            myResCount++;
          }
        }
        printf("Please select reservation which you want to delete :\n");
        scanf("%d", &choice);
        for (int i = 0; i < reservationCount; i++)
        {
          if (reservations[i].customer.id == account->id && choice != 1)
          {
            choice--;
          }
          else if (reservations[i].customer.id == account->id && choice == 1)
          {
            deleteReservation(&reservations[i], reservations[i].reservationId);
          }
        }

        printf("Your reservation deleted successfuly... We wait again.");

        break;
      case 5:
        account = NULL;
        isLoggedIn = 0;
        printf("You logged out successfuly...\n");
        printf("\n--------------WE WAIT AGAIN--------------\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");

        break;
      }
    }
    else
    {

      printf("\nWhat do you want to login as? \n");
      printf("1 - Click 1 to login.\n");
      printf("2 - Click 2 to register.\n");
      fflush(stdin);
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
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
      case 2:
        printf("\nDO YOU WANT TO REGISTER? \n");
        printf("Please enter your name :\n");
        scanf("%s", customerName);
        printf("Please enter your surname : \n");
        scanf("%s", customerSurname);
        printf("Please enter your password : \n");
        scanf("%s", password);
        printf("Please enter your username : \n");
        scanf("%s", username);

        createCustomer((idC + customerCount), customerName, customerSurname, password, username, 0); //??

        break;
      default:

        break;
      }
    }
  }

  return 0;
}
