#include <stdio.h>

int main(){
    int n;
    printf("Ingrese la cantidad de terminos de la serie Fibonaci\n");
    scanf("%d",&n);
    printf("\t----------\n");
    int acu[n];
    for (int i = 0; i < n; i++)
    {
        if (i<2)
        {
            acu[i]=1;
        }else{
            acu[i]=acu[i-1]+acu[i-2];
        }
        printf("%d",acu[i]);
        printf("\n");
    }
    return 0;
}