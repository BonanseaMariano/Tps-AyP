#include <stdio.h>

void saludo(char *nombre);

int main()
{
    char nombre[100];
    printf("Cual es tu nombre?\n");
    scanf("%[^\n]s",nombre);
    saludo(nombre);

    return 0;
}

void saludo(char *nombre){
    printf("Hola %s",nombre);
}