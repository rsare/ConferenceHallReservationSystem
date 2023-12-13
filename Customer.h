#ifndef CUSTOMER_H
#define CUSTOMER_H


typedef struct Customer
{
    int id;
    char name[50];
    char surname[50];
    char password[10];
    char username[20];
    bool isAdmin;
    struct Reservation *(*getAllReservations)(struct Customer *customer);
    
}Customer;

Customer createCustomer(int id, char *name, char *surname, char *password, char *username, bool isAdmin);
struct Reservation *getAllReservations(Customer *customer);

#endif