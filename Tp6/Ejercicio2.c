#include <stdio.h>

int potencia(int base, int exponente);

int main() {
    int base, exponente;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);
    printf("%d elevado a la %d es igual a %d.\n", base, exponente, potencia(base, exponente));
    return 0;
}

int potencia(int base, int exponente) {
    if (exponente == 0) { //Caso base
        return 1;
    } else if (exponente % 2 == 0) {//Caso base 2
        int temp = potencia(base, exponente / 2);
        return temp * temp;
    } else {
        return base * potencia(base, exponente - 1);//Caso recursiovo
    }
}