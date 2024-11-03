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
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            continue; // Continue em caso de falha na leitura
        }
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
    int coins[] = {25, 10, 5, 1}; // Valores das moedas
    int sizeCoins = sizeof(coins) / sizeof(coins[0]);
    int pennyValue = 0;
    int transactions = 0;
    float userNum = get_float("Digite um numero: ");
    int cents = (int)roundf(fmodf(userNum * 100, 100));

    for (int i = 0; i < sizeCoins; i++) {
        while (cents >= coins[i]) {
            cents -= coins[i];
            pennyValue += coins[i];
            transactions++;
        }
    }
    
    printf("\nO valor do troco em moedas foi: %d centavos\n", pennyValue);
    printf("E foram usadas %d moedas.\n", transactions);
    
    return pennyValue;
}
