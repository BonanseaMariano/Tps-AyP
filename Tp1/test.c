#include <stdio.h>
#include <math.h>

int cant;

int inversa(int num);

int main(){
    int num,inv;
    printf("Ingrese un numero: ");
    scanf("%i",&num);
    inv=inversa(num);
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

int inversa(int num){
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