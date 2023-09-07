#include <stdio.h>
#include <string.h>

int main(){
    char cadenas[10][20];
    char inp[50];
    int i;    

    //Limpieza de array de strings
    for (int i = 0; i < 50; i++)
    {
        strcpy(cadenas[i],"");
    }
    

    //Validacion condicion de corte "fin"
    do
    {
        //Validacion tamaño max de la cadena
        do
        {
            printf("Ingrese la cadena:\n");
            scanf(" %[^\n]s",inp);
        } while (strlen(inp)>20);

        
        for (i = 0; strcmp(inp,cadenas[i])>0 && i<20; i++);
        //No llego al final del arreglo
        if (i<20)
        {
            //Corro las columnas
            for (int j = i; j < 19; j++)
            {
                strcpy(cadenas[i+1],cadenas[i]);
            }
            //Pego en la posicion acorde
            strcpy(cadenas[i], inp);
            //Impresion de todo el arreglo
            for (int i = 0; i < 20; i++)
            {
                if (strcmp(cadenas[i],"")!=0)
                {
                    printf("%s\n",cadenas[i]);
                }
            }
        }
    } while (strcmp("fin",inp)!=0);
    
    return 0;
}