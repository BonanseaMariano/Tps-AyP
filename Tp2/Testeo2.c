#include <stdio.h>
#include <string.h>

//strcat / strcpy
// "\0 para poner fin de string"

int main(){
    char f1[]={"06/02/1999"};
    f1[3]='\0';
    f1[6]='\0';

    printf("%s\n",f1);
    printf("%s\n",f1[3]);
    printf("%s\n",f1[6]);

    
    return 0;
}
