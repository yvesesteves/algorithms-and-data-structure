#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

int main(){
    int i = 0;
    int ativo = 0;
    int x1,x2,y1,y2;
    float distancia;
    Ponto *generate();
    Ponto *P;

    while(ativo != 4){
        printf("-----Menu-----\n");
        printf("[1] - Criar uma instancia de um ponto sem valores\n");
        printf("[2] - Eliminar um ponto criado\n");
        printf("[3] - Calcular a distancia entre os pontos\n");
        printf("[4] - para fechar o programa\n");

        scanf("%d", &i);
        setbuf(stdin, NULL);

        switch(i){
            case 1:
                P = generate();
                if(P == NULL){
                    printf("Erro na alocacão\n");
                    break;
                }
                else
                    printf("Pontos criados!\n");
                    break;
                
            case 2:
                libera_pto(&P);
                if(P == 0){
                    printf("Ponto liberado!\n");
                    break;
            
            case 3:
                printf("Informe as coordenadas do primeiro ponto: ");
                scanf("%d, %d", &x1, &x2);
                printf("\nInforme as coordenadas do segundo ponto: ");
                scanf("%d, %d", &y1, &y2);
                distancia = distancia_pto(x1,x2,y1,y2);
                printf("A distancia entre os pontos eh de: %.1f", distancia);
                printf("\n\n");
                    break;

            case 4:
                printf("---Fim do programa---\n\n");
                ativo = 4;
                    break;

            default:
                printf("Opcao invalida, digite uma opcao de 1 a 4");
        }
    }

    return 0;
}
}