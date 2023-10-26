#include <stdio.h>

int piramide(int numero);

int main(){
    int numero;
    printf("Ingrese un numero:");
    scanf("%d",&numero);
    piramide(numero);
    return 0;
}

int piramide(int numero){
    if (numero==1) 
    {
        printf("\n\t1");
    }else{
        int temp = piramide(numero-1);
        for (int i = 0; i < temp; i++)
        {
            printf("\n\t%d", temp);
        }
    }
}