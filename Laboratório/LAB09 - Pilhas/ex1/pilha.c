#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define max 20

// Pilha Estática Sequencial

/*
    Pilhas:
        - os elementos sao removidos na ordem inversa da inserção
        - estrutura de dados mais simples e mais utilizada na programação
        - todo acesso aos elementos devem ser feitos pelo topo
*/

struct pilha{
    int no[max];
    int topo;
};

Pilha cria_pilha(){
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));
    if(p != NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia(Pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha p){
    if(p->topo == max-1)
        return 1;
    else
        return 0;
}

int push(Pilha p, int elem){
    if(p == NULL || pilha_cheia(p) == 1)
        return 0;
    //Insere o elemento no topo
    p->topo++;
    p->no[p->topo] = elem;
    return 1;
}

int pop(Pilha p, int *elem){    // referencia
    if(p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo]; // retorna o elemento
    p->topo--;      // remove o elemento
    return 1;
}

int le_topo(Pilha p, int *elem){
    if(p == NULL || pilha_vazia(p) == 1)
        return 0;
    *elem  = p->no[p->topo];    // retorna o elemento
    return 1;
}

void imprime_pilha(Pilha p){
    if(p == NULL || pilha_vazia(p) == 1)
        printf("Pilha invalida ou vazia\n");
    else{
        for(int i = 0; i < p->topo+1; i++)
            printf("%d\n", p->no[i]); 
    }
}

void libera_pilha(Pilha *p){
    free(*p);
    *p = NULL;
}