#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 20

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    int num_strings = 0;
    char new_string[MAX_LENGTH];

    while (1) {
        printf("Ingrese una cadena (\"fin\" para terminar): ");
        scanf("%s", new_string);

        if (strcmp(new_string, "fin") == 0) {
            break;
        }

        int i;
        for (i = num_strings - 1; i >= 0; i--) {
            if (strcmp(new_string, strings[i]) > 0) {
                break;
            }
            strcpy(strings[i + 1], strings[i]);
        }

        if (i == num_strings - 1 && num_strings == MAX_STRINGS) {
            printf("No se puede insertar la cadena.\n");
            continue;
        }

        strcpy(strings[i + 1], new_string);
        num_strings++;

        if (num_strings > MAX_STRINGS) {
            num_strings = MAX_STRINGS;
        }

        printf("Arreglo actualizado:\n");
        for (int j = 0; j < num_strings; j++) {
            printf("%s\n", strings[j]);
        }
    }

    return 0;
}
