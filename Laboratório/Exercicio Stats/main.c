#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main() {
  int n;
  printf("Digite a quantidade de numeros: ");
  scanf("%d", &n);

  float *arr = (float*) malloc(n * sizeof(float));

  for(int i = 0; i < n; i++) {
    printf("Digite o %d-esimo numero: ", i);
    scanf("%f", &arr[i]);
  }

  float s = soma(arr, n);
  float m = media(arr, n);
  float d = desvio(arr, n);

  printf("Soma = %f\n", s);
  printf("Media = %f\n", m);
  printf("Desvio = %f\n", d);

  return 0;
}