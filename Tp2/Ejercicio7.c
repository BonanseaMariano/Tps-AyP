#include <stdio.h>
#include <string.h>
#define MAX 4 // Tamaño máximo del arreglo
#define LEN 20 // Longitud máxima de las cadenas

void imprimir_arreglo(char arreglo[MAX][LEN]);
void insertar_ordenado(char arreglo[MAX][LEN], char cadena[LEN]);


int main() {
  char arreglo[MAX][LEN]; // Arreglo de cadenas
  char cadena[LEN]; // Cadena ingresada por el usuario

  // Inicializar el arreglo con cadenas vacías
    for (int i = 0; i < MAX; i++) {
        strcpy(arreglo[i], "");
    }

    // Pedir al usuario que ingrese una cadena
    printf("Ingrese una cadena o fin para terminar:\n");
    scanf("%s", cadena);

    // Mientras la cadena no sea "fin", intentar insertarla en el arreglo
    while (strcmp(cadena, "fin") != 0) {
        insertar_ordenado(arreglo, cadena);
        // Pedir otra cadena al usuario
        printf("Ingrese otra cadena o fin para terminar:\n");
        scanf("%s", cadena);
    }

    return 0;
}

// Función que imprime el arreglo de cadenas
void imprimir_arreglo(char arreglo[MAX][LEN]) {
    printf("Arreglo:\n");
    for (int i = 0; i < MAX; i++) {
        if (arreglo[i][0] != '\0'){
            printf("%s\n", arreglo[i]);
        }
    }
}

// Función que inserta una cadena en el arreglo en orden alfabético
void insertar_ordenado(char arreglo[MAX][LEN], char cadena[LEN]) {
    int i = 0;
    // Buscar la posición donde insertar la cadena ACA HAY QUE FIJARSE PQ I SIEMPRE QUEDA EN LA POS MAX DEL ARREGLO
    while (i < MAX && strcmp(arreglo[i], cadena) < 0) {
        i++;
    }
    printf("%i\n",i);
    // Si la posición es menor que el tamaño máximo, se puede insertar
    if (i < MAX) {
        // Desplazar las cadenas posteriores una posición a la derecha
        for (int j = MAX - 1; j > i; j--) {
            strcpy(arreglo[j], arreglo[j - 1]);
        }
        // Copiar la cadena en la posición encontrada
        strcpy(arreglo[i], cadena);
        // Imprimir el arreglo actualizado
        imprimir_arreglo(arreglo);
    }
}