#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica com encadeamento duplo ORDENADA

int main()
{
    Lista lst;
    int i=0;
    int elem;

    inicio:
    while(i!=5){

        printf(" \n--------------Menu--------------\n");
        printf(" Digite [1], para iniciar uma lista:\n");
        printf(" Digite [2], para verificar se lista esta vazia:\n");
        printf(" Digite [3], para inserir elementos na lista:\n");
        printf(" Digite [4], eliminar um elemento da lista:\n");
        printf(" Digite [5], para imprimir a lista:\n");
        printf(" Digite [6], para liberar a lista:\n");
        printf(" Digite [7], para fechar o programa:\n");

        scanf("%d", &i);
        setbuf(stdin, NULL);
    
        
        switch (i){
            case 1:
                lst = cria_lista();
                printf("Lista criada!\n");
            break;
            
            case 2:
                if(lista_vazia(lst) == 1) {
                    printf("A lista esta vazia\n");
                }
                else {
                    printf("A lista não esta vazia\n");
                }
            break;

            case 3:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                if(insere_ord(&lst, elem)) {
                    printf("\nElemento inserido!\n");
                }
                else {
                    printf("Erro ao inserir elemento!\n");
                }
                break;
            
            case 4:
                printf(" digite um elemento a ser removido da lista:\n");
                scanf("%d",&elem);
                
                if(remove_ord(&lst,elem)==0)
                printf("Erro ao remover elemento!\n");
                break;

            case 5:
                imprime_lista(lst);
                break;

                case 6:
                libera_lista(&lst);
                printf("Lista liberada!\n\n");
                break;
            
            case 7:
                goto inicio;
        }

    }  
   return 0;
}
