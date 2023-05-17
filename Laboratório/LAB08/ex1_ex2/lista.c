#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica Circular NÃO ordenada

struct no{
    int info;
    struct no *prox;
};

/* 
Lista cria_lista()
    Entrada: nenhuma
    Pré-Condição: nenhuma
    Processo: cria uma lista
    Saída: nenhuma
    Pós-Condição: uma lista vazia
*/

Lista cria_lista(){
    return NULL;
}

/*
int lista_vazia(Lista lst)
    Entrada: recebe a lista
    Pré-Condição: ter uma lista criada
    Processo: verifica se a lista está vazia
    Saída: 1 se lista vazia // 0 se não vazia
    Pós-Condição: nenhuma
*/


int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    else
        return 0;
}

/*  
insere_inicio(Lista *lst, int elem)
    Entrada: ponteiro para uma lista e um elemento
    Pré-condição: ter uma lista criada e estar alocada
    Processo: cria um no e aloca memoria para ele. Em seguida faz o no apontar para o proximo no.
                Se for o primeiro elemento, ele aponta para si mesmo. Se nao, aponta para o proximo no inserido.
    Saída: 1 se for sucesso e 0 se tiver falha
    Pós-condição: lista com um elemento a mais

*/

int insere_inicio(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;

    if(*lst==NULL){
        N->info=elem;
        N->prox=N;
        *lst=N;
    }
    else{
        N->info=elem;
        N->prox=(*lst)->prox;
        (*lst)->prox=N;
    }

    return 1;
}

/*
int insere_final(Lista *lst, int elem)
    Entrada: ponteiro pra lista e um elemento
    Pré-Condição: ter uma lista criada e a lista estar alocada
    Processo: adiciona um elem no final da lista
    Saída: 0 se falha // 1 se sucesso 
    Pós-Condição: uma lista com um elemento a mais no final dela
*/

int insere_final(Lista *lst, int elem){
    // Aloca um novo nó e preenche campo info
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N==NULL)
        return 0;   // falha; nó não alocado
    N->info = elem;     // insere o conteudo(valor do elem)

    //Trata lista vazia
    if(lista_vazia(*lst) == 1){
        N->prox = N;    // Faz o novo nó apontar pra ele mesmo
        *lst = N;       // Faz a lista apontar para o novo nó (ultimo nó)
    }

    // Trata lista com elementos (1 ou +)
    else{
        N->prox = (*lst)->prox;     // faz o novo nó apontar pro 1ºnó
        (*lst)->prox = N;           // faz o ultimo nó apontar para o novo nó
        *lst = N;       // Faz a lista apontar para o novo nó (ultimo nó)
    }
    return 1;       // sucesso
}

/*
int remove_inicio(Lista *lst, int *elem)
    Entrada: ponteiro pra lista e um ponteiro pro elemento
    Pré-Condição: lista não estar vazia
    Processo: remover um elemento que esteja no inicio da lista
    Saída: 1 se sucesso // 0 se falha
    Pós-Condição: lista com 1 elem a menos do inicio
*/

int remove_inicio(Lista *lst, int *elem){
    //Trata lista vazia
    if(lista_vazia(*lst) == 1)
        return 0;
    Lista aux = (*lst)->prox;   // faz aux apontar para o primeiro nó
    *elem = aux->info;          // retorna o valor do nó a ser removido
    if(*lst == (*lst)->prox)   // trata lista com 1 unico nó
        *lst = NULL;
    else    // trata lista com mais de um elem
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;   // sucesso
}

/*  
remove_final(Lista *lst, int *elem)
    Entrada: ponteiro para uma lista e um ponteiro para um elemento
    Pré-condição: A lista deve ser alocada e nao pode estar vazia
    Processo: cria um no auxiliar que aponta para o segundo no da lista.
                 Escreve no elemento inteiro o elemento a ser removido. Depois disso, exclui o
                    ultimo no, que estava o elemento.
    Saída: 1 se for sucesso e 0 se tiver falha
    Pós-condição: lista com um elemento a menos
*/

int remove_final(Lista *lst, int *elem){
    if(lst==NULL||lista_vazia(*lst))
        return 0;

    Lista aux=(*lst)->prox;

    while(aux->prox!=(*lst))
        aux=aux->prox;

    *elem=aux->prox->info;

    aux->prox=(*lst)->prox;
    (*lst)=aux;

    return 1;
}


/*
void imprime_lista(Lista lst)
    Entrada: endereço da lista
    Pré Condição: a lista nao deve estar vazia e deve estar alocada
    Processo: percorre a lista e a imprime
    Saída: nenhuma
    Pós Condição: nenhuma
*/


void imprime_lista(Lista lst){
    if(lst==NULL||lista_vazia(lst))
        printf("\nA lista esta vazia.\n");

    else{
        Lista aux=lst->prox;
        do{
            printf("%d\n",aux->info);
            aux=aux->prox;
        }while(aux!=lst->prox);
    }
}