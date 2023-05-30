#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Pilha Estática Sequencial

int main(){
    Pilha p;
    int ativo = 0;
    int i;
    int elem;
    int top;
    
    while(ativo != 7){
        printf("\n----------------Menu---------------\n");
        printf("Digite [1] para criar a pilha\n");
        printf("Digite [2] para empilhar um elemento na pilha\n");
        printf("Digite [3] para desempilhar um elemento da pilha \n");
        printf("Digite [4] para imprimir a pilha\n");
        printf("Digite [5] para ler elemento do topo da pilha\n");
        printf("Digite [6] para liberar pilha\n");
        printf("Digite [7] para sair\n");
    
        printf(" Opcao: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

    switch(i){
        case 1:
            p = cria_pilha();
            printf("Pilha criada!\n");
        break;
            
        case 2:
            printf("Digite o elemento: ");
            scanf("%d", &elem);
            push(p, elem);
            printf("Elemento empilhado!\n");
            if(p == NULL)
                printf("Erro ao empilhar elemento\n");
        break;
            
        case 3:
            pop(p, &elem);
            printf("Elemento desempilhado!\n");
        break;

        case 4:
            printf("\n<<PILHA>>\n");
            imprime_pilha(p);
            printf("\n--------------------------\n");
        break;

        case 5:
            le_topo(p, &elem);
            printf("O topo da pilha eh: %d", elem);
            printf("\n");
        break;

        case 6:
            libera_pilha(&p);
            printf("Pilha liberada!\n");
        break;

        case 7:
            ativo = 7;
            printf("Saindo...\n");
        break;

        default:
            printf("Opcao invalida, digite uma opcao de 1 a 7\n");
    }
    }
    return 0;
}