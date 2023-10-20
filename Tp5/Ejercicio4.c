#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE *archivo;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char dateS[27];

    archivo = fopen("registro.dat","r+");
    if (archivo == NULL)
    {
        printf("Es la primera vez que se ejecuta el programa");
        archivo = fopen("registro.dat","w");
        strftime(dateS, sizeof(dateS), "%d/%m/%Y, a las %H:%M:%S", tm);

        fwrite(&dateS,sizeof(dateS),1,archivo);
        fclose(archivo);
    }else{
        while (fread(&dateS, sizeof(dateS), 1, archivo)){
            printf("El programa se ejecuto por ultima vez el %s\n",dateS); 
        }
        strftime(dateS, sizeof(dateS), "%d/%m/%Y, a las %H:%M:%S", tm);
        fwrite(&dateS,sizeof(dateS),1,archivo);
    }
    fclose(archivo);
    return 0;
}