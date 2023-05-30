#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica Circular NÃO ordenada

int main()
{
    Lista lst;
    int i=0;
    int elem;

    inicio:
    while(i!=7){

        printf(" \n--------------Menu--------------\n");
        printf(" Digite [1], para iniciar uma lista:\n");
        printf(" Digite [2], para inserir elemento no inicio da lista:\n");
        printf(" Digite [3], para inserir elemento no final da lista:\n");
        printf(" Digite [4], para eliminar um elemento no inicio da lista:\n");
        printf(" Digite [5], para eliminar um elemento no final da lista:\n");
        printf(" Digite [6], para imprimir a lista:\n");
        printf(" Digite [7], para fechar o programa:\n");

        scanf("%d", &i);
        setbuf(stdin, NULL);
        printf("\n");
    
        
        switch (i){
            case 1:
                lst = cria_lista();
            break;
            
            case 2:
                printf(" digite o elemento a ser inserido no inicio:\n");
                scanf("%d",&elem);
                
                if(insere_inicio(&lst, elem)==0)
                    printf("Erro ao inserir elemento!\n");
                break;

            case 3:
                printf(" digite o elemento a ser inserido no final:\n");
                scanf("%d",&elem);
                
                if(insere_final(&lst, elem)==0)
                    printf("Erro ao inserir elemento!\n");
                break;
            
            case 4:
                printf(" digite um elemento a ser removido no inicio da lista:\n");
                scanf("%d",&elem);
                
                if(remove_inicio(&lst,&elem)==0)
                printf("Erro ao remover elemento!\n");
                break;

            case 5:
                printf(" digite um elemento a ser removido no final da lista:\n");
                scanf("%d",&elem);
                
                if(remove_final(&lst,&elem)==0)
                printf("Erro ao remover elemento!\n");
                break;

            case 6:
                printf("A lista é:\n");
                imprime_lista(lst);
                break;
            
            case 7:
                goto inicio;
        }

    }  
   return 0;
}
