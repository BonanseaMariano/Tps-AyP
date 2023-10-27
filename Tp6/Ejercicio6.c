#include <stdio.h>

int minCoins(int coins[], int m, int V); //(Valores de monedas y billetes disponibles, tamaño del arreglo, suma a cubrir)

int main() {
    int coins[] = {1, 5, 10, 20, 50, 100, 500, 1000};//Arreglo de monedas/billetes
    int m = sizeof(coins) / sizeof(coins[0]);
    int V;
    printf("Ingrese la suma a cubrir: $");
    scanf("%d", &V);
    printf("La cantidad mínima de billetes y monedas necesarias para cubrir la suma es: %d\n", minCoins(coins, m, V));
    return 0;
}

int minCoins(int coins[], int m, int V) {
    if (V == 0) {//Caso base, el valor a cubrir llego a 0
        return 0;
    }
    int res = 1000000;
    for (int i = 0; i < m; i++) {//Recorro el arreglo de monedas/billetes
        if (coins[i] <= V) {
            int sub_res = minCoins(coins, m, V - coins[i]);
            if (sub_res != 1000000 && sub_res + 1 < res) {
                res = sub_res + 1;
            }
        }
    }
    return res;
}
