#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm birthdate;
    double seconds;

    // Obtén la fecha actual
    time(&now);

    // Pide al usuario que ingrese su fecha de nacimiento
    printf("Por favor, ingresa tu fecha de nacimiento en formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &birthdate.tm_mday, &birthdate.tm_mon, &birthdate.tm_year);

    // Ajusta los valores ingresados por el usuario para que coincidan con los requeridos por la estructura tm
    birthdate.tm_year -= 1900;  // Año de nacimiento - 1900
    birthdate.tm_mon -= 1;      // Mes de nacimiento (enero es 0)

    // Calcula la diferencia en segundos entre la fecha actual y la fecha de nacimiento
    seconds = difftime(now, mktime(&birthdate));

    // Calcula la edad en años redondeando hacia abajo
    int age = (int)(seconds / (60 * 60 * 24 * 365.25));

    printf("La edad es: %d\n", age);

    return 0;
}
