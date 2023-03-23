#include <stdio.h>
#include <stdlib.h>

double *extremosVetor(double *vet, int size)
{
  double *ext;
  ext = vet;
  double maior = vet[0], menor = vet[0];
  for (int i = 0; i < size; i++)
  {
    {
      if (menor > *(vet + i))
        ext[0] = *(vet + i);
      if (maior < *(vet + i))
        ext[1] = *(vet + i);
    }
  }

  return ext;
}

int main()
{
  int n, i;
  double *vet, *extremos;

  printf("\nQuantos elementos deseja inserir: ");
  scanf("%d", &n);

  vet = (double *)malloc(n * sizeof(double));

  for (i = 0; i < n; i++)
  {
    printf("\nInforme o valor: ");
    scanf("%lf", &vet[i]);
  }

  extremos = extremosVetor(vet, n);

  printf("\nVetor inserido\n");
  for (i = 0; i < n; i++)
  {
    printf("\nvalor: %.2lf", vet[i]);
  }

  printf("\nMenor elemento: %.2lf", extremos[0]);
  printf("\nMaior elemento: %.2lf", extremos[1]);

  free(vet);

  return 0;
}