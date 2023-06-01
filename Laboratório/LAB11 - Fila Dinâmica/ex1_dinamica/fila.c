#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Fila Dinâmica Encadeada

struct no{
    int info;
    struct no *prox;
};

struct fila{
    struct no * ini;
    struct no * fim;
};

Fila cria_fila(){
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if(f!=NULL){
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem){
    struct no * N;
    N = (struct no *)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;
    N->info = elem; // preenche o campo info
    N->prox = NULL;     // preenche campo prox
    if(fila_vazia(f) == 1)
        f->ini = N;     //se fila vazia
    else
        (f->fim)->prox = N;     // Se fila com elementos(NÃO vazia)
    f->fim = N;     // campo fim aponta pra N
    return 1;
}

int remove_ini(Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;
    struct no *aux = f->ini;        // aux aonta para o 1 nó
    *elem = aux->info;      // retorna o valor do elemento

    //Verifica se a fila tem um unico nó
    if(f->ini == f->fim)
        f->fim == NULL;
    
    f->ini = aux->prox;     // retira 1º nó da fila
    free(aux);  // libera memoria alocada
    return 1;
}


int le_final(Fila f, int elem){
    if(fila_vazia(f) == 1)
        return 0;

    struct no *aux = f->ini;
    elem = aux->info;
        return 1;
}


void imprime_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("A fila esta vazia\n");
    struct no *aux = f->ini;
    for(aux; aux != NULL; aux = aux->prox){
        printf((aux->prox != NULL)? "%d" : "%d", aux->info);
        printf("\n");
    }
}

