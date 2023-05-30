#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//  Lista Dinâmica RECURSIVA ORDENADA

struct no{
    int info;
    struct no *prox;
};
typedef struct no *Lista;

Lista inicializa_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if (lst == NULL)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0; // lista nao vazia
    }
}


int insere_ord(Lista *lst, int elemento){
    if (lista_vazia(*lst) == 1 || elemento <= (*lst)->info)
    {
        Lista N = (Lista)malloc(sizeof(struct no));
        if (N == NULL)
        {
        return 0; // Falha: Nó nao alocado
        }
        N->info = elemento;
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    else
    {
        int r;
        r = insere_ord(&(*lst)->prox, elemento);
        return r;
    }
}

int remove_ord(Lista *lst, int elemento){
    if (lista_vazia(*lst) || elemento < (*lst)->info)
    {
        return 0;
    }
    else
    {
        Lista aux = *lst;
        if (elemento == (*lst)->info)
        {
        *lst = aux->prox;
        free(aux);
        return 1;
        }
        else
        {
        int r;
        r = remove_ord(&(*lst)->prox, elemento);
        return r;
        }
    }
}

int obtem_valor_elemento(Lista lst, int pos_elemento){
    int cont = 0;
    if (lista_vazia(lst) == 1)
    {
        return 0; // falha
    }
    for (lst; lst != NULL; lst = lst->prox)
    {
        if (cont == pos_elemento)
        {
        return (*lst).info;
        }
        cont++;
    }
}

void imprime_lista(Lista lst){
    if (lista_vazia(lst) == 1)
    {
        printf("Lista vazia ou nao existe");
    }
    else
    {
        for (lst; lst != NULL; lst = lst->prox)
        {
        printf("\n%d", (*lst).info);
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