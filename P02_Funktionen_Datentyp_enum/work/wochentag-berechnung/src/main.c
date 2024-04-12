#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum {JAN=1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC } month_t;

typedef enum {Sun=0,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat} weekday_t;
typedef struct{
    int year;
    month_t month;
    int day;
}date_t;

int is_leap_year(date_t date);
int get_month_length(date_t date);
int is_gregorian_date(date_t date);
int is_valid_date(date_t date);
int is_century(date_t date);
weekday_t calculate_weekday(date_t date);
void print_weekday(weekday_t day);



int main(int argc, char *argv[]){
    date_t date;

    if (argc < 2){
        printf("Error: invalid number of arguments\n");
        return EXIT_FAILURE;
    }
    if(sscanf(argv[1], "%d-%d-%d", &date.year, (int *)&date.month, &date.day) != 3){
        printf("Error: invalid number of arguments\n");
        return EXIT_FAILURE;
    }


    if (!is_valid_date(date))
    {
        printf("Error: invalid date\n");
        return EXIT_FAILURE;
    }
    printf("%04d-%02d-%02d is a ", date.year, date.month, date.day);
    print_weekday(calculate_weekday(date));

    return EXIT_SUCCESS;
}


int is_leap_year(date_t date){
    if ((!is_century(date) && date.year % 4 == 0) ||date.year % 400 == 0) {
        return 1;
    }return 0;
}

int is_century(date_t date){
    if(date.year % 100 == 0){
        return 1;
    } return 0;
}

int get_month_length(date_t date){
    switch(date.month){
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            return 31;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30;
        case FEB:
            if (is_leap_year(date)) {
                return 29;
            }else{
                return 28;
            }
        default:
            //if no valid month is given
            return 0;
    }
}

weekday_t calculate_weekday(date_t date){
    assert(is_valid_date(date));
    int m = 1 + (date.month + 9) % 12;
    int a = date.year < MAR ? date.year - 1:date.year;
    int y = a % 100;
    int c = a / 100;
    weekday_t weekday = ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
    return  weekday;
}

void print_weekday(weekday_t day){
    assert(day >= Sun && day <= Sat && "day is out-of-range");
    switch(day)
    {
        case Sun: fprintf( stdout,"Sun\n"); break;
        case Mon: fprintf( stdout,"Mon\n"); break;
        case Tue: fprintf( stdout,"Tue\n"); break;
        case Wed: fprintf( stdout,"Wed\n"); break;
        case Thu: fprintf( stdout,"Thu\n"); break;
        case Fri: fprintf( stdout,"Fri\n"); break;
        case Sat: fprintf( stdout,"Sat\n"); break;
        default: break;
    }
}

int is_gregorian_date(date_t date){
    if (date.year < 1582 || date.year > 9999)
        return 0;
    if(date.year == 1582){
        if(date.month < OCT){
            return 0;
        }if(date.month == OCT){
            if(date.day < 15){
                return 0;
            }
        }
    }
    return 1;
}

int is_valid_date(date_t date){
    if (!is_gregorian_date(date)) { return 0; }
    if (date.month < JAN || date.month > DEC) { return 0; }
    if (date.day < 1 || date.day > get_month_length(date)) { return 0; }
    return 1;
}


