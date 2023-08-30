#include <stdio.h>

int main(){
    int ed=2023,nac;
    printf("Ingresa tu anio de nacimiento\n");
    scanf("%d",&nac);
    ed-=nac;
    printf("Tenes %d anios",ed);
    return 0;
}