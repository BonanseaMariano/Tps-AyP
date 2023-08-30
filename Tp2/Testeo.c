#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//strcat / strcpy
// "\0 para poner fin de string"

int main(){
    char f1[]="06/02/1999";
    char delimitador[] = "/";
    char *token= strtok(f1,delimitador);
    char fechasinb[20];

    while (token!=NULL)
    {
        printf("Resultado: %s\t",token);
        token = strtok(NULL,delimitador);
    }

        strncpy(fechasinb, &f1[6],4);
        strncat(fechasinb, &f1[3],2);
        strncat(fechasinb, f1,2);

        printf("\n%s",fechasinb);

    
    return 0;
}

