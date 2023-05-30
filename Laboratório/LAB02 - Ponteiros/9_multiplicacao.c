#include <stdio.h>
#include <stdlib.h>

struct ponto
{
  int x, y;
};
typedef struct ponto Ponto;

void alteraPonto(Ponto *pto, int cte)
{
  (*pto).x = (*pto).x * cte;
  (*pto).y = (*pto).y * cte;
}

int main()
{
  int n = 1, i, cte;
  Ponto *vet;

  vet = (Ponto *)malloc(n * sizeof(Ponto));

  printf("\nDigite 1 ponto: ");

  for (i = 0; i < n; i++)
  {
    printf("\nPonto %d", i + 1);
    printf("\nInforme coordenada x: ");
    scanf("%d", &vet[i].x);
    printf("Informe coordenada y: ");
    scanf("%d", &vet[i].y);
  }

  printf("Digite a constante: ");
  scanf("%d", &cte);

  printf("\nPontos inseridos:\n");
  for (i = 0; i < n; i++)
  {
    printf("Ponto %d\n", i + 1);
    printf("coordenada x: %d\n", vet[i].x);
    printf("coordenada y: %d\n", vet[i].y);
    printf("\n");
  }

  // altera valor
  alteraPonto(&vet[0], cte);

  for (i = 0; i < n; i++)
  {
    printf("Novo Ponto (%d, %d)\n", vet[i].x, vet[i].y);
    printf("\n");
  }

  free(vet);

  return 0;
}