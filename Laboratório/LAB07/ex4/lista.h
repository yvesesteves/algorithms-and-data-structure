// Nome: ListaNaoOrdenada
// Dados: numeros inteiros
// Lista das operações: inicializa_lista, lista_vazia, lista_cheia, insere_elemento, remove_elemento, obtem_valor_elemento, libera_lista, imprime_lista

//  Lista Dinâmica RECURSIVA ORDENADA

typedef struct no *Lista;

// Entradas: nenhuma
// Pre-condicao: nenhuma
// Processo: criar uma Lista sem valores definidos e aloca espaco na memoria
// Saida: endereço de uma Lista criada
// Pos-condicao: nenhuma
Lista inicializa_lista();

// Entradas: endereco de uma Lista
// Pre-condicao: nenhuma
// Processo: Verifica se existe algum elemento na lista ou se ela nao possui elementos
// Saida: 1 caso lista esteja vazia, 0 se nao houver elementos ou lista for nula
// Pos-condicao: nenhuma
int lista_vazia(Lista lst);

// Entradas: endereco de uma Lista
// Pre-condicao: lista ser valida
// Processo: Verifica se a quantidade maxima, 20 elementos, foi atingida
// Saida: 1 caso lista esteja cheia, 0 se quantidade maxima nao foi atingida, ou seja, lista nao cheia
// Pos-condicao: nenhuma
// int lista_cheia(Lista *lst);

// Entradas: endereco da lista e elemento inteiro a ser inserido
// Pre-condicao: lista ser valida e nao estar cheia
// Processo: inserir elemento no final da lista
// Saida: 1 se sucesso ou 0 se falha
// Pos-condicao: lista de entrada com elemento a mais
int insere_ord(Lista *lst, int elemento);

// Entradas: endereco de uma lista e elemento a ser removido
// Pre-condicao: lista ser valida e nao estar vazia
// Processo: percorrer a lista ate encontrar elemento desejado ou chegar ao seu final. Se o elemento existe, remove ele da lista.
// Saida: 1 se sucesso ou 0 se falha
// Pos-condicao: lista de entrada com um elemento a menos
int remove_ord(Lista *lst, int elemento);

// Entradas: endereco da lista e posicao do elemento desejado
// Pre-condicao: lista ser valida e nao estar vazia
// Processo: percorrer a lista ate encontrar o elemento desejado. Se elemento existir, retornar elemento.
// Saida: elemento desejado se sucesso ou 0 se falha
// Pos-condicao: nenhuma
int obtem_valor_elemento(Lista lst, int pos_elemento);

// Entradas: endereco de memoria do endereco de memoria de uma Lista
// Pre-condicao: nenhuma
// Processo: limpar a memoria utilizada pela Lista e limpar seu endereco de memoria tambem
// Saida: nenhuma
// Pos-condicao: endereco da lista liberado
void libera_lista(Lista *lst);

// Entradas: endereco da lista
// Pre-condicao: lista ser valida e nao estar vazia
// Processo: percorrer a lista e printar cada elemento.
// Saida: nenhuma
// Pos-condicao: nenhuma
void imprime_lista(Lista lst);

void tamanho_lista(Lista lst);