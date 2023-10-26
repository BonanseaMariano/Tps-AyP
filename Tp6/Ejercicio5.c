#include <stdio.h>
#include <string.h>

int balanceo(char *cadena, int inicio, int fin);

int main() {
    char cadena[100];
    printf("Ingrese una palabra que contenga parentesis izquierdos y derechos: ");
    scanf("%s", cadena);

    if (balanceo(cadena, 0, strlen(cadena) - 1)) {
        printf("Los parentesis estan balanceados en: \"%s\".\n", cadena);
    } else {
        printf("Los parentesis NO estan balanceados en: \"%s\".\n", cadena);
    }
    return 0;
}

int balanceo(char *cadena, int inicio, int fin) {
    if (inicio >= fin) {//Caso base 
        return 1;
    }
    while (cadena[inicio]!="(")
    {
        inicio++;

        if (inicio > fin) {//Caso base 
            return 1;
        }
    }
    
    
    if () {
        return 0; //Caso de corte (los parentesis no estan balanceados)
    }
    return balanceo(cadena, inicio + 1, fin - 1);//Caso recursivo
}
