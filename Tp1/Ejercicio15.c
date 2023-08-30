#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Ver floor para sacarle la parte decimal si esta es cero con casteto (int)

float op(float n1, float n2, char s);
bool partedec(float n);

int main(){
    float fn1,fn2,res;
    char s;
    //Primer numero
    printf("Ingrese el primer numero\n");
    scanf("%f",&fn1);
    //Operacion
    printf("Ingrese la operacion (+,-,*,/,p)\n");
    scanf("%s",&s);
    //Segundo numero
    printf("Ingrese el segundo numero\n");
    scanf("%f",&fn2);   
    res=op(fn1,fn2,s);
    //Casos de impresion
    if (partedec(res))
    {
        printf("%.2f %s %.2f = %i",fn1,&s,fn2,(int)floor(res));    
    }else{
        printf("%.2f %s %.2f = %.2f",fn1,&s,fn2,res);
    }
    return 0;
}

float op(float n1, float n2, char s){
    switch (s)
    {
    case '+':
        return n1+n2;

    case '-':
        return n1-n2;

    case '*':
        return n1*n2;
    case '/':
        if (n2!=0)
        {
            return n1/n2;
        }else{
            printf("\n\t----No se puede dividir por 0\n");
            return 0;
        }
    case 'p':
        return pow(n1,n2);
    default:
        printf("\n\t----OPERACION INVALIDA----\n");
        return 0;
    }
}

//Falso si tiene parte decimal, verdadero si no tiene
bool partedec(float n){
    double exp,frac = modf(n, &exp);
    if (frac != 0)
    {
        return false;
    }
    return true;
}