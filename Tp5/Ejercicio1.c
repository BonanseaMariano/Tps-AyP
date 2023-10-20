#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *archivo;
    char c;
    archivo = fopen(__FILE__,"r");
    
    while ((c=fgetc(archivo)) != EOF)
    {
        printf("%c",c);
    }
    fclose(archivo);
    return 0;
}