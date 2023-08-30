#include <stdio.h>
#include <ctype.h>

void letras(char a);

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
        for (char i ='A'; i < let; i++)
        {
            printf("%c, ",toupper(i));
        }
    }else{
        for (char i ='a'; i < let; i++)
        {
            printf("%c, ",i);
        }
    }
}