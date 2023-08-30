#include <stdio.h>
#include <string.h>

int div(int num);
void lenght(int num);

int main(){
    int num;
    printf("Ingrese un numero\n");
    scanf("%d",&num);
    printf("El numero tiene %i digitos",div(num));
    return 0;
}

int div(int num){
     //Forma con divisiones
    int cont=0;
    while (num!=0)
    {
        cont++;
        num/=10;
    }
    return cont;
}

void lenght(int num){
    /* Forma pasando a String y viendo su lenght (hay que arreglar 
    que los negativos cuenta el - como un digito)*/
    char *aux;
    sprintf(aux,"%d",num);
    printf("\nEl numero tiene %d digitos",strlen(aux));
}