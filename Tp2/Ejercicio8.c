#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    srand(getpid());
    int nums[20];
    int reps[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    bool ban;

    //Carga de numeros
    for (int i = 0; i < 20; i++)
    {
        nums[i]= rand() % 10;
        printf("%d\t",nums[i]);
    }

    //Acumulacion de numeros no repetidos y eliminacion de repetidos
    for (int i = 0; i < 20; i++)
    {
        ban=false;
        
        if(nums[i]==reps[nums[i]]){
            //Para "borrar" el repetido (problema cuando)
            nums[i]=-1;
        }else{
            reps[nums[i]]=nums[i];
        }
    }

    printf("\n\t---- Arreglo con repetidos eliminados ----\n");
    //Impresion final
    for (int i = 0; i < 20; i++)
    {
        if (nums[i]!=-1)
        {
            printf("%d\t",nums[i]);
        }
    }
    
    return 0;
}