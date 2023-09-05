#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fibo(int *acu,int n);
void impresion(int *acu,int n);

int main(){
    srand(getpid());

    int n = ((rand() % 25)+1);
    int acu[n];

    printf("El %dª elemento de la serie de Fibonacci es: %d\n",n,fibo(acu,n));
    printf("\t----------\n");
    printf("Elementos de la serie de Fibonacci hasta la %dª posicion:\n",n);
    impresion(acu,n);
    return 0;
}

int fibo(int *acu,int n){
    for (int i = 0; i < n; i++)
    {
        if (i<2)
        {
            acu[i]=1;
        }else{
            acu[i]=acu[i-1]+acu[i-2];
        }
    }
    return acu[n-1];
}

void impresion(int *acu,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",acu[i]);
    }
}