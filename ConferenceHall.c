#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ConferenceHall.h"
// #include "AuditoriumOwner.c"


static const char *const saloons_Type[] = {
    [SMALL_SALOON] = "Small Saloon",
    [MEDIUM_SALOON] = "Medium Saloon",
    [LARGE_SALOON] = "Large Saloon",
    };



bool isHallFull(struct ConferenceHall *self, int date, int hour)
{
    for (int i = 0; i < reservationCount; i++)
    {

        if (reservations[i].conferenceHall.id == self->id && reservations[i].date == date && reservations[i].hour == hour)
        {
            return true;
        }
    }
    return false; // hepsini kontrol etmeden else'e atlayıp false döndürmesin diye return for'un dışında
}

int idCH = 20;
struct ConferenceHall createConferenceHall(int id, char *hallName, saloonsType capacity)
{

    ConferenceHall ch1;
    ch1.id = id;
    strcpy(ch1.hallName, hallName);
    ch1.capacity = capacity;

    saloonsKnowledge[id - idCH] = ch1;
    conferenceHallCount++;

    return ch1;
}

struct ConferenceHall updateConferenceHall(int newId, char *newHallName, int newCapacity)
{ // kendim

    ConferenceHall updateConferenceHall;

    updateConferenceHall.id = newId;
    strcpy(updateConferenceHall.hallName, newHallName);
    updateConferenceHall.capacity = newCapacity;

    saloonsKnowledge[newId - idCH] = updateConferenceHall;
}

int setPriceAccToCapacity(saloonsType saloonsType)
{
    int price = 500;
    if (saloonsType == 0)
    {
        price += 100;
    }
    else if (saloonsType == 1)
    {
        price += 300;
    }
    else
    {
        price += 500;
    }

    return price;
}


