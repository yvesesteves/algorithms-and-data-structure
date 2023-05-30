#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define MAX 20 

// Lista Sequencial NÃO ordenada.

int main(){
    int i, elem, elem2;
    int ativo = 0;
    Lista *lst;

    while(ativo != 9){
        printf("\n -- Lista estatica sequencial NAO ordenada -- \n");
        printf(" Digite [1] para criar uma lista\n");
        printf(" Digite [2] para verificar se a lista esta vazia\n");
        printf(" Digite [3] para verificar se a lista esta cheia\n");
        printf(" Digite [4] inserir um elemento\n");
        printf(" Digite [5] para excluir um elemento\n");
        printf(" Digite [6] para imprimir a lista\n");
        printf(" Digite [7] para saber o tamanho da lista\n");
        printf(" Digite [8] para liberar lista\n");
        printf(" Digite [9] para sair\n");
        printf(" Opcao: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

        switch(i){
            case 1:
                lst = cria_lista();
                printf("Lista criada!\n\n");
            break;

            case 2:
                printf("Verificando se lista esta vazia\n\n");
                int flag = lista_vazia(lst);
                if (flag == 1)
                    printf("\nA lista esta vazia\n");
                if (flag == 0)
                    printf("\nA lista nao esta vazia\n");
                break;

            case 3:
                printf("Verificando se lista esta cheia\n\n");
                int flag2 = lista_cheia(lst);
                if(flag2 == 1)
                    printf("\nA lista esta cheia\n");
                if(flag2 == 0)
                    printf("\nA lista nao esta cheia\n");
                break;

            case 4:
                printf("\nDigite o elemento que deseja inserir: ");
                scanf("%d", &elem);
                int flag3 = insere_elem(lst, elem);
                if(flag3 == 1){
                    printf("\n\n Elemento inserido!\n");
                }
                if(flag3 == 0){
                    printf("Erro ao inserir elemento\n");
                }
                break;

            case 5:
                printf("\nDigite o elemento que deseja remover: ");
                scanf("%d", &elem2);
                int flag4 = remove_elem(lst, elem2);
                if(flag4 == 1){
                    printf("\n\n Elemento removido!\n");
                }
                if(flag4 == 0){
                    printf("Erro ao remover elemento\n");
                }
                break;

            case 6:
                printf("\n-------LISTA-------\n");
                obtem_valor_elem(lst);
                printf("\n");
                break;

            case 7:
                tamanho_lista(lst);
                break;

            case 8:
                libera_lista(&lst);
                printf("Lista liberada!\n");
                break;

            case 9:
                printf("Fim do programa...\n\n");
                ativo = 9;
                break;


            default:
				printf("\n\n Opcao invalida, digite um numero de 1 a 9\n");
        }

    }


    return 0;
}