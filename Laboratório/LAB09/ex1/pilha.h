// Pilha Estática Sequencial

typedef struct pilha *Pilha;

/*
Pilha cria_pilha()
    Entrada: nenhuma
    Pré-Condição: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Saída: endereço da pilha criada
    Pós-Condição: nenhuma
*/
Pilha cria_pilha();

/*
int pilha_vazia(Pilha p)
    Entrada: endereço da pilha
    Pré-Condição: nenhuma
    Processo: verifica se a pilha está vazia
    Saída: retorna 1 se pilha vazia, 0 caso contrario
    Pós-Condição: nenhuma
*/
int pilha_vazia(Pilha p);

/*
int pilha_cheia(Pilha p)
    Entrada: endereço da pilha
    Pré-Condição: nenhuma
    Processo: verifica se a pilha está cheia
    Saída: retorna 1 se pilha cheia, 0 caso contrario
    Pós-Condição: nenhuma
*/
int pilha_cheia(Pilha p);

/*
int push(Pilha p, int elem)
    Entrada: endereço da pilha e o elem a ser inserido
    Pré-Condição: pilha nao estar cheia
    Processo: inserir o elemento informado no topo da pilha
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: a pilha de entrada com um elem a mais
*/
int push(Pilha p, int elem);

/*
int pop(Pilha p, int *elem)
    Entrada: endereço da pilha e o elem de retorno do elem do topo da pilha
    Pré-Condição: pilha nao estar vazia
    Processo: remover o elem que esta no topo da pilha e retorna-lo
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: a pilha de entrada com um elem a menos e a variavel de retorno com o elem removido
*/
int pop(Pilha p, int *elem);

/*
int le_topo(Pilha p, int *elem)
    Entrada: endereço da pilha e o elem de retorno do elem do topo da pilha
    Pré-Condição: pilha nao estar vazia
    Processo: retornar o elem que esta no topo da pilha SEM remove-lo
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: variavel de retorno com o elemento do topo
*/
int le_topo(Pilha p, int *elem);

/*
void imprime_pilha(Pilha p)
    Entrada: endereço da pilha
    Pré-Condição: pilha nao estar vazia e estar alocada
    Processo: percorre a pilha e a imprime
    Pós-Condição: nenhuma
    Saída: pilha mostrada na tela para o usuario
*/
void imprime_pilha(Pilha p);


void libera_pilha(Pilha *p);
