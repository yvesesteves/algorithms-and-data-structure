#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica Sequencial NÃO ordenada

int main(){
    int i;
    int ativo = 0;
    int elem;
    Lista lst;

    while (ativo != 8) {
        printf("\n--------Menu--------\n");
        printf(" Digite [1] para criar uma lista\n");
        printf(" Digite [2] para verificar se a lista esta vazia\n");
        printf(" Digite [3] inserir um elemento\n");
        printf(" Digite [4] para excluir um elemento\n");
        printf(" Digite [5] para imprimir a lista\n");
        printf(" Digite [6] para liberar lista\n");
        printf(" Digite [7] para verificar tamanho da lista\n");
        printf(" Digite [8] para sair\n");
        printf(" Opcao: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

        switch(i) {
            case 1:
                lst = cria_lista();
                printf("Lista criada!");
            break;

            case 2:
                if(lista_vazia(lst) == 1) {
                    printf("A lista esta vazia");
                break;
                }
                else {
                    printf("A lista não esta vazia");
                }
            break;

            case 3:
                printf("Digite o elemento a ser inserido ");
                scanf("%d", &elem);
                if(insere_elem(&lst, elem)) {
                    printf("\nElemento inserido!\n");
                }
                else {
                    printf("Erro ao inserir elemento!");
                }
            break;

            case 4:
                printf("Digite o elemento a ser removido ");
                scanf("%d", &elem);
                if(remove_elem(&lst, elem)) {
                    printf("\nElemento removido!\n");
                }
                else {
                    printf("Erro ao remover elemento!\n");
                }
            break;

            case 5:
                printf("-----------LISTA-----------\n");
                imprime_lista(lst);
                printf("_________________________\n");
            break;
            
            case 6:
                libera_lista(&lst);
                printf("Lista liberada!\n\n");
            break;

            case 7:
                tamanho_lista(lst);
            break;

            case 8:
                ativo = 8;
                printf("\n-----------Fim do programa!-----------\n\n");
            break;

            default:
                printf("\nOpÃ§ao invalida, digite uma opcao de 1 a 6\n");

        }
    }

    return 0;
}