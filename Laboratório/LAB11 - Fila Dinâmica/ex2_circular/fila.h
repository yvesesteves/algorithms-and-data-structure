// Fila com Encadeamento Circular
typedef struct no *Fila;

/*
Fila cria_fila()
    Entrada: nenhuma
    Pré Condição: nenhuma
    Processo: cria uma fila vazia
    Pós Condição: nenhuma
    Saída: uma fila vazia criada
*/
Fila cria_fila();


/*
int fila_vazia(Fila f)
    Entrada: endereço da fila
    Pré Condição: nenhuma
    Processo: verificar se a fila esta vazia
    Pós Condição: retorna 1 se fila vazia, 0 caso contrario
    Saída: nenhuma
*/
int fila_vazia(Fila f);


/*
int insere_fim(Fila *f, int elem)
    Entrada: ponteiro pra fila e elemento a ser inserido
    Pré Condição: ter uma fila criada
    Processo: inserir elemento no final da fila
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a mais no final
*/
int insere_fim(Fila *f, int elem);


/*
int remove_ini(Fila *f, int *elem)
    Entrada: ponteiro pra fila e elemento a ser removido
    Pré Condição: fila nao estar vazia
    Processo: remover elemento no inicio da fila
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a menos no inicio
*/
int remove_ini(Fila *f, int *elem);


/*
int le_final(Fila *f, int elem)
    Entrada: ponteiro pra fila e o elemento do final
    Pré-condição: a fila nao estar vazia
    Processo: ler o elemento informado no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: variavel de retorno com o elemento final da fila
*/
int le_final(Fila f, int *elem);


/*
void imprime_fila(Fila f)
    Entrada: ponteiro pra fila
    Pré-condição: a fila nao estar vazia
    Processo: inserir o elemento informado no final da fila
    Saída: nenhuma
    Pós-condição: a fila de entrada com um elemento a mais
*/
void imprime_fila(Fila f);