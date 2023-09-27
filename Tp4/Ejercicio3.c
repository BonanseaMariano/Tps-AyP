#include <stdio.h>
#include <time.h>

struct Fecha {
    int dia;
    int mes;
    int ano;
};

struct Persona {
    char nombre[50];
    char apellido[50];
    struct Fecha fechaNacimiento;
    int edad;
};

void carga(struct Fecha *f,struct Persona *p);
void calcEd();
void imprimir();

int main(){
    struct Fecha f;
    struct Persona per;


    return 0;
}

void carga(struct Fecha *f,struct Persona *p){
    char feNac[10];
    printf("Ingrese su nombre\n");
    scanf("%s",p->nombre);
    printf("Ingrese su apellido\n");
    scanf("%s",p->apellido);
    printf("Ingrese su fecha de nacimiento\n");
    scanf("%s",feNac);
    

}

void calcEd(){

}

void imprimir(){

}