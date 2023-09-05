#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void carga(int *a);
void busq(int *arr,int n);

int main(){
    int arreglo[10],n;
    srand(getpid()); 
    carga(arreglo);
    //Impresion
    for (int i = 0; i < 10; i++)
    {
        printf("%i\t",arreglo[i]);
    }
    printf("\nIngrese un numero para buscar:\n");
    scanf("%d",&n);
    busq(arreglo,n);
    return 0;
}

void carga(int *a){
    int i=0;
    //Carga de numeros random sin repetir
    //Iterador de recorrida del arreglo
    while (i < 10) {
        int numero = rand() % 11;
        int j = 0;
        //Iterador de control
        while (j < i && a[j] != numero) {
            j++;
        }
        if (j == i) {
            a[i] = numero;
            i++;
        }
    }
}

void busq(int *arr,int n){
    int i=0;
    for (i = 0; i < 10 && n!=arr[i]; i++);
    if (i<10)
    {
        printf("El elemento %d se encontro en el arreglo, en la %d* posicion",n,i + 1);
    }else{
        printf("El elemento %d NO se encontro en el arreglo",n);
    }
}