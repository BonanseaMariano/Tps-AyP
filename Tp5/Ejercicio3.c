#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    FILE *archivo;
    pid_t pid = getpid();
    archivo = fopen("pidfile","r");
    if (archivo == NULL)
    {
        archivo = fopen("pidfile","w");
        fwrite(&pid,sizeof(pid_t),1,archivo);
        printf("%d\n",getpid());
        fclose(archivo);
        getchar();
        if(remove("pidfile")!=0) printf("Error al eliminar el archivo");
        return 0;
    }
    fclose(archivo);
    printf("El programa ya se encuentra en ejecución");
    return 0;
}