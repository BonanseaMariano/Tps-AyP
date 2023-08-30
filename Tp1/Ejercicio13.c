#include <stdio.h>
#include <math.h>
//#include <string.h>
//#include <stdlib.h>

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

//Forma pasando a string e invirtiendo la cadena
/*int main(){
    int num,inum;
    char *aux;
    printf("Ingrese un numero:\n");
    scanf("%d", &num);
    //Convierto el numero a String
    sprintf(aux,"%d",num);
    //Invierto la cadena y la convierto nuevamente a int
    if(num<0)
    {
        inum=atoi(abs(strrev(aux)));
        aux*=-1;
    }else
    {
        inum=atoi(strrev(aux));
    }
    
    //Imprimo el numero invertido
    printf("El numero invertido es: %d",inum);
    //Lo comparo con el original para ver si es capicua
    if (num==inum)
    {
        printf("\nEl numero ES capicua");
    }else{
        printf("\nEl numero NO ES capicua");
    }
    return 0;
}*/