#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Fecha;

typedef struct{
    char nombre[50];
    char apellido[50];
    Fecha fechaNacimiento;
    int edad;
}Persona;

void lecturaArchivo(FILE *archivo,Persona *p,FILE *archivoDestino);
void imprimir(Persona *p);
void primerSplit(Persona *p,char *cadena);
void segundoSplit(Persona *p,char *cadena);

int main(){
    Fecha f;
    Persona per;
    FILE *archivo;
    FILE *archivoDestino;
    
    //Para que se cargue algo
    char test[]="Mariano;Bonansea;06/02/1999;24";
    archivo = fopen("datosAImportar.dat", "w+");
    fwrite(&test, sizeof(test), 1, archivo);
    fclose(archivo);

    printf("\tCarga Automatica (Hardcoded)\n");
    lecturaArchivo(archivo,&per,archivoDestino);
    return 0;
}

void imprimir(Persona *p){
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("Fecha de Nacimiento: %d/%d/%d\n",p->fechaNacimiento.dia,p->fechaNacimiento.mes,p->fechaNacimiento.ano);
    printf("Edad: %s\n",p->edad);
}

void lecturaArchivo(FILE *archivo,Persona *p,FILE *archivoDestino){
    char simpleFormat[100];
    
    archivo = fopen("datosAImportar.dat", "r+");
    
    //Errores al abrir el archivo
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        fclose(archivo);
    }else{

        //Cuando el archivo se encuentra vacio
        if (!fread(simpleFormat, sizeof(char), 100, archivo))
        {
            printf("\n\tEl archivo se encuentra vacio!\n");
            fclose(archivo);
        }else{
            //Cuando el archivo tiene contenido
            rewind(archivo);//Reinicio el cursor del archivo (esto es por el condicional de arriba que deja el cursor en cualquier lado)
            while (fread(simpleFormat, sizeof(char), 100, archivo)) {
                printf("\n\t---- datosAImportar.dat ----\n");
                printf("%s\n", simpleFormat); //Para testeo
                primerSplit(p,simpleFormat);
                //Cierro el archivo de inico
                fclose(archivo);
                //Parte de escritura
                //Abro el archivco de destino y escribo
                archivoDestino = fopen("datosImportados.dat", "wb+");
                fwrite(p, sizeof(Persona), 1, archivoDestino);
                printf("\n\t---- datosImportados.dat ----\n");
                rewind(archivoDestino);
                while (fread(p, sizeof(Persona), 1, archivoDestino)) {
                    imprimir(p);
                }
                fclose(archivoDestino);
            }
        }
    }
}

void primerSplit(Persona *p,char *cadena){
    char **tokens = (char **)malloc(4 * sizeof(char *));
    char *token; 
    int i=0;
    //Para guardar lo separado en un arreglo de strings
    token = strtok(cadena, ";");
    while (token != NULL)
    {
        tokens[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        strcpy(tokens[i], token);
        token = strtok(NULL, ";");
        i++;
    }
    
    //Nombre
    strcpy(p->nombre, tokens[0]);
    //Apellido  
    strcpy(p->apellido, tokens[1]);
    //Fecha de nacimiento
    segundoSplit(p,tokens[2]);
    //Edad (PREGUNTAR PQ ACA LA ASIGNACION DE EDAD NO HAY QUE CONVERTIRLA COMO LA DE LA FECHA DE NACIMIENTO, solo con un casting basta)
    p->edad = (int)tokens[3];
    //Para liberar la memoria del arreglo de strings dinamico
    free(tokens);
}

void segundoSplit(Persona *p,char *cadena){
    char *token;
    int fecha[3],i=0;

    token = strtok(cadena, "/");
    while (token != NULL)
    {
        fecha[i] = strtol(token, NULL, 10);
        token = strtok(NULL, "/");
        i++;
    }

    p->fechaNacimiento.dia = fecha[0];
    p->fechaNacimiento.mes = fecha[1];
    p->fechaNacimiento.ano = fecha[2];
}
