#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int inversa(int num, int cant);
void gen(int *ary);

int main(){
    srand(getpid());
    int ary[10];
    gen(ary);


    int num,inv,cant;
    printf("Ingrese un numero: ");
    scanf("%i",&num);
    inv=inversa(num, cant);
    if (cant%2!=0)
    {
        inv++;
    }
    printf("La inversa del numero %i es: %i",num,inv);
    if (num==inv)
    {
        printf("\nEl numero es capicua");
    }else{
        printf("\nEl numero NO es capicua");
    }
    return 0;
}

void gen(int *ary){
    //Numero de cifras random
    int c = (rand() % 5)+1;
    //Genera digitos del 1 al 9
    int dig = rand() % 10;
    

    for (int i = 0; i < 10; i++)
    {
        int esp=1;
        
    }
    
    
    

}

int inversa(int num, int cant){
    int res,sum = 0,i,c;
    cant=0;
    int num2 = num;
    while(num2!=0){
        num2/=10;
        cant++;
    }
    for(i = 1;i <= cant;i++){
        res = num%10;
        num/=10;
        sum += (res * pow(10,cant-i));  
    }
    return sum;
}

/*
    int generarCapicua () {
    int i, j;
    for (i = 1; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            int num = i * 100 + j * 10 + i;
            return num;
        }
    }
    for (i = 10; i <= 99; i++) {
        if (esCapicua (i)) {
            return i;
        }
    }
    for (i = 100; i <= 999; i++) {
        int num = i * 10 + i / 100;
        if (esCapicua (i)) {
            return i;
        }
    }
}

int main () {
    int capicua = generarCapicua ();
    printf ("%d\n", capicua);
    return 0;
}

*/