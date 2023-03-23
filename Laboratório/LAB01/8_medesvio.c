#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
    printf("------------MEDIA E DESVIO PADRAO------------\n");
    int v1,v2,v3,v4,v5;
    int v11,v22,v33,v44,v55;
    double m, qd, np, dp;
    printf("\nDigite os valores para calcular a media e o desvio-padrao\n");
    printf("Digite o valor 1: ");
    scanf("%d", &v1);
    printf("\nDigite o valor 2: ");
    scanf("%d", &v2);
    printf("\nDigite o valor 3: ");
    scanf("%d", &v3);
    printf("\nDigite o valor 4: ");
    scanf("%d", &v4);
    printf("\nDigite o valor 5: ");
    scanf("%d", &v5);

    m = ((v1+v2+v3+v4+v5)/5);
    v11 = v1-m;
    v22 = v2-m;
    v33 = v3-m;
    v44 = v4-m;
    v55 = v5-m;

    qd = (pow(v11,2) + pow(v22,2) + pow(v33,2) + pow(v44,2) + pow(v55,2));
    np = qd/5;
    dp = sqrt(np);


    printf("\nA media eh %.1f e o desvio-padrao eh %f\n",m, dp);
    return 0;
    
}