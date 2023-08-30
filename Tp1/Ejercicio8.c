#include <stdio.h>

int pot(int b,int e);
int sum(int veces, int num);

int main(){
    int b,e;
    printf("Ingrese la base\n");
    scanf("%d",&b);
    printf("Ingrese el exponente\n");
    scanf("%d",&e);
    printf("%d elevado a %d es: %d",b,e,pot(b,e));
    return 0;
}

int pot(int b,int e){
    int acusum=b;
    if (e==1)
    {
    return b;
    }else if (e==0)
    {
    return 1;
    }else{
        for (int i = 1; i < e; i++)
        {
            acusum=sum(b,acusum);
        }
        return acusum;
    }
}

int sum(int veces,int num){
    int n=0;
    for (int i = 0; i < veces; i++)
    {
        n+=num;
    }
    return n;
}