#include <stdio.h>


void descomponer(int n);

int main() {
    int numero;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &numero);
    if (numero <= 1) {
        printf("El numero debe ser mayor que 1.\n");
        return 1;
    }
    descomponer(numero);

    printf("\n");
    return 0;
}

void descomponer(int n){
    printf("Los factores primos de %d son: ", n);
    // Iteramos desde 2 (el primer número primo) hasta numero
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            // Si numero es divisible por i, i es un factor primo
            printf("%d", i);
            n = n / i;
            // Si todavía quedan más factores primos, imprimimos un asterisco
            if (n > 1) {
                printf(" * ");
            }
        }
    }
}