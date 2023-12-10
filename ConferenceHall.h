#ifndef CONFERENCEHALL_H
#define CONFERENCEHALL_H
//#include "AuditoriumOwner.h"



typedef enum saloonsType{

SMALL_SALOON,
MEDIUM_SALOON,
LARGE_SALOON

}saloonsType;

typedef struct ConferenceHall{
    int id;
    char hallName[100];
    saloonsType capacity;
    bool (*isHallFull)(struct ConferenceHall *self,int date, int hour);
    
}ConferenceHall;


ConferenceHall createConferenceHall(int id,char *hallName, saloonsType capacity);
ConferenceHall updateConferenceHall(int newId, char *newHallName, int newCapacity); //kendim
int setPriceAccToCapacity(saloonsType saloonsType); //kendim

bool isHallFull(struct ConferenceHall *self,int date, int hour); //bu tanım, süslü parantez açarsam method olur


#endif