// Fila Estática com desperdício de posição
typedef struct fila *Fila;

/*
Fila cria_fila()
    Entrada: nenhuma
    Pré-condição: nenhuma
    Processo: cria uma fila e a coloca no estado de fila vazia
    Saída: endereço da fila criada
    Pós-condição: nenhuma
*/
Fila cria_fila();

/*
int fila_vazia(Fila f)
    Entrada: endereço da fila
    Pré-condição: nenhuma
    Processo: verifica se a lista esta vazia
    Saída: retorna 1 se vazia ou 0 caso contrario
    Pós-condição: nenhuma
*/
int fila_vazia(Fila f);

/*
int fila_cheia(Fila f)
    Entrada: endereço da fila
    Pré-condição: nenhuma
    Processo: verifica se a fila esta cheia
    Saída: retorna 1 se cheia ou 0 caso contrario
    Pós-condição: nenhuma
*/
int fila_cheia(Fila f);

/*
int insere_fim(Fila f, int elem)
    Entrada: endereço da fila e o elemento a ser inserido 
    Pré-condição: fila não estar cheia
    Processo: inserir o elemento informado no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: a fila de entrada com um elemento a mais
*/
int insere_fim(Fila f, int elem);

/*
int remove_ini(Fila f, int *elem)
    Entrada: endereço da fila e o ponteiro do elemento a ser inserido 
    Pré-condição: fila não estar vazia
    Processo: remover o elemento no inicio da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: a fila de entradacom um elemento a menos
*/
int remove_ini(Fila f, int *elem);

/*
void imprime_fila(Fila f)
    Entrada: endereço da fila 
    Pré-condição: a fila nao estar vazia
    Processo: inserir o elemento informado no final da fila
    Saída: nenhuma
    Pós-condição: a fila de entrada com um elemento a mais
*/
void imprime_fila(Fila f);

/*
int le_final(Fila f, int elem)
    Entrada: endereço da fila e o elemento do final
    Pré-condição: a fila nao estar vazia
    Processo: ler o elemento informado no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: variavel de retorno com o elemento final da fila
*/
int le_final(Fila f, int elem);