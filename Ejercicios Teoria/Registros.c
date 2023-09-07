#include <stdio.h>
#include <stdbool.h>

union Nota
{
    int i;
    char c;
};

struct alu{
    char nombre[50];
    union Nota nota;
    bool tipo;
};

void carga(struct alu *a);

void imprimir(struct alu *a);

int main(){
    struct alu primero;
    carga(&primero);
    imprimir(&primero);
    return 0;
}

void carga(struct alu *a){
    int t;
    printf("Ingrese el nombre del alumno:\n");
    scanf("%[^\n]s",&a->nombre);
    printf("Que nota numerica (0) o alfabetica(1)\n");
    scanf("%d",&t);
    if (t==0)
    {
        a->tipo=false;
    }else{
        a->tipo=true;
    }

    if (!a->tipo)
    {
        printf("Ingrese la nota numerica (0 a 100) del alumno %s:\n",a->nombre);
        scanf("%i",&a->nota.i);
    }else{
        printf("Ingrese la nota alfabetica (A a F) del alumno %s:\n",a->nombre);
        scanf(" %c",&a->nota.c);
    }
}

void imprimir(struct alu *a){
    printf("Nombre del alumno: %s\n",a->nombre);
    if (!a->tipo)
    {
        printf("Tipo de nota del alumno: Numerica\n");
        printf("La nota del alumno es: %i",a->nota.i);
    }else{
        printf("Tipo de nota del alumno: Alfabetica\n");
        printf("La nota del alumno es: %c",a->nota.c);
    }   
}