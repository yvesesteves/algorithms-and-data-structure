#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define MAX 20

// Lista Sequencial NÃO ordenada.

struct lista{
    int num[MAX];
    int Fim;
};


Lista* cria_lista(){
    Lista *lst;
    lst = (Lista *)malloc(sizeof(struct lista));

    if(lst != NULL)
        lst -> Fim = 0;
    
    return lst;
}


int lista_vazia(Lista *lst){
    if(lst->Fim == 0)
        return 1;   // lista vazia
    else
        return 0;   // lista nao vazia
}


int lista_cheia(Lista *lst){
    if(lst->Fim == MAX)
        return 1;   // lista cheia
    else
        return 0;   // lista nao cheia
}


int insere_elem(Lista *lst, int elem){
    if(lst == NULL || lista_cheia(lst) == 1){
        return 0;       // falha na inserçao
    }
    
    lst -> num[lst->Fim] = elem;    // insere elem
    lst -> Fim++;                   // avança ao fim
        return 1;   // sucesso, elem inserido
}


int remove_elem(Lista *lst, int elem){
    if(lst == NULL || lista_vazia(lst) == 1){
        return 0;   // falha
    }
    
    int aux;
    while(aux < lst->Fim && lst->num[aux] != elem)    // percorrimento até achar o elem ou o final da lista
            aux++;

        if(aux == lst->Fim){ // final da lista (caso o elemento não existe)
            return 0;   // falha
        }       
    
        for(int i = aux+1; i < lst->Fim; i++){     // deslocando a esq do sucessor até o final da listal
            lst->num[i-1] = lst->num[i];
        }
         
        lst->Fim--;     // decremento do campo fim
        return 1;       // sucesso
    
}



void obtem_valor_elem(Lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1)
        printf("\nA lista esta vazia ou nao esta alocada");
    else{
        for(int aux = 0; aux < lst->Fim; aux++){
            printf("%d\n", lst->num[aux]);
        }
    }
}

void tamanho_lista(Lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1)
        printf("\nA lista esta vazia ou nao esta alocada");
    else
        printf("A lista contem %d elementos\n", lst->Fim);
}

void libera_lista(Lista **lst){
    free(*lst);
    *lst = NULL;
}
