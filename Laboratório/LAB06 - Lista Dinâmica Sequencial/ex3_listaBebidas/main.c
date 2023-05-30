#include <stdio.h>
#include <stdlib.h>
#include "bebidas.h"

//Lista Dinamica de bebidas NÃO ordenada.

int main()
{
    int op;
    Lista lst;

    do
    {
        do
        {
        printf("\n --- LISTAS DINAMICA ENCADEADA --- \n\n");
        printf(" Escolha uma opcao\n");
        printf(" 1. Criar lista\n");
        printf(" 2. Verificar lista vazia\n");
        printf(" 3. Inserir elemento\n");
        printf(" 4. Remover ultimo elemento\n");
        printf(" 5. Liberar lista\n");
        printf(" 6. Imprimir lista\n");
        printf(" 7. SAIR\n");
        printf(" Opcao: ");
        scanf("%d", &op);
        if ((op < 1) || (op > 7))
        {

            printf("\n\n Opcao Invalida! Tente novamente...");
            system("CLS || clear");
        }
        } while ((op < 1) || (op > 7));

        switch (op)
        {
        case 1:
        lst = inicializa_lista();
        printf("Lista criada!\n\n");
        break;

        case 2:
        printf("\n\n Ver se lista esta vazia");
        int flag = lista_vazia(lst);
        if (flag == 1)
        {
            printf("\nLista vazia\n");
        }
        if (flag == 0)
        {
            printf("\nLista nao vazia\n");
        }
        break;

        case 3:
        printf("\n\n Inserir elemento");
        char nome[50];
        int volume;
        float preco;
        printf("\n Qual nome do elemento que deseja inserir: ");
        fflush(stdin);
        gets(nome);
        printf("\n Qual volume (em ml) do elemento: ");
        scanf("%d", &volume);
        printf("\n Qual preco do elemento: ");
        scanf("%f", &preco);
        int flag3 = insere_elemento(&lst, nome, volume, preco);
        if (flag3 == 1)
        {
            printf("\n Elemento inserido com sucesso\n");
        }
        if (flag3 == 0)
        {
            printf("\nFalha na insercao\n");
        }
        break;

        case 4:
        printf("\n\n Remover ultimo elemento ");
        int flag4 = remove_ultimo(&lst);
        if (flag4 == 1)
        {
            printf("\n Elemento removido com sucesso\n");
        }
        if (flag4 == 0)
        {
            printf("\nFalha na remocao\n");
        }
        break;

        case 5:
        libera_lista(&lst);
        printf("Lista liberada!!\n");
        break;

        case 6:
        printf("\n<<Lista>>\n");
        imprime_lista(lst);
        printf("----------------------------------\n");
        break;

        default:
        printf("\n\n Pressione qualquer tecla para FINALIZAR...");
        }
    } while (op != 7);

    return 0;
    }