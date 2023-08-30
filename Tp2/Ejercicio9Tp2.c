#include <stdio.h>
#include <string.h>

int main(){
    char arreglo[20][30];
    char inp[50];
    
    do
    {
        printf("Ingresa la cadena de max 30 caracteres\n");
        scanf(" %[^\n]s",inp);
    } while (strlen(inp)>30);
    strcpy(arreglo[0],inp);

    for (int i = 1; i < 5; i++)
    {
        do
        {
            printf("Ingresa la cadena de max 30 caracteres\n");
            scanf(" %[^\n]s",inp);
            //Evaluar letras
        } while (strlen(inp)>30);
        
    }
    
    return 0;
}