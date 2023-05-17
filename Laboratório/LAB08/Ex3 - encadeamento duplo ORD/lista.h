#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

// Lista Dinâmica com encadeamento duplo ORDENADA

typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
void imprime_lista(Lista lst);
void libera_lista(Lista *lst);

#endif