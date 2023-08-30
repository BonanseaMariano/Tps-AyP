#include <stdio.h>

int main(){
    int n,f;
    printf("Ingrese un numero natural\n");
    scanf("%d",&n);
    f=n;
    for (int i = 1; i < n; i++)
    {
        f*=i;
    }
    printf("El factorial de %d es %d",n,f);
    return 0;
}