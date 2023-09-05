#include <stdio.h>

void saludo(char *nombre);
char *carga(char *nombre);

int main()
{
    char nombre[100];
    saludo(carga(nombre));
    return 0;
}

char *carga(char *nombre){
    printf("Cual es tu nombre?\n");
    scanf("%[^\n]s",nombre);
    return nombre;
}

void saludo(char *nombre){
    printf("Hola %s",nombre);
}