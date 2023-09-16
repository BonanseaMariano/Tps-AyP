#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*. Escriba un programa que llene un arreglo con 10 
números enteros aleatorios no repetidos entre 0 y 10 y lo imprima por pantalla.*/

int main(){
    int arreglo[10],i=0;
    int frecuencia[10]={0,0,0,0,0,0,0,0,0,0};
    srand(getpid()); 
    //Carga de numeros random sin repetir
    //Iterador de recorrida del arreglo
    while (i < 10) {
        int numero = rand() % 11;
        frecuencia[numero]++;
        int j = 0;
        //Iterador de control
        while (j < i && arreglo[j] != numero) {
            j++;
        }
        if (j == i) {
            arreglo[i] = numero;
            i++;
        }
    }
    //Impresion
    for (i = 0; i < 10; i++)
    {
        printf("%i\t",arreglo[i]);
    }
    printf("\n\t---- FRECUENCIAS ----\n");
    //Impresion frecuencia
    for (i = 0; i < 10; i++)
    {
        printf("Numero %i = %i veces\n",i,frecuencia[i]);
    }
    return 0;
}