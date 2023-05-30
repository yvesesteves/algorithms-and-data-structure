#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bebidas.h"
#define MAX 20

// Lista Sequencial Estática de bebidas NÃO ordenada

struct registro{
    char nome[20];
    int volume;
    float preco;
};

struct lista{
    Registro Registro[MAX];   // int no[MAX];
    int Fim;
};

Lista *cria_lista(){
    Lista *lst;
    lst = (Lista*)malloc(sizeof(Lista));

    if(lst != NULL)
        lst->Fim = 0;

    return lst;
}

int lista_vazia(Lista *lst){
    if(lst->Fim == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista *lst){
    if(lst->Fim == MAX)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *lst, char *nome, int volume, float preco){
    if(lst == NULL || lista_cheia(lst) == 1){
        return 0;   // falha
    }
    
    lst->Registro[lst->Fim].preco = preco;
    lst->Registro[lst->Fim].volume = volume;
    strcpy(lst->Registro[lst->Fim].nome, nome);
        lst->Fim++;
        return 1;   // sucesso
}

int remove_ultimo(Lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;

    lst->Fim--;
        return 1;   // removido
}

void imprime_tabela(Lista *lst){
    if(lst == NULL){
        printf("Lista nao existe\n");
    }
    else{
        for(int i = 0; i < lst-> Fim; i++){
            printf("\n%s", lst->Registro[i].nome);
            printf("\n%.2f", lst->Registro[i].preco);
            printf("\n%d", lst->Registro[i].volume);
            printf("\n");
        }
    }
}

void libera_lista(Lista **lst){
    free(*lst);
    *lst = NULL;
}