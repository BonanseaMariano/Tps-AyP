#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//Variables globales
int a[50];

//Funciones
void carga();
void moda(int mod[]);
float media(int acu);
void derest(float med);

int main(){
    srand(getpid());
    carga();
    return 0;
}

void carga(){
    int aux,
    mod[]={0,0,0,0,0,0,0,0,0,0},
    acu=0;
    //Carga
    for (int i = 0; i < 50; i++)
    {
        a[i] = rand() % 11;
        //Para la moda
        mod[a[i]]++;
        //Para la media
        acu+=a[i];
        printf("%d ",a[i]);
    }
    printf("\n");
    moda(mod);
    derest(media(acu));
}

void moda(int mod[]){
    int aux, max=1;
    //Calculo de la moda
    aux=mod[0];
    for (int i = 1; i < 10; i++)
    {
        if (mod[i]>aux)
        {
            aux=mod[i];
            max=i+1;
        }
    }
    //Impresion de la moda
    printf("La moda es: %i\n",max);
}

float media(int acu){
    //Calculo de la media
    float res=(float)acu/50;
    //Impresion de la media
    printf("La media es: %.2f\n",res);
    //Devuelvo la media para la derivacion estandar
    return res;
}

void derest(float med){
    float acu=0,aux;
    //Calculo de la derivacion estandar
    for (int i = 0; i < 50; i++)
    {
        acu += pow(a[i]-med,2);
    }
    aux=acu/50;
    //Impresion de la derivacion estandar
    printf("La derivacion estandar es: %.2f\n",sqrt(aux));
}