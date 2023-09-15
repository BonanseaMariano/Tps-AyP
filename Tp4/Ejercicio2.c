#include <stdio.h>
#include <time.h>

int main(void) {
    // Tiempo actual
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);

    // El lugar donde se pondrá la fecha y hora formateadas
    char fechaHora[70];

    // El formato. Mira más en https://en.cppreference.com/w/c/chrono/strftime
    char *formato = "%d-%m-%Y";

    // Intentar formatear es para chequear que efectivamente 
    int bytesEscritos = strftime(fechaHora, sizeof(fechaHora), formato, &tiempoLocal);

    if (bytesEscritos != 0) {
        // Si no hay error, los bytesEscritos no son 0
        printf("Hoy es: %s", fechaHora);
    } else {
        printf("Error formateando fecha");
    }
}
