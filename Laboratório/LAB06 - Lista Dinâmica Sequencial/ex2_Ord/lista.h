// Lista Dinâmica Sequencial ORDENADA 

typedef struct no * Lista;

Lista cria_lista();

int lista_vazia(Lista lst);

int insere_ord(Lista *lst, int elem);

int remove_ord(Lista *lst, int elem);

void imprime_lista(Lista lst);

void libera_lista(Lista *lst);

void tamanho_lista(Lista lst);