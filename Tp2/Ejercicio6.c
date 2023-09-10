#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char cadenas[10][10]={"06/02/1999","07/02/1999","08/02/1999","09/02/1999","10/02/1999","11/02/1999","06/02/1999","06/02/2000","06/02/1999","06/02/1999"};
    
    
    //Arreglos para comparar
    char min[10]="";
    char max[10]="";
    //Modificacion de formato de la fecha para min
    strncpy(min, &cadenas[0][6],4);
    strncat(min, &cadenas[0][3],2);
    strncat(min, &cadenas[0][0],2);

    //Modificacion de formato de la fecha para max
    strncpy(max, &cadenas[0][6],4);
    strncat(max, &cadenas[0][3],2);
    strncat(max, &cadenas[0][0],2);
    

    //Recorro filas
    for (int i = 1; i < 10; i++)
    {
        char aux[10]="";
        //Modificacion de formato de la fecha
        strncpy(aux, &cadenas[i][6],4);
        strncat(aux, &cadenas[i][3],2);
        strncat(aux, &cadenas[i][0],2);

        if (strcmp(aux,min)<0)
        {
            strcpy(min, aux);
        }
        if (strcmp(aux,max)>0)
        {
            strcpy(max, aux);
        }
    }

    printf("La fecha minima es: %s\n",min);
    printf("La fecha maxima es: %s\n",max);

    return 0;
}