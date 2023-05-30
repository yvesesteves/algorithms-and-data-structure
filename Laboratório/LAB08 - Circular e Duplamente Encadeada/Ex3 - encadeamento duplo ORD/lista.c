#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica com encadeamento duplo ORDENADA

struct no{
    int info;
    struct no *prox;
    struct no *ant;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 0;
    else
        return 1;
}

/*
    2 casos possiveis:
        -Lista vazia: insere o elem no campo info e coloca o campo ant e prox como NULL
        -Lista com elems: campo info com o valor do elem, campo prox aponta p/ o 1 nó (N->prox = L),
            campo ant com NULL (N->ant = L->ant), faz o campo ant do 1ºnó da lista apontar paraa o novo nó (L->ant = N),
            faz a lista apontar para o novo nó (L=N)

*/
int insere_ord(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0;
    
    N->info = elem;
    // trata lista vazia e menor que primeiro elem
    if (lista_vazia(*lst) == 1 || elem < (*lst)->info){
        N->ant = NULL;
        N->prox = *lst;
        if (lista_vazia(*lst) == 0)
        {
            (*lst)->ant = N;
        }
        *lst = N;
    }
    else{ // trata elem maior que o primeiro
        Lista aux = *lst;
        while (aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox;
        if (aux->prox == NULL) // trata elem maior que ultimo
            N->prox = NULL;
        else{ // trata elem inserido no meio de outros elementos
            N->prox = aux->prox;
            aux->prox->ant = N;
        }
        aux->prox = N;
        N->ant = aux;
    }
    return 1;
}

/* 
INSERÇÃO NAO ORDENADA
int insere_elem(Lista *lst, int elem){
    //aloca um novo nó e preenche o campo info
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL){
        return 0; 
    }  // falha, não alocado
    N->info = elem; // insere o conteudo, valor elem
    N->ant = NULL;  // não tem antecessor do novo nó
    N->prox = (*lst); // sucessor do novo nó recebe o mesmo end. da lista
    if(lista_vazia(*lst) == 0)  // se lista NÃO vazia
        (*lst)->ant=N;      // faz antecessor do 1º nó ser o novo nó
    *lst = N;   // faz a lista apontar para o novo nó
        return 1;
}
*/
/*
    6 cenários possiveis:
        -lista vazia
        -elem não está na çosta

        -elem está na lista:
            --lista com um unico nó
            --elem = 1ºnó
            --elem = ultimo nó
            --1ºnó < elem < ultimo nó
*/
int remove_ord(Lista *lst, int elem)
{
    if (lista_vazia(*lst) == 1 || elem < (*lst)->info)
        return 0;

    Lista aux = *lst; // aponta primeiro elemento
    if (elem == aux->info)
    {
        aux->prox->ant = NULL;
        *lst = aux->prox;
        aux->prox = NULL; // teste
        free(aux);
    }
    else
    {
        while (aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox;
        Lista aux2 = aux->prox; // aponta pro elem a ser removido
        if (aux2->prox == NULL && aux2->info == elem)
        { // trata ultimo elemento
            aux->prox = NULL;
            aux2->ant = NULL; // teste
            free(aux2);
        }
        else
        {
            if (aux2 == NULL)
                return 0;
            if (aux2->info != elem) // elem nao esta na lista
                return 0;
            aux->prox = aux2->prox;
            aux->prox->ant = aux;
            free(aux2);
        }
    }
    return 1;
}

/*
REMOÇÃO NAO ORDENADA

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst)) // trata lista vazia
        return 0;
    Lista aux = *lst;   // faz aux apontar para o 1nó
    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox;
    if(aux->info != elem)
        return 0;   // elem nao está na lista
    if(aux->prox != NULL)
        (aux)->prox->ant = aux->ant;
    if(aux->ant != NULL)
        (aux)->ant->prox = aux->prox;
    if(aux == *lst)
        *lst = aux->prox;
    free(aux);
    return 1;
}

*/

void imprime_lista(Lista lst)
{
    if (lista_vazia(lst) == 1)
        printf("Lista vazia!");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf("%d ", lst->info);
    }
}

void libera_lista(Lista *lst)
{
    Lista aux = *lst;
    Lista aux2;

    while (aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(aux);
    *lst = NULL;
    printf("\nLista liberada");
}