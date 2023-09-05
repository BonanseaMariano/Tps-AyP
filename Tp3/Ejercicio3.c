#include <stdio.h>

int calcularEdad(int *act,int *nac);

int main(){
    int actual[3],nac[3];
    //Datos fecha actual
    printf("Ingresa el anio actual\n");
    scanf("%d",&actual[0]);
    printf("Ingresa el mes actual\n");
    scanf("%d",&actual[1]);
    printf("Ingresa el dia actual\n");
    scanf("%d",&actual[2]);
    
    //Datos fecha nacimiento
    printf("Ingresa tu anio de nacimiento\n");
    scanf("%d",&nac[0]);
    printf("Ingresa tu mes de nacimiento\n");
    scanf("%d",&nac[1]);
    printf("Ingresa tu dia de nacimiento\n");
    scanf("%d",&nac[2]);
    
    
    printf("Tenes %d anios",calcularEdad(actual,nac));
    return 0;
}

int calcularEdad(int *act,int *nac){
    int ed;
    ed=act[0]-nac[0];
    if (nac[1]>act[1] || (nac[1]==act[1] && nac[2]>act[2]))
    {
        ed--;
    }
    return ed;
}