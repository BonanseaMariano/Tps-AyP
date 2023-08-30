#include <stdio.h>

int main(){
    int ed,a,m,d,anac,mnac,dnac;
    //Datos fecha actual
    printf("Ingresa el anio actual\n");
    scanf("%d",&a);
    printf("Ingresa el mes actual\n");
    scanf("%d",&m);
    printf("Ingresa el dia actual\n");
    scanf("%d",&d);
    
    //Datos fecha nacimiento
    printf("Ingresa tu anio de nacimiento\n");
    scanf("%d",&anac);
    printf("Ingresa tu mes de nacimiento\n");
    scanf("%d",&mnac);
    printf("Ingresa tu dia de nacimiento\n");
    scanf("%d",&dnac);
    ed=a-anac;
    if (mnac>m || (mnac==m && dnac>d))
    {
        ed--;
    }
    
    printf("Tenes %d anios",ed);
    return 0;
}