#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("----------VETOR DE CHAR----------\n");
    char nome[25];
    int i = 0;
    printf("Digite um nome: ");
    scanf("%s", nome);

    while(nome[i] != '\0'){
        if(97 <= nome[i] <= 122)
            nome[i] = nome[i] - 32;
        i++;
    }

    printf("\nO nome digitado eh: %s\n", nome);

    return 0;
}