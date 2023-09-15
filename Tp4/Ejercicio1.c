#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_STR 10

struct Fecha {
    int dia;
    int mes;
    int ano;
};

void sYa(char *fechaS, struct Fecha *f);

int main(){
    struct Fecha f;
    char fecha[LEN_STR];
    printf("Ingrese la fecha (formato dd/mm/aaaa):\n");
    scanf("%s",fecha);
    sYa(fecha,&f);
    printf("%i-%i-%i",f.dia,f.mes,f.ano);
    return 0;
}

void sYa(char *fechaS, struct Fecha *f){
    char aux[4];
    strncpy(aux, &fechaS[0],2);
    f->dia = atoi(aux);
    strncpy(aux, &fechaS[3],2);
    f->mes = atoi(aux);
    strncpy(aux, &fechaS[6],4);
    f->ano = atoi(aux);
}