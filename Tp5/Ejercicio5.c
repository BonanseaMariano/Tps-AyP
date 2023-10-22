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
void carga(Persona *p);
void calcEd(Persona *p);
void imprimir(Persona *p);

int main(){
    Fecha f;
    Persona per;
    FILE *archivo;
    FILE *archivoDestino;

    lecturaArchivo(archivo,&per,archivoDestino);
    
    return 0;
}

void carga(Persona *p){
    char feNac[10];
    printf("Ingrese su nombre\n");
    scanf("%s",p->nombre);
    printf("Ingrese su apellido\n");
    scanf("%s",p->apellido);
    printf("Ingrese su fecha de nacimiento en formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", p->fechaNacimiento.dia, p->fechaNacimiento.mes, p->fechaNacimiento.ano);
}

void calcEd(Persona *p){
    time_t now;
    time(&now);
    double seconds;
    struct tm birthdate = {0};

    // Ajusta los valores ingresados por el usuario para que coincidan con los requeridos por la estructura tm
    birthdate.tm_mday = p->fechaNacimiento.dia;
    birthdate.tm_mon = p->fechaNacimiento.mes - 1;      // Mes de nacimiento (enero es 0)
    birthdate.tm_year = p->fechaNacimiento.ano -= 1900;  // Año de nacimiento - 1900
    

    // Calcula la diferencia en segundos entre la fecha actual y la fecha de nacimiento
    seconds = difftime(now, mktime(&birthdate));

    // Calcula la edad en años redondeando hacia abajo
    p->edad = (int)(seconds / (60 * 60 * 24 * 365.25));
}

void imprimir(Persona *p){
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("Fecha de Nacimiento: %d/%d/%d\n",p->fechaNacimiento.dia,p->fechaNacimiento.mes,p->fechaNacimiento.ano);
    printf("Edad: %s\n",p->edad);
}

void lecturaArchivo(FILE *archivo,Persona *p,FILE *archivoDestino){
    char *simpleFormat;
    char delimitador[] = ";";
    char delimitador2[] = "/";
    
    archivo = fopen("datosAImportar.dat", "r+");
    
    //Errores al abrir el archivo
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        fclose(archivo);
    }else{

        rewind(archivo);//Reinicio el cursor del archivo

        //Cuando el archivo se encuentra vacio
        if (!fread(simpleFormat, sizeof(simpleFormat), 1, archivo))
        {
            printf("\n\tEl archivo se encuentra vacio!\n");
            fclose(archivo);
        }else{
            //Cuando el archivo tiene contenido
            rewind(archivo);//Reinicio el cursor del archivo (esto es por el condicional de arriba que deja el cursor en cualquier lado)
            while (fread(simpleFormat, sizeof(simpleFormat), 1, archivo)) {
                //Nombre
                char *token = strtok(simpleFormat, delimitador);
                strcpy(p->nombre, token);
                //Apellido  
                token = strtok(simpleFormat, delimitador);
                strcpy(p->apellido, token);
                //Fecha de nacimiento
                token = strtok(simpleFormat, delimitador);
                //Aca hay que hacer un segundo strok con otro token para que sea dia, mes, año
                char *token2 = strtok(token2, delimitador2);
                p->fechaNacimiento.dia = strtol(token2, NULL, 10);
                token2 = strtok(token2, delimitador2);
                p->fechaNacimiento.mes = strtol(token2, NULL, 10);
                token2 = strtok(token2, delimitador2);
                p->fechaNacimiento.ano = strtol(token2, NULL, 10);
                //Edad
                token = strtok(simpleFormat, delimitador);
                p->edad = strtol(token, NULL, 10);
                //Cierro el archivo de inico
                fclose(archivo);
                //Parte de escritura
                //Abro el archivco de destino y escribo
                archivo = fopen("datosImportados.dat", "wb");
                fwrite(&p, sizeof(Persona), 1, archivoDestino);
                printf("\n\t---- datosImportados.dat ----\n");
                while (fread(&p, sizeof(Persona), 1, archivoDestino)) {
                    imprimir(p);
                }
                fclose(archivoDestino);
            }
        }
    }
}
