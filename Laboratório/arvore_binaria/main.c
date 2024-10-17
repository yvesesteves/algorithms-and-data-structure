#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

// Função para exibir o menu
void exibirMenu()
{
    printf("=== Menu ===\n");
    printf("1. Inserir elemento\n");
    printf("2. Buscar elemento\n");
    printf("3. Remover elemento\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main()
{
    ArvBin *raiz = criaArvBin(); // Cria a árvore binária
    int opcao, valor;

    while (1)
    {
        exibirMenu();        // Exibe o menu
        scanf("%d", &opcao); // Lê a opção do usuário

        switch (opcao)
        {
        case 1: // Inserir
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            if (insereABB(arvore, valor))
                printf("Valor %d inserido com sucesso.\n", valor);
            else
                printf("Valor %d já existe na árvore.\n", valor);
            break;

        case 2: // Buscar
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            if (buscaABB(arvore, valor))
                printf("Valor %d encontrado na árvore.\n", valor);
            else
                printf("Valor %d não encontrado na árvore.\n", valor);
            break;

        case 3: // Remover
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            if (removeABB(arvore, valor))
                printf("Valor %d removido com sucesso.\n", valor);
            else
                printf("Valor %d não encontrado para remoção.\n", valor);
            break;

        case 4:                // Sair
            liberaArv(arvore); // Libera a memória da árvore
            printf("Saindo...\n");
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    }

    return 0; // Retorna 0 para indicar que o programa terminou corretamente
}
