#include <stdio.h>
#include <string.h>

//#define es para definir constantes con un nombre y desp poder referirse a ellas por su nombre

#define CANT_STR 20 // Tamaño máximo del arreglo
#define LEN_STR 30 // Longitud máxima de las cadenas

// Función que imprime el arreglo de cadenas
void imprimir_arreglo(char arreglo[CANT_STR][LEN_STR]) {
    printf("Arreglo:\n");
    for (int i = 0; i < CANT_STR; i++) {
        //Solo imprime si el string no esta vacio
        if (arreglo[i][0] != '\0')
        {
            printf("%s\n", arreglo[i]);
        }
    }
}

// Función que calcula la similitud entre dos cadenas
double similitud(char cadena1[LEN_STR], char cadena2[LEN_STR]) {
  int len1 = strlen(cadena1); // Longitud de la primera cadena
  int len2 = strlen(cadena2); // Longitud de la segunda cadena
  int max_len = len1 > len2 ? len1 : len2; // Longitud máxima entre las dos cadenas
  int iguales = 0; // Contador de letras iguales
  // Recorrer las cadenas comparando letra a letra
    for (int i = 0; i < max_len; i++) {
        if (cadena1[i] == cadena2[i]) {
        iguales++; // Incrementar el contador si las letras son iguales
        }
    }
    // Retornar la similitud como la división entre el contador y la longitud máxima
    return (double)iguales / max_len;
}

// Función que verifica si una cadena es al menos un 20% diferente a cualquier cadena del arreglo
int es_diferente(char arreglo[CANT_STR][LEN_STR], char cadena[LEN_STR]) {
  // Recorrer el arreglo comparando la similitud con cada cadena
    for (int i = 0; i < CANT_STR; i++) {
        if (similitud(arreglo[i], cadena) >= 0.8) {
        return 0; // Retornar falso si la similitud es mayor o igual a 0.8
        }
    }
  return 1; // Retornar verdadero si ninguna cadena es muy similar
}

int main() {
  char arreglo[CANT_STR][LEN_STR]; // Arreglo de cadenas
  char cadena[LEN_STR]; // Cadena ingresada por el usuario

    // Inicializar el arreglo con cadenas vacías
    for (int i = 0; i < CANT_STR; i++) {
        strcpy(arreglo[i], "");
    }

  // Pedir al usuario que ingrese una cadena
    printf("Ingrese una cadena o fin para terminar:\n");
    scanf("%s", cadena);

  // Mientras la cadena no sea "fin" y el arreglo no esté lleno, intentar insertarla en el arreglo
  int pos = 0; // Posición donde insertar la cadena
    while (strcmp(cadena, "fin") != 0 && pos < CANT_STR) {
        // Verificar si la cadena es suficientemente diferente a las del arreglo
        if (es_diferente(arreglo, cadena)) {
        // Copiar la cadena en la posición actual del arreglo
        strcpy(arreglo[pos], cadena);
        pos++; // Incrementar la posición para la próxima inserción
        // Imprimir el arreglo actualizado
        imprimir_arreglo(arreglo);
        } else {
        printf("La cadena es muy similar a alguna del arreglo. No se puede insertar.\n");
        }
        // Pedir otra cadena al usuario
        printf("Ingrese otra cadena o fin para terminar:\n");
        scanf("%s", cadena);
    }

    return 0;
}
