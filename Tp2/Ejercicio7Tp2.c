#include <stdio.h>
#include <string.h>

int main(){
    char texto[10][20];
    char inp[20];

    //Limpieza del arreglo
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; i < j; j++)
        {
            texto[i][j]=NULL;
        }
    }
    

    do
    {
        scanf("%[^\n]s",inp);

        
    } while (strcmp(texto,"fin")!=0);
    
    


    return 0;
}