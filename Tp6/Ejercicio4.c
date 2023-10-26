#include <stdio.h>

void imprimir_piramide(int n);

int main() {
    int n;
    printf("Ingrese un numero natural positivo: ");
    scanf("%d", &n);
    imprimir_piramide(n);
    return 0;
}

void imprimir_piramide(int n) {
    if (n == 0) {
        return;
    }
    for (int j = 0; j < n; j++) {
        printf("%d ", n);
    }
    printf("\n");  
    imprimir_piramide(n-1);
}