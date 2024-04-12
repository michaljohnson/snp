#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{JAN=1,FEB,MAR,APR,MAI,JUN,JUL,AUG,SEP,OKT,NOV,DEZ};

int istSchaltjahr(int jahr);
int tageProMonat(int monat, int jahr);
int gibIntWert(char *prompt, int min, int max);


int main(int argc, char *argv[]){

    int monat, jahr;

    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr  = gibIntWert("Jahr", 1600, 9999);

    //  Ausgabe zum Test
    (void) printf("Monat: %d, Jahr: %d \n", monat, jahr);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    (void) printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    (void) printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(monat, jahr));

    return 0;
}

int istSchaltjahr(int jahr){
    if((jahr % 4 == 0 && jahr % 100!= 0) || (jahr % 400 == 0)){
        return 1;
    } else{
        return 0;
    }
}

int tageProMonat(int monat, int jahr) {
    switch (monat) {
        case JAN:
        case MAR:
        case MAI:
        case JUL:
        case AUG:
        case OKT:
        case DEZ:
            return 31;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30;
        case FEB:
            if (istSchaltjahr(jahr)) {
                return 29;
            }else{
                return 28;
            }
        default:
            //if no valid month is given
            return 0;
    }
}

int gibIntWert(char* prompt, int min, int max) {
    char input[100]; // Buffer for the input
    int value;
    do {
        printf("%s (%d-%d): ", prompt, min, max);
        fgets(input, sizeof(input), stdin); // Read the input from user
        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;
        value = atoi(input); // Convert input to integer
        // Check if the value is outside the allowed range
        if(value < min || value > max){
            printf("Invalid input. Please try again.\n");
        }

    } while (value < min || value > max);
    return value;
}


