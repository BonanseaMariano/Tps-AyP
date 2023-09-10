#include <stdio.h>
#include <string.h>

#define CANT_STR 20 // Tamaño máximo del arreglo
#define LEN_STR 30 // Longitud máxima de las cadenas

int main(){
    
    char diccionario[CANT_STR][LEN_STR];

    //Limpieza inicial
    for (int i = 0; i < CANT_STR; i++)
    {
        strcpy(diccionario[i],"");
    }
    
    char oracion[100]; // Cadena para guardar la oración ingresada por el usuario
    char palabra[LEN_STR]; // Cadena para guardar cada palabra de la oración
    int i, j, encontrada; // Variables auxiliares

    // Leer la oración del usuario
    printf("Ingrese una oracion: ");
    scanf("%[^\n]", oracion);

    // Recorrer la oración palabra por palabra
    i = 0; // Índice para recorrer la oración
    while (oracion[i] != '\0') { // Mientras no se llegue al final de la oración
        j = 0; // Índice para recorrer la palabra
        while (oracion[i] != ' ' && oracion[i] != '\0') { // Mientras no se encuentre un espacio o el final de la oración
            palabra[j] = oracion[i]; // Copiar el carácter de la oración a la palabra
            i++; // Avanzar al siguiente carácter de la oración
            j++; // Avanzar al siguiente carácter de la palabra
        }
        palabra[j] = '\0'; // Agregar el carácter nulo al final de la palabra

        // Verificar si la palabra está en el diccionario
        encontrada = 0; // Bandera para indicar si se encontró la palabra
        for (j = 0; j < CANT_STR; j++) { // Recorrer el diccionario
            if (strcmp(palabra, diccionario[j]) == 0) { // Si la palabra es igual a alguna cadena del diccionario
                encontrada = 1; // Cambiar el valor de la bandera
                break; // Salir del ciclo
            }
        }

        if (encontrada) { // Si se encontró la palabra
            printf("La palabra %s esta en el diccionario.\n", palabra); // Imprimir un mensaje
        } else { // Si no se encontró la palabra
            printf("La palabra %s no esta en el diccionario.\n", palabra); // Imprimir un mensaje
            printf("¿Desea agregarla? (s/n): "); // Preguntar al usuario si desea agregarla
            char opcion; // Variable para guardar la opción del usuario
            scanf(" %c", &opcion); // Leer la opción del usuario (el espacio antes del %c es para ignorar el salto de línea anterior)
            
            if (opcion == 's' || opcion == 'S') { // Si el usuario desea agregarla
                for (j = 0; j < CANT_STR; j++) { // Buscar una posición libre en el diccionario
                    if (diccionario[j][0] == '\0') { // Si la cadena está vacía
                        strcpy(diccionario[j], palabra); // Copiar la palabra en el diccionario
                        printf("La palabra %s ha sido agregada al diccionario.\n", palabra); // Imprimir un mensaje
                        break; // Salir del ciclo
                    }
                }
            }
        }

        i++; // Avanzar al siguiente carácter de la oración (que debe ser un espacio o el final de la oración)
    }

    // Imprimir el estado actual del diccionario
    printf("El diccionario actual es:\n");
    for (i = 0; i < CANT_STR; i++) { // Recorrer el diccionario
        if (diccionario[i][0] != '\0') { // Si la cadena no está vacía
            printf("%s\n", diccionario[i]); // Imprimir la cadena
        }
    }

    return 0;
}