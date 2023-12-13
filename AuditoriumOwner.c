#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reservation.h"
#define CALCULATE_TOTAL_PROFIT(reservations, reservationCount) \
   do                                                          \
   {                                                           \
      int totalProfitMacro = 0;                                \
      for (int i = 0; i < reservationCount; i++)               \
      {                                                        \
         totalProfitMacro += reservations[i].price;            \
      }                                                        \
      printf("Total Profit : %d\n", totalProfitMacro);         \
   } while (0)

// bütün salonların sahibi auditoriumOwner diye bütün arrayleri burada tuttum

struct ConferenceHall saloonsKnowledge[500];
struct Reservation reservations[500];
struct Customer customers[500];

int static reservationCount = 0;
int conferenceHallCount = 0;
int customerCount = 0;

// FILE usage
void writeConferenceHall(ConferenceHall conf)
{

   FILE *file = fopen("ConferenceHall.bin", "ab");

   if (file == NULL)
   {

      printf("Error opening file for writing\n");

      return;
   }

   int status = fwrite(&conf, sizeof(ConferenceHall), 1, file); // komple struct'ı yazdırma
   fclose(file);

   if (status != 1)
   {
      printf("Error while writing the file !!");
   }
}

void readConferenceHall()
{
   conferenceHallCount = 0;
   FILE *file = fopen("ConferenceHall.bin", "rb");

   if (file == NULL)
   {
      printf("Error opening file for writing.\n");
      return;
   }

   int i = 0;
   while (fread(&saloonsKnowledge[i], sizeof(ConferenceHall), 1, file) != 0)
   {
      i++;
      conferenceHallCount++;
   }

   fclose(file);
}

void deleteConferenceHall(int confHallId)
{
   FILE *tempFile = fopen("Temp.bin", "ab");

   if (tempFile == NULL)
   {
      printf("Error opening file for writing.\n");
      return;
   }

   for (int i = 0; i < conferenceHallCount; i++)
   {
      if (confHallId == saloonsKnowledge[i].id)
      {
         continue;
      }
      fwrite(&saloonsKnowledge[i], sizeof(ConferenceHall), 1, tempFile); // silmek istediğim şeye eşitse onu atlayıp yeniden yazıyorum
   }
   conferenceHallCount--;
   fclose(tempFile);
   remove("ConferenceHall.bin");
   rename("Temp.bin", "ConferenceHall.bin");
   readConferenceHall(); // yeniden okuması için
}

Customer *login(char *username, char *password) // NULL sadece pointerlar için C'de
{

   for (int i = 0; i < customerCount; i++)
   {

      if (strcmp(customers[i].username, username) == 0 && strcmp(customers[i].password, password) == 0)
      {

         return &customers[i];
      }
   }
   return NULL;
}
void writeCustomer(Customer custom)
{

   FILE *file = fopen("Customer.bin", "ab");

   if (file == NULL)
   {

      printf("Error opening file for writing\n");

      return;
   }

   int status = fwrite(&custom, sizeof(Customer), 1, file); // komple struct'ı yazdırma
   fclose(file);

   if (status != 1)
   {
      printf("Error while writing the file !!");
   }
}

void readCustomer()
{
   customerCount = 0;
   FILE *file = fopen("Customer.bin", "rb");

   if (file == NULL)
   {
      printf("Error opening file for writing.\n");
      return;
   }

   int i = 0;
   while (fread(&customers[i], sizeof(Customer), 1, file) != 0)
   {
      i++;
      customerCount++;
   }

   fclose(file);
}

void deleteFromFile(int customerId)
{
   FILE *file = fopen("Customer.bin", "rb");
   if (file == NULL)
   {
      perror("File could not be opened !");
      exit(EXIT_FAILURE);
   }

   FILE *tempFile = fopen("temp.bin", "wb");
   if (tempFile == NULL)
   {
      perror("Temp file could not be created!");
      fclose(file);
      exit(EXIT_FAILURE);
   }

   Customer currentCustomer;

   while (fread(&currentCustomer, sizeof(Customer), 1, file) == 1)
   {
      if (currentCustomer.id != customerId)
      {
         fwrite(&currentCustomer, sizeof(Customer), 1, tempFile);
      }
   }

   fclose(file);
   fclose(tempFile);

   if (remove("Customer.bin") != 0)
   {
      perror("Original file could not be deleted");
      exit(EXIT_FAILURE);
   }

   if (rename("temp.bin", "Customer.bin") != 0)
   {
      perror("Could not name temp file");
      exit(EXIT_FAILURE);
   }

   printf("Customer successfully deleted.\n");
}
void writeReservation(Reservation reserv)
{

   FILE *file = fopen("Reservation.bin", "ab");

   if (file == NULL)
   {

      printf("Error opening file for writing\n");

      return;
   }

   int status = fwrite(&reserv, sizeof(Reservation), 1, file); // komple struct'ı yazdırma
   fclose(file);

   if (status != 1)
   {
      printf("Error while writing the file !!");
   }
}

void readReservation()
{
   reservationCount = 0;
   FILE *file = fopen("Reservation.bin", "rb");

   if (file == NULL)
   {
      printf("Error opening file for writing.\n");
      return;
   }

   int i = 0;
   while (fread(&reservations[i], sizeof(Reservation), 1, file) != 0)
   {
      i++;
      reservationCount++;
   }

   fclose(file);
}

int findCustomerIndex(int id)
{
   for (int i = 0; i < customerCount; i++)
   {
      if (id == customers[i].id)
      {
         return i;
      }
   }
   return -1; //NEDEN ÇALDIM DSFJKSDFHSDJFSDJF
}