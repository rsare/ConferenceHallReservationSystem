#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

int isUsernameTaken(const char *username) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].username, username) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int idC = 50;
Customer createCustomer(int id, char *name, char *surname, char *password, char *username, bool isAdmin)
{
    if (isUsernameTaken(username)) {
        printf("Error: Username already taken. Please choose a different username.\n");
    }else{
        printf("\nCustomer created successfuly.\n");
    }

    Customer c1;
    c1.id = id;
    strcpy(c1.name, name);
    strcpy(c1.surname, surname);
    strcpy(c1.password, password);
    strcpy(c1.username, username);
    c1.isAdmin = isAdmin;

    customers[customerCount] = c1;
    customerCount++;
    

    return c1;
}

Reservation *getAllReservations(Customer *customer)
{ // birden fazla rezervasyonu göstermesini istediğim için pointer

    Reservation *res = calloc(10, sizeof(Reservation));
    int index = 0;
    for (int i = 0; i < reservationCount; i++)
    {
        if (reservations[i].customer.id == customer->id)
        {
            res[index] = reservations[i];
            index++;
        }
    }

    return res;
}