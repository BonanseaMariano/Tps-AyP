#include <stdio.h>
#include <string.h>

int es_palindromo(char *cadena, int inicio, int fin);

int main() {
    char cadena[100];
    printf("Ingrese una palabra que contenga parentesis izquierdos y derechos: ");
    scanf("%s", cadena);

    if (es_palindromo(cadena, 0, strlen(cadena) - 1)) {
        printf("%s es un palindromo.\n", cadena);
    } else {
        printf("%s no es un palindromo.\n", cadena);
    }
    return 0;
}

int es_palindromo(char *cadena, int inicio, int fin) {
    if (inicio >= fin) {//Caso base (las palabras de una sola letra siempre son plaindromos)
        return 1;
    }
    if (cadena[inicio] != cadena[fin]) {
        return 0; //Caso de corte (no es un palindromo)
    }
    return es_palindromo(cadena, inicio + 1, fin - 1);//Caso recursivo
}
