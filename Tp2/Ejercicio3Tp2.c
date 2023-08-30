#include <stdio.h>

int main(){
    int v1[]={1,2,3,4,5},v2[]={5,4,3,2,1};
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",(v1[i]+v2[i]));
    }
    return 0;
}