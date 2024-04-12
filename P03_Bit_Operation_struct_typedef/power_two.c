#include <stdio.h>
#include <stdlib.h>



/*
 * A XOR B = B XOR A (commutativity)
 * A XOR 0 = A
 * A XOR A = 0
 * (A XOR B) XOR C = A XOR (B XOR C) (associativity)
 */
int main(){
    int a = 32;
    if (a > 0 && !(a & (a - 1))) { // checks if a > 0 because is not a power of 2
        // This works because in binary, numbers that are powers of 2 always have a single '1' bit
        // while (a-1) will have '1' in all the positions to the right of the '1' bit in 'a'
        // So, the binary bitwise AND operation (a & (a - 1)) for such numbers results in 0
    }
    printf("%d is a power of 2\n", a);
    return EXIT_SUCCESS;
}
