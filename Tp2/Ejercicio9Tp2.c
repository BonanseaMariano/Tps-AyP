#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ingreso(char *inp,char a[20][30]);
void imprimir(int cont,char a[20][30]);

int main(){
    char arreglo[20][30];    
    int cont=0;

    do
    {
        //Long max 30
        char inp[50]="";
        do
        {
            printf("Ingresa la cadena de max 30 caracteres\n");
            scanf(" %[^\n]s",inp);
        } while (strlen(inp)>30);
        if (ingreso(&inp,&arreglo[20][30]))
        {
            strcpy(arreglo[0],inp);
            cont++;
            imprimir(cont,arreglo[20][30]);
        }
    } while (cont<20);
    

    return 0;
}

bool ingreso(char *inp,char a[20][30]){
    int maylen=-1;
    
    //For de recorrer arreglo (filas)
    for (int i = 0; i < 20; i++)
    {
        //Evaluo la cadena mas larga para poder usar eso en el for
        if (strlen(inp)>strlen(a[i][0]))
        {
            maylen=strlen(inp);
        }else{
            maylen=strlen(a[i][0]);
        }
        //Contador de letras iguales
        int letig=0;
        //For de recorrer letra por letra
        for (int j = 0; j <= maylen; j++)
        {
            if
        }
        
    }
    
}

void imprimir(int cont,char a[20][30]){
    for (int i = 0; i <= cont; i++)
    {
        printf("%s\n",a[i][0]);
    }
}