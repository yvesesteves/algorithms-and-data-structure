// Pilha Dinâmica Sequencial
typedef struct no *Pilha;

Pilha cria_pilha();

int pilha_vazia(Pilha p);

int push(Pilha *p, int elem);

int pop(Pilha *p, int *elem);

int le_topo(Pilha *p, int *elem);

void imprime_pilha(Pilha p);

void libera_pilha(Pilha *p);