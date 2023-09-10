#include <stdio.h>

int main(){
    char let[]={'a','b','c','d','e','f','g','h','i','j'};
    for (int i = 0; i < 10; i++)
    {
        printf("%c\t",let[i]);
    }
    printf("\n\n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%c\t",let[i]);
    }
    return 0;
}