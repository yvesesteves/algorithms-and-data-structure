#include <stdio.h>
#include <stdlib.h>
#include “ArvoreBinaria.h”

struct No
{
    int info;
    struct No *esq;
    struct No *dir;
};

// CRIANDO ARVORE
ArvBin *criaArvBin()
{
    ArvBin *raiz = (ArvBin *)malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

// LIBERANDO ARVORE
void liberaArv(ArvBin *raiz)
{
    if (raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

// LIBERANDO NÓ
void liberaNo(struct No *no)
{
    if (no == NULL)
        return;
    liberaNo(no→esq);
    liberaNo(no→dir);
    free(no);
    no = NULL;
}

// BUSCAR UM ELEMENTO ABB
int buscaABB(ArvBin *raiz, int v)
{
    if (raiz == NULL)
        return 0; // não foi alocada
    struct No *atual = *raiz;
    while (atual != NULL)
    {
        if (v == atual→ info)
            return 1; // encontrou
        if (v < atual→ info)
            atual = atual→ esq;
        else
            atual = atual→ dir;
    }
    return 0; // não encontrou
}

// INSERIR UM ELEMENTO NO LOCAL CORRETO EM ABB
int insereABB(ArvBin *raiz, int v)
{
    if (raiz == NULL)
        return 0; // não alocou
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    if (novo == NULL)
        return 0; // não alocou
    novo→ info = v;
    novo→dir = novo→esq = NULL;
    if (*raiz == NULL) // árvore vazia
        *raiz = novo;
    else
    { // procurar a posição correta
        struct No *atual = *raiz, *ant = NULL;
        while (atual != NULL)
        {
            ant = atual;
            if (v == atual→info)
            { // já existe
                free(novo);
                return 0;
            }
            if (v < atual→ info)
                atual = atual→ esq;
            else
                atual = atual→dir;
        } // fim while
        if (v < ant→info) // inserindo pela esquerda
            ant→esq = novo;
        else
            ant→dir = novo;
    }
    return 1; // inserido
} // fim função

// REMOÇÃO NA ARVORE ABB (func q busca o nó a ser removido)
int removeABB(ArvBin *raiz, int v)
{
    if (raiz == NULL)
        return 0; // não foi alocada
    struct No *ant = NULL, *atual = *raiz;
    while (atual != NULL)
    {
        if (v == atual→ info)
        { // achei o elemento
            if (atual == *raiz)
                *raiz = removeAtual(atual);
            else if (ant→ esq == atual)
                ant→ esq = removeAtual(atual);
            else
                ant→ dir = removeAtual(atual);
            return 1; // elemento removido
        } // fim if
        ant = atual; // continua procurando
        if (v < atual→ info)
            atual = atual→ esq;
        else
            atual = atual→ dir;
    } // fim while
    return 0; // não foi removido
}

// REMOVE NÓ ATUAL (func responsavel por tratar os 3 tipos de remocao)
// são eles: nó folha, nó com 1 filho, nó com 2 filhos
No *removeAtual(struct No *atual)
{
    struct No *p, *q;
    // não existe subarv. esq.
    if (atual→ esq == NULL)
    { // CASO 1
        q = atual → dir;
        free(atual);
        return q;
    }
    p = atual; // procura o filho mais à direita da subárvore da esquerda
    q = atual→esq;
    while (q→ dir != NULL)
    { // CASO 2
        p = q;
        q = q→ dir;
    }
    if (p != atual)
    {                        // tem filho mais à direita, isto é, tem sub.arv.direita na sub.arv.esq de atual
        p→ dir = q→ esq;     //(1)
        q→ esq = atual→ esq; //(2)
    } // CASO 2.2
    q → dir = atual→ dir; //(3)
    free(atual);
    return q;
} // fim função

// CONSULTA NA ABB
int consulta_ABB(ArvBin *raiz, int v)
{
    if (raiz == NULL)
        return 0;
    struct No *atual = *raiz;
    while (atual != NULL)
    {
        if (v == atual->info)
        {
            return 1;
        }
        if (v > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
