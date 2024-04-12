#include <stdlib.h>
#include <stdio.h>

#define OPERAND_BUFFER_SIZE 10
/*
 * bit operations:
 * ~ NOT
 * & AND
 * | OR
 * ^ XOR
 * << LEFT SHIFT
 * >> RIGHT SHIFT
 */
typedef struct {
    /* 
    Students: The Expression struct should hold the two operands and
    the operation (use a char for the operation)
    */
    unsigned int operand1;
    unsigned int operand2;
    char operation;
} Expression;

int bits_per_int() {
    return sizeof(unsigned int) * 8;
}

unsigned int parse_operand(char operand_str[]) {
    unsigned int operand;
    if (operand_str[0] == '0' && operand_str[1] == 'x') {
        sscanf(&operand_str[2], "%x", &operand);
    } else if (operand_str[0] == '0') {
        sscanf(&operand_str[1], "%o", &operand);
    } else {
        sscanf(operand_str, "%u", &operand);
    }
    return operand;
}

void print_binary(unsigned int value) {
    int bitsTillNextApostrophe = 8;
    int amountOfApostrophes = (bits_per_int() / bitsTillNextApostrophe) - 1;

    int toPrintLength = bits_per_int() + 1 + amountOfApostrophes;

    char toPrint[toPrintLength];
    for (int i = 0; i < toPrintLength - 1; i++)
    {
        if ((i + 1) % (bitsTillNextApostrophe + 1) == 0)
        {
            toPrint[i] = '\'';
        }
        else
        {
            toPrint[i] = '0';
        }
    }

    toPrint[toPrintLength - 1] = '\0';

    int i = 0;
    while (value)
    {

        if (value & 1)
        {
            toPrint[toPrintLength - i - 2] = '1';
        }
        value >>= 1;
        i++;
        if (i + 1 % (bitsTillNextApostrophe + 1) == 0)
        {
            i++;
        }
    }

    printf("%s", toPrint);
}

void print_bit_operation_bin(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in bin including the result

    Bin:
    00000000'00000000'00000000'00001100
    00000000'00000000'00000000'00001111 ^
    -----------------------------------
    00000000'00000000'00000000'00000011
    */

    printf("Bin:\n");
    print_binary(expression.operand1);
    printf("\n");
    print_binary(expression.operand2);
    printf(" %c", expression.operation);
    printf("\n");
    for (int i = 0; i < bits_per_int() + 3; i++)
    {
        printf("-");
    }
    printf("\n");
    print_binary(result);
    printf("\n");
}

void print_bit_operation_hex(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in hex including the result

    Hex:
    0x0c ^ 0x0f = 0x03
    */
    printf("Hex:\n");
    printf("0x%02X %c 0x%02X = 0x%02X\n", expression.operand1, expression.operation, expression.operand2, result);
}

void print_bit_operation_dec(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in hex including the result

    Dec:
    12 ^ 15 = 3
    */
    printf("Dec:\n");
    printf("%u %c %u = %u\n", expression.operand1, expression.operation, expression.operand2, result);
}

unsigned int bit_operation(Expression expression) {
    // Students: Do the actual bit operation and return the result
    switch (expression.operation)
    {
        case '&':
            return expression.operand1 & expression.operand2;
        case '|':
            return expression.operand1 | expression.operand2;
        case '^':
            return expression.operand1 ^ expression.operand2;
        case '>':
            return expression.operand1 >> expression.operand2;
        case '<':
            return expression.operand1 << expression.operand2;
        default:
            printf("Invalid operation\n");
            return 0;
    }
}

int main(){
    char operand1_str[10];
    char operand2_str[10];
    char operation;

    unsigned int operand1, operand2;

    do
    {
        printf("Geben sie die Bit-Operation ein:\n");

        scanf("%s %c %s", operand1_str, &operation, operand2_str);

        operand1 = parse_operand(operand1_str);
        operand2 = parse_operand(operand2_str);

        Expression expression = {
                .operand1 = operand1,
                .operand2 = operand2,
                .operation = operation,
        }; // Students: Create an expression

        unsigned int result = bit_operation(expression);
        printf("\n");
        print_bit_operation_bin(expression, result);
        printf("\n");
        print_bit_operation_hex(expression, result);
        printf("\n");
        print_bit_operation_dec(expression, result);
        printf("\n");

        while (getchar() != '\n')
            ;
        printf("\nMöchten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");

    } while (getchar() == 'n');

    printf("\n");
    return EXIT_SUCCESS;
}
