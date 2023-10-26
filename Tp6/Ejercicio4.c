#include <stdio.h>

void imprimir_piramide(int n,int i);

int main() {
    int n;
    printf("Ingrese un numero natural positivo: ");
    scanf("%d", &n);
    imprimir_piramide(n,1);
    return 0;
}

void imprimir_piramide(int n,int i) {
    if (n == 0) {
        return;
    }
    for (int j = 0; j < n; j++) {
        printf(" ");
    }
    for (int k = i; k > 0 ; k--)
    {
        printf("%d ",i);
    }
    printf("\n");
    imprimir_piramide(n-1,++i);
}