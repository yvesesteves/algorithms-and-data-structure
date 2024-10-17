#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct No *ArvBin;
ArvBin *criaArvBin();
void liberaArv(ArvBin *raiz);
void liberaNo(struct No *no);
int buscaABB(ArvBin *raiz, int v);
int insereABB(ArvBin *raiz, int v);
No *removeAtual(No *atual) int removeABB(ArvBin *raiz, int v);
int consulta_ABB(ArvBin *raiz, int v)

#endif