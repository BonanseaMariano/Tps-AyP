#include <stdio.h>
int main() {
    int v[5];
    int e;

    //El usuario carga los valores del arreglo v
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    //El usuario carga el valor entero de e
    scanf("%d", &e);

    //Imprime los valores del arreglo v que fueron cargados por el usuario
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    //Multiplica cada valor del arreglo por el entero e y luego imprime el resultado sin guardarlo
    for (int i = 0; i < 5; i++) {
        int p = v[i] * e;
        printf("%d ", p);
    }
    printf("\n");
    return 0;
}

/*El programa anterior carga valores en un arreglo por parte del usuario y posteriormente multiplica cada uno por un numero
preestablecido por el usuario e imprime el resultado (sin guardar los resultados)*/ 