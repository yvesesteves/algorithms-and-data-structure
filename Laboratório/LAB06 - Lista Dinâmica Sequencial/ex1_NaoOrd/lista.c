#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Lista Dinâmica Sequencial NÃO ordenada

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista(){
    //Lista *lst;
    return NULL;
}


int lista_vazia(Lista lst){
    if (lst == NULL)
        return 1;   // lista vazia
    else
        return 0;   // lista não vazia
}



/*
    Inserção na dinamica NAO ordenada:
        insere no inicio da lista(evita o percorrimento)
    2 criterios de inserção:
        - lista vazia
        - lista com 1 ou mais elementos
    Alocação do novo nó e preenchimento dos campos do novo nó
        info recebe o valor do novo elemento
        prox recebe o endereço armazenado pela lista(1ºnó atual)
    Alteração do endereço armazenado na lista
        exige que a variavel seja passada por REFERENCIA!
*/
int insere_elem(Lista *lst, int elem){
    Lista N = (Lista)malloc(sizeof(struct no));     // aloca um novo nó
    if(N == NULL)
        return 0;   // falha ao alocar nó

    //Preenche os campos do novo nó
    N->info = elem;     // insere o conteudo(valor do elem)
    N->prox = *lst;     // aponta para o primeiro nó atual da lista
    *lst = N;       // faz a lista apontar para o novo nó
    return 1;   // sucesso
}

/*
    Necessita de percorrimento da lista(busca pelo elem a ser removido)

    remoção no meio NÃO envolve movimentos dos nós(apenas mudanças nos ponteiros)

    Criterio de ordenaçao afeta quando nao existe o elem na lista(percorre ate o final)

    4 casos possiveis:
        - lista vazia
        - elem igual ao 1º nó da lista
        - elem entre o 2º e o ultimo nó da lista
        - elem não está na lista
*/
int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0;   // falha
    Lista aux = *lst;    // ponteiro auxiliar para o primeiro nó
    // trata elem = primeiro nó da lista
    if(elem == (*lst)->info){
        *lst = aux->prox;   // lista aponta para o segundo nó
        free(aux);  // libera memoria alocada
        return 1;   // sucesso
    }
    while(aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;
    if(aux->prox == NULL)   // trata final de lista
        return 0;   // falha
        // remove o primeiro elem diferente do primeiro nó da lista
    Lista aux2 = aux->prox;     // aponta nó a ser removido
    aux->prox = aux2->prox;     // retira nó da lista
    free(aux2);     // libera memoria alocada
    return 1;       // sucesso
    
}


void imprime_lista(Lista lst){
    if(lst==NULL || lista_vazia(lst))
        printf("\nA lista esta vazia\n");
    else{
        Lista aux = lst;

        while(aux!=NULL){
            printf("\n%d", aux->info);
            aux = aux -> prox;
        }
    }
}

/*
void libera_lista(Lista **lst){
    free(*lst);
    *lst = NULL;
}
*/
void libera_lista(Lista *lst){
    Lista aux = *lst;
    while(aux != NULL) {
        Lista temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *lst = NULL;
}

/*
void libera_lista(Lista *lst){
	struct no* aux = *lst;
	while(aux != NULL){
		struct no* tmp = aux;
		free(aux);
		aux = tmp->prox;
	}
	*lst = NULL;
}
*/


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