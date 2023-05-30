#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 20

// Fila Encadeada com uso do Contador

struct fila{
    int no[max];
    int ini, cont;
};

Fila cria_fila(){
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = 0;
        f->cont = 0;
    }
    return f;
}


int fila_vazia(Fila f){
    if(f->cont == 0)
        return 1;
    else
        return 0;
}


int fila_cheia(Fila f){
    if(f->cont == max)
        return 1;
    else
        return 0;
}


int insere_fim(Fila f, int elem){
    if(fila_cheia(f) == 1)
        return 0;
    
    //Insere o elemento no final
    f->no[(f->ini+f->cont)%max] = elem;
    f->cont++;  // incremento normal
    return 1;
}


int remove_ini(Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;

    // Remove o elemento do início
    *elem = f->no[f->ini];
    f->ini = (f->ini+1)%max;    // incremento circular
    f->cont--;  // decremento não circular
    return 1;
}


void imprime_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("A fila esta vazia\n");
    else{
        int i;
        for(i = 0; i < f->cont; i++){
            printf("%d\n", f->no[(f->ini+i)%max]);
        }
    }
}


int le_final(Fila f, int elem){
    if(fila_vazia(f) == 1)
        return 0;
    elem = f->no[(f->ini+f->cont-1)%max];
        return 1;
}