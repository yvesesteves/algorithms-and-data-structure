#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica Sequencial ORDENADA 

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else
        return 0;
}

/*
    Inserção na dinamica ORDENADA:
    Inserção na posiçao correta(envolve percorrimento)
    4 cenarios possiveis:
        - lista vazia
        - novo elemento <= 1ºnó da lista
        - novo elemento > ultimo nó da lista
        - novo elemento entre o 1º e o ultimo nó da lista

*/
int insere_ord(Lista *lst, int elem){
    // Aloca um novo nó
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;   // falha
    N->info = elem; // insere o valor do elem(conteudo)
    if(lista_vazia(*lst) || elem <= (*lst)->info){
        N->prox = *lst; // aponta para o 1ºnó atual da lista
        *lst = N;   // fa a lista apontar para o novo nó
        return 1;
    }

    // Percorrimento da lista(elem > 1ºnó da lista)
    Lista aux = *lst;   // faz aux apontar para o 1º nó
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux-> prox;   // avança
    //Insere o novo elem na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}


/*
    Remoção da dinamica ORDENADA:
    Percorre até achar o nó maior
    6 cenarios possiveis:
        - lista vazia
        - elem é o ultimo nó da lista
        - elem está entre o 1º e ultimo nó da lista
        -ELEM NAO ESTA NA LISTA(divido em criterio de ord){
            - elem < 1º nó da lista
            - elem > ultimo nó da lista
            - 1º < elem < ultimo nó da lista
            }
        

*/
int remove_ord(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1 || elem < (*lst)->info)
        return 0;   // falha
    
    Lista aux = *lst;   // ponteiro auxiliar p/ o 1º nó
    //Trata elem = 1º nó da lista
    if(elem == (*lst)->info){   
        *lst = aux->prox;// lista aponta para o 2ºnó
        free(aux);  // libera memória alocada
        return 1;
    }
    //Percorrimento até o final da lista, achar elem ou nó maior
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->info < elem) // achar elem ou nó maior
        return 0;   // falha
    
    Lista aux2 = aux->prox;     // aponta nó a ser removido
    aux->prox = aux2->prox;     // retira nó da lista
    free(aux2);     // libera memória alocada
    return 1;
}

void imprime_lista(Lista lst)
{
    if (lista_vazia(lst) == 1){
        printf("Lista vazia ou nao existe\n");
    }
    else{
        for (lst; lst != NULL; lst = lst->prox){
            printf("%d\n", (*lst).info);
        }
    }
}

void libera_lista(Lista *lst){
    Lista aux = *lst;
    while(aux != NULL) {
        Lista temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *lst = NULL;
}

void tamanho_lista(Lista lst){
    int tam = 0;
    if(lista_vazia(lst) == 1)
        printf("A lista eh vazia ou nao existente\n");
    else{
        while(lst != NULL){
            tam++;
            lst = lst->prox;
        }
        printf("A lista contem %d elementos\n", tam);
    }
}