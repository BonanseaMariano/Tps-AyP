#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *archivo;
    char c;
    if (argc!=2)
    {
        printf("Uso: \"./Ejercicio2.exe nombre_archivo\"");
        return 0;
    }
    
    archivo = fopen(argv[1],"r");

    if (archivo==NULL)
    {
        printf("Error al abir el archivo");
        return 1;
    }
    
    while ((c=fgetc(archivo)) != EOF)
    {
        printf("%c",c);
    }
    fclose(archivo);
    return 0;
}