#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ConferenceHall.h"




bool saloon1_full = false;
bool saloon2_full = false;
bool saloon3_full = false;

bool isHallFull(struct ConferenceHall *self,int date, int hour)
{
    switch (self->capacity)
    {
    case 1:
        return saloon1_full =  true;
    case 2:
        return saloon2_full = true;
    case 3:
        return saloon3_full = true;

    default:
        return false;
    }
}

/* bool isFull = true;
    printf("Please enter a date.");
    scanf("%s\n",date);
    printf("Please enter a hour.");
    scanf("%s\n",hour);

    if(date == true && hour == true){
        printf("The conference hall is full on the entered date!");
    }else{
        printf("You can make a reservation for the conference hall.");
    }
*/

/*#include <stdio.h>
#include <stdbool.h>

// Örnek bir konferans salonu veri yapısı
struct ConferenceRoom {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    bool isOccupied;
};

// Fonksiyon: Konferans salonunun dolu olup olmadığını kontrol et
bool isConferenceRoomOccupied(struct ConferenceRoom room, int checkDay, int checkMonth, int checkYear, int checkHour, int checkMinute) {
    // İlgili tarih ve saat kontrolü
    if (room.year == checkYear && room.month == checkMonth && room.day == checkDay &&
        room.hour == checkHour && room.minute == checkMinute) {
        return room.isOccupied;
    } else {
        return false; // Belirtilen tarih ve saatte salon dolu değil
    }
}

int main() {
    // Örnek bir konferans salonu oluşturuluyor
    struct ConferenceRoom myConferenceRoom = {12, 11, 2023, 14, 30, true};

    // Kontrol etmek istediğiniz tarih ve saat
    int checkDay = 12;
    int checkMonth = 11;
    int checkYear = 2023;
    int checkHour = 14;
    int checkMinute = 30;

    // Fonksiyon çağrısı ile konferans salonunun durumunu kontrol et
    if (isConferenceRoomOccupied(myConferenceRoom, checkDay, checkMonth, checkYear, checkHour, checkMinute)) {
        printf("Konferans salonu dolu.\n");
    } else {
        printf("Konferans salonu bos.\n");
    }

    return 0;
}
*/
