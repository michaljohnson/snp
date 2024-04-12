#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a = 3;
    int b = 4;
    printf("Before swap:\na: %d; b: %d\n", a, b);

    // Swap a and b using XOR operation
    a = a ^ b; //results in the binary bitwise a XOR b
    b = a ^ b; // a^b^b = original a
    a = a ^ b; // a^b^a = original b

    printf("\nAfter swap:\na: %d; b: %d\n", a, b);
    return EXIT_SUCCESS;
}