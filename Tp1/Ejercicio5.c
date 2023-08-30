#include <stdio.h>

void estacion(int mnac);

int main(){
    int anac,mnac,dnac;
    printf("Ingresa tu anio de nacimiento\n");
    scanf("%d",&anac);
    printf("Ingresa tu mes de nacimiento\n");
    scanf("%d",&mnac);
    printf("Ingresa tu dia de nacimiento\n");
    scanf("%d",&dnac);
    estacion(mnac);
    return 0;
}

void estacion(int mnac){
    char *est;
    if (mnac==12||mnac>=1 && mnac<=2)
    {
        est="Verano";
    }else if (mnac>=3 && mnac<=5)
    {
        est="Otonio";
    }else if (mnac>=6 && mnac<=8)
    {
        est="Invierno";
    }else if (mnac>=9 && mnac<=11)
    {
        est="Primavera";
    }
    printf("Naciste en la estacion: %s",est);
}