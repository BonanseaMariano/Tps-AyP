#include <stdio.h>

int main()
{
    char nombre[100];
    printf("Cual es tu nombre?\n");
    scanf("%[^\n]s",&nombre);
    printf("Hola %s",&nombre);
    return 0;
}