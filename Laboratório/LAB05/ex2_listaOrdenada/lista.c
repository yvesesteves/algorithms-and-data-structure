#include <stdio.h> 
#include <stdlib.h>
#include "lista.h"
#define MAX 20

// Lista Estática Sequencial Ordenada

struct lista{
    int num[MAX];
    int Fim;
};


Lista* cria_lista()
{
    Lista *lst;
    lst = (Lista*) malloc(sizeof(struct lista));
    
    if(lst!=NULL)
        lst->Fim=0;
    

    return lst;
} 

/*
    Entrada: recebe endereço da lista
    Pré Condição: nenhuma
    Processo: verificar se a lista esta vazia
    Saída: 1 - lista vazia // 0 - lista não vazia
    Pós Condição: nenhuma
*/
int lista_vazia(Lista *lst){
    if(lst->Fim==0)
        return 1; // Lista vazia
    else
        return 0; // Lista não vazia
}


int lista_cheia (Lista *lst){
    if (lst->Fim == MAX)
        return 1; // Lista cheia
    else
        return 0; // Lista não está cheia
}


int insere_ord(Lista *lst,int elem){
    if(lst ==NULL|| lista_cheia(lst)==1)
        return 0;
    
    //trata lista vazia ou elemento >= último da lista
    if(lista_vazia(lst) ==1 || elem >= lst-> num[lst->Fim-1]){
        lst-> num[lst->Fim]= elem;
    }
    else { 
        int i,aux=0;
        while (elem>=lst->num[aux])//percorrimento
            aux++;

        for(i=lst -> Fim; i > aux;i--)//deslocamento
            lst -> num[i]= lst->num[i-1];
        lst ->num[aux]=elem;//inclui o elemento na lista    
    }
    lst -> Fim++;// Avança o Fim
    return 1;
}


int remove_ord(Lista *lst,int elem){
    if(lst==NULL|| lista_vazia(lst)==1|| elem< lst ->num[0]|| elem>=lst ->num[lst->Fim-1])
        return 0; // falha 
    
    int i,Aux = 0;
    
    // Pecorrimento até achar o elem ou nó maior,ou final de lista
    while (Aux < lst ->Fim && lst ->num[Aux]<elem)
    Aux++;

    if (Aux ==lst->Fim || lst ->num[Aux]> elem)//(não existe elemento)
        return 0; // falha 

    //deslocamento à esq. do sucessor até o final da lista
    for (i= Aux + 1;i<lst->Fim;i++)
        lst -> num[i-1] = lst ->num[i];
    
    lst ->Fim --;// decremento do campo fim
    return 1; // sucesso

    
}


void obtem_valor_elem(Lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1){
        printf("\nA lista esta vazia ou nao esta alocada");
    }
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