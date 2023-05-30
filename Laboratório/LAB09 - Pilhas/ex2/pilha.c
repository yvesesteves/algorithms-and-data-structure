#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Pilha Dinâmica Sequencial

struct no{
    int info;
    struct no* prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

int push(Pilha *p, int elem){
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    N->info = elem;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p) == 1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(*p) == 1)
        return 0;
        *elem = (*p)->info;
    return 1;
    
}

void imprime_pilha(Pilha p){
    if(p == NULL || pilha_vazia(p))
        printf("A pilha eh invalida ou vazia");
    else{
        Pilha aux = p;

        while(aux != NULL){
            printf("\n%d", aux->info);
            aux = aux->prox;
        }
    }
}


void libera_pilha(Pilha *p){
    Pilha aux = *p;
    while(aux != NULL) {
        Pilha temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *p = NULL;
}

