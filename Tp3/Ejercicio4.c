#include <stdio.h>

int esPrimo(int numero);

int main() {
    int n;
    printf("Ingrese un numero: \n");
    scanf("%i", &n);
    printf("Los numeros primos menores o iguales a %d son:\n", n);
    for (int i = 0; i <= n; i++) {
        if (esPrimo(i)==1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int esPrimo(int numero) {
    if (numero <= 1) {
        return 0;
    }
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}