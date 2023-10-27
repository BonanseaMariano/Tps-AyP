#include <stdio.h>
#include <string.h>

int balanceo(char *str, int i, int count); //(Cadena, posicion actual en la caden, contador de parentesis)

int main() {
    char str[100];
    printf("Ingrese una cadena de caracteres que contenga parentesis izquierdos y derechos: ");
    scanf("%s", str);
    if (balanceo(str, 0, 0)) {//Inicializo la funcion recursiva con posicion 0 y cantidad de parentesis 0
        printf("Los parentesis estan balanceados.\n");
    } else {
        printf("Los parentesis no estan balanceados.\n");
    }
    return 0;
}

int balanceo(char *str, int i, int count) {
    if (i == strlen(str)) { //Caso base (se llego al final de la cadena)
        return count == 0; //Devuelvo que los parentesis estan balanceados
    } else if (count < 0) {//2do caso de corte (los parentesis no se encuentran balanceados, ya que hay mas parentesis cerrados ")" que abiertos "(")
        return 0; //Devuelvo "false"
    //CASOS RECURSIVOS
    } else if (str[i] == '(') { //Si encuentro una apertura de parentesis en algun lugar desde el inicio de la cadena
        return balanceo(str, i + 1, count + 1);//Incremento el indice de la posicion y el contador de parentesis
    } else if (str[i] == ')') { //Si encuentro un cierre de parentesis en algun lugar desde el inicio de la cadena
        return balanceo(str, i + 1, count - 1); //Incremento el indice de la posicion y decremento el contador de parentesis (pq si habia una apertura de parentesis se indica que se cerro, y caso contrario queda negativo para la condicion de corte)
    } else {//Si no encuentro ni apertura ni cierre de parentesis unicamente incremento el indice de posicion actual
        return balanceo(str, i + 1, count);
    }
}