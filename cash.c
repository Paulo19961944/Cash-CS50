#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

float get_float(const char *message) {
    char buffer[20];
    float number;

    while (1) {
        printf("%s", message);
        fgets(buffer, sizeof(buffer), stdin);
        char *endptr;
        number = strtof(buffer, &endptr);

        if (endptr == buffer || *endptr != '\n') {
            printf("Tipo de variável incorreto. O valor deve ser do tipo flutuante!\n");
        } else if (number > FLT_MAX || number < -FLT_MAX) {
            printf("O número excedeu o limite de ponto flutuante.\n");
        } else {
            return number;
        }
    }
}

int ATM_System() {
    int pennies = 0;
    int pennyValue = 0;
    int transactions = 0;
    float userNum = get_float("Digite um numero: ");
    int cents = (int)roundf(fmodf(userNum * 100, 100));
    
    while (cents > 0) {
        if (cents >= 25) {
            cents -= 25;
            pennyValue += 25;
            transactions += 1;
        } else if (cents >= 10) {
            cents -= 10;
            pennyValue += 10;
            transactions += 1;
        } else if (cents >= 5) {
            cents -= 5;
            pennyValue += 5;
            transactions += 1;
        } else if (cents > 0) {
            cents -= 1;
            pennyValue += 1;
            transactions += 1;
        }
    }
    
    printf("\nO valor do troco em moedas foi: %d centavos\n", pennyValue);
    printf("E foram usadas %d moedas.", transactions);
    
    return pennyValue;
}
