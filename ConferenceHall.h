

typedef enum saloonsType{

SMALL_SALOON,
MEDIUM_SALOON,
LARGE_SALOON

}saloonsType;

typedef struct ConferenceHall{
    int id;
    char *hallName;
    int capacity;
    bool (*isHallFull)(struct ConferenceHall *self,int date, int hour);
    
}ConferenceHall;


bool isHallFull(struct ConferenceHall *self,int date, int hour); //bu tanım, süslü parantez açarsam method olur