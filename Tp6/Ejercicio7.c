#include <stdio.h>

int descomponer(int n, int fp);

int main(){
    int n;
    printf("Ingrese un numero entero positivo:\n");
    scanf("%d",&n);
    printf("\nLa descomposicion en factores primos de %d es: ", n);
    descomponer(n, 2); //2 es el minimo factor distinto de 1 por el que se va a poder dividir el numero, por eso es que se pasa
    printf("\n");
    return 0;
}

int descomponer(int n,int fp){
    if (n==1)//Paso Base
    {
        return 1;
    }
    if (n % fp == 0) {//Mientras sea divisible por el mismo factor primo sigo utilizando e imprimiendo ese
        printf("%d*", fp);
        descomponer(n / fp, fp);
    } else {
        descomponer(n, fp + 1);//En caso de que no sea divisible por ese factor voy incrementando el factor en 1
    }
}