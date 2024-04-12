#include <stdlib.h>
#include <stdio.h>
/*
 * bit operations:
 * ~ NOT
 * & AND
 * | OR
 * ^ XOR
 * << LEFT SHIFT
 * >> RIGHT SHIFT
 */
int main()
{
    unsigned int number = 0x75; //hexa number
    unsigned int bit = 3; // bit position to be manipulate

    // Setting a bit
    number = number | (1 << bit); //moves 1 bit to the left and OR operation

    // Clearing a bit
    bit = 1; // reassining the bit to 1
    number = number & ~(1 << bit); //moves 1 to the left and ~ negation operator

    // Toggling a bit
    bit = 0; // reassining the bit to 0
    number = number ^ (1 << bit); //moves 1 to the left and XOR operation
    // if it was 1 <-> 0 and visa versa

    printf("number = 0x%02X\n", number);

    return EXIT_SUCCESS;
}
