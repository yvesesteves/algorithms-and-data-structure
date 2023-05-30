#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("------------Triangulo de Floyd------------\n");
    printf("Digite um numero para imprimir o triangulo\n");
    int n, i, j;
    int k = 0;

    scanf("%d", &n);
    for(i=1; i <= n; i++){
        for(j=1; j <= i; j++){
            k++;
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}