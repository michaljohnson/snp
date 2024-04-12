#include <stdlib.h>
#include <stdio.h>

int main()
{
    char word[8] = "sREedEv"; //creates a pointer to an array with the given characters
    char *wordptr = &word[0]; //a pointer shows to the first instance of the array

    while (wordptr < &word[7]) //loops through all the charcaters till it shows on the last character
    {
        printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing
        printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing
        wordptr++; //increments the pointer to show to the next character in the array
    }

    return EXIT_SUCCESS;
}

