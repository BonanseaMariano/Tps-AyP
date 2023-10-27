#include <stdio.h>

void minCoins(int bille[], int tam, int V); //(Valores de monedas y billetes disponibles, tamaño del arreglo, suma a cubrir)

int main() {
    int bille[] = {2000,1000,500,200,100,50,20,10,5,2,1};//Arreglo de monedas/billetes
    int V;
    printf("Ingrese la suma a cubrir: $");
    scanf("%d", &V);
    printf("La cantidad minima de billetes y monedas necesarias para cubrir la suma es de:\n");
    minCoins(bille, 0, V);
    return 0;
}

void minCoins(int bille[], int tam, int V) {
    if (V == 0) { //Caso base, el valor a cubrir llego a 0
        return;
    }
    //printf("Cantidad: %d", V);
    if (V>=bille[tam])//El billete alcanza para cubrir el valor restante
    {

        int cantBille = V / bille[tam]; // division para ver cantidad de billetes de esa denominacion que devo usar
        //printf("Cantidad billete: %d", cantBille);
        if (cantBille>0) //Si es que se uso al menos un billete de esa denominacion
        {
            printf("%d billetes de $%d\n",cantBille,bille[tam]); //Imprimo cuantos billetes y de que denominacion
            int res = cantBille*bille[tam]; //Calculo el resto que le debo quitar al total a cubrir
            minCoins(bille,tam+1,V-res); //Incremento tamaño para pasar al proximo billete y tambien resto al valor total
        }
        
    }else{ //El billete NO alcanza para cubrir el valor restante
        minCoins(bille,tam+1,V); //Incremento tamaño para pasar al proximo billete
    }
}
