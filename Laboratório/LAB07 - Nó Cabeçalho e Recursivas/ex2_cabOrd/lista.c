#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica ORDENADA COM NÓ cabeçalho


struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));
    if(cab!=NULL){
        cab->prox = NULL;
        cab->info = 0;  // opcional
    }
    return cab;
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1;
    else
        return 0;
}

int insere_ord(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;     // insere elem

    //percorrimento da lista
    Lista aux = *lst;   // faz aux apontar para nó cabeçalho
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;    // avança

    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++;        // opcional
        return 1;
}

int remove_ord(Lista *lst,int elem){
    if(lista_vazia (*lst) == 1)
        return 0; // falha 
    Lista aux = *lst;// ponteiro auxiliar para o nó cabeçalho
    // percorrimento até achar o elem ou final de lista 
    while (aux -> prox != NULL && aux -> prox -> info < elem)
        aux = aux -> prox;
    if (aux -> prox == NULL || aux -> prox -> info > elem) // Trata final de lista
        return 0; // falha
    // remove elemento da lista
    Lista aux2 = aux -> prox; // aponta nó a ser removido 
    aux -> prox = aux2 -> prox; //retira nó da lista 
    free(aux2); //libera memoria alocada
    (*lst)->info --; // opcional: decrementa qtde de nós na lista
    return 1;     
}

void imprime_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
    printf("\nA lista esta vazia.\n");

    else{
        Lista aux=lst->prox;

        while(aux!=NULL){
            printf("\n%d\n",aux->info);
            aux=aux->prox;
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

void tamanho_lista(Lista *lst){
    if(lista_vazia(*lst) == 1)
        printf("Lista vazia ou nao existente\n");
    else{
        printf("A lista tem %d elementos", (*lst)->info);
    }
}