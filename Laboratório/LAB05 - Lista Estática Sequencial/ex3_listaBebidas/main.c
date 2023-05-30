#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bebidas.h"
#define MAX 20

// Lista Sequencial Estática de bebidas NÃO ordenada

int main()
{
    int op;
    Lista *lst;

    do{
        do{
            printf("\n --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
        printf(" Escolha uma opcao\n");
        printf(" 1. Criar lista de registros\n");
        printf(" 2. Inserir registro\n");
        printf(" 3. Apagar ultimo registro\n");
        printf(" 4. Liberar lista\n");
        printf(" 5. Imprimir tabela\n");
        printf(" 6. SAIR\n");
        printf(" Opcao: ");
        scanf("%d", &op);
        if ((op < 1) || (op > 6)){
            printf("\n\n Opcao Invalida! Tente novamente...");
            system("CLS || clear");
        }
    } while ((op < 1) || (op > 6));

        switch (op){
        case 1:
            printf("\n\n Criar lista de registros");
            lst = cria_lista();
            break;

        case 2:
            printf("\n\n Inserir registro");
            char nome[50];
            int volume;
            float preco;
            printf("\n Qual nome do elemento que deseja inserir: ");
            fflush(stdin);
            gets(nome);
            printf("\n Qual volume do elemento: ");
            scanf("%d", &volume);
            printf("\n Qual preco do elemento: ");
            scanf("%f", &preco);
            int flag3 = insere_elem(lst, nome, volume, preco);
            if (flag3 == 1){
                printf("\n Elemento inserido com sucesso");
            }
            if (flag3 == 0){
                printf("\nFalha na insercao");
            }
            break;

        case 3:
            printf("\n\n Apagar ultimo elemento: ");
            int flag4 = remove_ultimo(lst);
            if (flag4 == 1){
            printf("\n Elemento removido com sucesso");
            }
            if (flag4 == 0){
                printf("\nFalha na remocao");
            }
            break;

        case 4:
            libera_lista(&lst);
            printf("Lista liberada!");
            break;
            
        case 5:
            printf("\n ---TABELA DE BEBIDAS---\n");
            imprime_tabela(lst);
            printf("_______________________________\n");
            break;
            
        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
        }
    } while (op != 6);

    return 0;
}