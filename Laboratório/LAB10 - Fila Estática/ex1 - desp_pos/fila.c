#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 20

// Fila Estática com desperdício de posição

struct fila{
    int no[max];
    int ini,fim;
};

Fila cria_fila(){
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->ini == f->fim)
        return 1;
    else
        return 0;
}

int fila_cheia(Fila f){
    if(f->ini == (f->fim+1)%max)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, int elem){
    if(fila_cheia(f) == 1)
        return 0;
    
    //Insere o elemento no final
    f->no[f->fim] = elem;
    f->fim = (f->fim+1)%max;    // incremento circular
    return 1;
}

int remove_ini(Fila f, int *elem){  // incremento circular
    if(fila_vazia(f) == 1)
        return 0;
    
    //Remove o elemento no inicio
    *elem = f->no[f->ini];
    f->ini = (f->ini+1)%max;    // incremento circular
    return 1;
}

void imprime_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("A fila esta vazia\n");
    else{
        for(int i = f->ini; i != f->fim; i = (i+1)%max){
            printf("%d\n", f->no[i]);
        }

    }
}

int le_final(Fila f, int elem){
    if(fila_vazia(f) == 1)
        return 0;
    elem = f->no[f->fim];   // retorna ao elem final
        return 1;
}
