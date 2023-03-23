#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    int x, y;
};
typedef struct ponto Ponto;

int main()
{
    int n, i;
    Ponto *vet;

    printf("\nQuantos pontos deseja digitar: ");
    scanf("%d", &n);

    vet = (Ponto *)malloc(n * sizeof(Ponto));

    for (i = 0; i < n; i++)
    {
        printf("\nPonto %d", i + 1);
        printf("\nInforme coordenada x: ");
        scanf("%d", &vet[i].x);
        printf("Informe coordenada y: ");
        scanf("%d", &vet[i].y);
    }

    printf("\nPontos inseridos:\n");
    for (i = 0; i < n; i++)
    {
        printf("Ponto %d\n", i + 1);
        printf("coordenada x: %d\n", vet[i].x);
        printf("coordenada y: %d\n", vet[i].y);
        printf("\n");
    }
    free(vet);

    return 0;
}