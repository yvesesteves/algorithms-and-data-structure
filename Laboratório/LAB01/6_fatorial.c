#include <stdio.h>

int fatorial(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return n*fatorial(n-1);
}

int main(){
    printf("------------------Fatorial------------------\n");
    int n;

    for(n=1;n<=10;n++){
        printf("!%d = %d\n", n, fatorial(n));
    }

    return 0;
}