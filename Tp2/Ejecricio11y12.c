#include <stdio.h>

int main() {
    int x[20] = {2, 5, 8, 12, 17, 20, 25, 30, 33, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90};
    int n = 20;
    int y[20];
    int m = 0;
    
        for (int i = 0; i < n; i++) {
            //Imprime el valor del arreglo x
            printf("%d ",x[i]);
            
            //si el valor del registro x no es par
            if (x[i] % 2 != 0) {
                //Guarda el valor del registro x en el registro y (desde 0)
                y[m++] = x[i];
            }
        }
        printf("\n");

        //Imprime todo el arreglo y
        for (int i = 0; i < m; i++) {
            printf("%d ", y[i]);
        }
        printf("\n");
    return 0;
}

/*La funcionalidad del ejercicio anterior es primero imprimir todos los valores del registro x, 
luego evalua cuales valores son pares y los almacena en el registro y para posteriormente
imprimirlos todos.*/