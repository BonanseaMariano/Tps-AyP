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

void carga(struct Persona *p);
void calcEd(struct Persona *p);
void imprimir(struct Persona *p);

int main(){
    struct Fecha f;
    struct Persona per;
    carga(&per);
    calcEd(&per);
    imprimir(&per);

    return 0;
}

void carga(struct Persona *p){
    char feNac[10];
    printf("Ingrese su nombre\n");
    scanf("%s",p->nombre);
    printf("Ingrese su apellido\n");
    scanf("%s",p->apellido);
    printf("Ingrese su fecha de nacimiento en formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", p->fechaNacimiento.dia, p->fechaNacimiento.mes, p->fechaNacimiento.ano);
}

void calcEd(struct Persona *p){
    time_t now;
    time(&now);
    double seconds;
    struct tm birthdate;

    // Ajusta los valores ingresados por el usuario para que coincidan con los requeridos por la estructura tm
    p->fechaNacimiento.ano -= 1900;  // Año de nacimiento - 1900
    p->fechaNacimiento.mes -= 1;      // Mes de nacimiento (enero es 0)

    // Calcula la diferencia en segundos entre la fecha actual y la fecha de nacimiento
    seconds = difftime(now, mktime(&p->fechaNacimiento));

    // Calcula la edad en años redondeando hacia abajo
    p->edad = (int)(seconds / (60 * 60 * 24 * 365.25));
}

void imprimir(struct Persona *p){
    printf("Nombre: %s\n", p->nombre);
    printf("Apellido: %s\n", p->apellido);
    printf("Fecha de Nacimiento: %d/%d/%d\n",p->fechaNacimiento.dia,p->fechaNacimiento.mes,p->fechaNacimiento.ano);
    printf("Edad: %s\n",p->edad);
}