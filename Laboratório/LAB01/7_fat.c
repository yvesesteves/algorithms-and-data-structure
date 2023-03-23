/* O programa dava erro porque os numeros eram muito grandes e o tipo de variavel inteiro não o suportava
    por isso, para corrigir, usei o tipo double, que suporta números maiores
*/

#include <stdio.h>

double fatorial(double n)
{
    if(n==0 || n==1)
        return 1;
    else
        return n*fatorial(n-1);
}

int main(){
    printf("------------------Fatorial------------------\n");
    double n;

    for(n=10;n<=15;n++){
        printf("!%.1f = %.1f\n", n, fatorial(n));
    }

    return 0;
}