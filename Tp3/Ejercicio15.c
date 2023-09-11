#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN_STR 100 // Longitud máxima de las cadenas

bool mod(char *frase);

int main(){
    char frase[LEN_STR]="";
    bool fin=false;
    printf("Ingrese una frase: \n");
    scanf("%[^\n]s",frase);
    do
    {
        fin = mod(frase);
    } while (fin!=true);
    
    return 0;
}

bool mod(char *frase){
    int posicion=0,contador=0;
    char *token,copia[LEN_STR]="", resultado[LEN_STR]="", palN[30]="";

    strcpy(copia,frase);
    //Este bucle se ejecuta mientras haya palabras que separar
    for (token = strtok(copia, " "); token != NULL; token = strtok(NULL, " ")){
        contador++;
    }

    printf("Ingrese la posicion a editar (1 a %d):\n",contador);
    scanf("%d",&posicion);
    
    //Corte del programa
    if (posicion==0)
    {
        return true;
    }
    
    printf("Ingrese la nueva palabra (no se admiten espacios):\n");
    scanf("%s",palN);

    contador=0;
    strcpy(copia,frase);
    
    for (token = strtok(copia, " "); token != NULL; token = strtok(NULL, " ")) {
        contador++; // aumentamos el contador en cada iteración
        if (contador == posicion) {
            printf("%s\t",token);
            strcpy(token, palN); // modificamos la palabra si coincide con la posición
        }
            strcat(resultado, token); //Concateno la siguiente palabra
            strcat(resultado, " "); //Concateno el espacio entre palabras
            
    }
    printf("\nFrase original:\n\t%s\n",frase);
    strcpy(frase,resultado);
    printf("Frase actualizada:\n\t%s\n",resultado);
    strcpy(resultado,"");
    return false; 
}