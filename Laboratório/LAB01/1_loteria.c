#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("-------------LOTERIA-------------\n");
    int inv1, inv2, inv3;
    float premio;
    int aux;
    float p1, p2, p3;
    printf("Informe a quantidade investida dos 3 jogadores respectivamente\n");
    scanf("%d %d %d", &inv1, &inv2, &inv3);

    printf("Informe o valor do premio\n");
    scanf("%f", &premio);

    aux = inv1 + inv2 + inv3;
    p1 = (((float)inv1/aux) * premio);
    p2 = (((float)inv2/aux) * premio);
    p3 = (((float)inv3/aux) * premio);
    printf("O jogador 1 vai receber: %.2f\n", p1);
    printf("O jogador 2 vai receber: %.2f\n", p2);
    printf("O jogador 3 vai receber: %.2f\n", p3);
    printf("-----------------------------------------");
    
    return 0;
}