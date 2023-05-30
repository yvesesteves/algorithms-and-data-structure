// Fila Encadeada com uso do Contador
typedef struct fila *Fila;

/*
Fila cria_fila()
    Entrada: nenhuma
    Pré condição: nenhuma
    Processo: cria uma fila e a coloca no estado de vazia
    Saída: endereço da fila criada
    Pós condição: nenhuma
*/
Fila cria_fila();

/*
fila_vazia(Fila f)
    Entrada: endereço da fila
    Pré condição: nenhuma
    Processo: verifica se a fila está vazia
    Saída: retorna 1 se fila vazia, 0 se não
    Pós condição: nenhuma
*/
int fila_vazia(Fila f);

/*
fila_cheia(Fila f)
    Entrada: endereço da fila
    Pré condição: nenhuma
    Processo: verifica se a fila está cheia
    Saída: retorna 1 se fila cheia, 0 se não
    Pós condição: nenhuma
*/
int fila_cheia(Fila f);

/*
insere_fim(Fila f, int elem)
    Entrada: endereço da fila e elemento a ser inserido
    Pré condição: fila nao estar cheia
    Processo: insere o elemento no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós condição: uma fila com um elemento a mais
*/
int insere_fim(Fila f, int elem);

/*
remove_ini(Fila f, int *elem)
    Entrada: endereço da fila e ponteiro do elemento
    Pré condição: fila nao estar vazia
    Processo: remove um elemento no inicio da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós condição: uma fila com um elemento a menos
*/
int remove_ini(Fila f, int *elem);

/*
void imprime_fila(Fila f)
    Entrada: endereço da fila
    Pré condição: fila não estar vazia
    Processo: percorre a fila e a imprime
    Saída: nenhuma
    Pós condição: nenhuma
*/
void imprime_fila(Fila f);

/*
int le_final(Fila f, int *elem)
    Entrada: endereço da fila e ponteiro do elemento
    Pré condição: fila não estar vazia
    Processo: ler o elemento informado no final da fila
    Saída: 1 se sucesso, 0 se falha
    Pós condiçao: variavel de retorno com o elemento final da fila
*/
int le_final(Fila f, int elem);