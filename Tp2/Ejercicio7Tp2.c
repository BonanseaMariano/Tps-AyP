#include <stdio.h>
#include <string.h>

int posAlf(char input);

int main(){
    char texto[10][20]="";
    char inp[20];

    do
    {
        printf("Ingrese la cadena:\n");
        scanf("%[^\n]s",inp);
        posAlf(inp);
        
    } while (strcmp(texto,"fin")!=0);
    
    


    return 0;
}

int posAlf(char input){
    //Recorro el arreglo hasta encontrar la posicion en la que colocar la nueva cadena
    for (int i = 0; i < 10; i++)
    {
        /* code */
    }
    

}