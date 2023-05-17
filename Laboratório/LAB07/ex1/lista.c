#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica NÃO ordenada COM NÓ cabeçalho

struct no{
    int info;
    struct no *prox;
};

/*
    A lista sempre aponta pro nó cabeçalho
        - Nó deve ser alocado dinamicamente na criação da lista
    Lista vazia é representada pelo nó cab apontando para NULL
*/
Lista cria_lista(){
    // alocando nó cabeçalho
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));
    // colocando a lista no estado de vazia
    if(cab!=NULL){  // só se a alocação nao falhar
        cab->prox = NULL;
        cab->info = 0;  // opcional (guardar qtd, tamanho da lista)
    }
    return cab; // se alocação falhar, retorna NULL
}

int lista_vazia(Lista lst){
    if(lst->prox == NULL)
        return 1;
    else
        return 0;
}

/*
    Implementação visa SIMPLIFICAÇÃO do código
        - evita tratar separadamente o 1º nó da lista

    2 tipos possiveis de inserção
        - lista vazia
        - lista com 1 ou mais elementos
    
    Preenchimento padrao dos campos do novo nó:
        - info: valor do novo elem
        - prox: recebe o endereço armazenado pelo nó cabeçalho

    -Nó cabeçalho recebe o endereço do novo nó e a lista é passada POR VALOR e não por referencia
*/
int insere_elem(Lista lst, int elem){ // (Lista *lst) ----> passagem por referencia
    // aloca um novo nó
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;   //falha na alocação
    //preenche os campos do novo nó
    N->info = elem; // insere o conteudo(valor do elem)
    N->prox = lst->prox;    // aponta para o 1º nó atual da lista // (*lst)-> prox      referencia
    lst->prox = N;  // faz o nó cabeçalho apontar para o novo nó // (*lst)->prox = N    referencia
    lst->info++;    // opcional(incrementa qtde de nós na lista)
    return 1;
}

/*
    Remoção nao afeta o ponteiro da lista
        -1ºnó é sempre o nó cabeçalho
        Envolve apenas mudança no campo prox dos nós
    3 casos possiveis
        - lista vazia
        - elemento existente na lista
        - elemento não está na lista
*/
int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0;   // falha
    
    Lista aux = *lst;   // ponteiro auxiliar para o nó cabeçalho
    //percorrimento até achar o elem ou final da lista
    while(aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;

    if(aux->prox == NULL)   // trata final de lista
        return 0;   // falha
    
    // remove elem != 1º nó da lista
    Lista aux2 = aux->prox; // aponta nó a ser removido
    aux->prox = aux2->prox; // retira nó da lista
    free(aux2); // libera memoria alocada
    (*lst)->info--; // opcional(decrementa qtde de elementos na lista)
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