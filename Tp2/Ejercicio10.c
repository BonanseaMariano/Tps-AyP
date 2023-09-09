#include <stdio.h>
#include <string.h>

int main(){
    char texto[1000][30];
    char inp[30]="";

    do
    {
        printf("Ingrese una oracion");
        scanf("%[^\n]s",inp);
    } while (strcmp(inp,"fin")!=0);
    

    return 0;
}