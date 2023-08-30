#include <stdio.h>
#include <ctype.h>

void letras(char let);

int main(){
    char letra,aux;
    aux='a';
    printf("Ingrese una letra:\n");
    scanf("%c",&letra);
    printf("\t----------\n");
    letras(letra);
    return 0;
}

void letras(char let){
    if (isupper(let))
    {
        for (char i ='Z'; i > let; i--)
        {
            printf("%c",toupper(i));
            printf("\n");
        }
    }else{
        for (char i ='z'; i > let; i--)
        {
            printf("%c",i);
            printf("\n");
        }
    }
}