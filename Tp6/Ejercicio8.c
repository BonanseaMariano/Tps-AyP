#include <stdio.h>

void invertirCadena(int *cadena, int inicio, int fin);

int main() {
    int n;
    printf("Ingrese el tamanio de la cadena de enteros: ");
    scanf("%d",&n);
    int cadena[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nIngrese el %d* entero de la cadena: ", i+1);
        scanf("%d",&cadena[i]); 
    }
    
    printf("\nCadena Original:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", cadena[i]);
    }
    
    //Por algun motivo el programa termina aca
    invertirCadena(cadena,0,n-1);

    printf("\nCadena Invertida:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", cadena[i]);
    }

    return 0;
}

void invertirCadena(int *cadena, int inicio, int fin) {
    if (inicio >= fin) {//Caso base
        return;
    }else{
        int aux = cadena[inicio];
        cadena[inicio] = cadena[fin];
        cadena[fin] = aux;
        invertirCadena(cadena, inicio+1, fin-1);//Caso recursivo
    }
}
