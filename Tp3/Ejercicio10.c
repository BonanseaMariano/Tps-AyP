#include <stdio.h>

void sumAr(int *v1,int *v2,int *res);

int main(){
    int v1[]={1,2,3,4,5},v2[]={5,4,3,2,1},res[]={0,0,0,0,0};
    
    sumAr(v1,v2,res);

    for (int i = 0; i < 5; i++)
    {
        printf("%d",res[i]);
    }
    return 0;
}

void sumAr(int *v1,int *v2,int *res){
    for (int i = 0; i < 5; i++)
    {
        res[i]=(v1[i]+v2[i]);
    }
}