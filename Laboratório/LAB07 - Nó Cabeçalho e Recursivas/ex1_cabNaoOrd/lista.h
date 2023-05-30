// Lista Dinâmica NÃO ordenada COM NÓ cabeçalho
typedef struct no *Lista;

Lista cria_lista();

int lista_vazia(Lista lst);

int insere_elem(Lista lst, int elem);

int remove_elem(Lista *lst, int elem);

void imprime_lista(Lista lst);

void libera_lista(Lista *lst);

void tamanho_lista(Lista *lst);

