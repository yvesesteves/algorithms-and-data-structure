#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bebidas.h"

//Lista Dinamica de bebidas NÃO ordenada.

struct registro{
    char nome[20];
    int volume;
    float preco;
};

struct no{
    Registro Registro;
    struct no *prox;
};

Lista inicializa_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if (lst == NULL){
        return 1; // lista vazia
    }
    else{
        return 0; // lista nao vazia
    }
}
    /*
    int lista_cheia(Lista lst)
    {
    if (lst->fim == MAX)
    {
        return 1; // lista cheia
    }
    else
    {
        return 0; // lista nao cheia
    }
    }
    */

int insere_elemento(Lista *lst, char *nome, int volume, float preco){
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL){
        return 0; // Falha: Nó nao alocado
    }
    N->Registro.preco = preco;
    N->Registro.volume = volume;
    strcpy(N->Registro.nome, nome);
    N->prox = *lst;
    *lst = N;
    return 1;
}

int remove_ultimo(Lista *lst){
    if (lista_vazia(*lst) == 1){
        return 0; // falha
    }
    Lista aux = *lst;
    // if (elemento == (*lst)->info)
    // {
    //   *lst = aux->prox;
    //   free(aux);
    //   return 1;
    // }

    while (aux->prox->prox != NULL){
        aux = aux->prox;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

void imprime_lista(Lista lst){
    if (lista_vazia(lst) == 1){
        printf("Lista vazia ou nao existente\n\n");
    }
    else{
        for (lst; lst != NULL; lst = lst->prox)
        {
        printf("\nBebida: %s", (*lst).Registro.nome);
        printf("\nVolume: %d ml", (*lst).Registro.volume);
        printf("\nPreco: R$%.2f ", (*lst).Registro.preco);
        printf("\n--------------------------------\n");
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