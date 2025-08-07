// manipulate structures with functions
#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

void readDate(struct date * today){
    scanf("%d %d %d",&today->year,&today->month,&today->day);
}

void printDate(struct date today){
    printf("%02d/%02d/%04d\n",today.month,today.day,today.year);
}

struct date advanceDay(struct date today){
    struct date tomorrow;
    int daysOfMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int day = today.day;
    int month = today.month;
    int year = today.year;
    
    if(day < daysOfMonths[month-1]){
        tomorrow.year = year;
        tomorrow.month = month;
        tomorrow.day = day +1;    
    }
    if(day == daysOfMonths[month-1]){
        if (month < 12){
            tomorrow.year = year;
            tomorrow.month = month + 1;
            tomorrow.day = 1;    
        } else{
            tomorrow.year = year + 1;
            tomorrow.month = 1;
            tomorrow.day = 1;
        }
    }
    
    return tomorrow;
}
