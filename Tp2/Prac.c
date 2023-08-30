#include <stdio.h>

int main(){
    //9999 tam de cada celda

    int n1[20];
    int n2[20];
    int res[20][2];

    //Limpieza de columna del carry
    for (int i = 0; i < 20; i++)
    {
        res[i][1]=0000;
        n1[i]=9999;
        n2[i]=9999;
    }
    

    //Suma
    for (int i = 0; i < 20; i++)
    {
        //Veo si hay carry y lo calculo
        if(n1[i]+n2[i]>9999 && i<19){
            res[i+1][1]=(n1[i]+n2[i])-9999;
        }

        //Pregunto si hay carry
        if (res[i][1]!=0)//No hay
        {   
            res[i][0]=n1[i]+n2[i];
        }else{//Hay
            res[i][0]=n1[i]+n2[i]+res[i][1];
        }

        //capeo del numero
        if (n1[i]+n2[i]>9999)
        {
            res[i][0]=9999;
        }
    }
    
    //Impresion
    for (int i = 0; i < 20; i++)
    {
        printf("%i|",res[i][0]);
    }
    printf("\n\t------------------------------------------------\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%i|",res[i][1]);
    }

    return 0;
}